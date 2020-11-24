#ifndef REGISTERS_STM32F446RE_DMA_H
#define REGISTERS_STM32F446RE_DMA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! DMA Register Offsets
 */
#define DMA_LISR_OFFSET   0x00UL /* (R/ ) Low Interrupt Status Register                                          */
#define DMA_HISR_OFFSET   0x04UL /* (R/ ) High Interrupt Status Register                                         */
#define DMA_LIFCR_OFFSET  0x08UL /* ( /W) Low Interrupt Flag Clear Register                                      */
#define DMA_HIFCR_OFFSET  0x0CUL /* ( /W) High Interrupt Flag Clear Register                                     */
#define DMA_S0CR_OFFSET   0x10UL /* (R/W) Stream 0 Configuration Register                                        */
#define DMA_S0NDTR_OFFSET 0x14UL /* (R/W) Stream 0 Number of Data Register                                       */
#define DMA_S0PAR_OFFSET  0x18UL /* (R/W) Stream 0 Peripheral Address Register                                   */
#define DMA_S0M0AR_OFFSET 0x1CUL /* (R/W) Stream 0 Memory 0 Address Register                                     */
#define DMA_S0M1AR_OFFSET 0x20UL /* (R/W) Stream 0 Memory 1 Address Register                                     */
#define DMA_S0FCR_OFFSET  0x24UL /* (R/W) Stream 0 FIFO Control Register                                         */
#define DMA_S1CR_OFFSET   0x28UL /* (R/W) Stream 1 Configuration Register                                        */
#define DMA_S1NDTR_OFFSET 0x2CUL /* (R/W) Stream 1 Number of Data Register                                       */
#define DMA_S1PAR_OFFSET  0x30UL /* (R/W) Stream 1 Peripheral Address Register                                   */
#define DMA_S1M0AR_OFFSET 0x34UL /* (R/W) Stream 1 Memory 0 Address Register                                     */
#define DMA_S1M1AR_OFFSET 0x38UL /* (R/W) Stream 1 Memory 1 Address Register                                     */
#define DMA_S1FCR_OFFSET  0x3CUL /* (R/W) Stream 1 FIFO Control Register                                         */
#define DMA_S2CR_OFFSET   0x40UL /* (R/W) Stream 2 Configuration Register                                        */
#define DMA_S2NDTR_OFFSET 0x44UL /* (R/W) Stream 2 Number of Data Register                                       */
#define DMA_S2PAR_OFFSET  0x48UL /* (R/W) Stream 2 Peripheral Address Register                                   */
#define DMA_S2M0AR_OFFSET 0x4CUL /* (R/W) Stream 2 Memory 0 Address Register                                     */
#define DMA_S2M1AR_OFFSET 0x50UL /* (R/W) Stream 2 Memory 1 Address Register                                     */
#define DMA_S2FCR_OFFSET  0x54UL /* (R/W) Stream 2 FIFO Control Register                                         */
#define DMA_S3CR_OFFSET   0x58UL /* (R/W) Stream 3 Configuration Register                                        */
#define DMA_S3NDTR_OFFSET 0x5CUL /* (R/W) Stream 3 Number of Data Register                                       */
#define DMA_S3PAR_OFFSET  0x60UL /* (R/W) Stream 3 Peripheral Address Register                                   */
#define DMA_S3M0AR_OFFSET 0x64UL /* (R/W) Stream 3 Memory 0 Address Register                                     */
#define DMA_S3M1AR_OFFSET 0x68UL /* (R/W) Stream 3 Memory 0 Address Register                                     */
#define DMA_S3FCR_OFFSET  0x6CUL /* (R/W) Stream 3 FIFO Control Register                                         */
#define DMA_S4CR_OFFSET   0x70UL /* (R/W) Stream 4 Configuration Register                                        */
#define DMA_S4NDTR_OFFSET 0x74UL /* (R/W) Stream 4 Number of Data Register                                       */
#define DMA_S4PAR_OFFSET  0x78UL /* (R/W) Stream 4 Peripheral Address Register                                   */
#define DMA_S4M0AR_OFFSET 0x7CUL /* (R/W) Stream 4 Memory 0 Address Register                                     */
#define DMA_S4M1AR_OFFSET 0x80UL /* (R/W) Stream 4 Memory 1 Address Register                                     */
#define DMA_S4FCR_OFFSET  0x84UL /* (R/W) Stream 4 FIFO Control Register                                         */
#define DMA_S5CR_OFFSET   0x88UL /* (R/W) Stream 5 Configuration Register                                        */
#define DMA_S5NDTR_OFFSET 0x8CUL /* (R/W) Stream 5 Number of Data Register                                       */
#define DMA_S5PAR_OFFSET  0x90UL /* (R/W) Stream 5 Peripheral Address Register                                   */
#define DMA_S5M0AR_OFFSET 0x94UL /* (R/W) Stream 5 Memory 0 Address Register                                     */
#define DMA_S5M1AR_OFFSET 0x98UL /* (R/W) Stream 5 Memory 1 Address Register                                     */
#define DMA_S5FCR_OFFSET  0x9CUL /* (R/W) Stream 5 FIFO Control Register                                         */
#define DMA_S6CR_OFFSET   0xA0UL /* (R/W) Stream 6 Configuration Register                                        */
#define DMA_S6NDTR_OFFSET 0xA4UL /* (R/W) Stream 6 Number of Data Register                                       */
#define DMA_S6PAR_OFFSET  0xA8UL /* (R/W) Stream 6 Peripheral Address Register                                   */
#define DMA_S6M0AR_OFFSET 0xACUL /* (R/W) Stream 6 Memory 0 Address Register                                     */
#define DMA_S6M1AR_OFFSET 0xB0UL /* (R/W) Stream 6 Memory 1 Address Register                                     */
#define DMA_S6FCR_OFFSET  0xB4UL /* (R/W) Stream 6 FIFO Control Register                                         */
#define DMA_S7CR_OFFSET   0xB8UL /* (R/W) Stream 7 Configuration Register                                        */
#define DMA_S7NDTR_OFFSET 0xBCUL /* (R/W) Stream 7 Number of Data Register                                       */
#define DMA_S7PAR_OFFSET  0xC0UL /* (R/W) Stream 7 Peripheral Address Register                                   */
#define DMA_S7M0AR_OFFSET 0xC4UL /* (R/W) Stream 7 Memory 0 Address Register                                     */
#define DMA_S7M1AR_OFFSET 0xC8UL /* (R/W) Stream 7 Memory 1 Address Register                                     */
#define DMA_S7FCR_OFFSET  0xCCUL /* (R/W) Stream 7 FIFO Control Register                                         */

/*! DMA Base Address
 */
#define DMA1_B_ADDR       0x40026000
#define DMA2_B_ADDR       0x40026400

/*! DMA Channel 1 Registers
 */
#define DMA1_LISR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_LISR_OFFSET))
#define DMA1_HISR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_HISR_OFFSET))
#define DMA1_LIFCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_LIFCR_OFFSET))
#define DMA1_HIFCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_HIFCR_OFFSET))
#define DMA1_S0CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0CR_OFFSET))
#define DMA1_S0NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0NDTR_OFFSET))
#define DMA1_S0PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0PAR_OFFSET))
#define DMA1_S0M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0M0AR_OFFSET))
#define DMA1_S0M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0M1AR_OFFSET))
#define DMA1_S0FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S0FCR_OFFSET))
#define DMA1_S1CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1CR_OFFSET))
#define DMA1_S1NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1NDTR_OFFSET))
#define DMA1_S1PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1PAR_OFFSET))
#define DMA1_S1M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1M0AR_OFFSET))
#define DMA1_S1M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1M1AR_OFFSET))
#define DMA1_S1FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S1FCR_OFFSET))
#define DMA1_S2CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2CR_OFFSET))
#define DMA1_S2NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2NDTR_OFFSET))
#define DMA1_S2PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2PAR_OFFSET))
#define DMA1_S2M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2M0AR_OFFSET))
#define DMA1_S2M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2M1AR_OFFSET))
#define DMA1_S2FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S2FCR_OFFSET))
#define DMA1_S3CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3CR_OFFSET))
#define DMA1_S3NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3NDTR_OFFSET))
#define DMA1_S3PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3PAR_OFFSET))
#define DMA1_S3M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3M0AR_OFFSET))
#define DMA1_S3M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3M1AR_OFFSET))
#define DMA1_S3FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S3FCR_OFFSET))
#define DMA1_S4CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4CR_OFFSET))
#define DMA1_S4NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4NDTR_OFFSET))
#define DMA1_S4PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4PAR_OFFSET))
#define DMA1_S4M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4M0AR_OFFSET))
#define DMA1_S4M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4M1AR_OFFSET))
#define DMA1_S4FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S4FCR_OFFSET))
#define DMA1_S5CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5CR_OFFSET))
#define DMA1_S5NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5NDTR_OFFSET))
#define DMA1_S5PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5PAR_OFFSET))
#define DMA1_S5M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5M0AR_OFFSET))
#define DMA1_S5M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5M1AR_OFFSET))
#define DMA1_S5FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S5FCR_OFFSET))
#define DMA1_S6CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6CR_OFFSET))
#define DMA1_S6NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6NDTR_OFFSET))
#define DMA1_S6PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6PAR_OFFSET))
#define DMA1_S6M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6M0AR_OFFSET))
#define DMA1_S6M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6M1AR_OFFSET))
#define DMA1_S6FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S6FCR_OFFSET))
#define DMA1_S7CR         *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7CR_OFFSET))
#define DMA1_S7NDTR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7NDTR_OFFSET))
#define DMA1_S7PAR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7PAR_OFFSET))
#define DMA1_S7M0AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7M0AR_OFFSET))
#define DMA1_S7M1AR       *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7M1AR_OFFSET))
#define DMA1_S7FCR        *((uint32_t volatile *)((uint8_t *)DMA1_B_ADDR + DMA_S7FCR_OFFSET))

/*! DMA Channel 2 Registers
 */
#define DMA2_LISR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_LISR_OFFSET))
#define DMA2_HISR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_HISR_OFFSET))
#define DMA2_LIFCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_LIFCR_OFFSET))
#define DMA2_HIFCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_HIFCR_OFFSET))
#define DMA2_S0CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0CR_OFFSET))
#define DMA2_S0NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0NDTR_OFFSET))
#define DMA2_S0PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0PAR_OFFSET))
#define DMA2_S0M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0M0AR_OFFSET))
#define DMA2_S0M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0M1AR_OFFSET))
#define DMA2_S0FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S0FCR_OFFSET))
#define DMA2_S1CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1CR_OFFSET))
#define DMA2_S1NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1NDTR_OFFSET))
#define DMA2_S1PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1PAR_OFFSET))
#define DMA2_S1M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1M0AR_OFFSET))
#define DMA2_S1M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1M1AR_OFFSET))
#define DMA2_S1FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S1FCR_OFFSET))
#define DMA2_S2CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2CR_OFFSET))
#define DMA2_S2NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2NDTR_OFFSET))
#define DMA2_S2PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2PAR_OFFSET))
#define DMA2_S2M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2M0AR_OFFSET))
#define DMA2_S2M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2M1AR_OFFSET))
#define DMA2_S2FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S2FCR_OFFSET))
#define DMA2_S3CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3CR_OFFSET))
#define DMA2_S3NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3NDTR_OFFSET))
#define DMA2_S3PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3PAR_OFFSET))
#define DMA2_S3M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3M0AR_OFFSET))
#define DMA2_S3M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3M1AR_OFFSET))
#define DMA2_S3FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S3FCR_OFFSET))
#define DMA2_S4CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4CR_OFFSET))
#define DMA2_S4NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4NDTR_OFFSET))
#define DMA2_S4PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4PAR_OFFSET))
#define DMA2_S4M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4M0AR_OFFSET))
#define DMA2_S4M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4M1AR_OFFSET))
#define DMA2_S4FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S4FCR_OFFSET))
#define DMA2_S5CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5CR_OFFSET))
#define DMA2_S5NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5NDTR_OFFSET))
#define DMA2_S5PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5PAR_OFFSET))
#define DMA2_S5M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5M0AR_OFFSET))
#define DMA2_S5M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5M1AR_OFFSET))
#define DMA2_S5FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S5FCR_OFFSET))
#define DMA2_S6CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6CR_OFFSET))
#define DMA2_S6NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6NDTR_OFFSET))
#define DMA2_S6PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6PAR_OFFSET))
#define DMA2_S6M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6M0AR_OFFSET))
#define DMA2_S6M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6M1AR_OFFSET))
#define DMA2_S6FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S6FCR_OFFSET))
#define DMA2_S7CR         *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7CR_OFFSET))
#define DMA2_S7NDTR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7NDTR_OFFSET))
#define DMA2_S7PAR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7PAR_OFFSET))
#define DMA2_S7M0AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7M0AR_OFFSET))
#define DMA2_S7M1AR       *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7M1AR_OFFSET))
#define DMA2_S7FCR        *((uint32_t volatile *)((uint8_t *)DMA2_B_ADDR + DMA_S7FCR_OFFSET))

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_STM32F446RE_DMA_H */

/* EOF */
