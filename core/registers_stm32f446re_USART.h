#ifndef REGISTERS_STM32F446RE_USART_H
#define REGISTERS_STM32F446RE_USART_H

#include <stdint.h>

/*! USART Register Offsets
 */
#define USART_SR_OFFSET   0x00U /* (R/W) Status Register                                                         */
#define USART_DR_OFFSET   0x04U /* (R/W) Data Register                                                           */
#define USART_BRR_OFFSET  0x08U /* (R/W) Baud Rate Register                                                      */
#define USART_CR1_OFFSET  0x0CU /* (R/W) Control Register 1                                                      */
#define USART_CR2_OFFSET  0x10U /* (R/W) Control Register 2                                                      */
#define USART_CR3_OFFSET  0x14U /* (R/W) Control Register 3                                                      */
#define USART_GTPR_OFFSET 0x18U /* (R/W) Guard Time and Prescalar Register                                       */

/*! USART Channel Base Addresses
 */
#define USART1_B_ADDR     0x40011000
#define USART2_B_ADDR     0x40004400
#define USART3_B_ADDR     0x40004800
#define UART4_B_ADDR      0x40004C00
#define UART5_B_ADDR      0x40005000
#define USART6_B_ADDR     0x40011400

/*! USART Channel 1 Registers
 */
#define USART1_SR         *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_SR_OFFSET  ))
#define USART1_DR         *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_DR_OFFSET  ))
#define USART1_BRR        *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_BRR_OFFSET ))
#define USART1_CR1        *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR1_OFFSET ))
#define USART1_CR2        *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR2_OFFSET ))
#define USART1_CR3        *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR3_OFFSET ))
#define USART1_GTPR       *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_GTPR_OFFSET))

/*! USART Channel 2 Registers
 */
#define USART2_SR         *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_SR_OFFSET  ))
#define USART2_DR         *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_DR_OFFSET  ))
#define USART2_BRR        *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_BRR_OFFSET ))
#define USART2_CR1        *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR1_OFFSET ))
#define USART2_CR2        *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR2_OFFSET ))
#define USART2_CR3        *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR3_OFFSET ))
#define USART2_GTPR       *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_GTPR_OFFSET))

/*! USART Channel 3 Registers
 */
#define USART3_SR         *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_SR_OFFSET  ))
#define USART3_DR         *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_DR_OFFSET  ))
#define USART3_BRR        *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_BRR_OFFSET ))
#define USART3_CR1        *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR1_OFFSET ))
#define USART3_CR2        *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR2_OFFSET ))
#define USART3_CR3        *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR3_OFFSET ))
#define USART3_GTPR       *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_GTPR_OFFSET))

/*! UART Channel 4 Registers
 */
#define UART4_SR          *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_SR_OFFSET  ))
#define UART4_DR          *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_DR_OFFSET  ))
#define UART4_BRR         *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_BRR_OFFSET ))
#define UART4_CR1         *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR1_OFFSET ))
#define UART4_CR2         *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR2_OFFSET ))
#define UART4_CR3         *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR3_OFFSET ))
#define UART4_GTPR        *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_GTPR_OFFSET))

/*! UART Channel 5 Registers
 */
#define UART5_SR          *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_SR_OFFSET  ))
#define UART5_DR          *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_DR_OFFSET  ))
#define UART5_BRR         *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_BRR_OFFSET ))
#define UART5_CR1         *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR1_OFFSET ))
#define UART5_CR2         *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR2_OFFSET ))
#define UART5_CR3         *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR3_OFFSET ))
#define UART5_GTPR        *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_GTPR_OFFSET))

/*! USART Channel 6 Registers
 */
#define USART6_SR         *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_SR_OFFSET  ))
#define USART6_DR         *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_DR_OFFSET  ))
#define USART6_BRR        *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_BRR_OFFSET ))
#define USART6_CR1        *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR1_OFFSET ))
#define USART6_CR2        *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR2_OFFSET ))
#define USART6_CR3        *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR3_OFFSET ))
#define USART6_GTPR       *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_GTPR_OFFSET))

#endif /* REGISTERS_STM32F446RE_USART_H */

/* EOF */
