#include <stdint.h>
#include "_stm32f446re_registers.h"

#ifndef _STM32F446RE_SYSTEM_H
#define _STM32F446RE_SYSTEM_H

/*! System clock frequency.
 */
extern uint32_t system_clk_freq;

/*! Returns the frequency of the AHB clock.
 *
 * @brief The AHB frequency is determined by the frequency of the system clock divided by the AHB prescaler. The
 *        system clock is determined at startup thus to find the AHB frequency we just read bits 7:4 of the
 *        RCC CFGR register to get the AHB prescaler and divide the system clock by it.
 *
 * @return The AHB clock frequency.
 */
__attribute__((always_inline)) inline uint32_t _SYS_AHB_clk()
{
	uint32_t AHB_freq = 0;
	uint32_t sys_clk_prescaler = RCC_CFGR & 0xF0U; //Masked for bits 7:4 (the AHB prescaler)

	/* Determine the AHB clk frequency (how much the sys clk is divided by, if any) */
	switch (sys_clk_prescaler)
	{
		case (128): //0b1000_XXXX
			AHB_freq = system_clk_freq / 2;
			break;
		case (144): //0b1001_XXXX
			AHB_freq = system_clk_freq / 4;
			break;
		case (160): //0b1010_XXXX
			AHB_freq = system_clk_freq / 8;
			break;
		case (176): //0b1011_XXXX
			AHB_freq = system_clk_freq / 16;
			break;
		case (192): //0b1100_XXXX
			AHB_freq = system_clk_freq / 64;
			break;
		case (208): //0b1101_XXXX
			AHB_freq = system_clk_freq / 128;
			break;
		case (224): //0b1110_XXXX
			AHB_freq = system_clk_freq / 256;
			break;
		case (240): //0b1111_XXXX
			AHB_freq = system_clk_freq / 512;
			break;
		default: //0b0XXX_XXXX
			AHB_freq = system_clk_freq;
			break;
	}
	return AHB_freq;
}

/*! Returns the frequency of the APB1 clock.
 *
 * @brief The APB1 frequency is determined by the frequency of the AHB clock divided by the APB1 prescaler. The AHB
 *        frequency is found with the _SYS_AHB_clk() call and that result is divided by the value in bits 12:10
 *        of the RCC CFGR register.
 *
 * @return The APB1 clock frequency.
 */
__attribute__((always_inline)) inline uint32_t _SYS_APB1_clk()
{
	uint32_t APB1_freq = 0;
	uint32_t AHB_freq = _SYS_AHB_clk();
	uint32_t AHB_prescaler = RCC_CFGR & 0x1C00U; //Masked for bits 12:10 (the APB1 prescaler)

	/* Determine the APB1 clk frequency (how much the AHB clock is divided by, if any) */
	switch (AHB_prescaler)
	{
		case (4096): //0bXXX1_00XX_XXXX_XXXX
			APB1_freq = AHB_freq / 2;
			break;
		case (5120): //0bXXX1_01XX_XXXX_XXXX
			APB1_freq = AHB_freq / 4;
			break;
		case (6144): //0bXXX1_10XX_XXXX_XXXX
			APB1_freq = AHB_freq / 8;
			break;
		case (7168): //0bXXX1_11XX_XXXX_XXXX
			APB1_freq = AHB_freq / 16;
			break;
		default:
			APB1_freq = AHB_freq;
			break;
	}
	return APB1_freq;
}

/*! Returns the frequency of the APB2 clock.
 *
 * @brief The APB2 frequency is determined by the frequency of the AHB clock divided by the APB2 prescaler. The AHB
 *        frequency is found with the _SYS_AHB_clk() call and that result is divided by the value in bits 15:13
 *        of the RCC CFGR register.
 *
 * @return The APB2 clock frequency.
 */
__attribute__((always_inline)) inline uint32_t _SYS_APB2_clk()
{
	uint32_t APB2_freq = 0;
	uint32_t AHB_freq = _SYS_AHB_clk();
	uint32_t AHB_prescaler = RCC_CFGR & 0xE000U; //Masked for bits 15:13 (the APB2 prescaler)

	/* Determine the APB2 clk frequency (how much the AHB clock is divided by, if any) */
	switch (AHB_prescaler)
	{
		case (32768): //0b100X_XXXX_XXXX_XXXX
			APB2_freq = AHB_freq / 2;
			break;
		case (40960): //0b101X_XXXX_XXXX_XXXX
			APB2_freq = AHB_freq / 4;
			break;
		case (49152): //0b110X_XXXX_XXXX_XXXX
			APB2_freq = AHB_freq / 8;
			break;
		case (57344): //0b111X_XXXX_XXXX_XXXX
			APB2_freq = AHB_freq / 16;
			break;
		default:
			APB2_freq = AHB_freq;
			break;
	}
	return APB2_freq;
}

#endif /* _STM32F446RE_SYSTEM_H */

/* EOF */
