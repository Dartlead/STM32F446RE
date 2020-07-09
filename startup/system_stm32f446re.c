#include <stdint.h>
#include "core/registers_stm32f446re.h"

#ifndef __SYS_CORE_CLK_SRC
#	error Source for system core clock must be defined via the '__SYS_CORE_CLK_SRC' preprocessor define
#endif

/*! Global variable containing the system's frequency.
 */
uint32_t system_core_clock = 0;

/* ============================================================================================================= */
/* Enumerations                                                                                                  */
/* ============================================================================================================= */
/*! Potential sources for the system core clock.
 */
typedef enum sys_core_clk_src {
	  sys_core_clk_src_HSI       //!# High-speed internal oscillator (HSI), 16 MHz
	, sys_core_clk_src_HSE       //!# High-speed external oscillator (HSE), 8 MHz
	, sys_core_clk_src_HSE_BYP   //!# HSE bypassed with an external user-provided clock
	, sys_core_clk_src_PLL_HSE_P //!# Main PLL P (a.k.a CLK) output, where the PLL is clocked by the HSE
	, sys_core_clk_src_PLL_HSE_R //!# Main PLL R output, where the PLL is clocked by the HSE
	, sys_core_clk_src_PLL_HSI_P //!# Main PLL P (a.k.a CLK) output, where the PLL is clocked by the HSI
	, sys_core_clk_src_PLL_HSI_R //!# Main PLL R output, where the PLL is clocked by the HSI
} sys_core_clk_src;

/*! Potential output frequencies for the main PLL.
 */
typedef enum PLL_P_freq {
	  PLL_P_freq_45_mhz
	, PLL_P_freq_60_mhz
	, PLL_P_freq_90_mhz
	, PLL_P_freq_180_mhz
} PLL_P_freq;

/*!
 */
typedef enum sys_core_clk_status {
	  sys_core_clk_success           =  0
	, sys_core_clk_stability_timeout = -1 //!# Desired system clock source failed to stabilize
	, sys_core_clk_accept_timeout    = -2 //!# System failed to select the desired system clock source
} sys_core_clk_status;

/* ============================================================================================================= */
/* Helper Functions                                                                                              */
/* ============================================================================================================= */
/*! Waits for the clock signal represented by the ready bit to be stable until a potential timeout.
 *
 * @param timeout_len
 *    (input) How long to wait for clock stability before timing out.
 * @param rdy_bit_mask
 *    (input) A mask that isolates the ready bit that determines whether the clock is stable or not (use the
 *            #defines in registers_stm32f446re_RCC.h starting on line 72).
 * @return 'sys_core_clk_success' on clock being stable, 'sys_core_clk_stability_timeout' on timeout being reached.
 */
static sys_core_clk_status wait_clk_stabilize(uint32_t const timeout_len
	, uint32_t const rdy_bit_mask
) {
	uint32_t clk_stable_cntr = 0UL;
	sys_core_clk_status stability_status = sys_core_clk_success;

#define TODO____DO_A_TIMEOUT_LENGTH_IN_A_UNIT_OF_TIME_BASED_ON_HSI_FREQ

	while (!(RCC_CR & rdy_bit_mask)) {
		if (clk_stable_cntr >= timeout_len) {
			stability_status = sys_core_clk_stability_timeout;
			break;
		} else {
			++clk_stable_cntr;
		}
	}

	return stability_status;
}

/*! Waits for the system to accept the desired system clock source until a potential timeout.
 *
 * @param timeout_len
 *    (input) How long to wait for clock stability before timing out.
 * @param SWS_switch
 *    (input) Which system clock source to check a switch for (use the #defines in registers_stm32f446re_RCC.h
 *            line 139).
 * @return 'sys_core_clk_success' on system accepting the system clock source, 'sys_core_clk_accept_timeout' on
 *         timeout being reached.
 */
static sys_core_clk_status wait_accept_sys_clk_src(uint32_t const timeout_len
	, uint32_t const SWS_accepted_mask
) {
	uint32_t sys_clk_accept_cntr = 0UL;
	sys_core_clk_status accept_status = sys_core_clk_success;

#define TODO____DO_A_TIMEOUT_LENGTH_IN_A_UNIT_OF_TIME_BASED_ON_HSI_FREQ

	while (RCC_CFGR & RCC_CFGR_SWS) != SWS_switch) {
		if (sys_clk_accept_cntr >= timeout_len) {
			accept_status = sys_core_clk_accept_timeout;
			break;
		} else {
			++sys_clk_accept_cntr;
		}
	}

	return accept_status;
}

/* ============================================================================================================= */
/* System Init Sub-Functions                                                                                     */
/* ============================================================================================================= */
/*! Sets the RCC CR, PLLCFGR, CFGR, and CIR registers to their reset values.
 */
static void _system_init_reset_RCC_regs()
{
	RCC_CR = 0x00000083UL;
	RCC_CFGR = 0x00000000UL;
	RCC_PLLCFGR = 0x24003010UL;
	RCC_CIR = 0x00000000UL;
}

/*! Sets the high-speed external oscillator (HSE) as the source for the system clock.
 *
 * @brief The high-speed external oscillator is really the MCO output of the ST-LINK microcontroller (the MCU on
 *        the part of the PCB that can be cut away) being used as an input clock. It is fixed at 8 MHz and is
 *        connected to GPIO PF0/PD0/PH0-OSC_IN of the stm32 MCU.
 *        To set it as the system clock source, we need to turn it on, wait for it to stabilize, switch the system
 *        clock source to the HSE, and then wait for the system to accept the HSE as a source.
 *
 * @return Whether or not the system clock source was successfully switched to the HSE or if an error occurred.
 */
static sys_core_clk_status _system_init_set_sys_clk_HSE()
{
	uint32_t const timeout = 0x5000UL;
	sys_core_clk_status HSE_status = sys_core_clk_success;

	RCC_CR |= RCC_CR_HSEON; //!# Turn on the HSE
	HSE_status = wait_clk_stablilize(timeout, RCC_CR_HSERDY);
	if (HSE_status == sys_core_clk_success) {
		RCC_CFGR |= RCC_CFGR_SW_HSE; //!# Select the HSE as the sys clock source
		HSE_status = wait_accept_sys_clk_src(timeout, RCC_CFGR_SWS_HSE);
		if (HSE_status == sys_core_clk_success) {
			system_core_clock = 8000000; //!# The HSE is now the system clock source so update the global
		} else {
			//!# Do nothing as the system failed to accept the HSE as the system clock source
		}
	} else {
		//!# Do nothing as the HSE failed to stabilize
	}

	return HSE_status;
}

/*! Initializes the main PLL's PLL_P output clock signal and sets it as the system clock source.
 *
 * @brief For this getup, the HSE is used as the input clock source to the main PLL which then divides said input
 *        clock source by the PLLM factor to get the PLL's internal voltage-controlled oscillator's (VCO) input
 *        frequency. The VCO's input frequency is multiplied by the PLLN factor to get the VCO's output frequency
 *        and from there the VCO output frequency is divided by the PLL_P factor to get the frequency that will be
 *        used as the sytem clock source.
 * 
 *        The VCO input frequency should always be 2 MHz (to limit PLL jitter) and thus the PLLM division factor
 *        should always be 4 (8 MHz HSE PLL input frequency / 4 = the necessary 2 MHz VCO input frequency).
 *
 *        The VCO output frequency must be between 100 and 432 MHz. However, because the VCO output frequency can
 *        be divided down by a PLL_P factor of as little 2 and the result of said division forms the system clock
 *        frequency which is capped to 180 MHz, the VCO output frequency is capped to 360 MHz and the PLL_N
 *        multiplication factor is capped at 180 (i.e. 2 MHz VCO input frequency * PLL_N of 180 = 360 MHz VCO
 *        output frequency).
 *
 *        ... something something ... VCO output / PLLP = PLL's PLL_P frequency which is used as sys clock capped
 *        at 180 MHz. ... something something ... wait for PLL to be stable then wait for system to be stable after
 *        selecting PLLP as system clock source.
 * 
 * @note  In the reference manual, the PLL_P output clock is also referenced as PLL_CLK.
 */
static sys_core_clk_status _system_init_set_sys_clk_PLL_HSE_P()
{
	uint32_t accum_pllcfgr = RCC_PLLCFGR;
	uint32_t const timeout = 0x5000UL;
	sys_core_clk_status PLLP_status = sys_core_clk_success;

	RCC_CR |= RCC_CR_HSEON; //!# Turn on the HSE
	PLLP_status = wait_clk_stablilize(timeout, RCC_CR_HSERDY);
	if (PLLP_status == sys_core_clk_success) {
		accum_pllcfgr |= RCC_PLLCFGR_PLLSRC_HSE; //!# Select the HSE as the main PLL input clock source
		accum_pllcfgr |= 0x4UL; //!# Set the PLLM division factor to 4
		accum_pllcfgr |= 0xB4UL << 6; //!# Set the PLLN multiplication factor to 180
		//!# Set the PLLP division factor to get the system clock frequency, defaults to 2
		RCC_PLLCFGR = accum_pllcfgr; //!# Write the main PLL accumulated configurations

		RCC_PLLCFGR |= RCC_CR_PLLON; //!# Turn on the main PLL
		PLLP_status = wait_clk_stablilize(timeout, RCC_CR_PLLRDY);
		if (PLLP_status == sys_core_clk_success) {
			RCC_CFGR |= RCC_CFGR_SW_PLL_P; //!# Select the main PLL's P output as the sys clock source
			PLLP_status = wait_accept_sys_clk_src(timeout, RCC_CFGR_SWS_PLL_P);
			if (PLLP_status == sys_core_clk_success) {
				system_core_clock = 180000000; //!# The PLL_P is now the system clock source so update the global
			} else {
				//!# Do nothing as the system failed to accept the PLL as the system clock source
			}
		} else {
			//!# Do nothing as the PLL was unable to lock
		}
	} else {
		//!# Do nothing as the HSE was unable to stabilize
	}

	return PLLP_status;
}

//	/* The voltage regulator supplies all the digital circuitries except for the backup domain and the standby
//	 * circuitry. the regulator output is around 1.2V.
//	 * At power scale 3, the typical regulator voltage output is 1.14V and the max HCLK (AHB freq) is 120 MHZ.
//	 * At power scale 2, the typical regulator voltage output is 1.26V and the max HCLK is 144 MHz with overdrive
//	 *    off or 168 MHz with over-drive on.
//	 * At power scale 1, the output is 1.32V and the max HCLK is 168 MHz with overdrive off  and 180 MHz with it on.
//	 * More details about the power scales can be found on page 75 of the STM32f446xC/E datasheet (General
//	 * Operating Conditions table).
//	 */
//	//!# Select regulator voltage output scale 1 mode for max frequency
//	RCC_APB1ENR |= RCC_APB1ENR_PWREN; //!# Turn on the clock to the power configuration circuitry
//	uint32_t volatile * const PWR_CR = (uint32_t volatile *)0x40007000;
//	*PWR_CR |= (uint32_t)0x0000C000; //1# PWR_CR bits 15 & 14 (VOS[1:0]) set to 0b11

/*!
 *
 * @note  The '__SYS_CORE_CLK_SRC' is provided via the preprocessor (and must be defined in the makefile).
 */
static void _system_init_set_sys_clock()
{
	//!# Determine desired system clock source
	sys_core_clk_src const clk_src = __SYS_CORE_CLK_SRC;
	sys_core_clk_status sys_clk_src_status = sys_core_clk_success;

	switch (clk_src) {
		case sys_core_clk_src_HSE:
			sys_clk_src_status = _system_init_set_sys_clk_HSE();
		case sys_core_clk_src_HSE_BYP:
			break; //!# Not implemented
		case sys_core_clk_src_PLL_HSE_P:
			sys_clk_src_status = _system_init_set_sys_clk_PLL_HSE_P();
		case sys_core_clk_src_HSI:
		default:
			break; //!# Do nothing as the HSI is the default system clock source
	}
}

/*! Device-specific system configuration function.
 *
 * @brief This function initializes the sytem clock to the output from either the high speed internal oscillator
 *        (HSI), high speed external oscillator (HSE), bypassed HSE with an external user clock (HSE bypass), the
 *        PLL clocked by the HSI (PLLCLK), or the PLL clocked by the HSE (PLLR).
 * @note  The RCC clock configuration registers have to be reset (via _system_init_reset_RCC_regs()) to ensure that
 *        irregardless of the type of reset the system goes through (system, power, or backup domain) we always
 *        start system initialization with the "clean slate" of RCC registers with the HSI being used as the system
 *        clock source.
 */
void system_init()
{
	_system_init_reset_RCC_regs();
	_system_init_set_sys_clock();
	//_system_init_set_bus_clks(); //!# APB1, APB2, and AHB clocks
}

/* EOF */
