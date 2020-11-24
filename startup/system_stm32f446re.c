#include "system_stm32f446re.h"
#include "registers_stm32f446re.h"
#include <stdbool.h>

/*! A system clock source MUST be chosen at compile time.
 */
#ifndef __SYS_CORE_CLK_SRC
#	error Source for system core clock must be defined via the '__SYS_CORE_CLK_SRC' preprocessor define
#endif

/*! All other configs can be left at default if none are specified (although errors may still arise from the
 *  default configurations).
 */
#ifndef __PLLP_FACTOR
#	define __PLLP_FACTOR    2
#endif
#ifndef __PLLR_FACTOR
#	define __PLLR_FACTOR    2
#endif
#ifndef __AHB_PRESCALER
#	define __AHB_PRESCALER  1
#endif
#ifndef __APB1_PRESCALER
#	define __APB1_PRESCALER 1
#endif
#ifndef __APB2_PRESCALER
#	define __APB2_PRESCALER 1
#endif

/*! Device's various clocks.
 */
uint32_t sys_clock     = 0;
uint32_t AHB_bus_clock  = 0;
uint32_t APB1_bus_clock = 0;
uint32_t APB2_bus_clock = 0;

/*! Potential sources for the system core clock.
 */
typedef enum _sys_clk_src {
	  sys_clk_src_HSI       //!# High-speed internal oscillator (HSI), 16 MHz
	, sys_clk_src_HSE       //!# High-speed external oscillator (HSE), 8 MHz
	, sys_clk_src_HSE_BYP   //!# HSE bypassed with an external user-provided clock
	, sys_clk_src_PLL_HSE_P //!# Main PLL P (a.k.a CLK) output, where the PLL is clocked by the HSE
	, sys_clk_src_PLL_HSE_R //!# Main PLL R output, where the PLL is clocked by the HSE
	, sys_clk_src_PLL_HSI_P //!# Main PLL P (a.k.a CLK) output, where the PLL is clocked by the HSI
	, sys_clk_src_PLL_HSI_R //!# Main PLL R output, where the PLL is clocked by the HSI
} sys_clk_src;

/*! A timeout that dictates the length of the wait for things like how long the system waits for the PLL to lock,
 *  overdrive mode to be ready, system clock source to be accepeted, etc.
 */
static uint32_t const clocking_timeout = 0x5000UL;

/* ============================================================================================================= */
/* System Clock Helper Functions                                                                                 */
/* ============================================================================================================= */
/*! Waits for the system to accept the desired system clock source.
 *
 * @param clk_src
 *    (input) The desired clock source that the system should accept.
 * @param timeout
 *    (input) The timeout limit for waiting for the system to accept the new clock source.
 * @param status
 *    (input/output) The status of the system trying to accept a new system clock source.
 */
static void wait_for_system_to_accept_src(sys_clk_src const clk_src
	, system_init_status * const status
) {
	uint32_t timeout_count = 0;
	uint32_t cfgr_sws_val  = 0;

	switch (clk_src) //!# Create the mask for the sys clk src
	{
		case sys_clk_src_HSI:
			cfgr_sws_val = 0x0UL;
			break;
		case sys_clk_src_HSE:
			cfgr_sws_val = 0x4UL;
			break;
		case sys_clk_src_PLL_HSE_P:
		case sys_clk_src_PLL_HSI_P:
			cfgr_sws_val = 0x8UL;
			break;
		case sys_clk_src_PLL_HSE_R:
		case sys_clk_src_PLL_HSI_R:
			cfgr_sws_val = 0xCUL;
			break;
		default:
			break;
	}

	while ((RCC_CFGR & 0xCUL) != cfgr_sws_val) { //!# Wait for the system to accept the new sys clk src
		if (timeout_count >= clocking_timeout) {
			status->sys_clk_accept = 1; //!# System failed to accept source
			break;
		} else {
			++timeout_count;
		}
	}
}

/*! Configures the main PLL's VCO input/output frequencies and the source that clocks it.
 *
 * @brief The system's main PLL must be clocked by either the HSE or HSI. The PLL will take that input signal and
 *        divide it by the PLLM factor to get the PLL's internal voltage-controlled oscillator's (VCO) input
 *        frequency. The VCO input frequency is then multiplied by the PLLN factor to get the VCO's output
 *        frequency.
 *
 *        The VCO input frequency should always be 2 MHz (to limit PLL jitter) and thus the PLLM division factor
 *        should always be 4 when the HSE is clock the PLL and 8 when the HSI is clocking the PLL (8 MHz HSE PLL
 *        input clk signal / 4 = 2 MHz VCO input frequency, 16 MHz HSI PLL input clk signal / 8 = 2 MHz VCO input
 *        frequency).
 *
 *        The VCO output frequency must be between 100 and 432 MHz. But because the VCO output frequency is later
 *        divided by a PLLP or PLLR factor that can be as small as 2 and the result of that division is the system
 *        clock which is limited to 180 MHz, the PLLN multiplication factor should always be 180 (2 MHz VCO input
 *        frequency * 180 = 360 MHz VCO output frequency which, when divided by the smallest PLLP/PLLR factor of 2
 *        gets a 180 MHz system clock which is the max).
 *
 *        With the VCO output frequency at 360 MHz, it can be divided down by any PLLP or PLLR factor and still be
 *        within the limits for the system clock.
 *
 * @param clk_src
 *    (input) The desired clocking source for the main PLL.
 * @param status
 *    (input/output) The status of configuring the main PLL and VCO.
 */
static void configure_main_PLL_and_VCO(sys_clk_src const clk_src
	, system_init_status * const status
) {
	uint32_t timeout_count      = 0;
	uint32_t pllcfgr_accumulate = RCC_PLLCFGR;

	switch (clk_src)
	{
		case sys_clk_src_PLL_HSI_P:
		case sys_clk_src_PLL_HSI_R:
			pllcfgr_accumulate &= ~(0x1UL << 22); //!# Clock the main PLL with the HSI
			pllcfgr_accumulate |= 0x8UL;          //!# Set the PLLM to 8 to get the 2 MHz VCO input clock
			break;
		case sys_clk_src_PLL_HSE_P:
		case sys_clk_src_PLL_HSE_R:
			RCC_CR |= (0x1UL << 16); //!# Turn on the HSE
			while (!(RCC_CR & (0x1UL << 17)) && (timeout_count++ < clocking_timeout)); //!# wait for HSE to stabilize
			status->HSE_stabilize = (timeout_count >= clocking_timeout) ? 1 : 0;
			pllcfgr_accumulate |= (0x1UL << 22); //!# Clock the main PLL with the HSE
			pllcfgr_accumulate |= 0x4UL;         //!# Set the PLLM to 4 to get the 2 MHz VCO input clock
			break;
		default:
			status->sys_clk_src = 1; //!# Invalid system clock source
			break;
	}

	if (status->sys_clk_src == 0) {
		pllcfgr_accumulate |= 0xB4UL;     //!# Multiply VCO input clk by PLLN of 180 to get 360 MHz VCO output clk
		RCC_PLLCFGR = pllcfgr_accumulate; //!# Write the accumulated changes
	} else {
		//!# An invalid system clock source was provided, do nothing
	}
}

/*! Sets the main PLL's P and R output division factors.
 *
 * @note  If an invalid PLLP or PLLR factor is provided, the default of 2 for both is kept (the default is set by
 *        the reset value of the PLL_CFGR register).
 *
 * @param PLLP_factor
 *    (input) The desired PLLP division factor.
 * @param PLLR_factor
 *    (input) The desired PLLR division factor.
 * @param status
 *    (input/output) The status of setting the PLLP and PLLR factors.
 */
static void set_PLL_P_R_factors(uint32_t const PLLP_factor
	, uint32_t const PLLR_factor
	, system_init_status * const status
) {
	uint32_t PLLR = RCC_PLLCFGR; //!# Used to clear then write to the PLLR field without ever leaving it as 0b00
	PLLR &= ~(0x7UL << 28);      //!# Clear the PLLR field

	//!# Set the PLLP factor
	switch (PLLP_factor)
	{
		case 2:
			RCC_PLLCFGR &= ~(0x3UL << 16); //!# Clear PLL_CFGR[17:16] to set PLLP of 2
			break;
		case 4:
			RCC_PLLCFGR |= (0x1UL << 16);  //!# Set PLL_CFGR[17:16] to 0b01 to set PLLP of 4
			break;
		case 6:
			RCC_PLLCFGR |= (0x2UL << 16);  //!# Set PLL_CFGR[17:16] to 0b10 to set PLLP of 6
			break;
		case 8:
			RCC_PLLCFGR |= (0x3UL << 16);  //!# Set PLL_CFGR_[17:16] to 0b11 for set PLLP of 8
			break;
		default:
			status->PLLP_factor = 1; //!# Invalid PLLP factor;
			break;
	}

	//!# Set the PLLR factor
	if ((PLLR_factor >= 2) && (PLLR_factor <= 7)) {
		PLLR |= ((PLLR_factor & 0x7) << 28); //!# Set PLL_CFGR[30:28] to desired PLLR
		RCC_PLLCFGR = PLLR;                  //!# Write the PLLR change
	} else {
		status->PLLR_factor = 1; //!# Invalid PLLR factor
	}
}

/*! Changes the voltage regulator's power scale.
 *
 * @brief The voltage regulator supplies all the digital circuitries in the system except for the backup domain
 *        and the standby circuitry. Its voltage affects the max system clock (and thereby all the bus clocks) and
 *        is usually around 1.2V. Its voltage scan be increased by changing the power scale which in turn allows
 *        for higher system clock frequencies.
 *
 *        At power scale 3 (typical voltage output of 1.14V), max system clock is 120 MHz.
 *        At power scale 2 (typical voltage output of 1.26V), max system clock is 144 MHz with overdrive mode off
 *           and 168 MHz with overdrive mode on.
 *        At power scale 1 (typical voltage output of 1.32V), max system clock is 168 MHz with overdrive mode off
 *           and 180 MHz with overdrive mode on.
 *
 *        For this case, we do not deal with overdrive mode (unless a system clock of 180 MHz is desired) thus the
 *        power scale is set at 3 for anything <= 120 MHz, 2 for anything between 120 and 144 MHz, and 1 for
 *        anything greater than 144 MHz.
 *
 * @param potential_sys_clk_freq
 *    (input) The system clock frequency that would result from the set PLLP or PLLR factor.
 * @param status
 *    (input/output) The status of setting the voltage regulator's power scale.
 */
static void set_voltage_regulator_power_scale(uint32_t const potential_sys_clk_freq
	, system_init_status * const status
) {
	if (!(RCC_CR & (0x1UL << 24))) { //!# Only proceed to change anything if the PLL is off
		RCC_APB1ENR |= (0x1UL << 28); //!# Enable the clock to the power control logic

		if (potential_sys_clk_freq <= 120000000) {
			PWR_CR &= ~(0x1UL << 15); //!# Set PWR_CR[15:14] to 0b01 for a power scale of 3 (reset val = 0b11)
		} else if (potential_sys_clk_freq > 120000000 && potential_sys_clk_freq < 144000000) {
			PWR_CR &= ~(0x1UL << 14); //!# Set PWR_CR[15:14] to 0b10 for a power scale of 2 (reset val = 0b11)
		} else {
			//!# Do nothing as PWR_CR[15:14] defaults to 0b11 which is what we want for a power scale of 1
		}
	} else {
		status->voltage_scale = 1; //!# We can't change the power scale while the PLL is on
	}
}

/*! Configures the voltage regulator's over-drive mode.
 *
 * @brief The only time which over-drive mode is needed is when the voltage regulator's power scale is at 1 and the
 *        desired system clock frequency is greater than 168 MHz (and less than 180 MHz).
 *
 * @param potential_sys_clk_freq
 *    (input) The system clock frequency that would result from the set PLLP or PLLR factor.
 * @param status
 *    (input/output) The status of configuring the voltage regulator's over-drive mode.
 */
static void configure_overdrive_mode(uint32_t const potential_sys_clk_freq
	, system_init_status * const status
) {
	uint32_t timeout_count = 0;

	if ((potential_sys_clk_freq > 168000000) && (status->voltage_scale == 0)) {
		RCC_APB1ENR |= (0x1UL << 28); //!# Enable the clock to the power control
		PWR_CR      |= (0x1UL << 16); //!# Enable over-drive

		//!# Wait for over-drive mode to be ready
		while (!(PWR_CSR & (0x1UL << 16)) && (timeout_count++ < clocking_timeout));
		status->overdrive = (timeout_count >= clocking_timeout) ? 1 : 0;

		if (status->overdrive == 0) {
			timeout_count = 0;
			PWR_CR |= (0x1UL << 17); //!# Enable over-drive switching

			//!# Wait for over-drive switching to be ready
			while (!(PWR_CSR & (0x1UL << 17)) && (timeout_count++ < clocking_timeout));
			status->overdrive = (timeout_count >= clocking_timeout) ? 2 : 0;
		} else {
			//!# Do nothing as over-drive mode failed to ready up
		}
	} else {
		//!# Do nothing as either overdrive mode is not required or will not work b/c there was a voltage scale issue
	}
}

/*! Configures the embedded flash controller's latency and presence of instruction/data caches.
 *
 * @brief As the system clock speed increases, the number of wait states (i.e. the latency) must be correctly set
 *        in the embedded flash controller's access registers otherwise the core will be unable to read from said
 *        flash. The HCLK frequency ranges and the number of associated wait states is based off of the assumption
 *        that the board will be operating on a VDD between 2.7V and 3.6V which should be valid when the board is
 *        powered via USB.
 *
 * @param potential_sys_clk_freq
 *    (input) The system clock frequency that would result from the set PLLP or PLLR factor.
 * @param status
 *    (input/output) The status of previously finished voltage scale and over-drive mode operations.
 */
static void configure_flash_latency_and_cache(uint32_t const potential_sys_clk_freq
	, system_init_status * const status
) {
	if ((status->voltage_scale == 0) && (status->overdrive == 0)) {
		FLASH_ACR |= (0x1UL << 8) | (0x1UL << 9) | (0x1UL << 10); //!# Enable prefetching, i$, and d$ (respectively)

		if (potential_sys_clk_freq <= 30000000) {
			//!# Do nothing as 0 wait state is the default behavior
		} else if (potential_sys_clk_freq > 30000000 && potential_sys_clk_freq <= 60000000) {
			FLASH_ACR |= (0x1UL & 0xFUL);  //!# 1 wait state (2 CPU cycles)
		} else if (potential_sys_clk_freq > 60000000 && potential_sys_clk_freq <= 90000000) {
			FLASH_ACR |= (0x2UL & 0xFUL); //!# 2 wait states (3 CPU cycles)
		} else if (potential_sys_clk_freq > 90000000 && potential_sys_clk_freq <= 120000000) {
			FLASH_ACR |= (0x3UL & 0xFUL); //!# 3 wait states (4 CPU cycles)
		} else if (potential_sys_clk_freq > 120000000 && potential_sys_clk_freq <= 150000000) {
			FLASH_ACR |= (0x4UL & 0xFUL); //!# 4 wait states (5 CPU cycles)
		} else {
			FLASH_ACR |= (0x5UL & 0xFUL); //!# 5 wait states (6 CPU cycles)
		}
	} else {
		//!# Voltage scale/overdrive operations failed, thus default flash latency/cache states suffice
	}
}

/*! Sets the APB1 or APB2 prescaler.
 *
 * @param APB1
 *    (input) 'true' to set the clock for the APB1 bus, 'false' to set the clock for the APB2 bus.
 * @param prescaler
 *    (input) The division factor from the AHB bus clock to create the APB bus clock.
 */
static void set_APB_prescaler(bool const APB1
	, uint32_t const prescaler
) {
	uint32_t position_in_CFGR = (APB1) ? 10 : 13; //!# PPRE1 is CFGR[12:10], PPRE2 is CFGR[15:13]

	switch (prescaler)
	{
		case 1:
			break; //!# Reset value covers this case
		case 2:
			RCC_CFGR |= (0x4UL << position_in_CFGR); //!# 0b100: AHB clock divided by 2
			break;
		case 4:
			RCC_CFGR |= (0x5UL << position_in_CFGR); //!# 0b101: AHB clock divided by 4
			break;
		case 8:
			RCC_CFGR |= (0x6UL << position_in_CFGR); //!# 0b110: AHB clock divided by 8
			break;
		case 16:
			RCC_CFGR |= (0x7UL << position_in_CFGR); //!# 0b111: AHB clock divided by 16
			break;
		default:
			break;
	}
}

/* ============================================================================================================= */
/* Functions to Set System Clock to a Particular Source                                                          */
/* ============================================================================================================= */
/*! Sets the high-speed external oscillator (HSE) as the source for the system clock.
 *
 * @note  If a bypassed HSE was chosen, the reference to the system clock will not be updated and the main program
 *        will have to update the value accordingly.
 *
 * @param bypassed
 *    (input) 'true' if a bypassed HSE is to be used, 'false' if the HSE itself is to be used.
 * @return The status of setting the system clock to the HSE.
 */
static void set_sys_clk_HSE(bool const bypassed
	, system_init_status * const status
) {
	uint32_t timeout_count = 0;

	if (bypassed) {
		RCC_CR |= 0x50000UL;     //!# Enable HSE bypassing and turn on the HSE
	} else {
		RCC_CR |= (0x1UL << 16); //!# Turn on the HSE
	}

	while (!(RCC_CR & (0x1UL << 17)) && (timeout_count++ < clocking_timeout)); //!# wait for the HSE to stabilize
	status->HSE_stabilize = (timeout_count >= clocking_timeout) ? 1 : 0;

	if (status->HSE_stabilize == 0) {
		RCC_CFGR |= 0x1UL; //!# Set RCC_CFGR[1:0] to 0b01, SW value of HSE as system clock src
		wait_for_system_to_accept_src(sys_clk_src_HSE, status);

		//!# If system accepts HSE, sys clk is 8 MHz else the system defaults to HSI clk @ 16 MHz
		if (bypassed) {
			sys_clock = 0;
		} else {
			sys_clock = (status->sys_clk_accept == 0) ? 8000000 : 16000000;
		}
	} else {
		sys_clock = 160000000; //!# HSE failed to stabilize, so we default to 16 MHz HSI
	}
}

/*! Configures, initializes, and sets the main PLL's P or R output as the system clock source.
 *
 * @note  In the reference manual, the PLL_P output clock is also referenced as PLL_CLK.
 * @note  **FUTURE NICK*** The order in which things are done here is VERY important.
 *
 * @param clk_src
 *    (input) The desired clock source for the system clock.
 * @param PLLP_factor
 *    (input) The desired PLL_P division factor for the VCO output frequency.
 * @param PLLR_factor
 *    (input) The desired PLL_R division factor for the VCO output frequency.
 * @param status
 *    (input/output) The status of setting the system clock to the main PLL's P or R output.
 */
static void set_sys_clk_PLL(sys_clk_src const clk_src
	, uint32_t const PLLP_factor
	, uint32_t const PLLR_factor
	, system_init_status * const status
) {
	uint32_t potential_system_clock_frequency = 0;
	uint32_t timeout_count                    = 0;

	configure_main_PLL_and_VCO(clk_src, status);
	set_PLL_P_R_factors(PLLP_factor, PLLR_factor, status);

	//!# Determine what the system clock frequency is going to be based off of the PLL/R factors
	if (clk_src == sys_clk_src_PLL_HSE_P || clk_src == sys_clk_src_PLL_HSI_P) {
		potential_system_clock_frequency = (status->PLLP_factor) ? (360000000 / 2) : (360000000 / PLLP_factor);
	} else {
		potential_system_clock_frequency = (status->PLLR_factor) ? (360000000 / 2) : (360000000 / PLLR_factor);
	}

	set_voltage_regulator_power_scale(potential_system_clock_frequency, status);
	RCC_CR |= (0x1UL << 24); //!# Set RCC_CR[24], PLL_ON
	while (!(RCC_CR & (0x1UL << 25)) && (timeout_count++ < clocking_timeout)); //!# Wait for the PLL to lock
	status->PLL_lock = (timeout_count >= clocking_timeout) ? 1 : 0;

	configure_overdrive_mode(potential_system_clock_frequency, status);
	configure_flash_latency_and_cache(potential_system_clock_frequency, status);

	if ((status->PLL_lock == 0) && (status->voltage_scale == 0) && (status->overdrive == 0)) {
		if (clk_src == sys_clk_src_PLL_HSI_P || clk_src == sys_clk_src_PLL_HSE_P) {
			RCC_CFGR |= 0x2UL; //!# Set the system clock source to the main PLL P output
		} else {
			RCC_CFGR |= 0x3UL; //!# Set the system clock source to the main PLL R output
		}
		wait_for_system_to_accept_src(clk_src, status);

		//!# Update the core clock variable (360 MHz VCO / PLLP or PLLR factor)
		if (clk_src == sys_clk_src_PLL_HSE_P || clk_src == sys_clk_src_PLL_HSI_P) {
			sys_clock = (status->sys_clk_accept == 0) ? 360000000 / PLLP_factor : 16000000;
		} else {
			sys_clock = (status->sys_clk_accept == 0) ? 360000000 / PLLR_factor : 16000000;
		}
	} else {
		sys_clock = 160000000; //!# PLL as the sys clk src failed, so we default to 16 MHz HSI
	}
}

/* ============================================================================================================= */
/* System Init Sub-Functions                                                                                     */
/* ============================================================================================================= */
/*! Sets the CR, PLLCFGR, CFGR, and CIR RCC registers to their reset values.
 */
static void reset_RCC_regs(void)
{
	RCC_CR = 0x00000083UL;
	RCC_CFGR = 0x00000000UL;
	RCC_PLLCFGR = 0x24003010UL;
	RCC_CIR = 0x00000000UL;
}

/*! Sets the system clock source to the desired source.
 *
 * @param clk_src
 *    (input) The desired hardware source for the system clock signal.
 * @param PLLP_factor
 *    (input) The PLL P division factor, necessary if the system clock source is a signal from the PLL. Must be
 *            2, 4, 6, or 8.
 * @param PLLR_factor
 *    (input) The PLL R division factor, necessary if the system clock source is a signal from the PLL. Must be
 *            between 2 and 7, inclusive.
 * @param status
 *    (input/output) The status of setting the system clock.
 */
static void set_sys_clock(sys_clk_src const clk_src
	, uint32_t const PLLP_factor
	, uint32_t const PLLR_factor
	, system_init_status * const status
) {
	switch (clk_src) {
		case sys_clk_src_HSI:
			sys_clock = 16000000; //!# HSI is the default sys clk source, thus 16 MHz
			break;
		case sys_clk_src_HSE:
			set_sys_clk_HSE(false, status);
			break;
		case sys_clk_src_HSE_BYP:
			set_sys_clk_HSE(true, status);
			break;
		case sys_clk_src_PLL_HSE_P:
		case sys_clk_src_PLL_HSE_R:
		case sys_clk_src_PLL_HSI_P:
		case sys_clk_src_PLL_HSI_R:
			set_sys_clk_PLL(clk_src, PLLP_factor, PLLR_factor, status);
			break;
		default:
			status->sys_clk_src = 1; //!# Invalid system clock source
			sys_clock = 16000000;    //!# Defaults to HSI as system clock in this case
			break;
	}
}

/*! Sets the AHB bus clock as a division from the system clock by the AHB prescaler.
 *
 * @note  If there is any error in the desired AHB prescaler, the AHB frequency will be set to the same value as
 *        the system clock. This requires no extra steps as by default the AHB prescaler is set to 1 (i.e. the
 *        same value as the system clock).
 *
 * @param AHB_prescaler
 *    (input) The division factor for the system clock to create the AHB bus clock.
 * @param status
 *    (input/output) The status of setting the AHB bus frequency.
 */
static void set_AHB_clk(uint32_t const AHB_prescaler
	, system_init_status * const status
) {
	switch (AHB_prescaler)
	{
		case 1:
			RCC_CFGR &= ~(0x1UL << 7);
			break;
		case 2:
			RCC_CFGR |= (0x8UL << 4);
			break;
		case 4:
			RCC_CFGR |= (0x9UL << 4);
			break;
		case 8:
			RCC_CFGR |= (0xAUL << 4);
			break;
		case 16:
			RCC_CFGR |= (0xBUL << 4);
			break;
		case 64:
			RCC_CFGR |= (0xCUL << 4);
			break;
		case 128:
			RCC_CFGR |= (0xDUL << 4);
			break;
		case 256:
			RCC_CFGR |= (0xEUL << 4);
			break;
		case 512:
			RCC_CFGR |= (0xFUL << 4);
			break;
		default:
			status->AHB_prescaler = 1; //!# Invalid AHB prescaler, default behavior will be used in this case
			break;
	}
	AHB_bus_clock = (status->AHB_prescaler == 0) ? sys_clock / AHB_prescaler : sys_clock;
}

/*! Sets the APB bus clock as a division from the AHB clock by the APB prescaler.
 *
 * @note  If there is any error in the desired APB prescaler, an APB prescaler is chosen such that the highest APB
 *        bus clock frequency (given a set AHB bus frequency) is set.
 *
 * @param APB1
 *    (input) 'true' to set the clock for the APB1 bus, 'false' to set the clock for the APB2 bus.
 * @param prescaler
 *    (input) The division factor from the AHB bus clock to create the APB bus clock.
 * @param status
 *    (input/output) The status of setting the APB bus frequency.
 */
static void set_APB_clk(bool const APB1
	, uint32_t prescaler
	, system_init_status * const status
) {
	uint32_t max_APB_frequency = (APB1) ? 45000000 : 90000000; //!# 45 MHz for APB1, 90 MHz for APB2

	if (  ((prescaler == 1 ) || (prescaler == 2) || (prescaler == 4) || (prescaler == 8) || (prescaler == 16))
		&& ((AHB_bus_clock / prescaler) <= max_APB_frequency)
	) {
		//!# Do nothing as we already have a valid prescaler
	} else {
		//!# An invalid APB1 prescaler was chosen
		if (APB1) {
			status->APB1_prescaler = 1;
		} else {
			status->APB2_prescaler = 1;
		}

		//!# Choose a new APB prescaler that results in the fastest possible (and still valid) APB bus frequency
		for (prescaler = 1; prescaler <= 16; prescaler *= 2) {
			if (AHB_bus_clock / prescaler <= max_APB_frequency) {
				break;
			} else {
				//!# Keep searching for the fastest, valid APB prescaler
			}
		}
	}

	//!# Now that we for sure have a valid prescaler we can set what needs to be set
	set_APB_prescaler(APB1, prescaler);
	if (APB1) {
		APB1_bus_clock = AHB_bus_clock / prescaler;
	} else {
		APB2_bus_clock = AHB_bus_clock / prescaler;
	}
}

/* ============================================================================================================= */
/* Public Functions                                                                                              */
/* ============================================================================================================= */
/*! Initializes the system clock and the AHB, APB1, and APB2 bus clocks.
 *
 * @note  The RCC clock configuration registers have to be reset first to ensure that irregardless of the type of
 *        reset the system goes through (i.e. system, power, or backup domain) we always start the system
 *        initialization process with a "clean slate" oF RCC registers.
 */
system_init_status system_init(void)
{
	system_init_status status = { 0 };

	//!# Pull the desired setup from preprocessor defines
	sys_clk_src const sys_clk_src    = __SYS_CORE_CLK_SRC;
	uint32_t    const PLLP_factor    = __PLLP_FACTOR;
	uint32_t    const PLLR_factor    = __PLLR_FACTOR;
	uint32_t    const AHB_prescaler  = __AHB_PRESCALER;
	uint32_t    const APB1_prescaler = __APB1_PRESCALER;
	uint32_t    const APB2_prescaler = __APB2_PRESCALER;

	reset_RCC_regs();

	//!# Set clocks
	set_sys_clock(sys_clk_src, PLLP_factor, PLLR_factor, &status);
	set_AHB_clk(AHB_prescaler, &status);
	set_APB_clk(true, APB1_prescaler, &status);
	set_APB_clk(false, APB2_prescaler, &status);

	return status;
}

/* EOF */
