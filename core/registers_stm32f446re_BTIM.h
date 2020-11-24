#ifndef REGISTERS_STM32F446RE_BTIM_H
#define REGISTERS_STM32F446RE_BTIM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! Basic Timer Register Offsets
 */
#define BTIM_CR1_OFFSET  0x00UL /* (R/W) Control Register 1                                                      */
#define BTIM_CR2_OFFSET  0x04UL /* (R/W) Control Register 2                                                      */
#define BTIM_DIER_OFFSET 0x0CUL /* (R/W) DMA/Interrupt Enable Register                                           */
#define BTIM_SR_OFFSET   0x10UL /* (R/ ) Status Register                                                         */
#define BTIM_EGR_OFFSET  0x14UL /* ( /W) Event Generation Register                                               */
#define BTIM_CNT_OFFSET  0x24UL /* (R/W) Count Register                                                          */
#define BTIM_PSC_OFFSET  0x28UL /* (R/W) Prescaler Register                                                      */
#define BTIM_ARR_OFFSET  0x2CUL /* (R/W) Auto-Reload Register                                                    */

/*! Basic Timer Base Addresses
 */
#define TIM6_B_ADDR      0x40001000UL
#define TIM7_B_ADDR      0x40001000UL

/*! Timer 6 (BTIM1) Registers
 */
#define TIM6_CR1         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CR1_OFFSET))
#define TIM6_CR2         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CR2_OFFSET))
#define TIM6_DIER        *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_DIER_OFFSET))
#define TIM6_SR          *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_SR_OFFSET))
#define TIM6_EGR         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_EGR_OFFSET))
#define TIM6_CNT         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CNT_OFFSET))
#define TIM6_PSC         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_PSC_OFFSET))
#define TIM6_ARR         *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_ARR_OFFSET))

#define TIM7_CR1         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CR1_OFFSET))
#define TIM7_CR2         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CR2_OFFSET))
#define TIM7_DIER        *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_DIER_OFFSET))
#define TIM7_SR          *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_SR_OFFSET))
#define TIM7_EGR         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_EGR_OFFSET))
#define TIM7_CNT         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CNT_OFFSET))
#define TIM7_PSC         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_PSC_OFFSET))
#define TIM7_ARR         *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_ARR_OFFSET))

/*! Timer 7 (BTIM2) Registers
 */
#define TIM7_CR1            *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CR1_OFFSET))

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_STM32F446RE_BTIM_H */

/* EOF */
