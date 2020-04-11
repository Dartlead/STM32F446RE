#include "bootloader_clks.h"
#include <stdbool.h>
#include <stdint.h>

/*! Enumeration of potential sources for system clock.
 */
typedef enum sys_clk_src {
	  SYS_CLK_PLL_P   //Main Phase-Locked Loop P (a.k.a CLK) Output
	, SYS_CLK_PLL_R   //Main Phase-Locked Loop R Output
	, SYS_CLK_HSI     //High-Speed Internal Oscillator
} sys_clk_src;

/*! Enumeration of the clock output signals from the main PLL.
 */
typedef enum main_pll_out_clk {
	  main_pll_out_clk_P
	, main_pll_out_clk_R
} main_pll_out_clock;

/* ============================================================================================================= */
/* Error Function                                                                                                */
/* ============================================================================================================= */
static void _clk_init_error() {
	while (1);
}

/* ============================================================================================================= */
/* _btldr_set_sys_clk_PLL() Sub-Functions                                                                        */
/* ============================================================================================================= */
/*! Sets the PLLN VCO input clk multiplication factor.
 *
 * @brief Sets the PLLN VCO input clk multiplication factor only if the desired VCO output frequency is between
 *        100 and 432 MHz. If boundary conditions are not met, _clk_init_error() is entered.
 *
 * @param vco_output_freq
 *    (input) The desired VCO output freq.
 * @param pllcfgr_accum
 *    (input) An accumulator variable to store changes to the PLLCFGR register before doing a single write.
 */
static void _btldr_set_sys_clk_PLL_set_PLLN(uint32_t const vco_output_freq
	, uint32_t * const pllcfgr_accum
) {
	if (vco_output_freq < 100000000 || vco_output_freq > 432000000) {
		_clk_init_error();
	} else {
		*pllcfgr_accum &= ~(0x7FC0UL);                      //Clear PLLN[8:0] (RCC_PLLCFGR[14:6])
		*pllcfgr_accum |= (vco_output_freq / 2000000) << 6; //Set PLLN[8:0] to get the desired VCO output frequency
	}
}

/*! Sets the PLLP or PLLR VCO output clk division factors.
 *
 * @brief If the PLL_P clock signal is to be used as the system clock source, this function sets PLLP to the
 *        provided p division factor if said division factor is either 2, 4, 6, or 8 AND the VCO output clk
 *        frequency divided by said division factor is less than 180000000. If the PLL_R clock signal is to be used
 *        as the system clock source, this function sets PLLR to the provided r division factor if said division
 *        factor is between 2 and 7, inclusive. If boundary conditions are not met, _clk_init_error() is entered.
 *
 * @param vco_output_freq
 *    (input) The desired VCO output freq, must be between 100 and 432 MHz.
 * @param pll_p_div_factor
 *    (input) The desired VCO output freq division factor for main PLL's PLL_P clock signal.
 * @param pll_r_div_factor
 *    (input) The desired VCO output freq division factor for the main PLL's PLL_R clock signal.
 * @param pll_out_clk
 *    (input) Which of the main PLL's output clocks to use as the system clock source.
 * @param pllcfgr_accum
 *    (input) An accumulator variable to store changes to the PLLCFGR register before doing a single write.
 */
static void _btldr_set_sys_clk_PLL_set_PLLP_R(uint32_t const vco_output_freq
	, uint32_t const pll_p_div_factor
	, uint32_t const pll_r_div_factor
	, main_pll_out_clock const pll_out_clk
	, uint32_t * const pllcfgr_accum
) {
	if (pll_out_clk == main_pll_out_clk_P) {
		/* Check the PLLP division factor (and the resultant PLL_P clk signal) is in bounds */
		if (   ((vco_output_freq / pll_p_div_factor) > 180000000)
			|| (pll_p_div_factor != 2)
			|| (pll_p_div_factor != 4)
			|| (pll_p_div_factor != 6)
			|| (pll_p_div_factor != 8)
		) {
			_clk_init_error();
		} else {
			*pllcfgr_accum &= ~(0x30000UL);           //Clear PLLP[1:0] (RCC_PLLCFGR[17:16])
			*pllcfgr_accum |= pll_p_div_factor << 16; //Set PLLP[1:0] to get the PLL_P frequency
		}
	} else {
		/* Check the PLLR division factor is in bounds */
		if ((pll_r_div_factor < 2) || (pll_r_div_factor > 7)) {
			_clk_init_error();
		} else {
			*pllcfgr_accum &= ~(0x70000000UL);        //Clear PLLR[2:0] (RCC_PLLCFGR[30:28])
			*pllcfgr_accum |= pll_r_div_factor << 28; //Set PLLR[2:0] to get the PLL_R frequency
		}
	}
}

/*! Sets the system clock source as either the PLL_P or PLL_R clk signals.
 *
 * @brief Changes the system clock source to PLL_P if the desired PLL clk signal is the P variant and the PLL_R
 *        otherwise.
 *
 * @param pll_out_clk
 *    (input) Which of the main PLL's output clocks to use as the system clock source.
 */
static void _btldr_set_sys_clk_PLL_set_sys_clk_src(main_pll_out_clock const pll_out_clk)
{
	uint32_t volatile * const rcc_cfgr = (uint32_t *)0x40023808;
	uint32_t cfgr_accum = *rcc_cfgr;
	cfgr_accum &= ~(0x3UL); //Clear SW[1:0] (RCC_CFGR[1:0])

	if (pll_out_clk == main_pll_out_clk_P) {
		cfgr_accum |= 0x2UL;    //Set the system clock source to PLL_P
		*rcc_cfgr = cfgr_accum; //Write the cfgr changes
	} else {
		cfgr_accum |= 0x3UL;    //Set the system clock source to PLL_R
		*rcc_cfgr = cfgr_accum; //Write the cfgr changes
	}
}

/* ============================================================================================================= */
/* btldr_set_sys_clk() Sub-Functions                                                                             */
/* ============================================================================================================= */
/*! Resets the RCC CR, PLLCFGR, CFGR, and CIR registers to their reset values.
 */
static void _btldr_set_sys_clk_reset_regs()
{
	uint32_t volatile * const rcc_cr = (uint32_t *)0x40023800;
	uint32_t volatile * const rcc_pllcfgr = (uint32_t *)0x40023804;
	uint32_t volatile * const rcc_cfgr = (uint32_t *)0x40023808;
	uint32_t volatile * const rcc_cir = (uint32_t *)0x4002380C;

	/* Reset the CR, CFGR, PLLCGFR, and CIR registers */
	*rcc_cr = 0x00000083UL;
	*rcc_cfgr = 0x00000000UL;
	*rcc_pllcfgr = 0x24003010UL;
	*rcc_cir = 0x00000000UL;
}

/*! Initializes and sets the main PLL's output PLL_P or PLL_R clock signals as the system clock source.
 *
 * @brief The main PLL is made up of an internal voltage-controlled oscillator (VCO) and several multipliers and
 *        dividers to manipulate the internal VCO's input and output clocks thus producing the main PLL's output
 *        clock signals (PLL_P, PLL_Q, and PLL_R).
 *
 *        The main PLL's input clock source (which in this case is limited to only the 16 MHz high-speed internal
 *        (HSI) oscillator) is divided down by the PLLM factor to create the VCO's input clock - note that the
 *        VCO input clock should always be 2 MHz to limit PLL jitter thus the PLLM factor should always be '8' as
 *        16 MHz / 8 = 2 MHz. This is governed by the following equation:
 *        VCO_input_freq = PLL_input_clk_freq / PLLM
 *
 *        From there the VCO's input clock is multiplied by the PLLN factor to create the VCO's output clock. The
 *        VCO's output clock must be between 100 and 432 MHz and because the VCO input clock should always be at
 *        2 MHz, the PLLN factor must be between 50 and 216. This is governed by the following equation:
 *        VCO_output_freq = VCO_input_freq * PLLN
 *
 *        From here, the outputs of the main PLL are derived from dividing down the VCO's output clock. The main
 *        PLL's PLL_P output clock signal is the VCO's output clock divided by the PLLP factor. The main PLL's
 *        PLL_R output clock signal is the VCO's output clock divided by the PLLR factor. This is governed by the
 *        following equations:
 *        PLL_P_freq = VCO_output_freq / PLLP
 *        PLL_R_freq = VCO_output_freq / PLLR
 *
 *        Once the main PLL and its output clocks have been properly configured (i.e. PLL_P or PLL_R have been set
 *        up depending on which is desired as the system clock source), the main PLL is switched on and then the
 *        user must wait until the output clock desired for the sytem clock source is stable. Then, said output
 *        clock is chosen as the system clock source and then the user must wait until the chip accepts the new
 *        system clock source.
 *
 * @note  In the reference manual, the PLL_P output clock is also referenced as PLL_CLK.
 *
 * @param vco_output_freq
 *    (input) The desired VCO output freq, must be between 100 and 432 MHz.
 * @param pll_p_div_factor
 *    (input) The desired VCO output freq division factor for main PLL's PLL_P clock signal.
 * @param pll_r_div_factor
 *    (input) The desired VCO output freq division factor for the main PLL's PLL_R clock signal.
 * @param pll_out_clk
 *    (input) Which of the main PLL's output clocks to use as the system clock source.
 */
static void _btldr_set_sys_clk_PLL(uint32_t const vco_output_freq
	, uint32_t const pll_p_div_factor
	, uint32_t const pll_r_div_factor
	, main_pll_out_clock const pll_out_clk
) {
	uint32_t volatile * const rcc_cr = (uint32_t *)0x40023800;
	uint32_t volatile * const rcc_cfgr = (uint32_t *)0x40023808;
	uint32_t volatile * const rcc_pllcfgr = (uint32_t *)0x40023804;
	uint32_t cfgr_accum = *rcc_cfgr;
	uint32_t pllcfgr_accum = *rcc_pllcfgr;

	pllcfgr_accum &= ~(0x1 << 22); //Select the HSI as the main PLL entry clock source
	pllcfgr_accum &= ~(0x3FUL);    //Clear PLLM[5:0] (RCC_PLLCFGR[5:0])
	pllcfgr_accum |= 0x8UL;        //Set PLLM[5:0] to 8 which gives us a VCO input frequency of 2 MHz

	_btldr_set_sys_clk_PLL_set_PLLN(vco_output_freq, &pllcfgr_accum);
	_btldr_set_sys_clk_PLL_set_PLLP_R(vco_output_freq
		, pll_p_div_factor
		, pll_r_div_factor
		, pll_out_clk
		, &pllcfgr_accum
	);

	*rcc_pllcfgr = pllcfgr_accum;     //Write the main PLL accumulated configurations
	*rcc_cr |= 0x1 << 24;             //Turn on the newly configured main PLL
	while (!(*rcc_cr & 0x2000000UL)); //Wait until main PLL is stable (a.k.a locked)

	_btldr_set_sys_clk_PLL_set_sys_clk_src(pll_out_clk);
	if (pll_out_clk == main_pll_out_clk_P) {
		while (!(*rcc_cfgr & 0x2UL)); //Wait for the chip to accept the new system clock source
	} else {
		while (!(*rcc_cfgr & 0x3UL)); //Wait for the chip to accept the new system clock source
	}
}

/* ============================================================================================================= */
/* Public Functions                                                                                              */
/* ============================================================================================================= */
/*! Sets the system clock source to either the HSI, PLL_P, or PLL_R.
 *
 * @brief Reset the necessary RCC registers and then call the appropriate sub-function to initialize the
 *        appropriate clock source and then set the system clock source to said clock source.
 */
void btldr_set_sys_clk()
{
	/* The following are provided by the preprocessor via the makefile */
	sys_clk_src const src = __SYS_CLK;
	uint32_t const vco_freq = __VCO_FREQ;
	uint32_t const pll_p_div = __PLL_P_DIV;
	uint32_t const pll_r_div = __PLL_R_DIV;

	_btldr_set_sys_clk_reset_regs();

	/* Choose and initialize the clock source for the system clock */
	switch (src) {
		case SYS_CLK_PLL_P:
			_btldr_set_sys_clk_PLL(vco_freq, pll_p_div, pll_r_div, main_pll_out_clk_P);
			break;
		case SYS_CLK_PLL_R:
			_btldr_set_sys_clk_PLL(vco_freq, pll_p_div, pll_r_div, main_pll_out_clk_R);
			break;
		default: //HSI
			//Do nothing as the HSI is the default system clock source
			break;
	}
}

/* EOF */
