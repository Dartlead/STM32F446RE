#ifndef REGISTERS_STM32F446RE_FLASH_H
#define REGISTERS_STM32F446RE_FLASH_H

#include <stdint.h>

/*! FLASH Register Offsets
 */
#define FLASH_ACR_OFFSET     0x00UL /* (R/W) Access Control Register                                             */
#define FLASH_KEYR_OFFSET    0x04UL /* ( /W) Key Register                                                        */
#define FLASH_OPTKEYR_OFFSET 0x08UL /* ( /W) Option Key Register                                                 */
#define FLASH_SR_OFFSET      0x0CUL /* (R/W) Status Register                                                     */
#define FLASH_CR_OFFSET      0x10UL /* (R/W) Control Register                                                    */
#define FLASH_OPTCR_OFFSET   0x14UL /* (R/W) Option Control Register                                             */

/*! FLASH Base Address
 */
#define FLASH_B_ADDR         0x40023C00UL

/*! Flash Registers
 */
#define FLASH_ACR            *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_ACR_OFFSET    ))
#define FLASH_KEY            *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_KEYR_OFFSET   ))
#define FLASH_OPTKEYR        *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_OPTKEYR_OFFSET))
#define FLASH_SR             *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_SR_OFFSET     ))
#define FLASH_CR             *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_CR_OFFSET     ))
#define FLASH_OPTCR          *((uint32_t volatile *)((uint8_t *)FLASH_B_ADDR + FLASH_OPTCR_OFFSET  ))

#endif /* REGISTERS_STM32F446RE_FLASH_H */

/* EOF */
