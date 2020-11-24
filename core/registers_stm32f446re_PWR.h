#ifndef REGISTERS_STM32F446RE_PWR_H
#define REGISTERS_STM32F446RE_PWR_H

#include <stdint.h>

/*! PWR Register Offsets
 */
#define PWR_CR_OFFSET  0x00U /* (R/W) Power Control Register                                                     */
#define PWR_CSR_OFFSET 0x04U /* (R/W) Power Control and Status Register                                          */

/*! Power Control Base Address
 */
#define PWR_B_ADDR     0x40007000

/*! PWR Registers
 */
#define PWR_CR         *((uint32_t volatile *)((uint8_t *)PWR_B_ADDR + PWR_CR_OFFSET ))
#define PWR_CSR        *((uint32_t volatile *)((uint8_t *)PWR_B_ADDR + PWR_CSR_OFFSET))

#endif /* REGISTERS_STM32F446RE_PWR_H */

/* EOF */
