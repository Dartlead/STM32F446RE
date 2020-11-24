#include <stdint.h>
#include <stdbool.h>

#ifndef USART_H
#define USART_H

/*! An enumeration of the USART channels offered by the system.
 */
typedef enum USART_channel {
	  USART_channel1 = 1
	, USART_channel2 = 2
	, USART_channel3 = 3
	, UART_channel4  = 4
	, UART_channel5  = 5
	, USART_channel6 = 6
} USART_channel;

/*! An enumeration of the USART channel's possible TX/RX pin configurations.
 */
typedef enum USART_pin_cnfg {
	  USART_pin_cnfg1
	, USART_pin_cnfg2
	, USART_pin_cnfg3
} USART_pin_cnfg;

/*! An enumeration of the different oversampling modes available.
 */
typedef enum USART_oversample_mode {
	  USART_oversample_8  = 1
	, USART_oversample_16 = 0 //default
} USART_oversample_mode;

/*! An enumeration of the different number of stop bits that can be used by the channel.
 */
typedef enum USART_stop_bits {
	  USART_1_stop   = 0
	, USART_0_5_stop = 1
	, USART_2_stop   = 2
	, USART_1_5_stop = 3
} USART_stop_bits;

/*! An enumeration of the different parity options provided by the channel.
 */
typedef enum USART_parity {
	  USART_parity_none
	, USART_parity_even
	, USART_parity_odd
} USART_parity;

/*! Configuration parameters for a USART channel. An explanation of each is found in USART_driver.txt.
 */
typedef struct USART_cnfg {
	bool IrDA_mode_en;
	bool smartcard_mode_en;
	bool LIN_mode_en;
	bool hw_flow_cntrl_en;
	USART_oversample_mode oversample_mode;
	USART_pin_cnfg pin_TX_RX;
	USART_pin_cnfg pin_CTS_RTS;
	USART_stop_bits num_stop_bits;
	USART_parity parity;
	uint32_t word_length;
	uint32_t baud_rate;
} USART_cnfg;

/* ============================================================================================================= */
/* Configuration/Initialization Functions                                                                        */
/* ============================================================================================================= */
/*! Configures and initializes a USART channel.
 *
 * @note  The pins used in the USART channel will be configured with a slow slew rate, push-pull, and with no
 *        pullup or pull-down resistors.
 *
 * @param channel
 *    (input) Which of the onboard USART channels to initialize.
 * @param cnfg
 *    (input) The configuration options for the channel.
 */
void USART_init_channel(USART_channel const channel
	, USART_cnfg const cnfg
);

/* ============================================================================================================= */
/* Write Functions                                                                                               */
/* ============================================================================================================= */
/*! Writes a byte or 9-bits (depending on word length) to the USART channel.
 *
 * @note  This call is blocking. It will continually spin until there is room for the outgoing data.
 * @note  The data gets sent out least significant bit first.
 *
 * @param channel
 *    (input) Which of the onboard USART channels to write to.
 * @param val
 *    (input) The byte to write. Even though the value is a 32-bit, the write value must be representable with 8
 *            bits.
 */
void USART_write_blocking(USART_channel const channel
	, uint32_t const val
);

/* ============================================================================================================= */
/* Read Functions                                                                                                */
/* ============================================================================================================= */
/*! Reads a byte or 9-bits (depending on word length) from the USART channel.
 *
 * @note  This call is blocking. It will continually spin until there is incoming data.
 *
 * @param channel
 *    (input) Which of the onboard USART channels to read from.
 * @return The 8-bit value read from the channel.
 */
uint32_t USART_read_blocking(USART_channel const channel);

#endif /* USART_H */

/* EOF */
