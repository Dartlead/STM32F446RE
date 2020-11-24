#ifndef REGISTERS_STM32F446RE_NVIC_H
#define REGISTERS_STM32F446RE_NVIC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! NVIC Registers Offsets
 */
#define NVIC_ISER0_OFFSET 0x000UL /* (R/W) Interrupt Set Enable Register 0                                       */
#define NVIC_ISER1_OFFSET 0x004UL /* (R/W) Interrupt Set Enable Register 1                                       */
#define NVIC_ISER2_OFFSET 0x008UL /* (R/W) Interrupt Set Enable Register 2                                       */
#define NVIC_ISER3_OFFSET 0x00CUL /* (R/W) Interrupt Set Enable Register 3                                       */
#define NVIC_ISER4_OFFSET 0x010UL /* (R/W) Interrupt Set Enable Register 4                                       */
#define NVIC_ISER5_OFFSET 0x014UL /* (R/W) Interrupt Set Enable Register 5                                       */
#define NVIC_ISER6_OFFSET 0x018UL /* (R/W) Interrupt Set Enable Register 6                                       */
#define NVIC_ISER7_OFFSET 0x01CUL /* (R/W) Interrupt Set Enable Register 7                                       */
#define NVIC_ICER0_OFFSET 0x080UL /* (R/W) Interrupt Clear Enable Register 0                                     */
#define NVIC_ICER1_OFFSET 0x084UL /* (R/W) Interrupt Clear Enable Register 1                                     */
#define NVIC_ICER2_OFFSET 0x088UL /* (R/W) Interrupt Clear Enable Register 2                                     */
#define NVIC_ICER3_OFFSET 0x08CUL /* (R/W) Interrupt Clear Enable Register 3                                     */
#define NVIC_ICER4_OFFSET 0x090UL /* (R/W) Interrupt Clear Enable Register 4                                     */
#define NVIC_ICER5_OFFSET 0x094UL /* (R/W) Interrupt Clear Enable Register 5                                     */
#define NVIC_ICER6_OFFSET 0x098UL /* (R/W) Interrupt Clear Enable Register 6                                     */
#define NVIC_ICER7_OFFSET 0x09CUL /* (R/W) Interrupt Clear Enable Register 7                                     */
#define NVIC_ISPR0_OFFSET 0x100UL /* (R/W) Interrupt Set Pending Register 0                                      */
#define NVIC_ISPR1_OFFSET 0x104UL /* (R/W) Interrupt Set Pending Register 1                                      */
#define NVIC_ISPR2_OFFSET 0x108UL /* (R/W) Interrupt Set Pending Register 2                                      */
#define NVIC_ISPR3_OFFSET 0x10CUL /* (R/W) Interrupt Set Pending Register 3                                      */
#define NVIC_ISPR4_OFFSET 0x110UL /* (R/W) Interrupt Set Pending Register 4                                      */
#define NVIC_ISPR5_OFFSET 0x114UL /* (R/W) Interrupt Set Pending Register 5                                      */
#define NVIC_ISPR6_OFFSET 0x118UL /* (R/W) Interrupt Set Pending Register 6                                      */
#define NVIC_ISPR7_OFFSET 0x11CUL /* (R/W) Interrupt Set Pending Register 7                                      */
#define NVIC_ICPR0_OFFSET 0x180UL /* (R/W) Interrupt Clear Pending Register 0                                    */
#define NVIC_ICPR1_OFFSET 0x184UL /* (R/W) Interrupt Clear Pending Register 1                                    */
#define NVIC_ICPR2_OFFSET 0x188UL /* (R/W) Interrupt Clear Pending Register 2                                    */
#define NVIC_ICPR3_OFFSET 0x18CUL /* (R/W) Interrupt Clear Pending Register 3                                    */
#define NVIC_ICPR4_OFFSET 0x190UL /* (R/W) Interrupt Clear Pending Register 4                                    */
#define NVIC_ICPR5_OFFSET 0x194UL /* (R/W) Interrupt Clear Pending Register 5                                    */
#define NVIC_ICPR6_OFFSET 0x198UL /* (R/W) Interrupt Clear Pending Register 6                                    */
#define NVIC_ICPR7_OFFSET 0x19CUL /* (R/W) Interrupt Clear Pending Register 7                                    */
#define NVIC_IABR0_OFFSET 0x200UL /* (R/W) Interrupt Active Bit Register 0                                       */
#define NVIC_IABR1_OFFSET 0x204UL /* (R/W) Interrupt Active Bit Register 1                                       */
#define NVIC_IABR2_OFFSET 0x208UL /* (R/W) Interrupt Active Bit Register 2                                       */
#define NVIC_IABR3_OFFSET 0x20CUL /* (R/W) Interrupt Active Bit Register 3                                       */
#define NVIC_IABR4_OFFSET 0x210UL /* (R/W) Interrupt Active Bit Register 4                                       */
#define NVIC_IABR5_OFFSET 0x214UL /* (R/W) Interrupt Active Bit Register 5                                       */
#define NVIC_IABR6_OFFSET 0x218UL /* (R/W) Interrupt Active Bit Register 6                                       */
#define NVIC_IABR7_OFFSET 0x21CUL /* (R/W) Interrupt Active Bit Register 7                                       */
#define NVIC_IP0_OFFSET   0x300UL /* (R/W) Interrupt Priority Register 0                                         */
#define NVIC_IP1_OFFSET   0x304UL /* (R/W) Interrupt Priority Register 1                                         */
#define NVIC_IP2_OFFSET   0x308UL /* (R/W) Interrupt Priority Register 2                                         */
#define NVIC_IP3_OFFSET   0x30CUL /* (R/W) Interrupt Priority Register 3                                         */
#define NVIC_IP4_OFFSET   0x310UL /* (R/W) Interrupt Priority Register 4                                         */
#define NVIC_IP5_OFFSET   0x314UL /* (R/W) Interrupt Priority Register 5                                         */
#define NVIC_IP6_OFFSET   0x318UL /* (R/W) Interrupt Priority Register 6                                         */
#define NVIC_IP7_OFFSET   0x31CUL /* (R/W) Interrupt Priority Register 7                                         */
#define NVIC_IP8_OFFSET   0x320UL /* (R/W) Interrupt Priority Register 8                                         */
#define NVIC_IP9_OFFSET   0x324UL /* (R/W) Interrupt Priority Register 9                                         */
#define NVIC_IP10_OFFSET  0x328UL /* (R/W) Interrupt Priority Register 10                                        */
#define NVIC_IP11_OFFSET  0x32CUL /* (R/W) Interrupt Priority Register 11                                        */
#define NVIC_IP12_OFFSET  0x330UL /* (R/W) Interrupt Priority Register 12                                        */
#define NVIC_IP13_OFFSET  0x334UL /* (R/W) Interrupt Priority Register 13                                        */
#define NVIC_IP14_OFFSET  0x338UL /* (R/W) Interrupt Priority Register 14                                        */
#define NVIC_IP15_OFFSET  0x33CUL /* (R/W) Interrupt Priority Register 15                                        */
#define NVIC_IP16_OFFSET  0x340UL /* (R/W) Interrupt Priority Register 16                                        */
#define NVIC_IP17_OFFSET  0x344UL /* (R/W) Interrupt Priority Register 17                                        */
#define NVIC_IP18_OFFSET  0x348UL /* (R/W) Interrupt Priority Register 18                                        */
#define NVIC_IP19_OFFSET  0x34CUL /* (R/W) Interrupt Priority Register 19                                        */
#define NVIC_IP20_OFFSET  0x350UL /* (R/W) Interrupt Priority Register 20                                        */
#define NVIC_IP21_OFFSET  0x354UL /* (R/W) Interrupt Priority Register 21                                        */
#define NVIC_IP22_OFFSET  0x358UL /* (R/W) Interrupt Priority Register 22                                        */
#define NVIC_IP23_OFFSET  0x35CUL /* (R/W) Interrupt Priority Register 23                                        */
#define NVIC_IP24_OFFSET  0x360UL /* (R/W) Interrupt Priority Register 24                                        */
#define NVIC_IP25_OFFSET  0x364UL /* (R/W) Interrupt Priority Register 25                                        */
#define NVIC_IP26_OFFSET  0x368UL /* (R/W) Interrupt Priority Register 26                                        */
#define NVIC_IP27_OFFSET  0x36CUL /* (R/W) Interrupt Priority Register 27                                        */
#define NVIC_IP28_OFFSET  0x370UL /* (R/W) Interrupt Priority Register 28                                        */
#define NVIC_IP29_OFFSET  0x374UL /* (R/W) Interrupt Priority Register 29                                        */
#define NVIC_IP30_OFFSET  0x378UL /* (R/W) Interrupt Priority Register 30                                        */
#define NVIC_IP31_OFFSET  0x37CUL /* (R/W) Interrupt Priority Register 31                                        */
#define NVIC_IP32_OFFSET  0x380UL /* (R/W) Interrupt Priority Register 32                                        */
#define NVIC_IP33_OFFSET  0x384UL /* (R/W) Interrupt Priority Register 33                                        */
#define NVIC_IP34_OFFSET  0x388UL /* (R/W) Interrupt Priority Register 34                                        */
#define NVIC_IP35_OFFSET  0x38CUL /* (R/W) Interrupt Priority Register 35                                        */
#define NVIC_IP36_OFFSET  0x390UL /* (R/W) Interrupt Priority Register 36                                        */
#define NVIC_IP37_OFFSET  0x394UL /* (R/W) Interrupt Priority Register 37                                        */
#define NVIC_IP38_OFFSET  0x398UL /* (R/W) Interrupt Priority Register 38                                        */
#define NVIC_IP39_OFFSET  0x39CUL /* (R/W) Interrupt Priority Register 39                                        */
#define NVIC_IP40_OFFSET  0x3A0UL /* (R/W) Interrupt Priority Register 40                                        */
#define NVIC_IP41_OFFSET  0x3A4UL /* (R/W) Interrupt Priority Register 41                                        */
#define NVIC_IP42_OFFSET  0x3A8UL /* (R/W) Interrupt Priority Register 42                                        */
#define NVIC_IP43_OFFSET  0x3ACUL /* (R/W) Interrupt Priority Register 43                                        */
#define NVIC_IP44_OFFSET  0x3B0UL /* (R/W) Interrupt Priority Register 44                                        */
#define NVIC_IP45_OFFSET  0x3B4UL /* (R/W) Interrupt Priority Register 45                                        */
#define NVIC_IP46_OFFSET  0x3B8UL /* (R/W) Interrupt Priority Register 46                                        */
#define NVIC_IP47_OFFSET  0x3BCUL /* (R/W) Interrupt Priority Register 47                                        */
#define NVIC_IP48_OFFSET  0x3C0UL /* (R/W) Interrupt Priority Register 48                                        */
#define NVIC_IP49_OFFSET  0x3C4UL /* (R/W) Interrupt Priority Register 49                                        */
#define NVIC_IP50_OFFSET  0x3C8UL /* (R/W) Interrupt Priority Register 50                                        */
#define NVIC_IP51_OFFSET  0x3CCUL /* (R/W) Interrupt Priority Register 51                                        */
#define NVIC_IP52_OFFSET  0x3D0UL /* (R/W) Interrupt Priority Register 52                                        */
#define NVIC_IP53_OFFSET  0x3D4UL /* (R/W) Interrupt Priority Register 53                                        */
#define NVIC_IP54_OFFSET  0x3D8UL /* (R/W) Interrupt Priority Register 54                                        */
#define NVIC_IP55_OFFSET  0x3D8UL /* (R/W) Interrupt Priority Register 55                                        */
#define NVIC_IP56_OFFSET  0x3DCUL /* (R/W) Interrupt Priority Register 56                                        */
#define NVIC_IP57_OFFSET  0x3E0UL /* (R/W) Interrupt Priority Register 57                                        */
#define NVIC_IP58_OFFSET  0x3E4UL /* (R/W) Interrupt Priority Register 58                                        */
#define NVIC_IP59_OFFSET  0x3E8UL /* (R/W) Interrupt Priority Register 59                                        */
#define NVIC_STIR_OFFSET  0xE00UL /* ( /W) Software Trigger Interrupt Register                                   */

/*! NVIC Base Address
 */
#define NVIC_B_ADDR       0xE000E100

/*! NVIC Registers
 */
#define NVIC_ISER0        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER0_OFFSET))
#define NVIC_ISER1        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER1_OFFSET))
#define NVIC_ISER2        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER2_OFFSET))
#define NVIC_ISER3        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER3_OFFSET))
#define NVIC_ISER4        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER4_OFFSET))
#define NVIC_ISER5        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER5_OFFSET))
#define NVIC_ISER6        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER6_OFFSET))
#define NVIC_ISER7        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISER7_OFFSET))
#define NVIC_ICER0        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER0_OFFSET))
#define NVIC_ICER1        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER1_OFFSET))
#define NVIC_ICER2        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER2_OFFSET))
#define NVIC_ICER3        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER3_OFFSET))
#define NVIC_ICER4        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER4_OFFSET))
#define NVIC_ICER5        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER5_OFFSET))
#define NVIC_ICER6        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER6_OFFSET))
#define NVIC_ICER7        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICER7_OFFSET))
#define NVIC_ISPR0        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR0_OFFSET))
#define NVIC_ISPR1        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR1_OFFSET))
#define NVIC_ISPR2        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR2_OFFSET))
#define NVIC_ISPR3        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR3_OFFSET))
#define NVIC_ISPR4        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR4_OFFSET))
#define NVIC_ISPR5        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR5_OFFSET))
#define NVIC_ISPR6        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR6_OFFSET))
#define NVIC_ISPR7        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ISPR7_OFFSET))
#define NVIC_ICPR0        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR0_OFFSET))
#define NVIC_ICPR1        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR1_OFFSET))
#define NVIC_ICPR2        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR2_OFFSET))
#define NVIC_ICPR3        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR3_OFFSET))
#define NVIC_ICPR4        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR4_OFFSET))
#define NVIC_ICPR5        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR5_OFFSET))
#define NVIC_ICPR6        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR6_OFFSET))
#define NVIC_ICPR7        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_ICPR7_OFFSET))
#define NVIC_IABR0        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR0_OFFSET))
#define NVIC_IABR1        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR1_OFFSET))
#define NVIC_IABR2        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR2_OFFSET))
#define NVIC_IABR3        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR3_OFFSET))
#define NVIC_IABR4        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR4_OFFSET))
#define NVIC_IABR5        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR5_OFFSET))
#define NVIC_IABR6        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR6_OFFSET))
#define NVIC_IABR7        *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IABR7_OFFSET))
#define NVIC_IP0          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP0_OFFSET  ))
#define NVIC_IP1          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP1_OFFSET  ))
#define NVIC_IP2          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP2_OFFSET  ))
#define NVIC_IP3          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP3_OFFSET  ))
#define NVIC_IP4          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP4_OFFSET  ))
#define NVIC_IP5          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP5_OFFSET  ))
#define NVIC_IP6          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP6_OFFSET  ))
#define NVIC_IP7          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP7_OFFSET  ))
#define NVIC_IP8          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP8_OFFSET  ))
#define NVIC_IP9          *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP9_OFFSET  ))
#define NVIC_IP10         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP10_OFFSET ))
#define NVIC_IP11         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP11_OFFSET ))
#define NVIC_IP12         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP12_OFFSET ))
#define NVIC_IP13         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP13_OFFSET ))
#define NVIC_IP14         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP14_OFFSET ))
#define NVIC_IP15         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP15_OFFSET ))
#define NVIC_IP16         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP16_OFFSET ))
#define NVIC_IP17         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP17_OFFSET ))
#define NVIC_IP18         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP18_OFFSET ))
#define NVIC_IP19         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP19_OFFSET ))
#define NVIC_IP20         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP20_OFFSET ))
#define NVIC_IP21         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP21_OFFSET ))
#define NVIC_IP22         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP22_OFFSET ))
#define NVIC_IP23         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP23_OFFSET ))
#define NVIC_IP24         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP24_OFFSET ))
#define NVIC_IP25         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP25_OFFSET ))
#define NVIC_IP26         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP26_OFFSET ))
#define NVIC_IP27         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP27_OFFSET ))
#define NVIC_IP28         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP28_OFFSET ))
#define NVIC_IP29         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP29_OFFSET ))
#define NVIC_IP30         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP30_OFFSET ))
#define NVIC_IP31         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP31_OFFSET ))
#define NVIC_IP32         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP32_OFFSET ))
#define NVIC_IP33         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP33_OFFSET ))
#define NVIC_IP34         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP34_OFFSET ))
#define NVIC_IP35         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP35_OFFSET ))
#define NVIC_IP36         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP36_OFFSET ))
#define NVIC_IP37         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP37_OFFSET ))
#define NVIC_IP38         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP38_OFFSET ))
#define NVIC_IP39         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP39_OFFSET ))
#define NVIC_IP40         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP40_OFFSET ))
#define NVIC_IP41         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP41_OFFSET ))
#define NVIC_IP42         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP42_OFFSET ))
#define NVIC_IP43         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP43_OFFSET ))
#define NVIC_IP44         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP44_OFFSET ))
#define NVIC_IP45         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP45_OFFSET ))
#define NVIC_IP46         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP46_OFFSET ))
#define NVIC_IP47         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP47_OFFSET ))
#define NVIC_IP48         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP48_OFFSET ))
#define NVIC_IP49         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP49_OFFSET ))
#define NVIC_IP50         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP50_OFFSET ))
#define NVIC_IP51         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP51_OFFSET ))
#define NVIC_IP52         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP52_OFFSET ))
#define NVIC_IP53         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP53_OFFSET ))
#define NVIC_IP54         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP54_OFFSET ))
#define NVIC_IP55         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP55_OFFSET ))
#define NVIC_IP56         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP56_OFFSET ))
#define NVIC_IP57         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP57_OFFSET ))
#define NVIC_IP58         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP58_OFFSET ))
#define NVIC_IP59         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_IP59_OFFSET ))
#define NVIC_STIR         *((uint32_t volatile *)((uint8_t *)NVIC_B_ADDR + NVIC_STIR_OFFSET ))

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_STM32F446RE_NVIC_H */

/* EOF */
