#ifndef REGISTERS_STM32F446RE_SCB_H
#define REGISTERS_STM32F446RE_SCB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! System Control Block Register Offsets
 */
#define SCB_CPUID_OFFSET 0x00UL /* (R/ ) CPUID Base Register                                                     */
#define SCB_ICSR_OFFSET  0x04UL /* (R/W) Interrupt Control and State Register                                    */
#define SCB_VTOR_OFFSET  0x08UL /* (R/W) Vector Table Offset Register                                            */
#define SCB_AIRCR_OFFSET 0x0CUL /* (R/W) Application Interupt and Reset Control Register                         */
#define SCB_SCR_OFFSET   0x10UL /* (R/W) System Control Register                                                 */
#define SCB_CCR_OFFSET   0x14UL /* (R/W) Configuration Control Register                                          */
#define SCB_SHP0_OFFSET  0x18UL /* (R/W) System Handlers Priority Register 0 (4-7)                               */
#define SCB_SHP1_OFFSET  0x1CUL /* (R/W) System Handlers Priority Register 1 (8-11)                              */
#define SCB_SHP2_OFFSET  0x20UL /* (R/W) System Handlers Priority Register 2 (12-15)                             */
#define SCB_SHCSR_OFFSET 0x24UL /* (R/W) System Handler Control and State Register                               */
#define SCB_CFSR_OFFSET  0x28UL /* (R/W) Configurable Fault Status Register                                      */
#define SCB_HFSR_OFFSET  0x2CUL /* (R/W) Hard Fault Status Register                                              */
#define SCB_DFSR_OFFSET  0x30UL /* (R/W) Debug Fault Status Register                                             */
#define SCB_MMFAR_OFFSET 0x34UL /* (R/W) Memory Management Fault Status Register                                 */
#define SCB_BFAR_OFFSET  0x38UL /* (R/W) Bus Fault Address Register                                              */
#define SCB_AFSR_OFFSET  0x3CUL /* (R/W) Auxiliary Fault Status Register                                         */
#define SCB_PFR0_OFFSET  0x40UL /* (R/ ) Processor Feature Register 0                                            */
#define SCB_PFR1_OFFSET  0x44UL /* (R/ ) Processor Feature Register 1                                            */
#define SCB_DFR_OFFSET   0x48UL /* (R/ ) Debug Feature Register                                                  */
#define SCB_ADR_OFFSET   0x4CUL /* (R/ ) Axuiliary Feature Register                                              */
#define SCB_MMFR0_OFFSET 0x50UL /* (R/ ) Memory Model Feature Register 0                                         */
#define SCB_MMFR1_OFFSET 0x54UL /* (R/ ) Memory Model Feature Register 1                                         */
#define SCB_MMFR2_OFFSET 0x58UL /* (R/ ) Memory Model Feature Register 2                                         */
#define SCB_MMFR3_OFFSET 0x5CUL /* (R/ ) Memory Model Feature Register 3                                         */
#define SCB_ISAR0_OFFSET 0x60UL /* (R/ ) Instruction Set Attributes Register 0                                   */
#define SCB_ISAR1_OFFSET 0x64UL /* (R/ ) Instruction Set Attributes Register 1                                   */
#define SCB_ISAR2_OFFSET 0x68UL /* (R/ ) Instruction Set Attributes Register 2                                   */
#define SCB_ISAR3_OFFSET 0x6CUL /* (R/ ) Instruction Set Attributes Register 3                                   */
#define SCB_ISAR4_OFFSET 0x70UL /* (R/ ) Instruction Set Attributes Register 4                                   */
#define SCB_CPACR_OFFSET 0x88UL /* (R/W) Coprocessor Access Control Register                                     */

/*! System Control Block Base Address
 */
#define SCB_B_ADDR       0xE000ED00

/*! System Control Block Registers
 */
#define SCB_CPUID        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_CPUID_OFFSET))
#define SCB_ICSR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_ICSR_OFFSET ))
#define SCB_VTOR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_VTOR_OFFSET ))
#define SCB_AIRCR        *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_AIRCR_OFFSET))
#define SCB_SCR          *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SCR_OFFSET  ))
#define SCB_CCR          *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CCR_OFFSET  ))
#define SCB_SHP0         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP0_OFFSET ))
#define SCB_SHP1         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP1_OFFSET ))
#define SCB_SHP2         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHP2_OFFSET ))
#define SCB_SHCSR        *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_SHCSR_OFFSET))
#define SCB_CFSR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CFSR_OFFSET ))
#define SCB_HFSR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_HFSR_OFFSET ))
#define SCB_DFSR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_DFSR_OFFSET ))
#define SCB_MMFAR        *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_MMFAR_OFFSET))
#define SCB_BFAR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_BFAR_OFFSET ))
#define SCB_AFSR         *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_AFSR_OFFSET ))
#define SCB_PFR0         *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_PFR0_OFFSET ))
#define SCB_PFR1         *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_PFR1_OFFSET ))
#define SCB_DFR          *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_DFR_OFFSET  ))
#define SCB_ADR          *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ADR_OFFSET  ))
#define SCB_MMFR0        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR0_OFFSET))
#define SCB_MMFR1        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR1_OFFSET))
#define SCB_MMFR2        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR2_OFFSET))
#define SCB_MMFR3        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_MMFR3_OFFSET))
#define SCB_ISAR0        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR0_OFFSET))
#define SCB_ISAR1        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR1_OFFSET))
#define SCB_ISAR2        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR2_OFFSET))
#define SCB_ISAR3        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR3_OFFSET))
#define SCB_ISAR4        *((uint32_t volatile const *)((uint8_t *)SCB_B_ADDR + SCB_ISAR4_OFFSET))
#define SCB_CPACR        *((uint32_t volatile       *)((uint8_t *)SCB_B_ADDR + SCB_CPACR_OFFSET))

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_STM32F446RE_SCB_H */

/* EOF */
