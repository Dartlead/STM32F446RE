#include "GPIO.h"
#include "_stm32f446re_registers.h"

/* ============================================================================================================= */
/* Helper Functions                                                                                              */
/* ============================================================================================================= */
/*! Checks if the configuration parameters for a GPIO port/pin combo are valid.
 *
 * @brief Checks if:
 *        - The pin number is between 0 and 15
 *        - The port is between ports A and H (0 and 7 in the enum)
 *        - The mode is between GPIO_mode_altrnt_func_0 and GPIO_mode_analog (0 and 18 in the enum)
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @param cnfg
 *    (input) The configuration for the desired port/pin combo.
 * @return false if the parameters are invalid, true otherwise.
 */
static bool _GPIO_params_are_valid(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t const max_pin_value = 15;
	bool params_are_valid = false;

	if (  (port >= GPIO_port_A && port <= GPIO_port_H)
		&& (pin <= max_pin_value)
		&& (cnfg.mode >= GPIO_mode_altrnt_func_0 && cnfg.mode <= GPIO_mode_analog)
	) {
		params_are_valid = true;
	} else {
		//Invalid params, return var is already false
	}

	return params_are_valid;
}

/*! Computes the address of a port's MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFRL, or AFRH register.
 *
 * @brief Each GPIO port has its own set of MODER, OTYPER, OSPEEDR, etc. registers and the base address of each
 *        GPIO port's register set is 0x400 apart from each other. We can compute the address of any GPIO port
 *        register by taking the address of that desired register for GPIO port A and then offsetting it by some
 *        multiple of 0x400.
 *
 *        For instance, if we wanted the address of GPIO port D's ODR register we start with the address of GPIO
 *        port A's ODR which is 0x4002_0014. Now GPIO port D's register set is 0xC00 apart from GPIO port A's (or
 *        3x 0x400) so if we offset the address of GPIO port A's ODR by that 0xC00 we get the correct address of
 *        GPIO port D's ODR.
 *
 * @param port
 *    (input) The desired port.
 * @return The address of the desired port's specific register.
 */
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_MODER_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_MODER)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_OTYPER_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_OTYPER)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_OSPEEDR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_OSPEEDR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_PUPDR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_PUPDR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_IDR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_IDR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_ODR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_ODR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_BSRR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_BSRR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_LCKR_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_LCKR)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_AFRL_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_AFRL)) + (uint32_t)(0x400U * port)); }
__attribute__((always_inline)) static inline uint32_t * _GPIO_compute_AFRH_addr(GPIO_port const port)
	{ return (uint32_t *)((uint8_t *)(&(GPIOA_AFRH)) + (uint32_t)(0x400U * port)); }

/* ============================================================================================================= */
/* GPIO Initialization Sub Functions                                                                             */
/* ============================================================================================================= */
/*! Updates the mode register to configure the pin's desired mode.
 *
 * @brief The 32 bits of the MODER register are broken up into 16 pairs where pair 0 correlates to pin 0, pair 1
 *        correlates to pin 1, etc. For each pair (and by extension pin), there exist 4 values that corresponds
 *        to the four modes that the pin can be in:
 *        Input Mode:              0b00
 *        Output Mode:             0b01
 *        Alternate Function Mode: 0b10
 *        Analog Mode:             0b11
 *
 *        This function takes the desired pin and finds which of the 16 pairs of bits this pin correlates to
 *        (bit_0_pos is bit 0, bit_1_pos is bit 1 of the pair) and then will either set or clear bits 0 and 1 of
 *        the pair depending on the mode via a temporary variable (that is initialized with the original value
 *        of the register, modified, then actuall written to the register).
 *
 * @param port
 *    (input) The desired por whose pin is being configured.
 * @param pin
 *    (input) The desired pin that is going to have its value in the MODER register configured.
 * @param mode
 *    (input) The desired mode of the pin.
 */
static void _GPIO_configure_port_pin_set_mode(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t volatile * const GPIOx_MODER_addr = _GPIO_compute_MODER_addr(port);
	uint32_t accum_MODER_val = *GPIOx_MODER_addr; //Holds accumulated MODER writes, initialized to current MODER
	uint32_t const bit_0_pos = pin * 2;           //The bitwise position of bit 0 is always 2 * the pin number
	uint32_t const bit_1_pos = bit_0_pos + 1;     //The bitwise position of bit 1 is then 1 more than bit 0

	switch (cnfg.mode)
	{
		case GPIO_mode_input: //Configure the MODER register for the desired pin for input mode
			accum_MODER_val &= ~(0x1 << bit_0_pos);
			accum_MODER_val &= ~(0x1 << bit_1_pos);
			break;
		case GPIO_mode_output: //Configure the MODER register for the desired pin for output mode
			accum_MODER_val |= 0x1 << bit_0_pos;
			accum_MODER_val &= ~(0x1 << bit_1_pos);
			break;
		case GPIO_mode_altrnt_func_0:
		case GPIO_mode_altrnt_func_1:
		case GPIO_mode_altrnt_func_2:
		case GPIO_mode_altrnt_func_3:
		case GPIO_mode_altrnt_func_4:
		case GPIO_mode_altrnt_func_5:
		case GPIO_mode_altrnt_func_6:
		case GPIO_mode_altrnt_func_7:
		case GPIO_mode_altrnt_func_8:
		case GPIO_mode_altrnt_func_9:
		case GPIO_mode_altrnt_func_10:
		case GPIO_mode_altrnt_func_11:
		case GPIO_mode_altrnt_func_12:
		case GPIO_mode_altrnt_func_13:
		case GPIO_mode_altrnt_func_14:
		case GPIO_mode_altrnt_func_15: //Configure the MODER register for the desired pin for alternate function mode
			accum_MODER_val &= ~(0x1 << bit_0_pos);
			accum_MODER_val |= 0x1 << bit_1_pos;
			break;
		case GPIO_mode_analog: //Configure the MODER register for the desired pin for analong mode
			accum_MODER_val |= 0x1 << bit_0_pos;
			accum_MODER_val |= 0x1 << bit_1_pos;
		default:
			break;
	}
	*GPIOx_MODER_addr = accum_MODER_val; //Write the accumulated changes to the register
}

/*! Updates the Alternate Function Low/High registers if an alternate function operation for the pin is desired.
 *
 * @brief When alternate function mode for a pin is desired, the AFRL or AFRH (AFRL when the pin is between 0
 *        and 7, AFRH when the pin is between 8 and 15) must be updated. Each register houses 8 quadruples of bits
 *        where each bit quadruple contains the desired alternate function (0 through 15) for the associated pin
 *        (i.e. quadruple 0 -> alternate function for pin 0, quadruple 1 -> alternate function for pin 1, etc).
 *
 *        The pin_shift_amnt variable refers to how many << operations must occur to get any 4-bit value in the
 *        correct bitwise position to properly reference the desired pin (i.e. 0 shifts are required to put in
 *        a 4-bit value for pin 0's bit quadruple and 4 shifts are required to put in a 4-bit value for pin 1's
 *        bit quadruple). Updating the AFR registers is then simply clearing the pin's bit quadruple and then
 *        ORing in the new value via a temporary variable (that is initialized with the original value of the
 *        register, modified as mentioned before, then actually written to the register).
 *
 * @param see _GPIO_configure_port_pin_set_mode(). The parameters are the same.
 */
static void _GPIO_configure_port_pin_set_AF(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t volatile * const GPIOx_AFRL_addr = _GPIO_compute_AFRL_addr(port);
	uint32_t volatile * const GPIOx_AFRH_addr = _GPIO_compute_AFRH_addr(port);
	uint32_t const pin_shift_amnt = (pin <= 7) ? (pin * 4) : ((pin - 8) * 4);
	uint32_t accum_AFR_val = 0; //Holds accumulated AFRL/H writes

	if (pin <= 7) { //AFRL
		accum_AFR_val = *GPIOx_AFRL_addr; //Initialize to register's current value

		/* Clear the 4 bits for alternate function, then write in the desired alternate function */
		accum_AFR_val &= ~(0xFU << pin_shift_amnt);
		accum_AFR_val |= ((cnfg.mode & 0xFU) << pin_shift_amnt);

		*GPIOx_AFRL_addr = accum_AFR_val; //Write the accumulated changes
	} else { //AFRH
		accum_AFR_val = *GPIOx_AFRH_addr; //Initialize to register's current value

		/* Clear the 4 bits for alternate function, then write in the desired alternate function */
		accum_AFR_val &= ~(0xFU << pin_shift_amnt);
		accum_AFR_val |= ((cnfg.mode & 0xFU) << pin_shift_amnt);

		*GPIOx_AFRH_addr = accum_AFR_val; //Write the accumulated changes
	}
}

/*! Updates the Output Type register with the outpute type for the pin combo.
 *
 * @brief The two types of output ports are either push-pull or open-drain. To update the Output Type register
 *        with one of these two possible values we need to first check the pin is configured to be an output port
 *        else the value of pin in this register is meaningless. Then we simply set or clear (for open-drain and
 *        push-pull, respectively) the appropriate bit in the register (i.e. bit 0 is to pin 0, bit 1 is to pin
 *        1, etc).
 *
 * @param see _GPIO_configure_port_pin_set_mode(). The parameters are the same.
 */
static void _GPIO_configure_port_pin_set_output_type(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t volatile * const GPIOx_OTYPER_addr = _GPIO_compute_OTYPER_addr(port);

	if (cnfg.type == GPIO_output_type_push_pull) {
		*GPIOx_OTYPER_addr &= ~(0x1 << pin);
	} else {
		*GPIOx_OTYPER_addr |= 0x1 << pin;
	}
}

/*! Updates the Output Speed register with the desired speed for the pin.
 *
 * @brief When the pin is configured as output (this function will do nothing if the pin is not in output mode),
 *        we can update the speed of the pin with the Output Speed register. This register has 16 2-bit fields that
 *        correspond to a particular pin on a GPIO port (i.e. field 0 is to pin 0, field 1 is to pin 1, etc). So
 *        we find which 2-bit field corresponds to the desired pin and write one of the following values:
 *        low:    b00
 *        medium: b01
 *        fast:   b10
 *        high:   b11
 *        to said 2-bit field using a temporary variable (that is initialized with the original value of the
 *        register, modified with one of the four aforementioned values, then written to the register).
 *
 * @param see _GPIO_configure_port_pin_set_mode(). The parameters are the same.
 */
static void _GPIO_configure_port_pin_set_output_speed(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t volatile * const GPIOx_OSPEEDR_addr = _GPIO_compute_OSPEEDR_addr(port);
	uint32_t accum_OSPEEDR_val = *GPIOx_OSPEEDR_addr; //Accumulator initialized to register's current value
	uint8_t const shift_amnt = pin * 2;               //The pin's bit placement in the register

	switch (cnfg.speed)
	{
		case GPIO_output_speed_low:
			accum_OSPEEDR_val &= ~(0x3 << shift_amnt);
			break;
		case GPIO_output_speed_medium:
			accum_OSPEEDR_val |= 0x1 << shift_amnt;
			accum_OSPEEDR_val &= ~(0x2 << shift_amnt);
			break;
		case GPIO_output_speed_fast:
			accum_OSPEEDR_val &= ~(0x1 << shift_amnt);
			accum_OSPEEDR_val |= 0x2 << shift_amnt;
			break;
		case GPIO_output_speed_high:
			accum_OSPEEDR_val |= 0x3 << shift_amnt;
			break;
		default:
			break;
	}
	*GPIOx_OSPEEDR_addr = accum_OSPEEDR_val; //Write the accumulated changes to the register
}

/*! Updates the Pullup Pulldown register with the desired pull for the pin.
 *
 * @brief The pull direction of the pin can be updated with the Pullup Pulldown register that has 16 2-bit fields
 *        that correspond to a particular pin on a GPIO port (i.e. field 0 is to pin 0, field 1 is to pin 1, etc).
 *        So we find which 2-bit field corresponds to the desired pin and write one of the following values:
 *        none:      b00
 *        pull-up:   b01
 *        pull-down: b10
 *        to said 2-bit field using a temporary variable (that is initialized with the original value of the
 *        register, modified with one of the aforementioned values, then written to the actual register).
 *
 * @param see _GPIO_configure_port_pin_set_mode(). The parameters are the same.
 */
static void _GPIO_configure_port_pin_set_pull(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	uint32_t volatile * const GPIOx_PUPDR_addr = _GPIO_compute_PUPDR_addr(port);
	uint32_t accum_PUPDR_val = *GPIOx_PUPDR_addr; //Accumulator initialized to register's current value
	uint8_t const shift_amnt = pin * 2;           //The pin's bit placement in the register

	switch (cnfg.pull)
	{
		case GPIO_pull_none:
			accum_PUPDR_val &= ~(0x3 << shift_amnt);
			break;
		case GPIO_pull_pull_up:
			accum_PUPDR_val |= 0x1 << shift_amnt;
			accum_PUPDR_val &= ~(0x2 << shift_amnt);
			break;
		case GPIO_pull_pull_down:
			accum_PUPDR_val &= ~(0x1 << shift_amnt);
			accum_PUPDR_val |= 0x2 << shift_amnt;
			break;
		default:
			break;
	}
	*GPIOx_PUPDR_addr = accum_PUPDR_val; //Write the accumulated changes to the register
}

/* ============================================================================================================= */
/* Configuration Functions                                                                                       */
/* ============================================================================================================= */
/*! Configures and initializes the desired GPIO port and pin with the desired configuration.
 *
 * @brief Read the comments on each sub function to determine its purpose in the configuration of the timer module.
 * @note  You MUST set the alternate function before setting the mode. Otherwise you will see glitches on the line.
 */
void GPIO_configure_port_pin(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
) {
	if (_GPIO_params_are_valid(port, pin, cnfg)) {
		RCC_AHB1ENR |= 0x1 << port; //Enable the clock to the GPIO port

		_GPIO_configure_port_pin_set_AF(port, pin, cnfg);
		_GPIO_configure_port_pin_set_mode(port, pin, cnfg);
		_GPIO_configure_port_pin_set_output_type(port, pin, cnfg);
		_GPIO_configure_port_pin_set_output_speed(port, pin, cnfg);
		_GPIO_configure_port_pin_set_pull(port, pin, cnfg);
	} else {
		//Invalid configuration parameters, do nothing
	}
}

/* ============================================================================================================= */
/* GPIO Write Functions                                                                                          */
/* ============================================================================================================= */
/*! Writes a binary 0 or 1 to the desired GPIO port and pin.
 *
 * @brief GPIO writes are done through the Output Data Register (ODR). We simply set the appropriate bit (0-15
 *        for pins 0-15) in the register (i.e. bit 0 is to pin 0, bit 1 is to pin 1, etc).
 */
void GPIO_write(GPIO_port const port
	, uint32_t const pin
	, uint32_t const write_val
) {
	uint32_t volatile * const GPIOx_ODR_addr = _GPIO_compute_ODR_addr(port);

	if ((pin >= 0) && (pin <= 15)) {
		if (write_val) {
			*GPIOx_ODR_addr |= 0x1 << pin;
		} else {
			*GPIOx_ODR_addr &= ~(0x1 << pin);
		}
	} else {
		//Out-of-bounds pin value, do nothing
	}
}

/*! Writes (atomically) a binary 0 or 1 to the desired GPIO port and pin.
 *
 * @brief Atomic GPIO writes are done through the Bit Set-Reset Register (BSRR). If an atomic write of '1' is
 *        desired, we simply set the appropriate bit (0-15 for pins 0-15) in the register (i.e. bit 0 is to pin
 *        0, bit 1 is to pin 1, etc). However, if an atomic write of '0' is desired, we still need to set a bit
 *        in the BSRR register but we use bits 31:16 instead 15:0. The same principle applies, bit 16 corresponds
 *        to port 0, bit 17 to port 1, bit 18 to port 2, etc. This is why the clr_bit_offset value is 16.
 */
void GPIO_write_atomic(GPIO_port const port
	, uint32_t const pin
	, uint32_t const write_val
) {
	uint32_t const clr_bit_offset = 16;
	uint32_t volatile * const GPIOx_BSRR_addr = _GPIO_compute_BSRR_addr(port);

	if ((pin >= 0) && (pin <= 15)) {
		if (write_val) {
			*GPIOx_BSRR_addr |= 0x1 << pin;
		} else {
			*GPIOx_BSRR_addr |= 0x1 << (pin + clr_bit_offset);
		}
	} else {
		//Out-of-bounds pin value, do nothing
	}
}

/*! Toggles the value on the desired GPIO port and pin.
 *
 * @brief GPIO toggles are done through the Output Data Register (ODR). We simply XOR the appropriate bit (0-15
 *        for pins 0-15) in the register (i.e. bit 0 is to pin 0, bit 1 is to pin 1, etc).
 */
void GPIO_toggle(GPIO_port const port
	, uint32_t const pin
) {
	uint32_t volatile * const GPIOx_ODR_addr = _GPIO_compute_ODR_addr(port);

	if ((pin >= 0) && (pin <= 15)) {
		*GPIOx_ODR_addr ^= 0x1 << pin;
	} else {
		//Out-of-bounds pin value, do nothing
	}
}

/* ============================================================================================================= */
/* GPIO Read Functions                                                                                           */
/* ============================================================================================================= */
/*! Reads the value on a GPIO port and pin.
 *
 * @brief GPIO reads are done through the Input Data Register (IDR). We simply check if the appropriate bit (0-15
 *        for pins 0-15) in the register (i.e. bit 0 is to pin 0, bit 1 is to pin 1, etc) has been set. If it has
 *        been set, then the GPIO pin is inputting a logical 1, else a logical 0.
 */
uint32_t GPIO_read(GPIO_port const port
	, uint32_t const pin
) {
	uint32_t pin_val = 0;
	uint32_t volatile * const GPIOx_IDR_addr = _GPIO_compute_IDR_addr(port);

	if ((pin >= 0) && (pin <= 15)) {
		if (*GPIOx_IDR_addr & (0x1 << pin)) {
			pin_val = 1;
		} else {
			pin_val = 0;
		}
	} else {
		//Out-of-bounds pin value, do nothing
	}

	return pin_val;
}

/* ============================================================================================================= */
/* GPIO Miscellaneous Functions                                                                                  */
/* ============================================================================================================= */
/*! Locks a GPIO port/pin combo.
 *
 * @brief The LCKR register is used to lock a GPIO port/pin combo and the register is broken down as such:
 *        Bit 16    - The locking 'write' bit, it must be written in a particular sequnce to lock anything
 *        Bits 15:0 - One bit per pin on a GPIO port (i.e. bit 0 is to pin 0, bit 1 is to pin 1, etc)
 *
 *        To lock a particular pin, its bit in the register must be set to '1' THEN the correct "write sequence"
 *        must be applied to the 'write' bit and to the rest of the register. The sequence is described as:
 *        1) WRITE '1' to the write bit, WRITE the current value of bits 15:0 (updated with a '1' for the pin
 *           that is to be locked) to bits 15:0
 *        2) WRITE '0' to the write bit, WRITE the current value of bits 15:0 (updated with a '1' for the pin
 *           that is to be locked) to bits 15:0
 *        3) WRITE '1' to the write bit, WRITE the current value of bits 15:0 (updated with a '1' for the pin
 *           that is to be locked) to bits 15:0
 *        4) READ bits 16:0
 *        5) (optional) Read bit 16
 *
 * @note  After locking a particular port/pin combo, that pin's place in the MODER, OTYPER, OSPEEDR, PUPDR, AFRL,
 *        and AFRH registers will be permanently locked until a system-wide reset is issued.
 */
void GPIO_lock(GPIO_port const port
	, uint32_t const pin
) {
	uint32_t volatile * const GPIOx_LCKR_addr = _GPIO_compute_LCKR_addr(port);
	uint32_t LCKR_15_0 = (*GPIOx_LCKR_addr & 0xFFFFU) | (0x1 << pin);

	if ((pin >= 0) && (pin <= 15)) {
		//Write sequence
		*GPIOx_LCKR_addr = 0x10000U | LCKR_15_0; //(1)
		*GPIOx_LCKR_addr = LCKR_15_0;            //(2)
		*GPIOx_LCKR_addr = 0x10000U | LCKR_15_0; //(3)
		LCKR_15_0 = *GPIOx_LCKR_addr;            //(4)
		LCKR_15_0 = *GPIOx_LCKR_addr;            //(5)
	} else {
		//Out-of-bounds pin value, do nothing
	}
}

/*! Checks if a GPIO port/pin combo is locked.
 *
 * @brief To see if a pin is locked for a particular port, we simply look at that port's LCKR register and the bit
 *        that corresponds to the desired pin (bit 0 is to pin 0, bit 1 is to pin 1, etc). If the bit has been set,
 *        then the pin is locked, else the pin is not locked.
 */
bool GPIO_is_pin_locked(GPIO_port const port
	, uint32_t const pin
) {
	uint32_t volatile * const GPIOx_LCKR_addr = _GPIO_compute_LCKR_addr(port);
	bool is_pin_locked = false;

	if ((pin >= 0) && (pin <= 15)) {
		if (*GPIOx_LCKR_addr & (0x1 << pin)) {
			is_pin_locked = true;
		} else {
			//Already false, do nothing
		}
	} else {
		//Out-of-bounds pin value, do nothing
	}

	return is_pin_locked;
}

/* EOF */
