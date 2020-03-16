#include "USART.h"
#include "GPIO.h"
#include "_stm32f446re_registers.h"
#include "_stm32f446re_system.h"
#include <math.h>
#include <stdlib.h>

/* ============================================================================================================= */
/* Helper Functions                                                                                              */
/* ============================================================================================================= */
/*! Determines if the desired configuration parameters for a USART channel are compatible.
 *
 * @brief Checks if:
 *        - The desired USART channel is within boundaries.
 *        - The desired oversampling rate is within boundaries.
 *        - The desired word length is either 8 or 9 bits.
 *        - The desired parity is within boundaries.
 *        - The pin configuration for CTS and RTS is not config 3.
 *
 *        - If the USART channel is 1, 2, 4, 5, or 6, the pin_TX_RX option cannot be USART_pin_cnfg3.
 *        - If the USART channel is 1, 4, or 5, the pin_CTS_RTS option cannot be USART_pin_cnfg2.
 *        - If IrDA, smartcard, or LIN mode is enabled, the oversampling rate cannot be 8.
 *        - If the number of stop bits is either 0.5 or 1.5, smartcard mode must be enabled.
 *        - If the number of stop bits is either 0.5 or 1.5, the USART channel cannot be 4 or 5.
 *
 * @param channel
 *    (input) The USART channel being checked.
 * @param cnfg
 *    (input) The configuration options for the channel being checked.
 */
static bool _USART_params_are_valid(USART_channel const channel
	, USART_cnfg const cnfg
) {
	bool params_are_valid = false;

	if (  ((channel >= USART_channel1) && (channel <= USART_channel6))
		&& ((cnfg.oversample_mode == USART_oversample_8) || (cnfg.oversample_mode == USART_oversample_16))
		&& ((cnfg.word_length == 8) || (cnfg.word_length == 9))
		&& ((cnfg.parity >= USART_parity_none) && (cnfg.parity <= USART_parity_odd))
		&& (cnfg.pin_CTS_RTS != USART_pin_cnfg3)
	) {
		params_are_valid = true;

		if ((channel == USART_channel1) && (cnfg.pin_TX_RX == USART_pin_cnfg3)) { params_are_valid = false; }
		if ((channel == USART_channel1) && (cnfg.pin_CTS_RTS == USART_pin_cnfg2)) { params_are_valid = false; }
		if ((channel == USART_channel2) && (cnfg.pin_TX_RX == USART_pin_cnfg3)) { params_are_valid = false; }
		if ((channel == UART_channel4)  && (cnfg.pin_TX_RX == USART_pin_cnfg3)) { params_are_valid = false; }
		if ((channel == UART_channel4) && (cnfg.pin_CTS_RTS == USART_pin_cnfg2)) { params_are_valid = false; }
		if ((channel == UART_channel5)  && (cnfg.pin_TX_RX == USART_pin_cnfg3)) { params_are_valid = false; }
		if ((channel == UART_channel5) && (cnfg.pin_CTS_RTS == USART_pin_cnfg2)) { params_are_valid = false; }
		if ((channel == USART_channel6) && (cnfg.pin_TX_RX == USART_pin_cnfg3)) { params_are_valid = false; }
		if (cnfg.IrDA_mode_en && (cnfg.oversample_mode == USART_oversample_8)) { params_are_valid = false; }
		if (cnfg.smartcard_mode_en && (cnfg.oversample_mode == USART_oversample_8)) { params_are_valid = false; }
		if (cnfg.LIN_mode_en && (cnfg.oversample_mode == USART_oversample_8)) { params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_0_5_stop) && !cnfg.smartcard_mode_en) { params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_1_5_stop) && !cnfg.smartcard_mode_en) { params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_0_5_stop) && (channel == UART_channel4)) {params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_0_5_stop) && (channel == UART_channel5)) {params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_1_5_stop) && (channel == UART_channel4)) {params_are_valid = false; }
		if ((cnfg.num_stop_bits == USART_1_5_stop) && (channel == UART_channel5)) {params_are_valid = false; }
	} else {
		//Invalid parameters, boolean is already false so do nothing
	}

	return params_are_valid;
}

/*! Sets the desired TX/RX port/pin combos to alternate function mode.
 *
 * @brief Configures the desired port/pin combos for the TX and RX signals as alternate function mode output GPIO.
 *        The exact alternate function number is dependent on the USART channel - channels 1, 2, and 3 use
 *        alternate function mode 7 whereas channels 4, 5, and 6 use alternate function mode 8.
 *
 * @param channel
 *    (input) The USART channel whose TX/RX pins are being configured.
 * @param TX_port
 *    (input) The GPIO port that is desired for the TX signal.
 * @param RX_port
 *    (input) The GPIO port that is desired for the RX signal.
 * @param TX_pin_num
 *    (input) The pin number that is desired for the TX signal.
 * @param RX_pin_num
 *    (input) The pin number that is desired for the RX signal.
 */
static void _USART_set_TX_RX_to_AF(USART_channel const channel
	, GPIO_port const TX_port
	, GPIO_port const RX_port
	, uint32_t const TX_pin_num
	, uint32_t const RX_pin_num
) {
	GPIO_cnfg TX_RX_pin_cnfg = {
		  .mode  = GPIO_mode_output,      .type  = GPIO_output_type_push_pull
		, .speed = GPIO_output_speed_low, .pull  = GPIO_pull_none
	};

	if ((channel <= USART_channel6) && (channel >= UART_channel4)) { //Channels 4, 5, or 6
		TX_RX_pin_cnfg.mode = GPIO_mode_altrnt_func_8;
	} else { //Channels 1, 2, or 3
		TX_RX_pin_cnfg.mode = GPIO_mode_altrnt_func_7;
	}

	GPIO_configure_port_pin(TX_port, TX_pin_num, TX_RX_pin_cnfg);
	GPIO_configure_port_pin(RX_port, RX_pin_num, TX_RX_pin_cnfg);
}

/*! Sets the desired CTS/RTX port/pin combos to alternate function mode.
 *
 * @brief Configures the desired port/pin combos for the CTS and RTS signals as alternate function mode output
 *        GPIO. The exact alternate function number is dependent on the USART channel - channels 4 and 6 use
 *        alternate function mode 8 for all configurations whereas channels 1, 2, 3, and 5 use alternate function
 *        mode 7 for all configurations.
 *
 * @param channel
 *    (input) The USART channel whose TX/RX pins are being configured.
 * @param TX_port
 *    (input) The GPIO port that is desired for the TX signal.
 * @param RX_port
 *    (input) The GPIO port that is desired for the RX signal.
 * @param TX_pin_num
 *    (input) The pin number that is desired for the TX signal.
 * @param RX_pin_num
 *    (input) The pin number that is desired for the RX signal.
 */
static void _USART_set_CTS_RTS_to_AF(USART_channel const channel
	, GPIO_port const CTS_port
	, GPIO_port const RTS_port
	, uint32_t const CTS_pin_num
	, uint32_t const RTS_pin_num
) {
	GPIO_cnfg CTS_RTS_pin_cnfg = {
		  .mode = GPIO_mode_output,       .type = GPIO_output_type_push_pull
		, .speed = GPIO_output_speed_low, .pull = GPIO_pull_none
	};

	if ((channel == UART_channel4) || (channel == USART_channel6)) { //Channels 4 or 6
		CTS_RTS_pin_cnfg.mode = GPIO_mode_altrnt_func_8;
	} else {
		CTS_RTS_pin_cnfg.mode = GPIO_mode_altrnt_func_7;
	}

	GPIO_configure_port_pin(CTS_port, CTS_pin_num, CTS_RTS_pin_cnfg);
	GPIO_configure_port_pin(RTS_port, RTS_pin_num, CTS_RTS_pin_cnfg);
}

/*! Computes a chhanel's BRR, SR, DR, CR1, and CR2 register addresses.
 *
 * @brief The address of the register of interest is going to be variable depending on the USART channel. The
 *        register banks for USART channels 2, 3, 4, and 5 are 0x400 apart from each other. Thus if the desired
 *        channel is 2, 3, 4, or 5 we take the address of the desired register for USART channel 2 and offset it by
 *        some multiple of 0x400 (0 for USART2, 1 for USART 3, etc.). If the desired channel is 1 or 6, we just
 *        return the address of that channel's BRR register via the macro provided in the registers header file.
 *
 * @param channel
 *    (input) The USART channel whose register address is being computed.
 */
static uint32_t * _USART_compute_BRR_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_BRR)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_BRR)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_BRR)));
		}
	}
	return addr;
}
static uint32_t * _USART_compute_CR1_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_CR1)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_CR1)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_CR1)));
		}
	}
	return addr;
}
static uint32_t * _USART_compute_CR2_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_CR2)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_CR2)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_CR2)));
		}
	}
	return addr;
}
static uint32_t * _USART_compute_CR3_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_CR3)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_CR3)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_CR3)));
		}
	}
	return addr;
}
static uint32_t * _USART_compute_SR_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_SR)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_SR)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_SR)));
		}
	}
	return addr;
}
static uint32_t * _USART_compute_DR_addr(USART_channel const channel)
{
	uint32_t * addr = 0;
	if (channel >= USART_channel2 && channel <= UART_channel5) {
		addr = (uint32_t *)((uint8_t *)(&(USART2_DR)) + (uint32_t)(0x400U * (channel - 2)));
	} else {
		if (channel == USART_channel1) {
			addr = (uint32_t *)((uint8_t *)(&(USART1_DR)));
		} else {
			addr = (uint32_t *)((uint8_t *)(&(USART6_DR)));
		}
	}
	return addr;
}

/* ============================================================================================================= */
/* Configuration/Initialization Sub Functions                                                                    */
/* ============================================================================================================= */
/*! Enables the APB peripheral clock to a USART channel.
 *
 * @brief Enabling the clock is done by simply setting the appropriate bit in the APB1ENR or APB2ENR register. The
 *        breakdown of which bit for which register is as follows:
 *        USART1 - APB2ENR, bit 4
 *        USART2 - APB1ENR, bit 17
 *        USART3 - APB1ENR, bit 18
 *        UART4  - APB1ENR, bit 19
 *        UART5  - APB1ENR, bit 20
 *        USART6 - APB2ENR, bit 5
 *        Thus the (15 + channel) part is taking 15 and adding '2' for USART2, '3' for USART3, etc.
 *
 * @param channel
 *    (input) The USART channel whose clock is to be enabled.
 */
static void _USART_init_channel_enable_clk(USART_channel const channel)
{
	switch (channel)
	{
		case USART_channel2:
		case USART_channel3:
		case UART_channel4:
		case UART_channel5:
			RCC_APB1ENR |= 0x1 << (15 + channel);
			break;
		case USART_channel1:
			RCC_APB2ENR |= 0x1 << 4;
			break;
		case USART_channel6:
			RCC_APB2ENR |= 0x1 << 6;
			break;
		default:
			break;
	}
}

/*! Configures the TX and RX signals in accordance to the USART channel's desired configuration.
 *
 * @brief The USART channel-pin config map is seen in USART_driver.txt "USART Pin Configurations Expalined" section
 *        and breaks down which port/pins are available for each USART channel per pin config. This function just
 *        assigns the TX and RX pins as per that map.
 *
 * @param channel
 *    (input) The USART channel being configured.
 * @param cnfg
 *    (input) The configuration options for the channel.
 */
static void _USART_init_channel_configure_TX_RX_pins(USART_channel const channel
	, USART_cnfg const cnfg
) {
	switch (channel)
	{
		case USART_channel1:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_A, GPIO_port_A, 9, 10);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_B, GPIO_port_B, 6, 7);
			}
			break;
		case USART_channel2:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_A, GPIO_port_A, 2, 3);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_D, GPIO_port_D, 5, 6);
			}
			break;
		case USART_channel3:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_B, GPIO_port_B, 10, 11);
			} else if (cnfg.pin_TX_RX == USART_pin_cnfg2) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_C, GPIO_port_C, 10, 5);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_D, GPIO_port_D, 8, 9);
			}
			break;
		case UART_channel4:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_A, GPIO_port_A, 0, 1);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_C, GPIO_port_C, 10, 11);
			}
			break;
		case UART_channel5:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_C, GPIO_port_D, 12, 2);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_E, GPIO_port_E, 7, 8);
			}
			break;
		case USART_channel6:
			if (cnfg.pin_TX_RX == USART_pin_cnfg1) {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_C, GPIO_port_C, 6, 7);
			} else {
				_USART_set_TX_RX_to_AF(channel, GPIO_port_G, GPIO_port_G, 14, 9);
			}
			break;
		default:
			break;
	}
}

/*! Configures the CTS and RTS signals in accordance to the USART channel's desired configuration.
 *
 * @brief The USART channel-pin config map is seen in USART_driver.txt "USART Pin Configurations Expalined" section
 *        and breaks down which port/pins are available for each USART channel per pin config. This function just
 *        assigns the CTS and RTS pins as per that map.
 *
 * @param channel
 *    (input) The USART channel being configured.
 * @param cnfg
 *    (input) The configuration options for the channel.
 */
static void _USART_init_channel_configure_RTS_CTS_pins(USART_channel const channel
	, USART_cnfg const cnfg
) {
	switch (channel)
	{
		case USART_channel1:
			_USART_set_CTS_RTS_to_AF(channel, GPIO_port_A, GPIO_port_A, 11, 12);
			break;
		case USART_channel2:
			if (cnfg.pin_CTS_RTS == USART_pin_cnfg1) {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_A, GPIO_port_A, 0, 1);
			} else {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_D, GPIO_port_D, 3, 4);
			}
			break;
		case USART_channel3:
			if (cnfg.pin_CTS_RTS == USART_pin_cnfg1) {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_B, GPIO_port_B, 13, 14);
			} else {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_D, GPIO_port_D, 11, 12);
			}
			break;
		case UART_channel4:
			_USART_set_CTS_RTS_to_AF(channel, GPIO_port_B, GPIO_port_A, 0, 15);
			break;
		case UART_channel5:
			_USART_set_CTS_RTS_to_AF(channel, GPIO_port_C, GPIO_port_C, 9, 8);
			break;
		case USART_channel6:
			if (cnfg.pin_CTS_RTS == USART_pin_cnfg1) {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_G, GPIO_port_G, 13, 8);
			} else {
				_USART_set_CTS_RTS_to_AF(channel, GPIO_port_G, GPIO_port_G, 15, 12);
			}
			break;
		default:
			break;
	}
}

/*! Converts the desired baud rate to a value appropriate for the BRR register.
 *
 * @brief The value appropriate for the BRR register is called the USARTDIV and is an unsigned fixed point number
 *        that is coded in one of two ways in the BRR register.
 *        - When oversampling by 16 (oversample_mode value of 'USART_oversample_16'), the fractional part of the
 *             fixed point USARTDIV is coded on 4 bits and is represented by bits 3:0 in the USART_BRR register.
 *             The integral part of the fixed point USARTDIV is coded on 12 bits and and is represented by bits
 *             15:4 in the USART_BRR register.
 *        - When oversampling by 8 (oversample_mode value of 'USART_oversample_8'), the fractional part of the
 *             fixed point USARTDIV is coded on 3 bits and is represented by bits 2:0 in the USART_BRR register -
 *             bit 3 must be kept cleared. The integral part of the fixed point USARTDIV is coded on 12 bits and is
 *             represented by bits 15:4 in the USART_BRR register.
 *
 *        The actual calculation for USARTDIV is set by one of the two following equations:
 *        Equation (1) - Standard USART (SPI mode included)
 *             desired_baud = fCK / (8 * (2 - OVER8) * USARTDIV) ...thus...
 *             USARTDIV = fCK / (8 * (2 - OVER8) * desired_baud)
 *        Equation (2) - Smartcard, LIN, and IrDA modes
 *             desired_baud = fCK / (16 * USARTDIV)
 *             USARTDIV = fCK / (16 * desired_baud)
 *
 *        Where desired_baud is the desired baud rate, fCK is the frequency of the clock driving the USART channel
 *        (i.e. APB1 clk for channels 2, 3, 4, and 5 and APB2 clk for channels 1 and 6), and OVER8 is the
 *        oversampling mode ('0' for an oversampling rate of 16, '1' for an oversampling rate of 8).
 *
 * @param see _USART_init_channel_configure_TX_RX_pins(). The parameters are the same.
 */
static void _USART_init_channel_set_baud_rate(USART_channel const channel
	, USART_cnfg const cnfg
) {
	float USARTDIV = 0, temp_fractional = 0, DIV_mantissa = 0;
	uint32_t fCK = 0, DIV_fractional = 0, DIV_fractional_ovrflw = 0;
	bool OVER8 = (cnfg.oversample_mode == USART_oversample_8) ? 1 : 0;
	uint32_t volatile * const USARTx_BRR_addr = _USART_compute_BRR_addr(channel);

	/* Determine fCK depending on the desired USART channel */
	if ((channel >= USART_channel2) && (channel <= UART_channel5)) {
		fCK = _SYS_APB1_clk();
	} else {
		fCK = _SYS_APB2_clk();
	}

	/* Compute the floating-point USARTDIV */
	if (cnfg.IrDA_mode_en || cnfg.smartcard_mode_en || cnfg.LIN_mode_en) {
		USARTDIV = fCK / (cnfg.baud_rate * 16);
	} else {
		USARTDIV = fCK / (cnfg.baud_rate * 8 * (2 - (float)cnfg.oversample_mode));
	}

	temp_fractional = modff(USARTDIV, &DIV_mantissa); //Breakup the USARTDIV into fractional/integral parts
	temp_fractional *= (OVER8) ? 16 : 8;              //Scale fractional by the oversampling rate
	temp_fractional = roundf(temp_fractional);        //Round the fractional to the nearest whole number

	/* Check for overflow */
	if (((temp_fractional > 7) && OVER8) || ((temp_fractional > 15) && !OVER8)) {
		DIV_fractional_ovrflw = (uint32_t)temp_fractional & (OVER8 ? 0xFFFFFFF8U : 0xFFFFFFF0U);
	} else {
		//No overflow, do nothing
	}
	DIV_fractional = (uint32_t)temp_fractional & (OVER8 ? 0x7U : 0xF); //Convert fractional to a 3 or 4 bit value

	/* Combine the mantissa and fractional and write to the BRR register */
	*USARTx_BRR_addr = (((uint32_t)DIV_mantissa + DIV_fractional_ovrflw) << 4) + DIV_fractional;
}

/*! Sets the desired number of stop bits for the channel.
 *
 * @brief To set the number of stop bits we have to simply write the number present in the configuration struct
 *        (the enum members are valued such that no conversion is necessary to place the value into the register)
 *        to bits 13:12 in the CR2 register.
 *
 * @param accum_CR2_val
 *    (input) An accumulator of writes for the CR2 register.
 * @param cnfg
 *    (input) The configuration options for the channel.
 */
static void _USART_init_channel_set_stop_bits(uint32_t * const accum_CR2_val
	, USART_cnfg const cnfg
) {
	*accum_CR2_val |= cnfg.num_stop_bits << 12;
}

/*! Sets the desired word length (number of data bits).
 *
 * @brief To set the word length we have to simply clear bit 12 in the CR2 register for a word length of 8 and set
 *        bit 12 for a word length of 9.
 *
 * @param accum_CR1_val
 *    (input) An accumulator of writes for the CR1 register.
 * @param cnfg
 *    (input) The configuration options for the channel.
 */
static void _USART_init_channel_set_word_len(uint32_t * const accum_CR1_val
	, USART_cnfg const cnfg
) {
	if (cnfg.word_length == 8) {
		*accum_CR1_val &= ~(0x1 << 12);
	} else {
		*accum_CR1_val |= (0x1 << 12);
	}
}

/*! Sets the desired parity if desired.
 *
 * @brief First this function checks if parity control is even desired (if the parity member of the configuration
 *        struct is not even or odd then parity control is not desired) and sets/clears bit 10 in the CR1 register
 *        accordingly - a '0' for this bit disables parity control and a '1' enables it. Then, if parity control
 *        was desired, bit 9 is set/cleared to configure the channel's parity - a '0' for this bit is even parity
 *        and a '1' is odd parity.
 *
 * @param see _USART_init_channel_set_world_len(). The parameters are the same.
 */
static void _USART_init_channel_set_parity(uint32_t * const accum_CR1_val
	, USART_cnfg const cnfg
) {
	if ((cnfg.parity != USART_parity_even) || (cnfg.parity != USART_parity_odd)) {
		*accum_CR1_val &= ~(0x1 << 10); //Disable parity control
	} else {
		*accum_CR1_val |= 0x1 << 10; //Enable parity control

		if (cnfg.parity == USART_parity_even) {
			*accum_CR1_val &= ~(0x1 << 9);
		} else {
			*accum_CR1_val |= 0x1 << 9;
		}
	}
}

/*! Enables TX and RX transmission/reception in the control register.
 *
 * @brief Enabling TX and RX transmission/reception is done by simply writing a '1' to bit 3 for TX and bit 2 for
 *        RX. The writes are done to an accumulated CR1 register value to gather all changes to the register over
 *        multiple USART channel initialization sub-functions before making one, final write to the actual
 *        register.
 *
 * @param accum_CR1_val
 *    (input) An accumulator of writes for the CR1 register.
 */
static void _USART_init_channel_enable_TX_RX(uint32_t * const accum_CR1_val)
{
	*accum_CR1_val |= 0x1 << 3; //Enable TX
	*accum_CR1_val |= 0x1 << 2; //Enable RX
}

/*! Enables CTS and RTS signals in the control register.
 *
 * @brief Enabling CTS and RTS signaling is done by simply writing a '1' to bit 9 for CTS and bit 8 for RTS in the
 *        CR3 register. The writes are done an register accumulator.
 *
 * @param accum_CR3_val
 *    (input) An accumulator of writes for the CR3 register.
 */
static void _USART_init_channel_enable_CTS_RTS(uint32_t * const accum_CR3_val)
{
	*accum_CR3_val |= 0x1 << 9; //Enable CTS
	*accum_CR3_val |= 0x1 << 8; //Enable RTS
}

/*! Enables the USART channel.
 *
 * @brief Writes a '1' to the USART enable (UE) bit in the CR1 register. If this write is done without an
 *        accumulator it will reset the transmite enable (TE) and receive enable (RE) bits in the CR1 register.
 *
 * @param see _USART_init_channel_enable_TX_RX(). The parameters are the same.
 */
static void _USART_init_channel_enable_channel(uint32_t * const accum_CR1_val)
{
	*accum_CR1_val |= 0x1 << 13;
}

/* ============================================================================================================= */
/* Configuration/Initialization Functions                                                                        */
/* ============================================================================================================= */
/*! Configures and initializes a USART channel.
 *
 * @brief Read the comments on each of the sub-functions to determine its purpose in the initialization of the
 *        USART channel.
 */
void USART_init_channel(USART_channel const channel
	, USART_cnfg const cnfg
) {
	uint32_t accum_CR1_val = 0, accum_CR2_val = 0, accum_CR3_val = 0;
	uint32_t volatile * const USARTx_CR1_addr = _USART_compute_CR1_addr(channel);
	uint32_t volatile * const USARTx_CR2_addr = _USART_compute_CR2_addr(channel);
	uint32_t volatile * const USARTx_CR3_addr = _USART_compute_CR3_addr(channel);

	if (_USART_params_are_valid(channel, cnfg)) {
		_USART_init_channel_enable_clk(channel);
		_USART_init_channel_configure_TX_RX_pins(channel, cnfg);
		_USART_init_channel_set_baud_rate(channel, cnfg);
		_USART_init_channel_set_stop_bits(&accum_CR2_val, cnfg);
		_USART_init_channel_set_word_len(&accum_CR1_val, cnfg);
		_USART_init_channel_set_parity(&accum_CR1_val, cnfg);
		_USART_init_channel_enable_TX_RX(&accum_CR1_val);
		_USART_init_channel_enable_channel(&accum_CR1_val);

		if (cnfg.hw_flow_cntrl_en) {
			_USART_init_channel_configure_RTS_CTS_pins(channel, cnfg);
			_USART_init_channel_enable_CTS_RTS(&accum_CR3_val);
		} else {
			//No hardware flow control, do nothing
		}

		*USARTx_CR3_addr = accum_CR3_val; //Write the accumulated CR3 changes
		*USARTx_CR2_addr = accum_CR2_val; //Write the accumulated CR2 changes
		*USARTx_CR1_addr = accum_CR1_val; //Write the accumulated CR1 changes
	} else {
		//Invalid configuration parameter combination, do nothing
	}
}

/* ============================================================================================================= */
/* Write Functions                                                                                               */
/* ============================================================================================================= */
/*! Writes a byte to the USART channel
 *
 * @brief We have to read bit 12 from the CR1 register to determine if 9 or 8 bits are to be written (a value of
 *        '0' for this bit means 8 data bits, a value of '1' means 9 data bits).
 */
void USART_write_blocking(USART_channel const channel
	, uint32_t const val
) {
	uint32_t volatile * const USARTx_SR_addr = _USART_compute_SR_addr(channel);
	uint32_t volatile * const USARTx_DR_addr = _USART_compute_DR_addr(channel);
	uint32_t volatile * const USARTx_CR1_addr = _USART_compute_CR1_addr(channel);

	while (!(*USARTx_SR_addr & (0x1 << 7))); //Spin while transmit data register is not empty

	if (*USARTx_CR1_addr & (0x1 << 12)) {
		*USARTx_DR_addr = (val & 0x1FFU); //Write 9-bits of the desired write val
	} else {
		*USARTx_DR_addr = (val & 0xFFU); //Write 8-bits of the desired write val
	}
}

/* ============================================================================================================= */
/* Read Functions                                                                                                */
/* ============================================================================================================= */
/*! Reads a byte from the USART channel.
 *
 * @brief We have to read bit 12 from the CR1 register to determine if 9 or 8 bits are to be read (a value of
 *        '0' for this bit means 8 data bits, a value of '1' means 9 data bits).
 */
uint32_t USART_read_blocking(USART_channel const channel)
{
	uint32_t read_data = 0;
	uint32_t volatile * const USARTx_SR_addr = _USART_compute_SR_addr(channel);
	uint32_t volatile * const USARTx_DR_addr = _USART_compute_DR_addr(channel);
	uint32_t volatile * const USARTx_CR1_addr = _USART_compute_CR1_addr(channel);

	while (!(*USARTx_SR_addr & (0x1 << 5))); //Spin while read data register is empty

	if (*USARTx_CR1_addr & (0x1 << 12)) {
		read_data = *USARTx_DR_addr & 0x1FFU; //Read the incoming 9-bits of data
	} else {
		read_data = *USARTx_DR_addr & 0xFFU; //Read the incoming 8-bits of data
	}

	return read_data;
}

/* EOF */
