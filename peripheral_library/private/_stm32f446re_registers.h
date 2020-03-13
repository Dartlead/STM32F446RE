#include <stdint.h>

#ifndef _STM32F446RE_REGISTERS_H
#define _STM32F446RE_REGISTERS_H
/* ============================================================================================================= */
/* Basic Timers Registers (BTIM)                                                                                 */
/* Address Ranges:                                                                                               */
/* TIM6: 0x4000 1000 - 0x4000 13FF                                                                               */
/* TIM7: 0x4000 1400 - 0x4000 17FF                                                                               */
/* ============================================================================================================= */
#define BTIM_CR1_OFFSET  0x00U /* Offset: 0x00 (R/W) Control Register 1            */
#define BTIM_CR2_OFFSET  0x04U /* Offset: 0x04 (R/W) Control Register 2            */
#define BTIM_DIER_OFFSET 0x0CU /* Offset: 0x0C (R/W) DMA/Interrupt Enable Register */
#define BTIM_SR_OFFSET   0x10U /* Offset: 0x10 (R/ ) Status Register               */
#define BTIM_EGR_OFFSET  0x14U /* Offset: 0x14 ( /W) Event Generation Register     */
#define BTIM_CNT_OFFSET  0x24U /* Offset: 0x24 (R/W) Count Register                */
#define BTIM_PSC_OFFSET  0x28U /* Offset: 0x28 (R/W) Prescalar Register            */
#define BTIM_ARR_OFFSET  0x2CU /* Offset: 0x2C (R/W) Auto-Reload Register          */

#define TIM6_B_ADDR 0x40001000
#define TIM7_B_ADDR 0x40001400

#define TIM6_CR1  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CR1_OFFSET))
#define TIM6_CR2  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CR2_OFFSET))
#define TIM6_DIER *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_DIER_OFFSET))
#define TIM6_SR   *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_SR_OFFSET))
#define TIM6_EGR  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_EGR_OFFSET))
#define TIM6_CNT  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_CNT_OFFSET))
#define TIM6_PSC  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_PSC_OFFSET))
#define TIM6_ARR  *((uint32_t volatile *)((uint8_t *)TIM6_B_ADDR + BTIM_ARR_OFFSET))

#define TIM7_CR1  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CR1_OFFSET))
#define TIM7_CR2  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CR2_OFFSET))
#define TIM7_DIER *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_DIER_OFFSET))
#define TIM7_SR   *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_SR_OFFSET))
#define TIM7_EGR  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_EGR_OFFSET))
#define TIM7_CNT  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_CNT_OFFSET))
#define TIM7_PSC  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_PSC_OFFSET))
#define TIM7_ARR  *((uint32_t volatile *)((uint8_t *)TIM7_B_ADDR + BTIM_ARR_OFFSET))

/* ============================================================================================================= */
/* Universal Synchronous/Asynchronous Receiver Transmitter Channels 1 - 6 Registers (USART)                      */
/* Address Ranges:                                                                                               */
/* USART1: 0x4001 1000 - 0x4001 13FF                                                                             */
/* USART2: 0x4000 4400 - 0x4000 47FF                                                                             */
/* USART3: 0x4000 4800 - 0x4000 4BFF                                                                             */
/* UART4:  0x4000 4C00 - 0x4000 4FFF                                                                             */
/* UART5:  0x4000 5000 - 0x4000 53FF                                                                             */
/* USART6: 0x4001 1400 - 0x4001 17FF                                                                             */
/* ============================================================================================================= */
#define USART_SR_OFFSET   0x00U /* Offset: 0x00 (R/W) Status Register                   */
#define USART_DR_OFFSET   0x04U /* Offset: 0x04 (R/W) Data Register                     */
#define USART_BRR_OFFSET  0x08U /* Offset: 0x08 (R/W) Baud Rate Register                */
#define USART_CR1_OFFSET  0x0CU /* Offset: 0x0C (R/W) Control Register 1                */
#define USART_CR2_OFFSET  0x10U /* Offset: 0x10 (R/W) Control Register 2                */
#define USART_CR3_OFFSET  0x14U /* Offset: 0x14 (R/W) Control Register 3                */
#define USART_GTPR_OFFSET 0x18U /* Offset: 0x18 (R/W) Guard Time and Prescalar Register */

#define USART1_B_ADDR 0x40011000
#define USART2_B_ADDR 0x40004400
#define USART3_B_ADDR 0x40004800
#define UART4_B_ADDR  0x40004C00
#define UART5_B_ADDR  0x40005000
#define USART6_B_ADDR 0x40011400

#define USART1_SR   *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_SR_OFFSET))
#define USART1_DR   *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_DR_OFFSET))
#define USART1_BRR  *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_BRR_OFFSET))
#define USART1_CR1  *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR1_OFFSET))
#define USART1_CR2  *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR2_OFFSET))
#define USART1_CR3  *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_CR3_OFFSET))
#define USART1_GTPR *((uint32_t volatile *)((uint8_t *)USART1_B_ADDR + USART_GTPR_OFFSET))

#define USART2_SR   *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_SR_OFFSET))
#define USART2_DR   *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_DR_OFFSET))
#define USART2_BRR  *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_BRR_OFFSET))
#define USART2_CR1  *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR1_OFFSET))
#define USART2_CR2  *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR2_OFFSET))
#define USART2_CR3  *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_CR3_OFFSET))
#define USART2_GTPR *((uint32_t volatile *)((uint8_t *)USART2_B_ADDR + USART_GTPR_OFFSET))

#define USART3_SR   *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_SR_OFFSET))
#define USART3_DR   *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_DR_OFFSET))
#define USART3_BRR  *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_BRR_OFFSET))
#define USART3_CR1  *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR1_OFFSET))
#define USART3_CR2  *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR2_OFFSET))
#define USART3_CR3  *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_CR3_OFFSET))
#define USART3_GTPR *((uint32_t volatile *)((uint8_t *)USART3_B_ADDR + USART_GTPR_OFFSET))

#define UART4_SR    *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_SR_OFFSET))
#define UART4_DR    *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_DR_OFFSET))
#define UART4_BRR   *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_BRR_OFFSET))
#define UART4_CR1   *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR1_OFFSET))
#define UART4_CR2   *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR2_OFFSET))
#define UART4_CR3   *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_CR3_OFFSET))
#define UART4_GTPR  *((uint32_t volatile *)((uint8_t *)UART4_B_ADDR + USART_GTPR_OFFSET))

#define UART5_SR    *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_SR_OFFSET))
#define UART5_DR    *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_DR_OFFSET))
#define UART5_BRR   *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_BRR_OFFSET))
#define UART5_CR1   *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR1_OFFSET))
#define UART5_CR2   *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR2_OFFSET))
#define UART5_CR3   *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_CR3_OFFSET))
#define UART5_GTPR  *((uint32_t volatile *)((uint8_t *)UART5_B_ADDR + USART_GTPR_OFFSET))

#define USART6_SR   *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_SR_OFFSET))
#define USART6_DR   *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_DR_OFFSET))
#define USART6_BRR  *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_BRR_OFFSET))
#define USART6_CR1  *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR1_OFFSET))
#define USART6_CR2  *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR2_OFFSET))
#define USART6_CR3  *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_CR3_OFFSET))
#define USART6_GTPR *((uint32_t volatile *)((uint8_t *)USART6_B_ADDR + USART_GTPR_OFFSET))

/* ============================================================================================================= */
/* System Configuration Registers (SYSCFG)                                                                       */
/* Address Range: 0x4001 3800 - 0x4001 3BFF                                                                      */
/* ============================================================================================================= */
#define SYSCFG_MEMRMP_OFFSET  0x00U /* Offset: 0x00 (R/W) Memory Remap Register                       */
#define SYSCFG_PMC_OFFSET     0x04U /* Offset: 0x04 (R/W) Peripheral Mode Configuration Register      */
#define SYSCFG_EXTICR1_OFFSET 0x08U /* Offset: 0x08 (R/W) External Interrupt Configuration Register 1 */
#define SYSCFG_EXTICR2_OFFSET 0x0CU /* Offset: 0x0C (R/W) External Interrupt Configuration Register 2 */
#define SYSCFG_EXTICR3_OFFSET 0x10U /* Offset: 0x10 (R/W) External Interrupt Configuration Register 3 */
#define SYSCFG_EXTICR4_OFFSET 0x14U /* Offset: 0x14 (R/W) External Interrupt Configuration Register 4 */
#define SYSCFG_CMPCR_OFFSET   0x20U /* Offset: 0x20 (R/W) Compensation Cell Control Register          */
#define SYSCFG_CFGR_OFFSET    0x2CU /* Offset: 0x2C (R/W) Configuration Register                      */

#define SYSCFG_B_ADDR 0x40013800

#define SYSCFG_MEMRMP  *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_MEMRMP_OFFSET))
#define SYSCFG_PMC     *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_PMC_OFFSET))
#define SYSCFG_EXTICR1 *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_EXTICR1_OFFSET))
#define SYSCFG_EXTICR2 *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_EXTICR2_OFFSET))
#define SYSCFG_EXTICR3 *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_EXTICR3_OFFSET))
#define SYSCFG_EXTICR4 *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_EXTICR4_OFFSET))
#define SYSCFG_CMPCR   *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_CMPCR_OFFSET))
#define SYSCFG_CFGR    *((uint32_t volatile *)((uint8_t *)SYSCFG_B_ADDR + SYSCFG_CFGR_OFFSET))

/* ============================================================================================================= */
/* External Interrupt Controller Registers (EXTI)                                                                */
/* Address Range: 0x4001 3C00 - 0x4001 3FFF                                                                      */
/* ============================================================================================================= */
#define EXTI_IMR_OFFSET   0x00U /* Offset: 0x00 (R/W) Interrupt Mask Register            */
#define EXTI_EMR_OFFSET   0x04U /* Offset: 0x04 (R/W) Event Mask Register                */
#define EXTI_RTSR_OFFSET  0x08U /* Offset: 0x08 (R/W) Rising Trigger Selection Register  */
#define EXTI_FTSR_OFFSET  0x0CU /* Offset: 0x0C (R/W) Falling Trigger Selection Register */
#define EXTI_SWIER_OFFSET 0x10U /* Offset: 0x10 (R/W) Software Interrupt Event Register  */
#define EXTI_PR_OFFSET    0x14U /* Offset: 0x14 (R/W) Pending Register                   */

#define EXTI_B_ADDR 0x40013C00

#define EXTI_IMR   *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_IMR_OFFSET))
#define EXTI_EMR   *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_EMR_OFFSET))
#define EXTI_RTSR  *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_RTSR_OFFSET))
#define EXTI_FTSR  *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_FTSR_OFFSET))
#define EXTI_SWIER *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_SWIER_OFFSET))
#define EXTI_PR    *((uint32_t volatile *)((uint8_t *)EXTI_B_ADDR + EXTI_PR_OFFSET))

/* ============================================================================================================= */
/* General Purpose Input Output Registers (GPIO)                                                                 */
/* Address Range: 0x4002 0000 - 0x4002 1FFF                                                                      */
/* ============================================================================================================= */
#define GPIO_MODER_OFFSET   0x00U /* Offset: 0x00 (R/W) Mode Register                    */
#define GPIO_OTYPER_OFFSET  0x04U /* Offset: 0x04 (R/W) Output Type Register             */
#define GPIO_OSPEEDR_OFFSET 0x08U /* Offset: 0x08 (R/W) Output Speed Register            */
#define GPIO_PUPDR_OFFSET   0x0CU /* Offset: 0x0C (R/W) Pull-up/Pull-down Register       */
#define GPIO_IDR_OFFSET     0x10U /* Offset: 0x10 (R/W) Input Data Register              */
#define GPIO_ODR_OFFSET     0x14U /* Offset: 0x14 (R/W) Output Data Register             */
#define GPIO_BSRR_OFFSET    0x18U /* Offset: 0x18 (R/W) Bit Set/Reset Register           */
#define GPIO_LCKR_OFFSET    0x1CU /* Offset: 0x1C (R/W) Configuration Lock Register      */
#define GPIO_AFRL_OFFSET    0x20U /* Offset: 0x20 (R/W) Alternate Function Low Register  */
#define GPIO_AFRH_OFFSET    0x24U /* Offset: 0x24 (R/W) Alternate Function High Register */

#define GPIOA_B_ADDR 0x40020000
#define GPIOB_B_ADDR 0x40020400
#define GPIOC_B_ADDR 0x40020800
#define GPIOD_B_ADDR 0x40020C00
#define GPIOE_B_ADDR 0x40021000
#define GPIOF_B_ADDR 0x40021400
#define GPIOG_B_ADDR 0x40021800
#define GPIOH_B_ADDR 0x40021C00

#define GPIOA_MODER   *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOA_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOA_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOA_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOA_IDR     *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOA_ODR     *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOA_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOA_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOA_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOA_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOB_MODER   *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOB_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOB_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOB_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOB_IDR     *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOB_ODR     *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOB_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOB_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOB_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOB_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOC_MODER   *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOC_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOC_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOC_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOC_IDR     *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOC_ODR     *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOC_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOC_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOC_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOC_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOD_MODER   *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOD_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOD_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOD_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOD_IDR     *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOD_ODR     *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOD_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOD_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOD_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOD_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOE_MODER   *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOE_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOE_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOE_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOE_IDR     *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOE_ODR     *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOE_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOE_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOE_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOE_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOF_MODER   *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOF_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOF_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOF_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOF_IDR     *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOF_ODR     *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOF_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOF_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOF_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOF_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOG_MODER   *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOG_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOG_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOG_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOG_IDR     *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOG_ODR     *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOG_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOG_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOG_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOG_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_AFRH_OFFSET))

#define GPIOH_MODER   *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_MODER_OFFSET))
#define GPIOH_OTYPER  *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOH_OSPEEDR *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOH_PUPDR   *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOH_IDR     *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_IDR_OFFSET))
#define GPIOH_ODR     *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_ODR_OFFSET))
#define GPIOH_BSRR    *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_BSRR_OFFSET))
#define GPIOH_LCKR    *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_LCKR_OFFSET))
#define GPIOH_AFRL    *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_AFRL_OFFSET))
#define GPIOH_AFRH    *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_AFRH_OFFSET))

/* ============================================================================================================= */
/* Reset and Clock Control Registers (RCC)                                                                       */
/* Address Range: 0x4002 3800 - 0x4002 3BFF                                                                      */
/* ============================================================================================================= */
#define RCC_CR_OFFSET         0x00U /* Offset: 0x00 (R/W) Clock Control Register                                 */
#define RCC_PLLCFGR_OFFSET    0x04U /* Offset: 0x04 (R/W) PLL Configuration Register                             */
#define RCC_CFGR_OFFSET       0x08U /* Offset: 0x08 (R/W) Clock Configuration Register                           */
#define RCC_CIR_OFFSET        0x0CU /* Offset: 0x0C (R/W) Clock Interrupt Register                               */
#define RCC_AHB1RSTR_OFFSET   0x10U /* Offset: 0x10 (R/W) AHB1 Peripheral Reset Register                         */
#define RCC_AHB2RSTR_OFFSET   0x14U /* Offset: 0x14 (R/W) AHB2 Peripheral Reset Register                         */
#define RCC_AHB3RSTR_OFFSET   0x18U /* Offset: 0x18 (R/W) AHB3 Peripheral Reset Register                         */
#define RCC_APB1RSTR_OFFSET   0x20U /* Offset: 0x20 (R/W) APB1 Peripheral Reset Register                         */
#define RCC_APB2RSTR_OFFSET   0x24U /* Offset: 0x24 (R/W) APB2 Peripheral Reset Register                         */
#define RCC_AHB1ENR_OFFSET    0x30U /* Offset: 0x30 (R/W) AHB1 Peripheral Clock Enable Register                  */
#define RCC_AHB2ENR_OFFSET    0x34U /* Offset: 0x34 (R/W) AHB2 Peripheral Clock Enable Register                  */
#define RCC_AHB3ENR_OFFSET    0x38U /* Offset: 0x38 (R/W) AHB3 Peripheral Clock Enable Register                  */
#define RCC_APB1ENR_OFFSET    0x40U /* Offset: 0x40 (R/W) APB1 Peripheral Clock Enable Register                  */
#define RCC_APB2ENR_OFFSET    0x44U /* Offset: 0x44 (R/W) APB1 Peripheral Clock Enable Register                  */
#define RCC_AHB1LPENR_OFFSET  0x50U /* Offset: 0x50 (R/W) AHB1 Peripheral Clock Enable Lower Power Mode Register */
#define RCC_AHB2LPENR_OFFSET  0x54U /* Offset: 0x54 (R/W) AHB2 Peripheral Clock Enable Lower Power Mode Register */
#define RCC_AHB3LPENR_OFFSET  0x58U /* Offset: 0x58 (R/W) AHB3 Peripheral Clock Enable Lower Power Mode Register */
#define RCC_APB1LPENR_OFFSET  0x60U /* Offset: 0x60 (R/W) APB1 Peripheral Clock Enable Lower Power Mode Register */
#define RCC_APB2LPENR_OFFSET  0x64U /* Offset: 0x64 (R/W) APB2 Peripheral Clock Enable Lower Power Mode Register */
#define RCC_BDCR_OFFSET       0x70U /* Offset: 0x70 (R/W) Backup Domain Control Register                         */
#define RCC_CSR_OFFSET        0x74U /* Offset: 0x74 (R/W) Clock Control & Status Register                        */
#define RCC_SSCGR_OFFSET      0x80U /* Offset: 0x80 (R/W) Spread Spectrum Clock Generation Register              */
#define RCC_PLLI2SCFGR_OFFSET 0x84U /* Offset: 0x84 (R/W) PLLI2S Configuration Register                          */
#define RCC_PLLSAICFGR_OFFSET 0x88U /* Offset: 0x88 (R/W) PLLSAI Configuration Register                          */
#define RCC_DCKCFGR_OFFSET    0x8CU /* Offset: 0x8C (R/W) Dedicated Clocks Configuration Register                */
#define RCC_CKGATENR_OFFSET   0x90U /* Offset: 0x90 (R/W) Clocks Gated Enabled Register                          */
#define RCC_DCKCFGR2_OFFSET   0x94U /* Offset: 0x94 (R/W) Dedicated Clocks Configuration Register 2              */

#define RCC_B_ADDR 0x40023800

#define RCC_CR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CR_OFFSET))
#define RCC_PLLCFGR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLCFGR_OFFSET))
#define RCC_CFGR       *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CFGR_OFFSET))
#define RCC_CIR        *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CIR_OFFSET))
#define RCC_AHB1RSTR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1RSTR_OFFSET))
#define RCC_AHB2RSTR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2RSTR_OFFSET))
#define RCC_AHB3RSTR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3RSTR_OFFSET))
#define RCC_APB1RSTR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1RSTR_OFFSET))
#define RCC_APB2RSTR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2RSTR_OFFSET))
#define RCC_AHB1ENR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1ENR_OFFSET))
#define RCC_AHB2ENR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2ENR_OFFSET))
#define RCC_AHB3ENR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3ENR_OFFSET))
#define RCC_APB1ENR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1ENR_OFFSET))
#define RCC_APB2ENR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2ENR_OFFSET))
#define RCC_AHB1LPENR  *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1LPENR_OFFSET))
#define RCC_AHB2LPENR  *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2LPENR_OFFSET))
#define RCC_AHB3LPENR  *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3LPENR_OFFSET))
#define RCC_APB1LPENR  *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1LPENR_OFFSET))
#define RCC_APB2LPENR  *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2LPENR_OFFSET))
#define RCC_BDCR       *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_BDCR_OFFSET))
#define RCC_CSR        *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CSR_OFFSET))
#define RCC_SSCGR      *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_SSCGR_OFFSET))
#define RCC_PLLI2SCFGR *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLI2SCFGR_OFFSET))
#define RCC_PLLSAICFGR *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLSAICFGR_OFFSET))
#define RCC_DCKCFGR    *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_DCKCFGR_OFFSET))
#define RCC_CKGATENR   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CKGATENR_OFFSET))
#define RCC_DCKCFGR2   *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_DCKCFGR2_OFFSET))

/* ============================================================================================================= */
/* Direct Memory Access Controller Registers (DMA)                                                               */
/* Address Range:                                                                                                */
/* DMA1: 0x4002 6000 - 0x4002 63FF                                                                               */
/* DMA2: 0x4002 6400 - 0x4002 67FF                                                                               */
/* ============================================================================================================= */
#define DMA_LISR_OFFSET   0x00U /* Offset: 0x00 (R/ ) Low Interrupt Status Register        */
#define DMA_HISR_OFFSET   0x04U /* Offset: 0x04 (R/ ) High Interrupt Status Register       */
#define DMA_LIFCR_OFFSET  0x08U /* Offset: 0x08 ( /W) Low Interrupt Flag Clear Register    */
#define DMA_HIFCR_OFFSET  0x0CU /* Offset: 0x0C ( /W) High Interrupt Flag Clear Register   */
#define DMA_S0CR_OFFSET   0x10U /* Offset: 0x10 (R/W) Stream 0 Configuration Register      */
#define DMA_S0NDTR_OFFSET 0x14U /* Offset: 0x14 (R/W) Stream 0 Number of Data Register     */
#define DMA_S0PAR_OFFSET  0x18U /* Offset: 0x18 (R/W) Stream 0 Peripheral Address Register */
#define DMA_S0M0AR_OFFSET 0x1CU /* Offset: 0x1C (R/W) Stream 0 Memory 0 Address Register   */
#define DMA_S0M1AR_OFFSET 0x20U /* Offset: 0x20 (R/W) Stream 0 Memory 1 Address Register   */
#define DMA_S0FCR_OFFSET  0x24U /* Offset: 0x24 (R/W) Stream 0 FIFO Control Register       */
#define DMA_S1CR_OFFSET   0x28U /* Offset: 0x28 (R/W) Stream 1 Configuration Register      */
#define DMA_S1NDTR_OFFSET 0x2CU /* Offset: 0x2C (R/W) Stream 1 Number of Data Register     */
#define DMA_S1PAR_OFFSET  0x30U /* Offset: 0x30 (R/W) Stream 1 Peripheral Address Register */
#define DMA_S1M0AR_OFFSET 0x34U /* Offset: 0x34 (R/W) Stream 1 Memory 0 Address Register   */
#define DMA_S1M1AR_OFFSET 0x38U /* Offset: 0x38 (R/W) Stream 1 Memory 1 Address Register   */
#define DMA_S1FCR_OFFSET  0x3CU /* Offset: 0x3C (R/W) Stream 1 FIFO Control Register       */
#define DMA_S2CR_OFFSET   0x40U /* Offset: 0x40 (R/W) Stream 2 Configuration Register      */
#define DMA_S2NDTR_OFFSET 0x44U /* Offset: 0x44 (R/W) Stream 2 Number of Data Register     */
#define DMA_S2PAR_OFFSET  0x48U /* Offset: 0x48 (R/W) Stream 2 Peripheral Address Register */
#define DMA_S2M0AR_OFFSET 0x4CU /* Offset: 0x4C (R/W) Stream 2 Memory 0 Address Register   */
#define DMA_S2M1AR_OFFSET 0x50U /* Offset: 0x50 (R/W) Stream 2 Memory 1 Address Register   */
#define DMA_S2FCR_OFFSET  0x54U /* Offset: 0x54 (R/W) Stream 2 FIFO Control Register       */
#define DMA_S3CR_OFFSET   0x58U /* Offset: 0x58 (R/W) Stream 3 Configuration Register      */
#define DMA_S3NDTR_OFFSET 0x5CU /* Offset: 0x5C (R/W) Stream 3 Number of Data Register     */
#define DMA_S3PAR_OFFSET  0x60U /* Offset: 0x60 (R/W) Stream 3 Peripheral Address Register */
#define DMA_S3M0AR_OFFSET 0x64U /* Offset: 0x64 (R/W) Stream 3 Memory 0 Address Register   */
#define DMA_S3M1AR_OFFSET 0x68U /* Offset: 0x68 (R/W) Stream 3 Memory 0 Address Register   */
#define DMA_S3FCR_OFFSET  0x6CU /* Offset: 0x6C (R/W) Stream 3 FIFO Control Register       */
#define DMA_S4CR_OFFSET   0x70U /* Offset: 0x70 (R/W) Stream 4 Configuration Register      */
#define DMA_S4NDTR_OFFSET 0x74U /* Offset: 0x74 (R/W) Stream 4 Number of Data Register     */
#define DMA_S4PAR_OFFSET  0x78U /* Offset: 0x78 (R/W) Stream 4 Peripheral Address Register */
#define DMA_S4M0AR_OFFSET 0x7CU /* Offset: 0x7C (R/W) Stream 4 Memory 0 Address Register   */
#define DMA_S4M1AR_OFFSET 0x80U /* Offset: 0x80 (R/W) Stream 4 Memory 1 Address Register   */
#define DMA_S4FCR_OFFSET  0x84U /* Offset: 0x84 (R/W) Stream 4 FIFO Control Register       */
#define DMA_S5CR_OFFSET   0x88U /* Offset: 0x88 (R/W) Stream 5 Configuration Register      */
#define DMA_S5NDTR_OFFSET 0x8CU /* Offset: 0x8C (R/W) Stream 5 Number of Data Register     */
#define DMA_S5PAR_OFFSET  0x90U /* Offset: 0x90 (R/W) Stream 5 Peripheral Address Register */
#define DMA_S5M0AR_OFFSET 0x94U /* Offset: 0x94 (R/W) Stream 5 Memory 0 Address Register   */
#define DMA_S5M1AR_OFFSET 0x98U /* Offset: 0x98 (R/W) Stream 5 Memory 1 Address Register   */
#define DMA_S5FCR_OFFSET  0x9CU /* Offset: 0x9C (R/W) Stream 5 FIFO Control Register       */
#define DMA_S6CR_OFFSET   0xA0U /* Offset: 0xA0 (R/W) Stream 6 Configuration Register      */
#define DMA_S6NDTR_OFFSET 0xA4U /* Offset: 0xA4 (R/W) Stream 6 Number of Data Register     */
#define DMA_S6PAR_OFFSET  0xA8U /* Offset: 0xA8 (R/W) Stream 6 Peripheral Address Register */
#define DMA_S6M0AR_OFFSET 0xACU /* Offset: 0xAC (R/W) Stream 6 Memory 0 Address Register   */
#define DMA_S6M1AR_OFFSET 0xB0U /* Offset: 0xB0 (R/W) Stream 6 Memory 1 Address Register   */
#define DMA_S6FCR_OFFSET  0xB4U /* Offset: 0xB4 (R/W) Stream 6 FIFO Control Register       */
#define DMA_S7CR_OFFSET   0xB8U /* Offset: 0xB8 (R/W) Stream 7 Configuration Register      */
#define DMA_S7NDTR_OFFSET 0xBCU /* Offset: 0xBC (R/W) Stream 7 Number of Data Register     */
#define DMA_S7PAR_OFFSET  0xC0U /* Offset: 0xC0 (R/W) Stream 7 Peripheral Address Register */
#define DMA_S7M0AR_OFFSET 0xC4U /* Offset: 0xC4 (R/W) Stream 7 Memory 0 Address Register   */
#define DMA_S7M1AR_OFFSET 0xC8U /* Offset: 0xC8 (R/W) Stream 7 Memory 1 Address Register   */
#define DMA_S7FCR_OFFSET  0xCCU /* Offset: 0xCC (R/W) Stream 7 FIFO Control Register       */

#define DMA1_B_ADDR 0x40026000
#define DMA2_B_ADDR 0x40026400

#define DMA1_LISR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_LISR_OFFSET))
#define DMA1_HISR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_HISR_OFFSET))
#define DMA1_LIFCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_LIFCR_OFFSET))
#define DMA1_HIFCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_HIFCR_OFFSET))
#define DMA1_S0CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0CR_OFFSET))
#define DMA1_S0NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0NDTR_OFFSET))
#define DMA1_S0PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0PAR_OFFSET))
#define DMA1_S0M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0M0AR_OFFSET))
#define DMA1_S0M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0M1AR_OFFSET))
#define DMA1_S0FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0FCR_OFFSET))
#define DMA1_S1CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1CR_OFFSET))
#define DMA1_S1NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1NDTR_OFFSET))
#define DMA1_S1PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1PAR_OFFSET))
#define DMA1_S1M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1M0AR_OFFSET))
#define DMA1_S1M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1M1AR_OFFSET))
#define DMA1_S1FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1FCR_OFFSET))
#define DMA1_S2CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2CR_OFFSET))
#define DMA1_S2NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2NDTR_OFFSET))
#define DMA1_S2PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2PAR_OFFSET))
#define DMA1_S2M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2M0AR_OFFSET))
#define DMA1_S2M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2M1AR_OFFSET))
#define DMA1_S2FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2FCR_OFFSET))
#define DMA1_S3CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3CR_OFFSET))
#define DMA1_S3NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3NDTR_OFFSET))
#define DMA1_S3PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3PAR_OFFSET))
#define DMA1_S3M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3M0AR_OFFSET))
#define DMA1_S3M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3M1AR_OFFSET))
#define DMA1_S3FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3FCR_OFFSET))
#define DMA1_S4CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4CR_OFFSET))
#define DMA1_S4NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4NDTR_OFFSET))
#define DMA1_S4PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4PAR_OFFSET))
#define DMA1_S4M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4M0AR_OFFSET))
#define DMA1_S4M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4M1AR_OFFSET))
#define DMA1_S4FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4FCR_OFFSET))
#define DMA1_S5CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5CR_OFFSET))
#define DMA1_S5NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5NDTR_OFFSET))
#define DMA1_S5PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5PAR_OFFSET))
#define DMA1_S5M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5M0AR_OFFSET))
#define DMA1_S5M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5M1AR_OFFSET))
#define DMA1_S5FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5FCR_OFFSET))
#define DMA1_S6CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6CR_OFFSET))
#define DMA1_S6NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6NDTR_OFFSET))
#define DMA1_S6PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6PAR_OFFSET))
#define DMA1_S6M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6M0AR_OFFSET))
#define DMA1_S6M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6M1AR_OFFSET))
#define DMA1_S6FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6FCR_OFFSET))
#define DMA1_S7CR   *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7CR_OFFSET))
#define DMA1_S7NDTR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7NDTR_OFFSET))
#define DMA1_S7PAR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7PAR_OFFSET))
#define DMA1_S7M0AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7M0AR_OFFSET))
#define DMA1_S7M1AR *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7M1AR_OFFSET))
#define DMA1_S7FCR  *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7FCR_OFFSET))

#define DMA2_LISR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_LISR_OFFSET))
#define DMA2_HISR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_HISR_OFFSET))
#define DMA2_LIFCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_LIFCR_OFFSET))
#define DMA2_HIFCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_HIFCR_OFFSET))
#define DMA2_S0CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0CR_OFFSET))
#define DMA2_S0NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0NDTR_OFFSET))
#define DMA2_S0PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0PAR_OFFSET))
#define DMA2_S0M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0M0AR_OFFSET))
#define DMA2_S0M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0M1AR_OFFSET))
#define DMA2_S0FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0FCR_OFFSET))
#define DMA2_S1CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1CR_OFFSET))
#define DMA2_S1NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1NDTR_OFFSET))
#define DMA2_S1PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1PAR_OFFSET))
#define DMA2_S1M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1M0AR_OFFSET))
#define DMA2_S1M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1M1AR_OFFSET))
#define DMA2_S1FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1FCR_OFFSET))
#define DMA2_S2CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2CR_OFFSET))
#define DMA2_S2NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2NDTR_OFFSET))
#define DMA2_S2PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2PAR_OFFSET))
#define DMA2_S2M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2M0AR_OFFSET))
#define DMA2_S2M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2M1AR_OFFSET))
#define DMA2_S2FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2FCR_OFFSET))
#define DMA2_S3CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3CR_OFFSET))
#define DMA2_S3NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3NDTR_OFFSET))
#define DMA2_S3PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3PAR_OFFSET))
#define DMA2_S3M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3M0AR_OFFSET))
#define DMA2_S3M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3M1AR_OFFSET))
#define DMA2_S3FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3FCR_OFFSET))
#define DMA2_S4CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4CR_OFFSET))
#define DMA2_S4NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4NDTR_OFFSET))
#define DMA2_S4PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4PAR_OFFSET))
#define DMA2_S4M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4M0AR_OFFSET))
#define DMA2_S4M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4M1AR_OFFSET))
#define DMA2_S4FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4FCR_OFFSET))
#define DMA2_S5CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5CR_OFFSET))
#define DMA2_S5NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5NDTR_OFFSET))
#define DMA2_S5PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5PAR_OFFSET))
#define DMA2_S5M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5M0AR_OFFSET))
#define DMA2_S5M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5M1AR_OFFSET))
#define DMA2_S5FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5FCR_OFFSET))
#define DMA2_S6CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6CR_OFFSET))
#define DMA2_S6NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6NDTR_OFFSET))
#define DMA2_S6PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6PAR_OFFSET))
#define DMA2_S6M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6M0AR_OFFSET))
#define DMA2_S6M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6M1AR_OFFSET))
#define DMA2_S6FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6FCR_OFFSET))
#define DMA2_S7CR   *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7CR_OFFSET))
#define DMA2_S7NDTR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7NDTR_OFFSET))
#define DMA2_S7PAR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7PAR_OFFSET))
#define DMA2_S7M0AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7M0AR_OFFSET))
#define DMA2_S7M1AR *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7M1AR_OFFSET))
#define DMA2_S7FCR  *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7FCR_OFFSET))

/* ============================================================================================================= */
/* Nested Vectored Interrupt Controller Registers (NVIC)                                                         */
/* Address Range: 0xE000 E100 - 0xE000 EF00                                                                      */
/* ============================================================================================================= */
#define NVIC_ISER0_OFFSET 0x00U  /* Offset: 0x00  (R/W) Interrupt Set Enable Register 0     */
#define NVIC_ISER1_OFFSET 0x04U  /* Offset: 0x04  (R/W) Interrupt Set Enable Register 1     */
#define NVIC_ISER2_OFFSET 0x08U  /* Offset: 0x08  (R/W) Interrupt Set Enable Register 2     */
#define NVIC_ISER3_OFFSET 0x0CU  /* Offset: 0x0C  (R/W) Interrupt Set Enable Register 3     */
#define NVIC_ISER4_OFFSET 0x10U  /* Offset: 0x10  (R/W) Interrupt Set Enable Register 4     */
#define NVIC_ISER5_OFFSET 0x14U  /* Offset: 0x14  (R/W) Interrupt Set Enable Register 5     */
#define NVIC_ISER6_OFFSET 0x18U  /* Offset: 0x18  (R/W) Interrupt Set Enable Register 6     */
#define NVIC_ISER7_OFFSET 0x1CU  /* Offset: 0x1C  (R/W) Interrupt Set Enable Register 7     */
#define NVIC_ICER0_OFFSET 0x80U  /* Offset: 0x80  (R/W) Interrupt Clear Enable Register 0   */
#define NVIC_ICER1_OFFSET 0x84U  /* Offset: 0x84  (R/W) Interrupt Clear Enable Register 1   */
#define NVIC_ICER2_OFFSET 0x88U  /* Offset: 0x88  (R/W) Interrupt Clear Enable Register 2   */
#define NVIC_ICER3_OFFSET 0x8CU  /* Offset: 0x8C  (R/W) Interrupt Clear Enable Register 3   */
#define NVIC_ICER4_OFFSET 0x90U  /* Offset: 0x90  (R/W) Interrupt Clear Enable Register 4   */
#define NVIC_ICER5_OFFSET 0x94U  /* Offset: 0x94  (R/W) Interrupt Clear Enable Register 5   */
#define NVIC_ICER6_OFFSET 0x98U  /* Offset: 0x98  (R/W) Interrupt Clear Enable Register 6   */
#define NVIC_ICER7_OFFSET 0x9CU  /* Offset: 0x9C  (R/W) Interrupt Clear Enable Register 7   */
#define NVIC_ISPR0_OFFSET 0x100U /* Offset: 0x100 (R/W) Interrupt Set Pending Register 0    */
#define NVIC_ISPR1_OFFSET 0x104U /* Offset: 0x104 (R/W) Interrupt Set Pending Register 1    */
#define NVIC_ISPR2_OFFSET 0x108U /* Offset: 0x108 (R/W) Interrupt Set Pending Register 2    */
#define NVIC_ISPR3_OFFSET 0x10CU /* Offset: 0x10C (R/W) Interrupt Set Pending Register 3    */
#define NVIC_ISPR4_OFFSET 0x110U /* Offset: 0x110 (R/W) Interrupt Set Pending Register 4    */
#define NVIC_ISPR5_OFFSET 0x114U /* Offset: 0x114 (R/W) Interrupt Set Pending Register 5    */
#define NVIC_ISPR6_OFFSET 0x118U /* Offset: 0x118 (R/W) Interrupt Set Pending Register 6    */
#define NVIC_ISPR7_OFFSET 0x11CU /* Offset: 0x11C (R/W) Interrupt Set Pending Register 7    */
#define NVIC_ICPR0_OFFSET 0x180U /* Offset: 0x180 (R/W) Interrupt Clear Pending Register 0  */
#define NVIC_ICPR1_OFFSET 0x184U /* Offset: 0x184 (R/W) Interrupt Clear Pending Register 1  */
#define NVIC_ICPR2_OFFSET 0x188U /* Offset: 0x188 (R/W) Interrupt Clear Pending Register 2  */
#define NVIC_ICPR3_OFFSET 0x18CU /* Offset: 0x18C (R/W) Interrupt Clear Pending Register 3  */
#define NVIC_ICPR4_OFFSET 0x190U /* Offset: 0x190 (R/W) Interrupt Clear Pending Register 4  */
#define NVIC_ICPR5_OFFSET 0x194U /* Offset: 0x194 (R/W) Interrupt Clear Pending Register 5  */
#define NVIC_ICPR6_OFFSET 0x198U /* Offset: 0x194 (R/W) Interrupt Clear Pending Register 6  */
#define NVIC_ICPR7_OFFSET 0x19CU /* Offset: 0x19C (R/W) Interrupt Clear Pending Register 7  */
#define NVIC_IABR0_OFFSET 0x200U /* Offset: 0x200 (R/W) Interrupt Active Bit Register 0     */
#define NVIC_IABR1_OFFSET 0x204U /* Offset: 0x204 (R/W) Interrupt Active Bit Register 1     */
#define NVIC_IABR2_OFFSET 0x208U /* Offset: 0x208 (R/W) Interrupt Active Bit Register 2     */
#define NVIC_IABR3_OFFSET 0x20CU /* Offset: 0x20C (R/W) Interrupt Active Bit Register 3     */
#define NVIC_IABR4_OFFSET 0x210U /* Offset: 0x210 (R/W) Interrupt Active Bit Register 4     */
#define NVIC_IABR5_OFFSET 0x214U /* Offset: 0x214 (R/W) Interrupt Active Bit Register 5     */
#define NVIC_IABR6_OFFSET 0x218U /* Offset: 0x218 (R/W) Interrupt Active Bit Register 6     */
#define NVIC_IABR7_OFFSET 0x21CU /* Offset: 0x21C (R/W) Interrupt Active Bit Register 7     */
#define NVIC_IP0_OFFSET   0x300U /* Offset: 0x300 (R/W) Interrupt Priority Register 0       */
#define NVIC_IP1_OFFSET   0x304U /* Offset: 0x304 (R/W) Interrupt Priority Register 1       */
#define NVIC_IP2_OFFSET   0x308U /* Offset: 0x308 (R/W) Interrupt Priority Register 2       */
#define NVIC_IP3_OFFSET   0x30CU /* Offset: 0x30C (R/W) Interrupt Priority Register 3       */
#define NVIC_IP4_OFFSET   0x310U /* Offset: 0x300 (R/W) Interrupt Priority Register 4       */
#define NVIC_IP5_OFFSET   0x314U /* Offset: 0x300 (R/W) Interrupt Priority Register 5       */
#define NVIC_IP6_OFFSET   0x318U /* Offset: 0x300 (R/W) Interrupt Priority Register 6       */
#define NVIC_IP7_OFFSET   0x31CU /* Offset: 0x300 (R/W) Interrupt Priority Register 7       */
#define NVIC_IP8_OFFSET   0x320U /* Offset: 0x300 (R/W) Interrupt Priority Register 8       */
#define NVIC_IP9_OFFSET   0x324U /* Offset: 0x300 (R/W) Interrupt Priority Register 9      */
#define NVIC_IP10_OFFSET  0x328U /* Offset: 0x300 (R/W) Interrupt Priority Register 10      */
#define NVIC_IP11_OFFSET  0x32CU /* Offset: 0x300 (R/W) Interrupt Priority Register 11      */
#define NVIC_IP12_OFFSET  0x330U /* Offset: 0x300 (R/W) Interrupt Priority Register 12      */
#define NVIC_IP13_OFFSET  0x334U /* Offset: 0x300 (R/W) Interrupt Priority Register 13      */
#define NVIC_IP14_OFFSET  0x338U /* Offset: 0x300 (R/W) Interrupt Priority Register 14      */
#define NVIC_IP15_OFFSET  0x33CU /* Offset: 0x300 (R/W) Interrupt Priority Register 15      */
#define NVIC_IP16_OFFSET  0x340U /* Offset: 0x300 (R/W) Interrupt Priority Register 16      */
#define NVIC_IP17_OFFSET  0x344U /* Offset: 0x300 (R/W) Interrupt Priority Register 17      */
#define NVIC_IP18_OFFSET  0x348U /* Offset: 0x300 (R/W) Interrupt Priority Register 18      */
#define NVIC_IP19_OFFSET  0x34CU /* Offset: 0x300 (R/W) Interrupt Priority Register 19      */
#define NVIC_IP20_OFFSET  0x350U /* Offset: 0x300 (R/W) Interrupt Priority Register 20      */
#define NVIC_IP21_OFFSET  0x354U /* Offset: 0x300 (R/W) Interrupt Priority Register 21      */
#define NVIC_IP22_OFFSET  0x358U /* Offset: 0x300 (R/W) Interrupt Priority Register 22      */
#define NVIC_IP23_OFFSET  0x35CU /* Offset: 0x300 (R/W) Interrupt Priority Register 23      */
#define NVIC_IP24_OFFSET  0x360U /* Offset: 0x300 (R/W) Interrupt Priority Register 24      */
#define NVIC_IP25_OFFSET  0x364U /* Offset: 0x300 (R/W) Interrupt Priority Register 25      */
#define NVIC_IP26_OFFSET  0x368U /* Offset: 0x300 (R/W) Interrupt Priority Register 26      */
#define NVIC_IP27_OFFSET  0x36CU /* Offset: 0x300 (R/W) Interrupt Priority Register 27      */
#define NVIC_IP28_OFFSET  0x370U /* Offset: 0x300 (R/W) Interrupt Priority Register 28      */
#define NVIC_IP29_OFFSET  0x374U /* Offset: 0x300 (R/W) Interrupt Priority Register 29      */
#define NVIC_IP30_OFFSET  0x378U /* Offset: 0x300 (R/W) Interrupt Priority Register 30      */
#define NVIC_IP31_OFFSET  0x37CU /* Offset: 0x300 (R/W) Interrupt Priority Register 31      */
#define NVIC_IP32_OFFSET  0x380U /* Offset: 0x300 (R/W) Interrupt Priority Register 32      */
#define NVIC_IP33_OFFSET  0x384U /* Offset: 0x300 (R/W) Interrupt Priority Register 33      */
#define NVIC_IP34_OFFSET  0x388U /* Offset: 0x300 (R/W) Interrupt Priority Register 34      */
#define NVIC_IP35_OFFSET  0x38CU /* Offset: 0x300 (R/W) Interrupt Priority Register 35      */
#define NVIC_IP36_OFFSET  0x390U /* Offset: 0x300 (R/W) Interrupt Priority Register 36      */
#define NVIC_IP37_OFFSET  0x394U /* Offset: 0x300 (R/W) Interrupt Priority Register 37      */
#define NVIC_IP38_OFFSET  0x398U /* Offset: 0x300 (R/W) Interrupt Priority Register 38      */
#define NVIC_IP39_OFFSET  0x39CU /* Offset: 0x300 (R/W) Interrupt Priority Register 39      */
#define NVIC_IP40_OFFSET  0x3A0U /* Offset: 0x300 (R/W) Interrupt Priority Register 40      */
#define NVIC_IP41_OFFSET  0x3A4U /* Offset: 0x300 (R/W) Interrupt Priority Register 41      */
#define NVIC_IP42_OFFSET  0x3A8U /* Offset: 0x300 (R/W) Interrupt Priority Register 42      */
#define NVIC_IP43_OFFSET  0x3ACU /* Offset: 0x300 (R/W) Interrupt Priority Register 43      */
#define NVIC_IP44_OFFSET  0x3B0U /* Offset: 0x300 (R/W) Interrupt Priority Register 44      */
#define NVIC_IP45_OFFSET  0x3B4U /* Offset: 0x300 (R/W) Interrupt Priority Register 45      */
#define NVIC_IP46_OFFSET  0x3B8U /* Offset: 0x300 (R/W) Interrupt Priority Register 46      */
#define NVIC_IP47_OFFSET  0x3BCU /* Offset: 0x300 (R/W) Interrupt Priority Register 47      */
#define NVIC_IP48_OFFSET  0x3C0U /* Offset: 0x300 (R/W) Interrupt Priority Register 48      */
#define NVIC_IP49_OFFSET  0x3C4U /* Offset: 0x300 (R/W) Interrupt Priority Register 49      */
#define NVIC_IP50_OFFSET  0x3C8U /* Offset: 0x300 (R/W) Interrupt Priority Register 50      */
#define NVIC_IP51_OFFSET  0x3CCU /* Offset: 0x300 (R/W) Interrupt Priority Register 51      */
#define NVIC_IP52_OFFSET  0x3D0U /* Offset: 0x300 (R/W) Interrupt Priority Register 52      */
#define NVIC_IP53_OFFSET  0x3D4U /* Offset: 0x300 (R/W) Interrupt Priority Register 53      */
#define NVIC_IP54_OFFSET  0x3D8U /* Offset: 0x300 (R/W) Interrupt Priority Register 54      */
#define NVIC_IP55_OFFSET  0x3D8U /* Offset: 0x300 (R/W) Interrupt Priority Register 55      */
#define NVIC_IP56_OFFSET  0x3DCU /* Offset: 0x300 (R/W) Interrupt Priority Register 56      */
#define NVIC_IP57_OFFSET  0x3E0U /* Offset: 0x300 (R/W) Interrupt Priority Register 57      */
#define NVIC_IP58_OFFSET  0x3E4U /* Offset: 0x300 (R/W) Interrupt Priority Register 58      */
#define NVIC_IP59_OFFSET  0x3E8U /* Offset: 0x300 (R/W) Interrupt Priority Register 59      */
#define NVIC_STIR_OFFSET  0xE00U /* Offset: 0xE00 ( /W) Software Trigger Interrupt Register */

#define NVIC_B_ADDR 0xE000E100

#define NVIC_ISER0 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER0_OFFSET))
#define NVIC_ISER1 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER1_OFFSET))
#define NVIC_ISER2 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER2_OFFSET))
#define NVIC_ISER3 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER3_OFFSET))
#define NVIC_ISER4 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER4_OFFSET))
#define NVIC_ISER5 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER5_OFFSET))
#define NVIC_ISER6 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER6_OFFSET))
#define NVIC_ISER7 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER7_OFFSET))
#define NVIC_ICER0 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER0_OFFSET))
#define NVIC_ICER1 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER1_OFFSET))
#define NVIC_ICER2 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER2_OFFSET))
#define NVIC_ICER3 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER3_OFFSET))
#define NVIC_ICER4 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER4_OFFSET))
#define NVIC_ICER5 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER5_OFFSET))
#define NVIC_ICER6 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER6_OFFSET))
#define NVIC_ICER7 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER7_OFFSET))
#define NVIC_ISPR0 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR0_OFFSET))
#define NVIC_ISPR1 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR1_OFFSET))
#define NVIC_ISPR2 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR2_OFFSET))
#define NVIC_ISPR3 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR3_OFFSET))
#define NVIC_ISPR4 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR4_OFFSET))
#define NVIC_ISPR5 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR5_OFFSET))
#define NVIC_ISPR6 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR6_OFFSET))
#define NVIC_ISPR7 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR7_OFFSET))
#define NVIC_ICPR0 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR0_OFFSET))
#define NVIC_ICPR1 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR1_OFFSET))
#define NVIC_ICPR2 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR2_OFFSET))
#define NVIC_ICPR3 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR3_OFFSET))
#define NVIC_ICPR4 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR4_OFFSET))
#define NVIC_ICPR5 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR5_OFFSET))
#define NVIC_ICPR6 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR6_OFFSET))
#define NVIC_ICPR7 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR7_OFFSET))
#define NVIC_IABR0 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR0_OFFSET))
#define NVIC_IABR1 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR1_OFFSET))
#define NVIC_IABR2 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR2_OFFSET))
#define NVIC_IABR3 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR3_OFFSET))
#define NVIC_IABR4 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR4_OFFSET))
#define NVIC_IABR5 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR5_OFFSET))
#define NVIC_IABR6 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR6_OFFSET))
#define NVIC_IABR7 *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR7_OFFSET))
#define NVIC_IP0   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP0_OFFSET))
#define NVIC_IP1   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP1_OFFSET))
#define NVIC_IP2   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP2_OFFSET))
#define NVIC_IP3   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP3_OFFSET))
#define NVIC_IP4   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP4_OFFSET))
#define NVIC_IP5   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP5_OFFSET))
#define NVIC_IP6   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP6_OFFSET))
#define NVIC_IP7   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP7_OFFSET))
#define NVIC_IP8   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP8_OFFSET))
#define NVIC_IP9   *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP9_OFFSET))
#define NVIC_IP10  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP10_OFFSET))
#define NVIC_IP11  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP11_OFFSET))
#define NVIC_IP12  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP12_OFFSET))
#define NVIC_IP13  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP13_OFFSET))
#define NVIC_IP14  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP14_OFFSET))
#define NVIC_IP15  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP15_OFFSET))
#define NVIC_IP16  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP16_OFFSET))
#define NVIC_IP17  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP17_OFFSET))
#define NVIC_IP18  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP18_OFFSET))
#define NVIC_IP19  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP19_OFFSET))
#define NVIC_IP20  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP20_OFFSET))
#define NVIC_IP21  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP21_OFFSET))
#define NVIC_IP22  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP22_OFFSET))
#define NVIC_IP23  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP23_OFFSET))
#define NVIC_IP24  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP24_OFFSET))
#define NVIC_IP25  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP25_OFFSET))
#define NVIC_IP26  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP26_OFFSET))
#define NVIC_IP27  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP27_OFFSET))
#define NVIC_IP28  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP28_OFFSET))
#define NVIC_IP29  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP29_OFFSET))
#define NVIC_IP30  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP30_OFFSET))
#define NVIC_IP31  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP31_OFFSET))
#define NVIC_IP32  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP32_OFFSET))
#define NVIC_IP33  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP33_OFFSET))
#define NVIC_IP34  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP34_OFFSET))
#define NVIC_IP35  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP35_OFFSET))
#define NVIC_IP36  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP36_OFFSET))
#define NVIC_IP37  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP37_OFFSET))
#define NVIC_IP38  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP38_OFFSET))
#define NVIC_IP39  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP39_OFFSET))
#define NVIC_IP40  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP40_OFFSET))
#define NVIC_IP41  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP41_OFFSET))
#define NVIC_IP42  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP42_OFFSET))
#define NVIC_IP43  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP43_OFFSET))
#define NVIC_IP44  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP44_OFFSET))
#define NVIC_IP45  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP45_OFFSET))
#define NVIC_IP46  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP46_OFFSET))
#define NVIC_IP47  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP47_OFFSET))
#define NVIC_IP48  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP48_OFFSET))
#define NVIC_IP49  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP49_OFFSET))
#define NVIC_IP50  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP50_OFFSET))
#define NVIC_IP51  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP51_OFFSET))
#define NVIC_IP52  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP52_OFFSET))
#define NVIC_IP53  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP53_OFFSET))
#define NVIC_IP54  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP54_OFFSET))
#define NVIC_IP55  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP55_OFFSET))
#define NVIC_IP56  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP56_OFFSET))
#define NVIC_IP57  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP57_OFFSET))
#define NVIC_IP58  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP58_OFFSET))
#define NVIC_IP59  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP59_OFFSET))
#define NVIC_STIR  *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_STIR_OFFSET))

/* ============================================================================================================= */
/* System Control Block Registers (SCB)                                                                          */
/* Address Range: 0xE000 ED00 - 0xE000 ED40                                                                      */
/* ============================================================================================================= */
#define SCB_CPUID_OFFSET 0x00U /* Offset: 0x00 (R/ ) CPUID Base Register                             */
#define SCB_ICSR_OFFSET  0x04U /* Offset: 0x04 (R/W) Interrupt Control and State Register            */
#define SCB_VTOR_OFFSET  0x08U /* Offset: 0x08 (R/W) Vector Table Offset Register                    */
#define SCB_AIRCR_OFFSET 0x0CU /* Offset: 0x0C (R/W) Application Interupt and Reset Control Register */
#define SCB_SCR_OFFSET   0x10U /* Offset: 0x10 (R/W) System Control Register                         */
#define SCB_CCR_OFFSET   0x14U /* Offset: 0x14 (R/W) Configuration Control Register                  */
#define SCB_SHP0_OFFSET  0x18U /* Offset: 0x18 (R/W) System Handlers Priority Register 0 (4-7)       */
#define SCB_SHP1_OFFSET  0x1CU /* Offset: 0x1C (R/W) System Handlers Priority Register 1 (8-11)      */
#define SCB_SHP2_OFFSET  0x20U /* Offset: 0x20 (R/W) System Handlers Priority Register 2 (12-15)     */
#define SCB_SHCSR_OFFSET 0x24U /* Offset: 0x24 (R/W) System Handler Control and State Register       */
#define SCB_CFSR_OFFSET  0x28U /* Offset: 0x28 (R/W) Configurable Fault Status Register              */
#define SCB_HFSR_OFFSET  0x2CU /* Offset: 0x2C (R/W) Hard Fault Status Register                      */
#define SCB_DFSR_OFFSET  0x30U /* Offset: 0x30 (R/W) Debug Fault Status Register                     */
#define SCB_MMFAR_OFFSET 0x34U /* Offset: 0x34 (R/W) Memory Management Fault Status Register         */
#define SCB_BFAR_OFFSET  0x38U /* Offset: 0x38 (R/W) Bus Fault Address Register                      */
#define SCB_AFSR_OFFSET  0x3CU /* Offset: 0x3C (R/W) Auxiliary Fault Status Register                 */
#define SCB_PFR0_OFFSET  0x40U /* Offset: 0x40 (R/ ) Processor Feature Register 0                    */
#define SCB_PFR1_OFFSET  0x44U /* Offset: 0x44 (R/ ) Processor Feature Register 1                    */
#define SCB_DFR_OFFSET   0x48U /* Offset: 0x48 (R/ ) Debug Feature Register                          */
#define SCB_ADR_OFFSET   0x4CU /* Offset: 0x4C (R/ ) Axuiliary Feature Register                      */
#define SCB_MMFR0_OFFSET 0x50U /* Offset: 0x50 (R/ ) Memory Model Feature Register 0                 */
#define SCB_MMFR1_OFFSET 0x54U /* Offset: 0x54 (R/ ) Memory Model Feature Register 1                 */
#define SCB_MMFR2_OFFSET 0x58U /* Offset: 0x58 (R/ ) Memory Model Feature Register 2                 */
#define SCB_MMFR3_OFFSET 0x5CU /* Offset: 0x5C (R/ ) Memory Model Feature Register 3                 */
#define SCB_ISAR0_OFFSET 0x60U /* Offset: 0x60 (R/ ) Instruction Set Attributes Register 0           */
#define SCB_ISAR1_OFFSET 0x64U /* Offset: 0x64 (R/ ) Instruction Set Attributes Register 1           */
#define SCB_ISAR2_OFFSET 0x68U /* Offset: 0x68 (R/ ) Instruction Set Attributes Register 2           */
#define SCB_ISAR3_OFFSET 0x6CU /* Offset: 0x6C (R/ ) Instruction Set Attributes Register 3           */
#define SCB_ISAR4_OFFSET 0x70U /* Offset: 0x70 (R/ ) Instruction Set Attributes Register 4           */
#define SCB_CPACR_OFFSET 0x88U /* Offset: 0x88 (R/W) Coprocessor Access Control Register             */

#define SCB_B_ADDR 0xE000ED00

#define SCB_CPUID *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_CPUID_OFFSET))
#define SCB_ICSR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_ICSR_OFFSET))
#define SCB_VTOR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_VTOR_OFFSET))
#define SCB_AIRCR *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_AIRCR_OFFSET))
#define SCB_SCR   *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SCR_OFFSET))
#define SCB_CCR   *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CCR_OFFSET))
#define SCB_SHP0  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP0_OFFSET))
#define SCB_SHP1  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP1_OFFSET))
#define SCB_SHP2  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP2_OFFSET))
#define SCB_SHCSR *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHCSR_OFFSET))
#define SCB_CFSR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CFSR_OFFSET))
#define SCB_HFSR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_HFSR_OFFSET))
#define SCB_DFSR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_DFSR_OFFSET))
#define SCB_MMFAR *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_MMFAR_OFFSET))
#define SCB_BFAR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_BFAR_OFFSET))
#define SCB_AFSR  *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_AFSR_OFFSET))
#define SCB_PFR0  *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_PFR0_OFFSET))
#define SCB_PFR1  *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_PFR1_OFFSET))
#define SCB_DFR   *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_DFR_OFFSET))
#define SCB_ADR   *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ADR_OFFSET))
#define SCB_MMFR0 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR0_OFFSET))
#define SCB_MMFR1 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR1_OFFSET))
#define SCB_MMFR2 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR2_OFFSET))
#define SCB_MMFR3 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR3_OFFSET))
#define SCB_ISAR0 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR0_OFFSET))
#define SCB_ISAR1 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR1_OFFSET))
#define SCB_ISAR2 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR2_OFFSET))
#define SCB_ISAR3 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR3_OFFSET))
#define SCB_ISAR4 *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR4_OFFSET))
#define SCB_CPACR *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CPACR_OFFSET))

#endif /* _STM32F446RE_REGISTERS_H */

/* EOF */
