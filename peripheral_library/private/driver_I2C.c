#include "driver_I2C.h"
#include "registers_stm32f446re.h"
#include "system_stm32f446re.h"
#include "GPIO.h"
#include <stdlib.h>

/* ============================================================================================================= */
/* I2C Interrupt Vector Table Entries                                                                            */
/* ============================================================================================================= */
/*! I2C interface 1 event interrupt vector table entry.
 */
void I2C1_EV_handler(void)
{
	;
}

/*! I2C interface 1 error interrupt vector table entry.
 */
void I2C1_ER_handler(void)
{
	;
}

/*! I2C interface 2 event interrupt vector table entry.
 */
void I2C2_EV_handler(void)
{
	;
}

/*! I2C interface 2 error interrupt vector table entry.
 */
void I2C2_ER_handler(void)
{
	;
}

/*! I2C interface 3 event interrupt vector table entry.
 */
void I2C3_EV_handler(void)
{
	;
}

/*! I2C interface 3 error interrupt vector table entry.
 */
void I2C3_ER_handler(void)
{
	;
}

/* ============================================================================================================= */
/* Driver Capability/Configuration Helper Functions                                                              */
/* ============================================================================================================= */
/*! Checks that the configuration parameters are valid.
 *
 * @param interface
 *    (input) The I2C interface being initialized.
 * @param config
 *    (input) The configuration parameters for the I2C interface.
 * @return 'true' if the config is valid, 'false' otherwise.
 */
static bool I2C_init_config_valid(I2C_interface_t const interface
	, I2C_config_t const * const config
) {
	bool config_valid = true;

	if (config != NULL) {
		/* Only 100 kHz or 400 kHz SCL frequencies are allowed */
		if (config->SCL_freq != 100000 && config->SCL_freq != 400000) { config_valid = false; }

		/* APB1 must be >= 2 MHz and <= 42 MHz to fulfill CR1 FREQ[5:0] requirements */
		if (APB1_bus_clock < 2000000) { config_valid = false; }
		if (APB1_bus_clock > 42000000) {config_valid = false; }

		/* In SM mode APB clk >= 2 MHz, in FM mode APB clk >= 4 MHz AND must be a multiple of 10 MHz */
		if ((config->SCL_freq == 100000) && (APB1_bus_clock < 2000000)) { config_valid = false; }
		if ((config->SCL_freq == 400000) && (APB1_bus_clock < 4000000)) { config_valid = false; }
		if ((config->SCL_freq == 400000) && (APB1_bus_clock % 10000000 != 0)) { config_valid = false; }
	} else {
		config_valid = false;
	}

	return config_valid;
}

/*! Configures the GPIO pins to host I2C functionality.
 *
 * @brief All I2C interfaces are hosted through alternate function 4 thus the GPIO SDA_SCL_config defaults to it.
 *        Because the I2C spec calls for open-drain I2C pins, SDA and SCL are configured for open-drain with no
 *        pull-up or pull-down resistor (it is expected that the user place external pullup resistors on the I2C
 *        bus). Otherwise see the I2C driver explanation plain text for a breakdown of which ports/pins go with
 *        which I2C interface depending on the config pinout.
 *
 * @param interface
 *    (input) The I2C interface being initialized.
 * @param config
 *    (input) The configuration parameters for the I2C interface.
 */
static void I2C_init_config_GPIO_pins(I2C_interface_t const interface
	, I2C_config_t const * const config
) {
	GPIO_cnfg SDA_SCL_cnfg = {
		  .mode  = GPIO_mode_altrnt_func_4
		, .type  = GPIO_output_type_open_drain
		, .speed = GPIO_output_speed_low
		, .pull  = GPIO_pull_none
	};
	GPIO_port SDA_port = GPIO_port_A, SCL_port = GPIO_port_A;
	uint32_t SDA_pin = 0, SCL_pin = 0;

	switch (interface)
	{
		case kI2C_interface_1:
			SDA_port = SCL_port = GPIO_port_B;
			if (config->pinout == kI2C_pinout_1) {
				SDA_pin = 7;
				SCL_pin = 6;
			} else {
				SDA_pin = 9;
				SCL_pin = 8;
			}
			break;
		case kI2C_interface_2:
			if (config->pinout == kI2C_pinout_1) {
				SDA_port = SCL_port = GPIO_port_B;
				SDA_pin = 11;
				SCL_pin = 10;
			} else {
				SDA_port = SCL_port = GPIO_port_F;
				SDA_pin = 0;
				SCL_pin = 1;
			}
			break;
		case kI2C_interface_3:
			SDA_port = GPIO_port_B;
			SCL_port = GPIO_port_A;
			SDA_pin = 4;
			SCL_pin = 8;
			break;
		default:
			break;
	};
	GPIO_configure_port_pin(SDA_port, SDA_pin, SDA_SCL_cnfg);
	GPIO_configure_port_pin(SCL_port, SCL_pin, SDA_SCL_cnfg);
}

/*! Configures CR2 with the frequency of the APB1 bus.
 *
 * @brief The CR2 FREQ[5:0] field is used to generate data setup and hold times and must contain the frequency of
 *        the APB1 bus (because the APB1 is the bus that clocks the I2C peripherals) in MHz. For instance, if the
 *        APB1 is operating at 15 MHz, then FREQ[5:0] must contain the value 15.
 *
 * @param interface
 *    (input) The I2C interface being initialized.
 */
static void I2C_init_set_FREQ(I2C_interface_t const interface)
{
	uint32_t temp = I2C_CR2(interface);

	temp &= ~(0x3FUL);                              //Clear the CR2 FREQ[5:0] field
	temp |= ((APB1_bus_clock / 1000000U) & 0x3FUL); //Set the CR2 FREQ[5:0] field to APB1 bus frequency
	I2C_CR2(interface) = temp;                      //Write changes to CR2 FREQ[5:0] field
}

/*! Configures the CCR with the appropriate value to generate SCL at the desired frequency.
 *
 * @note  SM mode CCR equation:
 *        From the data sheet, T_high = T_low = CCR * T_pclk1 where T_high is the time the SCL signal spends high,
 *        T_low is the time the SCL signal spends low, and T_pclk1 is the period of the APB1 bus clock. We can
 *        convert the equation to one in the realm of frequencies instead of periods as so:
 *        T_high = T_low = (1 / desired SCL frequency) / 2       i.e. if we want a 100 kHz SCL this results in a
 *        OR                                                          period of 10000 ns, so 5000 ns for high and
 *        T_high = T_low = 1 / (2 * desired SCL frequency)            5000 ns for low.
 *
 *        T_pclk1 = 1 / (APB1 bus frequency)
 *
 *        Thus the original equation in time now becomes the following equation in terms of frequency:
 *        1 / (2 * desired SCL frequency) = CCR * (1 / APB1 bus frequency)
 *        OR
 *        CCR = APB1 bus frequency / (2 * desired SCL frequency)
 * @note  FM mode CCR equation (duty cycle of 2 i.e. T_low/T_high = 2):
 *        From the data sheet, T_high = CCR * T_pclk1 but b/c the duty cycle is 2, T_high is 1/3 of the total
 *        period of the desired SCL frequency (i.e. if T_high is 1/3 then T_low is 2/3 and then T_low is 2x
 *        T_high which satisfies the duty cycle of requirement). So...
 *        T_high = 1/3 of the SCL period = (1 / desired SCL frequency) / 3 = 1 / (3 * desired SCL frequency)
 *        T_pclk1 = 1 / (APB1 bus frequency)
 *
 *        thus CCR = T_high / T_pclk1 = (1 / (3 * desired SCL frequency)) / (1 / APB1 bus frequency)
 *                 = APB1 bus frequency / (3 * desired SCL frequency)
 *
 *        FM mode CCR equation (duty cycle of 16/9)
 *        Now instead of T_high being 1/3 of the total period of SCL, T_high is 9/25 and T_low is 16/25 of the SCL
 *        period. Thus T_high = 9/25 of the SCL period => T_high = 9 * CCR * T_pclk1
 *
 *        -> (9/25)(1/SCL) = 9 * CCR * (1/APB1) -> 1 / (25 * SCL) = CCR / APB1 -> CCR = APB1 / (25 * SCL)
 *
 * @param interface
 *    (input) The I2C interface being initialized.
 * @param config
 *    (input) The configuration parameters for the I2C interface.
 */
static void I2C_init_set_CCR(I2C_interface_t const interface
	, I2C_config_t const * const config
) {
	uint32_t const minimum_CCR_value = (config->SCL_freq <= 100000) ? 4 : 1;
	uint32_t CCR = 0;

	if (config->SCL_freq <= 100000) { //Standard-mode
		CCR = APB1_bus_clock / (2 * config->SCL_freq);
		CCR = (CCR < minimum_CCR_value) ? minimum_CCR_value : CCR; //Minimum value for CCR in SM is 4
	} else {
		if (config->SCL_duty_cycle == kI2C_FM_duty_2) {
			CCR = APB1_bus_clock / (3 * config->SCL_freq);
		} else {
			CCR |= (0x1UL << 14); //Set the CCR DUTY bit to '1', duty cycle of 16/9
			CCR = APB1_bus_clock / (25 * config->SCL_freq);
		}
		CCR |= (0x1UL << 15); //Set the FM mode bit to '1' (configure CCR to FM mode)

		CCR = (CCR < minimum_CCR_value) ? minimum_CCR_value : CCR;
	}

	I2C_CCR(interface) |= (CCR & 0xFFFUL);
}

/*! Configures the TRISE with the appropriate value to generate the maximum SCL rise time.
 *
 * @note  TRISE is quite literally the maximum SCL rise time (as defined in the NXP specification) as a function of
 *        the CR2 register's FREQ[5:0] (which is the APB1 clock in MHz).
 *
 *        In SM mode, the max rise time is 1000 ns which correlates to an equivalent 1 MHz clock (we deal with
 *        frequency as opposed to time b/c TRISE is a function of FREQ[5:0] which is really just the APB1 bus
 *        frequency in MHz). Thus we want an equivalent value of 1 MHz in TRISE and we have the APB1 bus clock in
 *        MHz so we just divide the APB1 bus clock the aforementioned 1 MHz. For instance if we have an APB1 of 8
 *        MHz, we take the 8,000,000 Hz and divide it by 1,000,000 Hz to get 8. Thus the 1 MHz TRISE equivalent is 
 *        correct.
 *
 *        In FM mode, we can apply the same principle with a max rise time of 300 ns which correlates to an
 *        equivalent clock of 3.33 MHz. Now taking the APB1 bus frequency and dividing it by 3.33 MHz to get TRISE
 *        as a function of the equivalent 3.33 MHz clock is a pain in the ass b/c we are dividing by a float.
 *        Instead we can take the result from the SM mode and scale to the 300 ns (3.33 MHz) target. To scale from
 *        1000 ns to 300 ns, we just take the 1000 ns * 300 then divide by 1000. Thus the new equation looks like:
 *        TRISE_FM = (SM result * 300) / 1000; and the SM result is APB1 clock / FREQ[5:0] leading us with:
 *        TRISE_FM = ((APB1 / FREQ[5:0]) * 300) / 1000) where freq[5:0]
 *
 *        Finally we add 1 to both equations as per the reference manual.
 *
 * @param interface
 *    (input) The I2C interface being initialized.
 * @param config
 *    (input) The configuration parameters for the I2C interface.
 */
static void I2C_init_set_TRISE(I2C_interface_t const interface
	, I2C_config_t const * const config
) {
	uint32_t TRISE = I2C_TRISE(interface);
	TRISE &= ~(0x3FUL); //Clear TRISE for now

	if (config->SCL_freq <= 100000) {
		TRISE = (APB1_bus_clock / 1000000) + 1;
	} else {
		TRISE = (((APB1_bus_clock / 1000000) * 300) / 1000) + 1;
	}
	I2C_TRISE(interface) = TRISE; //Write the new TRISE value
}

/* ============================================================================================================= */
/* Transfer Helper Functions                                                                                     */
/* ============================================================================================================= */
/*! Performs a one byte read of a register.
 *
 * @brief This function is called right after the address of the I2C slave's register is sent. As per the reference
 *        manual pg. 769, the ACK bit must be cleared BEFORE the ADDR bit is cleared. This ensures that the master
 *        receiver will generate the NACK at the right time.
 *        From there it's just a matter of waiting until RxNE is set signifying that data from the slave is in the
 *        DR register and is ready to be read.
 *
 * @param interface
 *    (input) Which I2C interface to receive the data from.
 * @param rx_buffer
 *    (input) Buffer to hold the data being received.
 */
static void I2C_master_receive_1_byte_blocking(I2C_interface_t const interface
	, void * rx_buffer
) {
	uint32_t __attribute__((unused)) ADDR_bit_clear = 0;

	while (!(I2C_SR1(interface) & 0x2UL)); //Wait for ADDR to be set (when the slave ACKs the register address)
	I2C_CR1(interface) &= ~(0x1UL << 10);  //Clear the ACK bit
	ADDR_bit_clear = I2C_SR1(interface);   //This and the subsequent SR1 read clears the ADDR bit
	ADDR_bit_clear = I2C_SR2(interface);

	while (!(I2C_SR1(interface) & (0x1UL << 6))); //Wait for data to be available to read (RxNE = 1)
	*((uint8_t *)rx_buffer) = I2C_DR(interface);  //Read the data

	I2C_CR1(interface) |= (0x1UL << 9); //Send STOP condition
}

/*! Performs a two byte auto-increment read of a register.
 *
 * @brief This function is called right after the address of the I2C slave's register is sent. As per the reference
 *        manual pg. 770:
 *        - Wait until ADDR = 1 (SCL stretched low until the ADDR flag is cleared)
 *        - Set ACK low, set POS high
 *        - Clear ADDR flag
 *        - Wait until BTF = 1 (Data 1 in DR, Data2 in shift register, SCL stretched low until a data is read)
 *        - Set STOP high
 *        - Read data 1 and 2
 *
 * @param interface
 *    (input) Which I2C interface to receive the data from.
 * @param rx_buffer
 *    (input) Buffer to hold the data being received.
 */
static void I2C_master_receive_2_bytes_blocking(I2C_interface_t const interface
	, void * rx_buffer
) {
	uint32_t __attribute__((unused)) ADDR_bit_clear = 0;

	while (!(I2C_SR1(interface) & 0x2UL)); //Wait for ADDR to be set (when the slave ACKs the register address)
	I2C_CR1(interface) &= ~(0x1UL << 10);  //Clear the ACK bit
	I2C_CR1(interface) |= (0x1UL << 11);   //Set the POS bit
	ADDR_bit_clear = I2C_SR1(interface);   //This and the subsequent SR1 read clears the ADDR bit
	ADDR_bit_clear = I2C_SR2(interface);

	while (!(I2C_SR1(interface) & 0x4UL)); //Wait until BTF=1 (data0 will be in DR and data1 will be in shift reg)
	I2C_CR1(interface) |= (0x1UL << 9);    //Set STOP high

	/* Read the data */
	((uint8_t *)rx_buffer)[0] = I2C_DR(interface);
	((uint8_t *)rx_buffer)[1] = I2C_DR(interface);
}

/*! Performs an n-byte auto-increment read of a register.
 *
 * @brief This function is called right after the address of the I2C slave's register is sent. As per the reference
 *        manual pg. 771:
 *        - Wait until BTF = 1 (data N-2 in DR, data N-1 in shift register, SCL stretched low until data N-2 is
 *          read)
 *        - Set ACK low
 *        - Read data N-2
 *        - Wait until BTF = 1 (data N-1 in DR, data N in shift register, SCL stretched low until data N-1 is read)
 *        - Set STOP high
 *        - Read data N-1 and N
 *
 * @param interface
 *    (input) Which I2C interface to receive the data from.
 * @param rx_buffer
 *    (input) Buffer to hold the data being received.
 * @param rx_size
 *    (input) The number of bytes to read.
 */
static void I2C_master_receive_n_bytes_blocking(I2C_interface_t const interface
	, void * rx_buffer
	, uint32_t const rx_size
) {
	uint32_t rx_idx = 0;
	uint32_t __attribute__((unused)) ADDR_bit_clear = 0;

	while (!(I2C_SR1(interface) & 0x2UL)); //Wait for ADDR to be set (when the slave ACKs the register address)
	ADDR_bit_clear = I2C_SR1(interface);   //Clear the ADDR bit step 1
	ADDR_bit_clear = I2C_SR2(interface);   //Clear the ADDR bit step 2

	/* Perform all the reads until there are 3 reads left: data N-2, data N-1, and data N */
	for (; rx_idx < (rx_size - 3); rx_idx++) {
		while (!(I2C_SR1(interface) & 0x4UL)); //Wait for BTF (data0 in DR, data1 in shift reg)
		((uint8_t *)rx_buffer)[rx_idx] = I2C_DR(interface); //read the data
	}

	while (!(I2C_SR1(interface) & 0x4UL)); //Wait for BTF (data N-2 is in DR here)

	/* Data N-2 in DR and data N-1 should in the shift register now, so we can clear ACK */
	I2C_CR1(interface) &= ~(0x1UL << 10);

	/* Read data N-2, which moves Data N-1 into the DR and clears the shift register */
	((uint8_t *)rx_buffer)[rx_idx++] = I2C_DR(interface);

	/* Wait for BTF, at which point data N-1 is in the DR and data N should in the shift register */
	while (!(I2C_SR1(interface) & 0x4UL));

	I2C_CR1(interface) |= (0x1UL << 9); //Send the STOP condition

	((uint8_t *)rx_buffer)[rx_idx++] = I2C_DR(interface); //Read data N-1
	((uint8_t *)rx_buffer)[rx_idx]   = I2C_DR(interface); //Read data N
}

/* ============================================================================================================= */
/* Driver Capability/Configuration Functions                                                                     */
/* ============================================================================================================= */
/*! Gets the capabilities of the I2C driver.
 */
I2C_driver_capabilities_t I2C_get_capabilities(void)
{
	I2C_driver_capabilities_t capabilities = {
		  .addressing_10_bit = 0
		, .reserved          = 0
	};
	return capabilities;
}

/*! Provides a default configuration for an I2C interface.
 */
void I2C_get_default_config(I2C_config_t * const config)
{
	if (config != NULL) {
		config->SCL_freq = 100000;
		config->SCL_duty_cycle = kI2C_SM_no_duty;
		config->pinout = kI2C_pinout_1;
	} else {
		//Do nothing, pointer is NULL
	}
}

/*! Initializes and configures the I2C interface.
 */
I2C_status_t I2C_init(I2C_interface_t const interface
	, I2C_config_t const * const config
) {
	I2C_status_t status = kI2C_status_generic_error;

	if (I2C_init_config_valid(interface, config)) {
		I2C_init_config_GPIO_pins(interface, config);
		RCC_APB1ENR |= (0x1UL << (21 + interface)); //Enable clock to I2C interface
		I2C_CR1(interface) &= ~(0x1UL << 0);        //Disable the selected I2C interface

		I2C_init_set_FREQ(interface);
		I2C_init_set_CCR(interface, config);
		I2C_init_set_TRISE(interface, config);
		I2C_CR1(interface) |= (0x1UL << 0); //Re-enable the selected I2C interface
	} else {
		status = kI2C_status_invalid_config;
	}

	return status;
}

/* ============================================================================================================= */
/* Transfer Functions                                                                                            */
/* ============================================================================================================= */
/*! Performs a polling send transfer on the I2C bus.
 *
 * @brief After the slave's address has been sent (and the ADDR bit has been set verifying the slave ACKed the
 *        address and subsequently cleared) it is okay to send DATA via the DR register. The first data to send is
 *        the address of the register of the slave that is to be written to. After that write is when the true data
 *        gets sent and the process goes like (as per the reference manual pg. 767):
 *
 *        Wait for TxE to be set (set when DR register is empty as a result of the slave ACKing the previous data
 *        that was sent)
 *        Wait for BTF to be set (set when TxE is set and no new write to DR has occurred)
 *        Once both TxE and BTF are set we are good to write to the DR register (which will clear both Txe and BTF)
 *        Repeat
 */
void I2C_master_send_blocking(I2C_interface_t const interface
	, uint8_t slave_addr
	, uint8_t const slave_reg_addr
	, void * tx_buffer
	, uint32_t const tx_size
) {
	uint32_t __attribute__((unused)) ADDR_bit_clear = 0;

	slave_addr = (slave_addr << 1) & ~0x1UL; //Place write bit into the address[0]

	while (I2C_SR2(interface) & 0x2UL);    //Wait for the bus to not be busy (BUSY bit)
	I2C_CR1(interface) |= (0x1UL << 8);    //Send START condition
	while (!(I2C_SR1(interface) & 0x1UL)); //Wait to verify START (SB bit) was sent
	I2C_DR(interface) = slave_addr;        //Send address (this DR write + previous SR1 read clears SB)
	while (!(I2C_SR1(interface) & 0x2UL)); //Wait to verify ADDR was set (ADDR bit)
	ADDR_bit_clear = I2C_SR1(interface);   //This and the subsequent SR1 read clears the ADDR bit
	ADDR_bit_clear = I2C_SR2(interface);
	I2C_DR(interface) = slave_reg_addr;    //Send the slave's register's address

	for (uint32_t idx = 0; idx < tx_size; idx++) {
		while (!(I2C_SR1(interface) & 0x80UL)); //Wait for TxE (i.e. DR to be empty)
		while (!(I2C_SR1(interface) & 0x4UL));  //Wait for BTF (i.e. a new byte should be sent and DR is empty)
		I2C_DR(interface) = ((uint8_t *)tx_buffer)[idx];
	}

	I2C_CR1(interface) |= (0x1UL << 9); //Send the STOP condition
}

/*! Performs a polling receive transfer on the I2C bus.
 *
 */
void I2C_master_receive_blocking(I2C_interface_t const interface
	, uint8_t slave_addr
	, uint8_t const slave_reg_addr
	, void * rx_buffer
	, uint32_t const rx_size
) {
	uint32_t __attribute__((unused)) ADDR_bit_clear = 0;

	slave_addr = (slave_addr << 1) & ~0x1UL; //Place the write bit into the address

	I2C_CR1(interface) |= (0x1UL << 10);   //Ensure the ACK bit is set
	while (I2C_SR2(interface) & 0x2UL);    //Wait for the bus to not be busy (BUSY bit)
	I2C_CR1(interface) |= (0x1UL << 8);    //Send START condition
	while (!(I2C_SR1(interface) & 0x1UL)); //Wait to verify START (SB bit) was sent
	I2C_DR(interface) = slave_addr;        //Send address (this DR write + previous SR1 read clears SB)
	while (!(I2C_SR1(interface) & 0x2UL)); //Wait to verify ADDR was set (ADDR bit)
	ADDR_bit_clear = I2C_SR1(interface);   //This and the subsequent SR1 read clears the ADDR bit
	ADDR_bit_clear = I2C_SR2(interface);
	I2C_DR(interface) = slave_reg_addr;    //Send the slave's register's address
	I2C_CR1(interface) |= (0x1UL << 8);    //Send the repeat START condition
	while (!(I2C_SR1(interface) & 0x1UL)); //Wait to verify START (SB bit) was sent
	slave_addr |= 0x1UL;                   //Change R/W bit to a read
	I2C_DR(interface) = slave_addr;        //Send address (this DR write + previous SR1 read clears SB)

	/* The rest of the receiving sequence is different depending on the number of bytes being received */
	if (rx_size == 1) {
		I2C_master_receive_1_byte_blocking(interface, rx_buffer);
	} else if (rx_size == 2) {
		I2C_master_receive_2_bytes_blocking(interface, rx_buffer);
	} else {
		I2C_master_receive_n_bytes_blocking(interface, rx_buffer, rx_size);
	}
}

/* EOF */
