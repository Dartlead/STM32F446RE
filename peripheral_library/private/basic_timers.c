#include "basic_timers.h"
#include "registers_stm32f446re.h"
#include "system_stm32f446re.h"
#include "_NVIC.h"
#include "_GCC_ARM_ASM_intrinsics.h"
#include <stdlib.h>

/* ============================================================================================================= */
/* Interrupt Service Routines                                                                                    */
/* ============================================================================================================= */
/*! Basic Timer Module, Timer 6 ISR.
 */
#include "_shared_ISR_TIM6_DAC.h"

/*! Basic Timer Module, Timer 7 ISR.
 */
static void (* TIM7_user_handler)(void) = NULL;
__attribute__((interrupt("TIM7_handler"))) void TIM7_handler()
{
	if (TIM7_user_handler != NULL) {
		TIM7_user_handler();
	} else {
		while (1);
	}
}

/* ============================================================================================================= */
/* Helper Functions                                                                                              */
/* ============================================================================================================= */
/*! Checks if the configuration parameters for a basic timer module are valid.
 *
 * @brief Checks if:
 *        - The desired timer module is either BTIM_module_TIM6 or BTIM_module_TIM7
 *        - The prescalar value is not 0
 *        - The auto-reload value is between 1 and 65535
 *        - If interrupt functionality is desired, the IRQ handler is not NULL
 *        - If interrupt functionality is desired, the IRQ priority is between 0 and 15
 * @note  The nested if-statements are for the check on "if this is set, then this condition must be met".
 *
 * @param cnfg
 *    (input) The configuration options for a basic timer module.
 * @return 'true' if the configuration parameters are valid, 'false' otherwise.
 */
static bool _BTIM_params_are_valid(BTIM_module const timer
	, BTIM_cnfg const cnfg)
{
	bool params_are_valid = false;

	if (  ((timer == BTIM_module_TIM6) || (timer == BTIM_module_TIM7))
		&& (cnfg.timer_freq >= 0)
		&& (cnfg.auto_reload_val >= 1 && cnfg.auto_reload_val <= 65535)
	) {
		params_are_valid = true;

		/* If this-then that config checks */
		if (cnfg.IRQ_en && (cnfg.IRQ_handler == NULL)) { params_are_valid = false; }
		if (cnfg.IRQ_en && (cnfg.IRQ_priority > 15))   { params_are_valid = false; }
	} else {
		//Boolean is already false, do nothing
	}

	return params_are_valid;
}

/*! Computes the address of a timer's CR1, CR2, DIER, SR, EGR, CNT, PSC, and ARR registers.
 *
 * @brief Each basic timer module has its own set of registers that are 0x400 apart from each other (the base
 *        address of the TIM6 register set is 0x4000_1000 and TIM7 is 0x4000_1400). To compute the address of any
 *        of the registers in the set depending on the desired timer we simply take the address of the desired
 *        register for TIM6 and offset it by either 0x0 (for a TIM6 register) or 0x400 (for a TIM7) register. To
 *        determine whether the offset should be 0x0 or 0x400, I take the desired timer module's enumeration
 *        value (6 for TIM6, 7 for TIM7) and subtract it by 6 to get 0x400 * 0 = 0x0 for a TIM6 register and
 *        0x400 * 1 = 0x400 for a TIM7 register.
 *
 *        For instance, if we wanted the address of TIM7's DIER register, we start with the address of the DIER
 *        register for TIM6 which is 0x4000_100C. Now b/c we want TIM7's register we take TIM7's enum value of 7
 *        and subtract 6 to get 1 which is then multipled by 0x400 to get the TIM7's DIER register offset from
 *        TIM6's DIER register. We add TIM6's DIER address to the offset to get the desired register address.
 *
 * @param timer
 *    (input) The basic timer module whose register address is desired.
 * @return The address of the module's desired register.
 */
__attribute__((always_inline)) static inline uint32_t * _BTIM_compute_CR1_addr(BTIM_module const timer)
	{ return (uint32_t *)((uint8_t *)(&(TIM6_CR1)) + (uint32_t)(0x400 * (timer - 6))); }
__attribute__((always_inline)) static inline uint32_t * _BTIM_compute_ARR_addr(BTIM_module const timer)
	{ return (uint32_t *)((uint8_t *)(&(TIM6_ARR)) + (uint32_t)(0x400 * (timer - 6))); }
__attribute__((always_inline)) static inline uint32_t * _BTIM_compute_DIER_addr(BTIM_module const timer)
	{ return (uint32_t *)((uint8_t *)(&(TIM6_DIER)) + (uint32_t)(0x400 * (timer - 6))); }
__attribute__((always_inline)) static inline uint32_t * _BTIM_compute_PSC_addr(BTIM_module const timer)
	{ return (uint32_t *)((uint8_t *)(&(TIM6_PSC)) + (uint32_t)(0x400 * (timer - 6))); }
__attribute__((always_inline)) static inline uint32_t * _BTIM_compute_EGR_addr(BTIM_module const timer)
	{ return (uint32_t *)((uint8_t *)(&(TIM6_EGR)) + (uint32_t)(0x400 * (timer - 6))); }

/*! Converts the desired timer frequency in hertz to a value appropriate for the PSC register.
 *
 * @brief The value for the PSC register is given by the equation (taken from the reference manual):
 *        counter_clk_freq = freq_CK_PSC / (PSC[15:0] + 1)
 *        or
 *        PSC[15:0] = (freq_CK_PSC / counter_clk_freq) - 1   *re-arranged, solving for PSC[15:0]
 *        where counter clock frequency is the desired frequency of the timer in hertz
 *              freq_CK_PSC is the frequency of the APB1 bus
 *              PSC[15:0] is the value of the PSC register
 *
 * @param freq
 *    (input) The desired frequency of the timer.
 * @return The desired frequency converted to a PSC register-ready value.
 */
static uint16_t _BTIM_convert_freq_to_PSC(uint32_t const freq)
{
	uint32_t APB1_freq = APB1_bus_clock;
	return (uint16_t)((APB1_freq / freq) - 1);
}

/* ============================================================================================================= */
/* Timer Initialization Sub-Functions                                                                            */
/* ============================================================================================================= */
/*! Sets the auto reload value for the timer.
 *
 * @brief Setting the auto reload value is done by simply writing the configuration struct's auto_reload_value into
 *        the ARR register. But because the ARR register is 16 bits read-write, we have to AND by 0xFFFF to ensure
 *        we are getting just the lower 16 bits.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules being initialized.
 * @param cnfg
 *    (input) The configuration for the basic timer module.
 */
static void _BTIM_init_timer_set_auto_reload_val(BTIM_module const timer
	, BTIM_cnfg const cnfg
) {
	uint32_t volatile * const TIMx_ARR_addr  = _BTIM_compute_ARR_addr(timer);
	*TIMx_ARR_addr = cnfg.auto_reload_val & 0xFFFF;
}

/*! Sets the timer's prescaler from the desired frequency for the timer's clock.
 *
 * @brief Converts the desired timer frequency to the appropriate prescaler value (with help from the
 *        _BTIM_convert_freq_to_PSC() helper function) and then writes the prescaler value into the PSC register.
 *
 * @param see _BTIM_init_timer_set_auto_reload_val(). The parameters are the same.
 */
static void _BTIM_init_timer_set_prescaler(BTIM_module const timer
	, BTIM_cnfg const cnfg
) {
	uint32_t volatile * const TIMx_PSC_addr  = _BTIM_compute_PSC_addr(timer);
	//*TIMx_PSC_addr = _BTIM_convert_freq_to_PSC(cnfg.timer_freq);
	*TIMx_PSC_addr |= (cnfg.timer_freq + 1) & (0xFFFFU);
}

/*! Updates the first configuration option with the timer's configuration options.
 *
 * @brief The timer's configuration options that are updated (where a '1' enables the feature and a '0' disables
 *        the feature) are the following:
 *        - the auto reload preload option (bit 7)
 *        - the one pulse mode option (bit 3)
 *        - the update request source option (bit 2)
 *        - the update event disable option (bit 1)
 * @note  An accumulated value for the CR1 register is used to gather all writes that would have been made to the
 *        register before writing them all at once.
 *
 * @param see _BTIM_init_timer_set_auto_reload_val(). The parameters are the same.
 */
static void _BTIM_init_timer_set_counter_config(BTIM_module const timer
	, BTIM_cnfg const cnfg
) {
	uint32_t volatile * const TIMx_CR1_addr = _BTIM_compute_CR1_addr(timer);
	uint32_t accum_CR1_val = *TIMx_CR1_addr; //Holds accumulated CR writes, initialized to current CR1 value

	//Set the auto reload preload, one pulse mode, update request source, and update event disable options
	accum_CR1_val = (cnfg.auto_reload_preload_en) ? (accum_CR1_val | (0x1 << 7)) : (accum_CR1_val & ~(0x1 << 7));
	accum_CR1_val = (cnfg.one_pulse_mode_en) ? (accum_CR1_val | (0x1 << 3)) : (accum_CR1_val & ~(0x1 << 3));
	accum_CR1_val = (cnfg.update_request_src_en) ? (accum_CR1_val | (0x1 << 2)) : (accum_CR1_val & ~(0x1 << 2));
	accum_CR1_val = (cnfg.update_event_dis) ? (accum_CR1_val | (0x1 << 1)) : (accum_CR1_val & ~(0x1 << 1));

	//Write the accumulated changes to the register
	*TIMx_CR1_addr = accum_CR1_val;
}

/*! Configures the timer's DMA and interrupt generation capabilities.
 *
 * @brief The DMA generation capability of the timer is controlled by bit 8 of the DIER register (where a '1'
 *        enables the timer to generate a DMA request and a '0' disables). The interrupt generation is controlled
 *        by bit 0 of the DIER register (where a '1' enables the timer to generate a interrupt request and a '0'
 *        disables). Once the DMA/interrupt capabilities have been set in the DIER register, the NVIC needs to have
 *        the timer registered in order for the CPU to service the interrupt signal. First we have to globally
 *        disable interrupts, then set the priority of the TIM6 or TIM7 NVIC channel, then enable either the TIM6
 *        or TIM7 channel in the NVIC, then register the user provided ISR with the static global of this file, and
 *        finally globally re-enable interrupts.
 * @note  An accumulated value for the DIER register is used to gather all writes that would have been made to the
 *        register before writing them all at once.
 *
 * @param see _BTIM_init_timer_set_auto_reload_val(). The parameters are the same.
 */
static void _BTIM_init_timer_configure_IRQ_DMA(BTIM_module const timer
	, BTIM_cnfg const cnfg
) {
	uint32_t volatile * const TIMx_DIER_addr = _BTIM_compute_DIER_addr(timer);
	uint32_t accum_DIER_val = *TIMx_DIER_addr; //Holds accumulated DIER writes, initialized to current DIER value

	//Set the DMA request capability
	accum_DIER_val = (cnfg.DMA_request_en) ? (accum_DIER_val | (0x1 << 8)) : (accum_DIER_val & ~(0x1 << 8));

	//Set the IRQ capability
	if (cnfg.IRQ_en) {
		accum_DIER_val |= 0x1; //Enable IRQ generation

		/* Register the timer's NVIC channel with the NVIC and register the user-provided ISR */
		_disable_global_irq();
		if (timer == BTIM_module_TIM6) {
			_NVIC_channel_set_priority(NVIC_TIM6_DAC_IRQn, cnfg.IRQ_priority);
			_NVIC_channel_enable(NVIC_TIM6_DAC_IRQn);
			TIM6_DAC_user_handler = cnfg.IRQ_handler;
		} else {
			_NVIC_channel_set_priority(NVIC_TIM7_IRQn, cnfg.IRQ_priority);
			_NVIC_channel_enable(NVIC_TIM7_IRQn);
			TIM7_user_handler = cnfg.IRQ_handler;
		}
		_enable_global_irq();
	} else {
		accum_DIER_val &= ~0x1; //Disable IRQ generation
	}

	//Write the accumulated changes to the register
	*TIMx_DIER_addr = accum_DIER_val;
}

/* ============================================================================================================= */
/* Configuration/Initialization Functions                                                                        */
/* ============================================================================================================= */
/*! Initializes one of the two onboard basic timer modules with the desired configuration.
 *
 * @brief Read the comments on each sub function to determine its purpose in the configuration of the timer module.
 * @note  The write of '1' in bit position 0 into the EGR register is needed to forcibly update all of the actual
 *        registers - without this update the timer does not work.
 */
void BTIM_init_timer(BTIM_module const timer
	, BTIM_cnfg const cnfg
) {
	uint32_t volatile * const TIMx_EGR_addr  = _BTIM_compute_EGR_addr(timer);

	if (_BTIM_params_are_valid(timer, cnfg)) {
		RCC_APB1ENR |= 0x1 << (timer - 2); //Enable the clock to timer module 6 or 7

		_BTIM_init_timer_set_auto_reload_val(timer, cnfg);
		_BTIM_init_timer_set_prescaler(timer, cnfg);
		_BTIM_init_timer_set_counter_config(timer, cnfg);
		_BTIM_init_timer_configure_IRQ_DMA(timer, cnfg);

		*TIMx_EGR_addr = 0x1; //Force register updates
	} else {
		//Invalid configuration parameters, do nothing
	}
}

/*! Updates the frequency of the clock driving the specified basic timer module.
 *
 * @brief 'On-the-fly' updating of the driving frequency (i.e. the prescaler frequency) is done by simply writing
 *        to the prescaler register. Because the PSC register is buffered, it will not take effect until the next
 *        update event.
 */
void BTIM_update_timer_freq(BTIM_module const timer
	, uint32_t const timer_freq
) {
	uint32_t volatile * const TIMx_PSC_addr = _BTIM_compute_PSC_addr(timer);

	*TIMx_PSC_addr = _BTIM_convert_freq_to_PSC(timer_freq);
}

/* ============================================================================================================= */
/* Start/Stop/Read Functions                                                                                     */
/* ============================================================================================================= */
/*! Starts one of the two onboard basic timer modules.
 *
 * @brief To start a timer, we simply set the count enable (bit 0) in that timer module's CR1 register.
 */
void BTIM_start_timer(BTIM_module const timer)
{
	if (timer == BTIM_module_TIM6) {
		TIM6_CR1 |= 0x1;
	} else {
		TIM7_CR1 |= 0x1;
	}
}

/*! Stops one of the two onboard basic timer modules.
 *
 * @brief To stop a timer, we simply clear the count enable (bit 0) in that timer module's CR1 register.
 */
void BTIM_stop_timer(BTIM_module const timer)
{
	if (timer == BTIM_module_TIM6) {
		TIM6_CR1 &= ~0x1;
	} else {
		TIM7_CR1 &= ~0x1;
	}
}

/*! Reads the current value of one of the two onboard basic timers.
 *
 * @brief To read the current value of a timer, we just read that timer's CNT register.
 */
uint32_t BTIM_read_timer(BTIM_module const timer)
{
	uint32_t cur_timer_val = 0;

	if (timer == BTIM_module_TIM6) {
		cur_timer_val = TIM6_CNT;
	} else {
		cur_timer_val = TIM7_CNT;
	}

	return cur_timer_val;
}

/* ============================================================================================================= */
/* Interupt/DMA Functionality                                                                                    */
/* ============================================================================================================= */
/*! Clears an update event (i.e. IRQ) of one of the two onboard basic timers.
 *
 * @brief To clear an update event, we just set the Update Interrupt Flag (UIF) bit to zero.
 */
void BTIM_clear_update_event(BTIM_module const timer)
{
	if (timer == BTIM_module_TIM6) {
		TIM6_SR = 0x0;
	} else {
		TIM7_SR = 0x0;
	}
}

/*! Provides the address of the count register of one of the two onboard basic timers.
 *
 * @brief Provides the address of either TIM6_CNT or TIM7_CNT using the TIM6 base address macro and count offset
 *        macro to avoid discarding the volatile qualifier if the normal 'TIM6_CNT' or 'TIM7_CNT' macro was used
 *        instead.
 */
uint32_t * BTIM_count_reg_addr(BTIM_module const timer)
{
	uint32_t * count_addr = NULL;

	if (timer == BTIM_module_TIM6) {
		count_addr = (uint32_t *)((uint8_t *)TIM6_B_ADDR + BTIM_CNT_OFFSET);
	} else {
		count_addr = (uint32_t *)((uint8_t *)TIM7_B_ADDR + BTIM_CNT_OFFSET);
	}

	return count_addr;
}

/* EOF */
