#include <stdint.h>

#ifndef REGISTERS_STM32F446RE_RCC_H
#define REGISTERS_STM32F446RE_RCC_H

/* ============================================================================================================= */
/* Reset and Clock Control (RCC) Register Addresses                                                              */
/* Address Range: 0x4002 3800 - 0x4002 3BFF                                                                      */
/* ============================================================================================================= */
#define RCC_CR_OFFSET         0x00UL /* Offset: 0x00 (R/W) Clock Control Register                                */
#define RCC_PLLCFGR_OFFSET    0x04UL /* Offset: 0x04 (R/W) PLL Configuration Register                            */
#define RCC_CFGR_OFFSET       0x08UL /* Offset: 0x08 (R/W) Clock Configuration Register                          */
#define RCC_CIR_OFFSET        0x0CUL /* Offset: 0x0C (R/W) Clock Interrupt Register                              */
#define RCC_AHB1RSTR_OFFSET   0x10UL /* Offset: 0x10 (R/W) AHB1 Peripheral Reset Register                        */
#define RCC_AHB2RSTR_OFFSET   0x14UL /* Offset: 0x14 (R/W) AHB2 Peripheral Reset Register                        */
#define RCC_AHB3RSTR_OFFSET   0x18UL /* Offset: 0x18 (R/W) AHB3 Peripheral Reset Register                        */
#define RCC_APB1RSTR_OFFSET   0x20UL /* Offset: 0x20 (R/W) APB1 Peripheral Reset Register                        */
#define RCC_APB2RSTR_OFFSET   0x24UL /* Offset: 0x24 (R/W) APB2 Peripheral Reset Register                        */
#define RCC_AHB1ENR_OFFSET    0x30UL /* Offset: 0x30 (R/W) AHB1 Peripheral Clock Enable Register                 */
#define RCC_AHB2ENR_OFFSET    0x34UL /* Offset: 0x34 (R/W) AHB2 Peripheral Clock Enable Register                 */
#define RCC_AHB3ENR_OFFSET    0x38UL /* Offset: 0x38 (R/W) AHB3 Peripheral Clock Enable Register                 */
#define RCC_APB1ENR_OFFSET    0x40UL /* Offset: 0x40 (R/W) APB1 Peripheral Clock Enable Register                 */
#define RCC_APB2ENR_OFFSET    0x44UL /* Offset: 0x44 (R/W) APB1 Peripheral Clock Enable Register                 */
#define RCC_AHB1LPENR_OFFSET  0x50UL /* Offset: 0x50 (R/W) AHB1 Peripheral Clock Enable Lower Power Mode Register*/
#define RCC_AHB2LPENR_OFFSET  0x54UL /* Offset: 0x54 (R/W) AHB2 Peripheral Clock Enable Lower Power Mode Register*/
#define RCC_AHB3LPENR_OFFSET  0x58UL /* Offset: 0x58 (R/W) AHB3 Peripheral Clock Enable Lower Power Mode Register*/
#define RCC_APB1LPENR_OFFSET  0x60UL /* Offset: 0x60 (R/W) APB1 Peripheral Clock Enable Lower Power Mode Register*/
#define RCC_APB2LPENR_OFFSET  0x64UL /* Offset: 0x64 (R/W) APB2 Peripheral Clock Enable Lower Power Mode Register*/
#define RCC_BDCR_OFFSET       0x70UL /* Offset: 0x70 (R/W) Backup Domain Control Register                        */
#define RCC_CSR_OFFSET        0x74UL /* Offset: 0x74 (R/W) Clock Control & Status Register                       */
#define RCC_SSCGR_OFFSET      0x80UL /* Offset: 0x80 (R/W) Spread Spectrum Clock Generation Register             */
#define RCC_PLLI2SCFGR_OFFSET 0x84UL /* Offset: 0x84 (R/W) PLLI2S Configuration Register                         */
#define RCC_PLLSAICFGR_OFFSET 0x88UL /* Offset: 0x88 (R/W) PLLSAI Configuration Register                         */
#define RCC_DCKCFGR_OFFSET    0x8CUL /* Offset: 0x8C (R/W) Dedicated Clocks Configuration Register               */
#define RCC_CKGATENR_OFFSET   0x90UL /* Offset: 0x90 (R/W) Clocks Gated Enabled Register                         */
#define RCC_DCKCFGR2_OFFSET   0x94UL /* Offset: 0x94 (R/W) Dedicated Clocks Configuration Register 2             */

#define RCC_B_ADDR 0x40023800UL

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
/* Reset and Clock Control (RCC) Register Bit Definitions                                                        */
/* ============================================================================================================= */
//!# CR Register

#define RCC_CR_HSION        0x00000001UL
#define RCC_CR_HSIRDY       0x00000002UL

#define RCC_CR_HSITRIM      0x000000F8UL
#define RCC_CR_HSITRIM_0    0x00000008UL
#define RCC_CR_HSITRIM_1    0x00000010UL
#define RCC_CR_HSITRIM_2    0x00000020UL
#define RCC_CR_HSITRIM_3    0x00000040UL
#define RCC_CR_HSITRIM_4    0x00000080UL

#define  RCC_CR_HSICAL      0x0000FF00UL
#define  RCC_CR_HSICAL_0    0x00000100UL
#define  RCC_CR_HSICAL_1    0x00000200UL
#define  RCC_CR_HSICAL_2    0x00000400UL
#define  RCC_CR_HSICAL_3    0x00000800UL
#define  RCC_CR_HSICAL_4    0x00001000UL
#define  RCC_CR_HSICAL_5    0x00002000UL
#define  RCC_CR_HSICAL_6    0x00004000UL
#define  RCC_CR_HSICAL_7    0x00008000UL

#define  RCC_CR_HSEON       0x00010000UL
#define  RCC_CR_HSERDY      0x00020000UL
#define  RCC_CR_HSEBYP      0x00040000UL
#define  RCC_CR_CSSON       0x00080000UL

#define  RCC_CR_PLLON       0x01000000UL
#define  RCC_CR_PLLRDY      0x02000000UL
#define  RCC_CR_PLLI2SON    0x04000000UL
#define  RCC_CR_PLLI2SRDY   0x08000000UL
#define  RCC_CR_PLLSAION    0x10000000UL
#define  RCC_CR_PLLSAIRDY   0x20000000UL

//!# PLLCFGR Register

#define  RCC_PLLCFGR_PLLM   0x0000003FUL
#define  RCC_PLLCFGR_PLLM_0 0x00000001UL
#define  RCC_PLLCFGR_PLLM_1 0x00000002UL
#define  RCC_PLLCFGR_PLLM_2 0x00000004UL
#define  RCC_PLLCFGR_PLLM_3 0x00000008UL
#define  RCC_PLLCFGR_PLLM_4 0x00000010UL
#define  RCC_PLLCFGR_PLLM_5 0x00000020UL

#define  RCC_PLLCFGR_PLLN   0x00007FC0UL
#define  RCC_PLLCFGR_PLLN_0 0x00000040UL
#define  RCC_PLLCFGR_PLLN_1 0x00000080UL
#define  RCC_PLLCFGR_PLLN_2 0x00000100UL
#define  RCC_PLLCFGR_PLLN_3 0x00000200UL
#define  RCC_PLLCFGR_PLLN_4 0x00000400UL
#define  RCC_PLLCFGR_PLLN_5 0x00000800UL
#define  RCC_PLLCFGR_PLLN_6 0x00001000UL
#define  RCC_PLLCFGR_PLLN_7 0x00002000UL
#define  RCC_PLLCFGR_PLLN_8 0x00004000UL

#define  RCC_PLLCFGR_PLLP   0x00030000UL
#define  RCC_PLLCFGR_PLLP_0 0x00010000UL
#define  RCC_PLLCFGR_PLLP_1 0x00020000UL

#define  RCC_PLLCFGR_PLLSRC 0x00400000UL

#define  RCC_PLLCFGR_PLLQ   0x0F000000UL
#define  RCC_PLLCFGR_PLLQ_0 0x01000000UL
#define  RCC_PLLCFGR_PLLQ_1 0x02000000UL
#define  RCC_PLLCFGR_PLLQ_2 0x04000000UL
#define  RCC_PLLCFGR_PLLQ_3 0x08000000UL

#define  RCC_PLLCFGR_PLLR   0x70000000UL
#define  RCC_PLLCFGR_PLLR_0 0x10000000UL
#define  RCC_PLLCFGR_PLLR_1 0x20000000UL
#define  RCC_PLLCFGR_PLLR_2 0x40000000UL

//!# CFGR Register


#endif /* REGISTERS_STM32F446RE_RCC_H */

/* EOF */
