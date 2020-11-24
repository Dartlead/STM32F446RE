#ifndef REGISTERS_STM32F446RE_GPIO_H
#define REGISTERS_STM32F446RE_GPIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! GPIO Register Offsets
 */
#define GPIO_MODER_OFFSET   0x00UL /* (R/W) Mode Register                                                        */
#define GPIO_OTYPER_OFFSET  0x04UL /* (R/W) Output Type Register                                                 */
#define GPIO_OSPEEDR_OFFSET 0x08UL /* (R/W) Output Speed Register                                                */
#define GPIO_PUPDR_OFFSET   0x0CUL /* (R/W) Pull-up/Pull-down Register                                           */
#define GPIO_IDR_OFFSET     0x10UL /* (R/W) Input Data Register                                                  */
#define GPIO_ODR_OFFSET     0x14UL /* (R/W) Output Data Register                                                 */
#define GPIO_BSRR_OFFSET    0x18UL /* (R/W) Bit Set/Reset Register                                               */
#define GPIO_LCKR_OFFSET    0x1CUL /* (R/W) Configuration Lock Register                                          */
#define GPIO_AFRL_OFFSET    0x20UL /* (R/W) Alternate Function Low Register                                      */
#define GPIO_AFRH_OFFSET    0x24UL /* (R/W) Alternate Function High Register                                     */

/*! GPIO Base Addresses
 */
#define GPIOA_B_ADDR        0x40020000UL
#define GPIOB_B_ADDR        0x40020400UL
#define GPIOC_B_ADDR        0x40020800UL
#define GPIOD_B_ADDR        0x40020C00UL
#define GPIOE_B_ADDR        0x40021000UL
#define GPIOF_B_ADDR        0x40021400UL
#define GPIOG_B_ADDR        0x40021800UL
#define GPIOH_B_ADDR        0x40021C00UL

/*! GPIO Port A Registers
 */
#define GPIOA_MODER         *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOA_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOA_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOA_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOA_IDR           *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOA_ODR           *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOA_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOA_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOA_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOA_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOA_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port B Registers
 */
#define GPIOB_MODER         *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOB_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOB_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOB_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOB_IDR           *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOB_ODR           *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOB_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOB_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOB_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOB_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOB_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port C Registers
 */
#define GPIOC_MODER         *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOC_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOC_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOC_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOC_IDR           *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOC_ODR           *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOC_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOC_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOC_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOC_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOC_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port D Registers
 */
#define GPIOD_MODER         *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOD_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOD_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOD_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOD_IDR           *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOD_ODR           *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOD_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOD_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOD_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOD_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOD_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port E Registers
 */
#define GPIOE_MODER         *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOE_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOE_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOE_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOE_IDR           *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOE_ODR           *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOE_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOE_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOE_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOE_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOE_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port F Registers
 */
#define GPIOF_MODER         *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOF_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOF_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOF_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOF_IDR           *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOF_ODR           *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOF_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOF_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOF_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOF_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOF_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port G Registers
 */
#define GPIOG_MODER         *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOG_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOG_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOG_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOG_IDR           *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOG_ODR           *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOG_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOG_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOG_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOG_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOG_B_ADDR + GPIO_AFRH_OFFSET   ))

/*! GPIO Port H Registers
 */
#define GPIOH_MODER         *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_MODER_OFFSET  ))
#define GPIOH_OTYPER        *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_OTYPER_OFFSET ))
#define GPIOH_OSPEEDR       *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOH_PUPDR         *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_PUPDR_OFFSET  ))
#define GPIOH_IDR           *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_IDR_OFFSET    ))
#define GPIOH_ODR           *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_ODR_OFFSET    ))
#define GPIOH_BSRR          *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_BSRR_OFFSET   ))
#define GPIOH_LCKR          *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_LCKR_OFFSET   ))
#define GPIOH_AFRL          *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_AFRL_OFFSET   ))
#define GPIOH_AFRH          *((uint32_t volatile *)((uint8_t *)GPIOH_B_ADDR + GPIO_AFRH_OFFSET   ))

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_STM32F446RE_GPIO_H */

/* EOF */
