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
#define RCC_AHB1ENR_OFFSET    0x30UL /* Offset: 0x30 (R/W) AHB1 Peripheral Clk Enable Register                   */
#define RCC_AHB2ENR_OFFSET    0x34UL /* Offset: 0x34 (R/W) AHB2 Peripheral Clk Enable Register                   */
#define RCC_AHB3ENR_OFFSET    0x38UL /* Offset: 0x38 (R/W) AHB3 Peripheral Clk Enable Register                   */
#define RCC_APB1ENR_OFFSET    0x40UL /* Offset: 0x40 (R/W) APB1 Peripheral Clk Enable Register                   */
#define RCC_APB2ENR_OFFSET    0x44UL /* Offset: 0x44 (R/W) APB1 Peripheral Clk Enable Register                   */
#define RCC_AHB1LPENR_OFFSET  0x50UL /* Offset: 0x50 (R/W) AHB1 Peripheral Clk Enable Lower Power Mode Register  */
#define RCC_AHB2LPENR_OFFSET  0x54UL /* Offset: 0x54 (R/W) AHB2 Peripheral Clk Enable Lower Power Mode Register  */
#define RCC_AHB3LPENR_OFFSET  0x58UL /* Offset: 0x58 (R/W) AHB3 Peripheral Clk Enable Lower Power Mode Register  */
#define RCC_APB1LPENR_OFFSET  0x60UL /* Offset: 0x60 (R/W) APB1 Peripheral Clk Enable Lower Power Mode Register  */
#define RCC_APB2LPENR_OFFSET  0x64UL /* Offset: 0x64 (R/W) APB2 Peripheral Clk Enable Lower Power Mode Register  */
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
/* RCC CR Register Bit Definitions                                                                               */
/* ============================================================================================================= */
#define RCC_CR_HSION                0x00000001UL
#define RCC_CR_HSIRDY               0x00000002UL
#define RCC_CR_HSITRIM              0x000000F8UL
#define RCC_CR_HSICAL               0x0000FF00UL
#define RCC_CR_HSEON                0x00010000UL
#define RCC_CR_HSERDY               0x00020000UL
#define RCC_CR_HSEBYP               0x00040000UL
#define RCC_CR_CSSON                0x00080000UL
#define RCC_CR_PLLON                0x01000000UL
#define RCC_CR_PLLRDY               0x02000000UL
#define RCC_CR_PLLI2SON             0x04000000UL
#define RCC_CR_PLLI2SRDY            0x08000000UL
#define RCC_CR_PLLSAION             0x10000000UL
#define RCC_CR_PLLSAIRDY            0x20000000UL

/* ============================================================================================================= */
/* RCC PLLCFGR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_PLLCFGR_PLLM            0x0000003FUL
#define RCC_PLLCFGR_PLLN            0x00007FC0UL
#define RCC_PLLCFGR_PLLP            0x00030000UL
#define RCC_PLLCFGR_PLLSRC          0x00400000UL
#define RCC_PLLCFGR_PLLQ            0x0F000000UL
#define RCC_PLLCFGR_PLLR            0x70000000UL

/* ============================================================================================================= */
/* RCC CFGR Register Bit Definitions                                                                             */
/* ============================================================================================================= */
#define RCC_CFGR_SW                 0x00000003UL
#define RCC_CFGR_SW_HSI             0x00000000UL
#define RCC_CFGR_SW_HSE             0x00000001UL
#define RCC_CFGR_SW_PLL_P           0x00000002UL
#define RCC_CFGR_SW_PLL_R           0x00000003UL

#define RCC_CFGR_SWS                0x0000000CUL
#define RCC_CFGR_SWS_HSI            0x00000001UL
#define RCC_CFGR_SWS_HSE            0x00000002UL
#define RCC_CFGR_SWS_PLL_P          0x00000003UL
#define RCC_CFGR_SWS_PLL_R          0x00000004UL

#define RCC_CFGR_HPRE               0x000000F0UL
#define RCC_CFGR_HPRE_NO_DIV        0x00000000UL
#define RCC_CFGR_HPRE_DIV_2         0x00000080UL
#define RCC_CFGR_HPRE_DIV_4         0x00000090UL
#define RCC_CFGR_HPRE_DIV_8         0x000000A0UL
#define RCC_CFGR_HPRE_DIV_16        0x000000B0UL
#define RCC_CFGR_HPRE_DIV_64        0x000000C0UL
#define RCC_CFGR_HPRE_DIV_128       0x000000D0UL
#define RCC_CFGR_HPRE_DIV_256       0x000000E0UL
#define RCC_CFGR_HPRE_DIV_512       0x000000F0UL

#define RCC_CFGR_PPRE1              0x00001C00UL
#define RCC_CFGR_PPRE1_NO_DIV       0x00000000UL
#define RCC_CFGR_PPRE1_DIV_2        0x00001000UL
#define RCC_CFGR_PPRE1_DIV_4        0x00001400UL
#define RCC_CFGR_PPRE1_DIV_8        0x00001800UL
#define RCC_CFGR_PPRE1_DIV_16       0x00001C00UL

#define RCC_CFGR_PPRE2              0x0000E000UL
#define RCC_CFGR_PPRE2_NO_DIV       0x00000000UL
#define RCC_CFGR_PPRE2_DIV_2        0x00008000UL
#define RCC_CFGR_PPRE2_DIV_4        0x0000A000UL
#define RCC_CFGR_PPRE2_DIV_8        0x0000C000UL
#define RCC_CFGR_PPRE2_DIV_16       0x0000E000UL

#define RCC_CFGR_RTCPRE             0x001F0000UL
#define RCC_CFGR_RTCPRE_DIV_2       0x00020000UL
#define RCC_CFGR_RTCPRE_DIV_3       0x00030000UL
#define RCC_CFGR_RTCPRE_DIV_4       0x00040000UL
#define RCC_CFGR_RTCPRE_DIV_5       0x00050000UL
#define RCC_CFGR_RTCPRE_DIV_6       0x00060000UL
#define RCC_CFGR_RTCPRE_DIV_7       0x00070000UL
#define RCC_CFGR_RTCPRE_DIV_8       0x00080000UL
#define RCC_CFGR_RTCPRE_DIV_9       0x00090000UL
#define RCC_CFGR_RTCPRE_DIV_10      0x000A0000UL
#define RCC_CFGR_RTCPRE_DIV_11      0x000B0000UL
#define RCC_CFGR_RTCPRE_DIV_12      0x000C0000UL
#define RCC_CFGR_RTCPRE_DIV_13      0x000D0000UL
#define RCC_CFGR_RTCPRE_DIV_14      0x000E0000UL
#define RCC_CFGR_RTCPRE_DIV_15      0x000F0000UL
#define RCC_CFGR_RTCPRE_DIV_16      0x00100000UL
#define RCC_CFGR_RTCPRE_DIV_17      0x00110000UL
#define RCC_CFGR_RTCPRE_DIV_18      0x00120000UL
#define RCC_CFGR_RTCPRE_DIV_19      0x00130000UL
#define RCC_CFGR_RTCPRE_DIV_20      0x00140000UL
#define RCC_CFGR_RTCPRE_DIV_21      0x00150000UL
#define RCC_CFGR_RTCPRE_DIV_22      0x00160000UL
#define RCC_CFGR_RTCPRE_DIV_23      0x00170000UL
#define RCC_CFGR_RTCPRE_DIV_24      0x00180000UL
#define RCC_CFGR_RTCPRE_DIV_25      0x00190000UL
#define RCC_CFGR_RTCPRE_DIV_26      0x001A0000UL
#define RCC_CFGR_RTCPRE_DIV_27      0x001B0000UL
#define RCC_CFGR_RTCPRE_DIV_28      0x001C0000UL
#define RCC_CFGR_RTCPRE_DIV_29      0x001D0000UL
#define RCC_CFGR_RTCPRE_DIV_30      0x001E0000UL
#define RCC_CFGR_RTCPRE_DIV_31      0x001F0000UL

#define RCC_CFGR_MCO1               0x00600000UL
#define RCC_CFGR_MCO1_HSI           0x00000000UL
#define RCC_CFGR_MCO1_LSE           0x00200000UL
#define RCC_CFGR_MCO1_HSE           0x00400000UL
#define RCC_CFGR_MCO1_PLL           0x00600000UL

#define RCC_CFGR_MCO1PRE            0x07000000UL
#define RCC_CFGR_MCO1PRE_NO_DIV     0x00000000UL
#define RCC_CFGR_MCO1PRE_DIV_2      0x04000000UL
#define RCC_CFGR_MCO1PRE_DIV_3      0x05000000UL
#define RCC_CFGR_MCO1PRE_DIV_4      0x06000000UL
#define RCC_CFGR_MCO1PRE_DIV_5      0x07000000UL

#define RCC_CFGR_MCO2PRE            0x38000000UL
#define RCC_CFGR_MCO1PRE_NO_DIV     0x00000000UL
#define RCC_CFGR_MCO1PRE_DIV_2      0x30000000UL
#define RCC_CFGR_MCO1PRE_DIV_3      0x28000000UL
#define RCC_CFGR_MCO1PRE_DIV_4      0x30000000UL
#define RCC_CFGR_MCO1PRE_DIV_5      0x38000000UL

#define RCC_CFGR_MCO2               0xC0000000UL
#define RCC_CFGR_MCO2_SYSCLK        0x00000000UL
#define RCC_CFGR_MCO2_PLLI2S        0x40000000UL
#define RCC_CFGR_MCO2_HSE           0x80000000UL
#define RCC_CFGR_MCO2_PLL           0xC0000000UL

/* ============================================================================================================= */
/* RCC CIR Register Bit Definitions                                                                              */
/* ============================================================================================================= */
#define RCC_CIR_LSIRDYF             0x00000001UL
#define RCC_CIR_LSERDYF             0x00000002UL
#define RCC_CIR_HSIRDYF             0x00000004UL
#define RCC_CIR_HSERDYF             0x00000008UL
#define RCC_CIR_PLLRDYF             0x00000010UL
#define RCC_CIR_PLLI2SRDYF          0x00000020UL
#define RCC_CIR_PLLSAIRDYF          0x00000040UL
#define RCC_CIR_CSSF                0x00000080UL
#define RCC_CIR_LSIRDYIE            0x00000100UL
#define RCC_CIR_LSERDYIE            0x00000200UL
#define RCC_CIR_HSIRDYIE            0x00000400UL
#define RCC_CIR_HSERDYIE            0x00000800UL
#define RCC_CIR_PLLRDYIE            0x00001000UL
#define RCC_CIR_PLLI2SRDYIE         0x00002000UL
#define RCC_CIR_PLLSAIRDYIE         0x00004000UL
#define RCC_CIR_LSIRDYC             0x00010000UL
#define RCC_CIR_LSERDYC             0x00020000UL
#define RCC_CIR_HSIRDYC             0x00040000UL
#define RCC_CIR_HSERDYC             0x00080000UL
#define RCC_CIR_PLLRDYC             0x00100000UL
#define RCC_CIR_PLLI2SRDYC          0x00200000UL
#define RCC_CIR_PLLSAIRDYC          0x00400000UL
#define RCC_CIR_CSSC                0x00800000UL

/* ============================================================================================================= */
/* RCC AHB1RSTR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_AHB1RSTR_GPIOARST       0x00000001UL
#define RCC_AHB1RSTR_GPIOBRST       0x00000002UL
#define RCC_AHB1RSTR_GPIOCRST       0x00000004UL
#define RCC_AHB1RSTR_GPIODRST       0x00000008UL
#define RCC_AHB1RSTR_GPIOERST       0x00000010UL
#define RCC_AHB1RSTR_GPIOFRST       0x00000020UL
#define RCC_AHB1RSTR_GPIOGRST       0x00000040UL
#define RCC_AHB1RSTR_GPIOHRST       0x00000080UL
#define RCC_AHB1RSTR_CRCRST         0x00001000UL
#define RCC_AHB1RSTR_DMA1RST        0x00020000UL
#define RCC_AHB1RSTR_DMA2RST        0x00040000UL
#define RCC_AHB1RSTR_OTGHSRST       0x10000000UL

/* ============================================================================================================= */
/* RCC AHB2RSTR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_AHB2RSTR_DCMIRST        0x00000001UL
#define RCC_AHB2RSTR_OTGFSRST       0x00000080UL

/* ============================================================================================================= */
/* RCC AHB3RSTR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_AHB3RSTR_FMCRST         0x00000001UL
#define RCC_AHB3RSTR_QSPIRST        0x00000002UL

/* ============================================================================================================= */
/* RCC APB1RSTR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_APB1RSTR_TIM2RST        0x00000001UL
#define RCC_APB1RSTR_TIM3RST        0x00000002UL
#define RCC_APB1RSTR_TIM4RST        0x00000004UL
#define RCC_APB1RSTR_TIM5RST        0x00000008UL
#define RCC_APB1RSTR_TIM6RST        0x00000010UL
#define RCC_APB1RSTR_TIM7RST        0x00000020UL
#define RCC_APB1RSTR_TIM12RST       0x00000040UL
#define RCC_APB1RSTR_TIM13RST       0x00000080UL
#define RCC_APB1RSTR_TIM14RST       0x00000100UL
#define RCC_APB1RSTR_WWDGRST        0x00000800UL
#define RCC_APB1RSTR_SPI2RST        0x00004000UL
#define RCC_APB1RSTR_SPI3RST        0x00008000UL
#define RCC_APB1RSTR_SPDIFRXRST     0x00010000UL
#define RCC_APB1RSTR_UART2RST       0x00020000UL
#define RCC_APB1RSTR_UART3RST       0x00040000UL
#define RCC_APB1RSTR_UART4RST       0x00080000UL
#define RCC_APB1RSTR_UART5RST       0x00100000UL
#define RCC_APB1RSTR_I2C1RST        0x00200000UL
#define RCC_APB1RSTR_I2C2RST        0x00400000UL
#define RCC_APB1RSTR_I2C3RST        0x00800000UL
#define RCC_APB1RSTR_FMPI2C1RST     0x01000000UL
#define RCC_APB1RSTR_CAN1RST        0x02000000UL
#define RCC_APB1RSTR_CAN2RST        0x04000000UL
#define RCC_APB1RSTR_CECRST         0x08000000UL
#define RCC_APB1RSTR_PWRRST         0x10000000UL
#define RCC_APB1RSTR_DACRST         0x20000000UL

/* ============================================================================================================= */
/* RCC APB2RSTR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_APB2RSTR_TIM1RST        0x00000001UL
#define RCC_APB2RSTR_TIM8RST        0x00000002UL
#define RCC_APB2RSTR_USART1RST      0x00000010UL
#define RCC_APB2RSTR_USART6RST      0x00000020UL
#define RCC_APB2RSTR_ADACRST        0x00000100UL
#define RCC_APB2RSTR_SDIORST        0x00000800UL
#define RCC_APB2RSTR_SPI1RST        0x00001000UL
#define RCC_APB2RSTR_SPI4RST        0x00002000UL
#define RCC_APB2RSTR_SYSCFGRST      0x00004000UL
#define RCC_APB2RSTR_TIM9RST        0x00010000UL
#define RCC_APB2RSTR_TIM10RST       0x00020000UL
#define RCC_APB2RSTR_TIM11RST       0x00040000UL
#define RCC_APB2RSTR_SAI1RST        0x00400000UL
#define RCC_APB2RSTR_SAI2RST        0x00800000UL

/* ============================================================================================================= */
/* RCC AHB1ENR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_AHB1ENR_GPIOAEN         0x00000001UL
#define RCC_AHB1ENR_GPIOBEN         0x00000002UL
#define RCC_AHB1ENR_GPIOCEN         0x00000004UL
#define RCC_AHB1ENR_GPIODEN         0x00000008UL
#define RCC_AHB1ENR_GPIOEEN         0x00000010UL
#define RCC_AHB1ENR_GPIOFEN         0x00000020UL
#define RCC_AHB1ENR_GPIOGEN         0x00000040UL
#define RCC_AHB1ENR_GPIOHEN         0x00000080UL
#define RCC_AHB1ENR_CRCEN           0x00001000UL
#define RCC_AHB1ENR_BKPSRAMEN       0x00040000UL
#define RCC_AHB1ENR_DMA1EN          0x00200000UL
#define RCC_AHB1ENR_DMA2EN          0x00400000UL
#define RCC_AHB1ENR_OTGHSEN         0x20000000UL
#define RCC_AHB1ENR_OTGHSULPIEN     0x40000000UL

/* ============================================================================================================= */
/* RCC AHB2ENR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_AHB2ENR_DCMIEN          0x00000001UL
#define RCC_AHB2ENR_OTGFSEN         0x00000080UL

/* ============================================================================================================= */
/* RCC AHB3ENR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_AHB3ENR_FMCEN           0x00000001UL
#define RCC_AHB3ENR_QSPIEN          0x00000002UL

/* ============================================================================================================= */
/* RCC APB1ENR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_APB1ENR_TIM2EN          0x00000001UL
#define RCC_APB1ENR_TIM3EN          0x00000002UL
#define RCC_APB1ENR_TIM4EN          0x00000004UL
#define RCC_APB1ENR_TIM5EN          0x00000008UL
#define RCC_APB1ENR_TIM6EN          0x00000010UL
#define RCC_APB1ENR_TIM7EN          0x00000020UL
#define RCC_APB1ENR_TIM12EN         0x00000040UL
#define RCC_APB1ENR_TIM13EN         0x00000080UL
#define RCC_APB1ENR_TIM14EN         0x00000100UL
#define RCC_APB1ENR_WWDGEN          0x00000800UL
#define RCC_APB1ENR_SPI2EN          0x00004000UL
#define RCC_APB1ENR_SPI3EN          0x00008000UL
#define RCC_APB1ENR_SPDIFRXEN       0x00010000UL
#define RCC_APB1ENR_USART2EN        0x00020000UL
#define RCC_APB1ENR_USART3EN        0x00040000UL
#define RCC_APB1ENR_UART4EN         0x00080000UL
#define RCC_APB1ENR_UART5EN         0x00100000UL
#define RCC_APB1ENR_I2C1EN          0x00200000UL
#define RCC_APB1ENR_I2C2EN          0x00400000UL
#define RCC_APB1ENR_I2C3EN          0x00800000UL
#define RCC_APB1ENR_FMPI2C1EN       0x01000000UL
#define RCC_APB1ENR_CAN1EN          0x02000000UL
#define RCC_APB1ENR_CAN2EN          0x04000000UL
#define RCC_APB1ENR_CECEN           0x08000000UL
#define RCC_APB1ENR_PWREN           0x10000000UL
#define RCC_APB1ENR_DACEN           0x20000000UL

/* ============================================================================================================= */
/* RCC APB2ENR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_APB2ENR_TIM1EN          0x00000001UL
#define RCC_APB2ENR_TIM8EN          0x00000002UL
#define RCC_APB2ENR_USART1EN        0x00000010UL
#define RCC_APB2ENR_USART6EN        0x00000020UL
#define RCC_APB2ENR_ADC1EN          0x00000100UL
#define RCC_APB2ENR_ADC2EN          0x00000200UL
#define RCC_APB2ENR_ADC3EN          0x00000400UL
#define RCC_APB2ENR_SDIOEN          0x00000800UL
#define RCC_APB2ENR_SPI1EN          0x00001000UL
#define RCC_APB2ENR_SPI4EN          0x00002000UL
#define RCC_APB2ENR_SYSCFGEN        0x00004000UL
#define RCC_APB2ENR_TIM9EN          0x00010000UL
#define RCC_APB2ENR_TIM10EN         0x00020000UL
#define RCC_APB2ENR_TIM11EN         0x00040000UL
#define RCC_APB2ENR_SAI1EN          0x00400000UL
#define RCC_APB2ENR_SAI2EN          0x00800000UL

/* ============================================================================================================= */
/* RCC AHB1LPENR Register Bit Definitions                                                                        */
/* ============================================================================================================= */
#define RCC_AHB1LPENR_GPIOALPEN     0x00000001UL
#define RCC_AHB1LPENR_GPIOBLPEN     0x00000002UL
#define RCC_AHB1LPENR_GPIOCLPEN     0x00000004UL
#define RCC_AHB1LPENR_GPIODLPEN     0x00000008UL
#define RCC_AHB1LPENR_GPIOALPEN     0x00000010UL
#define RCC_AHB1LPENR_GPIOALPEN     0x00000020UL
#define RCC_AHB1LPENR_GPIOALPEN     0x00000040UL
#define RCC_AHB1LPENR_GPIOALPEN     0x00000080UL
#define RCC_AHB1LPENR_CRCLPEN       0x00001000UL
#define RCC_AHB1LPENR_FLITFLPEN     0x00008000UL
#define RCC_AHB1LPENR_SRAM1LPEN     0x00010000UL
#define RCC_AHB1LPENR_SRAM2LPEN     0x00020000UL
#define RCC_AHB1LPENR_BKPSRAMLPEN   0x00040000UL
#define RCC_AHB1LPENR_DMA1LPEN      0x00200000UL
#define RCC_AHB1LPENR_DMA2LPEN      0x00400000UL
#define RCC_AHB1LPENR_OTGHSLPEN     0x20000000UL
#define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000UL

/* ============================================================================================================= */
/* RCC AHB2LPENR Register Bit Definitions                                                                        */
/* ============================================================================================================= */
#define RCC_AHB2LPENR_DCMILPEN      0x00000001UL
#define RCC_AHB2LPENR_OTGFSLPEN     0x00000080UL

/* ============================================================================================================= */
/* RCC AHB3LPENR Register Bit Definitions                                                                        */
/* ============================================================================================================= */
#define RCC_AHB3LPENR_FMCLPEN       0x00000001UL
#define RCC_AHB3LPENR_QSPILPEN      0x00000002UL

/* ============================================================================================================= */
/* RCC APB1LPENR Register Bit Definitions                                                                        */
/* ============================================================================================================= */
#define RCC_APB1LPENR_TIM2LPEN      0x00000001UL
#define RCC_APB1LPENR_TIM3LPEN      0x00000002UL
#define RCC_APB1LPENR_TIM4LPEN      0x00000004UL
#define RCC_APB1LPENR_TIM5LPEN      0x00000008UL
#define RCC_APB1LPENR_TIM6LPEN      0x00000010UL
#define RCC_APB1LPENR_TIM7LPEN      0x00000020UL
#define RCC_APB1LPENR_TIM12LPEN     0x00000040UL
#define RCC_APB1LPENR_TIM13LPEN     0x00000080UL
#define RCC_APB1LPENR_TIM14LPEN     0x00000100UL
#define RCC_APB1LPENR_WWDGLPEN      0x00000800UL
#define RCC_APB1LPENR_SPI2LPEN      0x00004000UL
#define RCC_APB1LPENR_SPI3LPEN      0x00008000UL
#define RCC_APB1LPENR_SPDIFRXLPEN   0x00010000UL
#define RCC_APB1LPENR_USART2LPEN    0x00020000UL
#define RCC_APB1LPENR_USART3LPEN    0x00040000UL
#define RCC_APB1LPENR_UART4LPEN     0x00080000UL
#define RCC_APB1LPENR_UART5LPEN     0x00100000UL
#define RCC_APB1LPENR_I2C1LPEN      0x00200000UL
#define RCC_APB1LPENR_I2C2LPEN      0x00400000UL
#define RCC_APB1LPENR_I2C3LPEN      0x00800000UL
#define RCC_APB1LPENR_FMPI2C1LPEN   0x01000000UL
#define RCC_APB1LPENR_CAN1LPEN      0x02000000UL
#define RCC_APB1LPENR_CAN2LPEN      0x04000000UL
#define RCC_APB1LPENR_CECLPEN       0x08000000UL
#define RCC_APB1LPENR_PWRLPEN       0x10000000UL
#define RCC_APB1LPENR_DACLPEN       0x20000000UL

/* ============================================================================================================= */
/* RCC APB2LPENR Register Bit Definitions                                                                        */
/* ============================================================================================================= */
#define RCC_APB2LPENR_TIM1LPEN      0x00000001UL
#define RCC_APB2LPENR_TIM8LPEN      0x00000002UL
#define RCC_APB2LPENR_USART1LPEN    0x00000010UL
#define RCC_APB2LPENR_USART6LPEN    0x00000020UL
#define RCC_APB2LPENR_ADC1LPEN      0x00000100UL
#define RCC_APB2LPENR_ADC2LPEN      0x00000200UL
#define RCC_APB2LPENR_ADC3LPEN      0x00000400UL
#define RCC_APB2LPENR_SDIOLPEN      0x00000800UL
#define RCC_APB2LPENR_SPI1LPEN      0x00001000UL
#define RCC_APB2LPENR_SPI4LPEN      0x00002000UL
#define RCC_APB2LPENR_SYSCFGLPEN    0x00004000UL
#define RCC_APB2LPENR_TIM9LPEN      0x00010000UL
#define RCC_APB2LPENR_TIM10LPEN     0x00020000UL
#define RCC_APB2LPENR_TIM11LPEN     0x00040000UL
#define RCC_APB2LPENR_SAI1LPEN      0x00400000UL
#define RCC_APB2LPENR_SAI2LPEN      0x00800000UL

/* ============================================================================================================= */
/* RCC BDCR Register Bit Definitions                                                                             */
/* ============================================================================================================= */
#define RCC_BDCR_LSEON              0x00000001UL
#define RCC_BDCR_LSERDY             0x00000002UL
#define RCC_BDCR_LSEBYP             0x00000004UL
#define RCC_BDCR_LSEMOD             0x00000008UL
#define RCC_BDCR_RTCSEL             0x00000300UL
#define RCC_BDCR_RTCEN              0x00008000UL
#define RCC_BDCR_BDRST              0x00010000UL

/* ============================================================================================================= */
/* RCC CSR Register Bit Definitions                                                                              */
/* ============================================================================================================= */
#define RCC_CSR_LSION               0x00000001UL
#define RCC_CSR_LSIRDY              0x00000002UL
#define RCC_CSR_RMVF                0x01000000UL
#define RCC_CSR_BORRSTF             0x02000000UL
#define RCC_CSR_PINRSTF             0x04000000UL
#define RCC_CSR_PORRSTF             0x08000000UL
#define RCC_CSR_SFTRSTF             0x10000000UL
#define RCC_CSR_IWDGRSTF            0x20000000UL
#define RCC_CSR_WWDGRSTF            0x40000000UL
#define RCC_CSR_LPWRRSTF            0x80000000UL

/* ============================================================================================================= */
/* RCC SSCGR Register Bit Definitions                                                                            */
/* ============================================================================================================= */
#define RCC_SSCGR_MODPER            0x00001FFFUL
#define RCC_SSCGR_INCSTEP           0x0FFFE000UL
#define RCC_SSCGR_SPREADSEL         0x40000000UL
#define RCC_SSCGR_SSCGEN            0x80000000UL

/* ============================================================================================================= */
/* RCC PLLI2SCGFR Register Bit Definitions                                                                       */
/* ============================================================================================================= */
#define RCC_PLLI2SCGFR_PLLI2SM      0x0000003FUL
#define RCC_PLLI2SCGFR_PLLI2SN      0x00007FC0UL
#define RCC_PLLI2SCGFR_PLLI2SP      0x00030000UL
#define RCC_PLLI2SCGFR_PLLI2SQ      0x0F000000UL
#define RCC_PLLI2SCGFR_PLLI2SR      0x70000000UL

/* ============================================================================================================= */
/* RCC PLLSAICFGR Register Bit Definitions                                                                       */
/* ============================================================================================================= */
#define RCC_PLLSAICFGR_PLLSAIM      0x0000003FUL
#define RCC_PLLSAICFGR_PLLSAIN      0x00007FC0UL
#define RCC_PLLSAICFGR_PLLSAIP      0x00030000UL
#define RCC_PLLSAICFGR_PLLSAIQ      0x0F000000UL

/* ============================================================================================================= */
/* RCC DCKCFGR Register Bit Definitions                                                                          */
/* ============================================================================================================= */
#define RCC_DCKCFGR_PLLI2SDIVQ      0x0000001FUL
#define RCC_DCKCFGR_PLLSAIDIVQ      0x00001F00UL
#define RCC_DCKCFGR_SAI1SRC         0x00300000UL
#define RCC_DCKCFGR_SAI2SRC         0x00C00000UL
#define RCC_DCKCFGR_TIMPRE          0x01000000UL
#define RCC_DCKCFGR_I2S1SRC         0x06000000UL
#define RCC_DCKCFGR_I2S2SRC         0x18000000UL

/* ============================================================================================================= */
/* RCC CKGATENR Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_CKGATENR_AHB2APB1_CKEN  0x00000001UL
#define RCC_CKGATENR_AHB2APB2_CKEN  0x00000002UL
#define RCC_CKGATENR_CM4DBG_CKEN    0x00000004UL
#define RCC_CKGATENR_SPARE_CKEN     0x00000008UL
#define RCC_CKGATENR_SRAM_CKEN      0x00000010UL
#define RCC_CKGATENR_FLITF_CKEN     0x00000020UL
#define RCC_CKGATENR_RCC_CKEN       0x00000040UL

/* ============================================================================================================= */
/* RCC DCKCFGR2 Register Bit Definitions                                                                         */
/* ============================================================================================================= */
#define RCC_DCKCFGR2_FMPI2C1SEL     0x00C00000UL
#define RCC_DCKCFGR2_CECSEL         0x04000000UL
#define RCC_DCKCFGR2_CK48MSEL       0x08000000UL
#define RCC_DCKCFGR2_SDIOSEL        0x10000000UL
#define RCC_DCKCFGR2_SPDIFRXSEL     0x20000000UL

#endif /* REGISTERS_STM32F446RE_RCC_H */

/* EOF */
