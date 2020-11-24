#ifndef REGISTERS_STM32F446RE_RCC_H
#define REGISTERS_STM32F446RE_RCC_H

#include <stdint.h>

/*! RCC Register Offsets
 */
#define RCC_CR_OFFSET         0x00UL /* (R/W) Clock Control Register                                             */
#define RCC_PLLCFGR_OFFSET    0x04UL /* (R/W) PLL Configuration Register                                         */
#define RCC_CFGR_OFFSET       0x08UL /* (R/W) Clock Configuration Register                                       */
#define RCC_CIR_OFFSET        0x0CUL /* (R/W) Clock Interrupt Register                                           */
#define RCC_AHB1RSTR_OFFSET   0x10UL /* (R/W) AHB1 Peripheral Reset Register                                     */
#define RCC_AHB2RSTR_OFFSET   0x14UL /* (R/W) AHB2 Peripheral Reset Register                                     */
#define RCC_AHB3RSTR_OFFSET   0x18UL /* (R/W) AHB3 Peripheral Reset Register                                     */
#define RCC_APB1RSTR_OFFSET   0x20UL /* (R/W) APB1 Peripheral Reset Register                                     */
#define RCC_APB2RSTR_OFFSET   0x24UL /* (R/W) APB2 Peripheral Reset Register                                     */
#define RCC_AHB1ENR_OFFSET    0x30UL /* (R/W) AHB1 Peripheral Clk Enable Register                                */
#define RCC_AHB2ENR_OFFSET    0x34UL /* (R/W) AHB2 Peripheral Clk Enable Register                                */
#define RCC_AHB3ENR_OFFSET    0x38UL /* (R/W) AHB3 Peripheral Clk Enable Register                                */
#define RCC_APB1ENR_OFFSET    0x40UL /* (R/W) APB1 Peripheral Clk Enable Register                                */
#define RCC_APB2ENR_OFFSET    0x44UL /* (R/W) APB1 Peripheral Clk Enable Register                                */
#define RCC_AHB1LPENR_OFFSET  0x50UL /* (R/W) AHB1 Peripheral Clk Enable Lower Power Mode Register               */
#define RCC_AHB2LPENR_OFFSET  0x54UL /* (R/W) AHB2 Peripheral Clk Enable Lower Power Mode Register               */
#define RCC_AHB3LPENR_OFFSET  0x58UL /* (R/W) AHB3 Peripheral Clk Enable Lower Power Mode Register               */
#define RCC_APB1LPENR_OFFSET  0x60UL /* (R/W) APB1 Peripheral Clk Enable Lower Power Mode Register               */
#define RCC_APB2LPENR_OFFSET  0x64UL /* (R/W) APB2 Peripheral Clk Enable Lower Power Mode Register               */
#define RCC_BDCR_OFFSET       0x70UL /* (R/W) Backup Domain Control Register                                     */
#define RCC_CSR_OFFSET        0x74UL /* (R/W) Clock Control & Status Register                                    */
#define RCC_SSCGR_OFFSET      0x80UL /* (R/W) Spread Spectrum Clock Generation Register                          */
#define RCC_PLLI2SCFGR_OFFSET 0x84UL /* (R/W) PLLI2S Configuration Register                                      */
#define RCC_PLLSAICFGR_OFFSET 0x88UL /* (R/W) PLLSAI Configuration Register                                      */
#define RCC_DCKCFGR_OFFSET    0x8CUL /* (R/W) Dedicated Clocks Configuration Register                            */
#define RCC_CKGATENR_OFFSET   0x90UL /* (R/W) Clocks Gated Enabled Register                                      */
#define RCC_DCKCFGR2_OFFSET   0x94UL /* (R/W) Dedicated Clocks Configuration Register 2                          */

/*! RCC Base Address
 */
#define RCC_B_ADDR            0x40023800UL

/*! RCC Registers
 */
#define RCC_CR                *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CR_OFFSET        ))
#define RCC_PLLCFGR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLCFGR_OFFSET   ))
#define RCC_CFGR              *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CFGR_OFFSET      ))
#define RCC_CIR               *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CIR_OFFSET       ))
#define RCC_AHB1RSTR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1RSTR_OFFSET  ))
#define RCC_AHB2RSTR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2RSTR_OFFSET  ))
#define RCC_AHB3RSTR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3RSTR_OFFSET  ))
#define RCC_APB1RSTR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1RSTR_OFFSET  ))
#define RCC_APB2RSTR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2RSTR_OFFSET  ))
#define RCC_AHB1ENR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1ENR_OFFSET   ))
#define RCC_AHB2ENR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2ENR_OFFSET   ))
#define RCC_AHB3ENR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3ENR_OFFSET   ))
#define RCC_APB1ENR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1ENR_OFFSET   ))
#define RCC_APB2ENR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2ENR_OFFSET   ))
#define RCC_AHB1LPENR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB1LPENR_OFFSET ))
#define RCC_AHB2LPENR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB2LPENR_OFFSET ))
#define RCC_AHB3LPENR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_AHB3LPENR_OFFSET ))
#define RCC_APB1LPENR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB1LPENR_OFFSET ))
#define RCC_APB2LPENR         *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_APB2LPENR_OFFSET ))
#define RCC_BDCR              *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_BDCR_OFFSET      ))
#define RCC_CSR               *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CSR_OFFSET       ))
#define RCC_SSCGR             *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_SSCGR_OFFSET     ))
#define RCC_PLLI2SCFGR        *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLI2SCFGR_OFFSET))
#define RCC_PLLSAICFGR        *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_PLLSAICFGR_OFFSET))
#define RCC_DCKCFGR           *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_DCKCFGR_OFFSET   ))
#define RCC_CKGATENR          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_CKGATENR_OFFSET  ))
#define RCC_DCKCFGR2          *((uint32_t volatile *)((uint8_t *)RCC_B_ADDR + RCC_DCKCFGR2_OFFSET  ))

#endif /* REGISTERS_STM32F446RE_RCC_H */

/* EOF */
