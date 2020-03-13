#include <stdint.h>

/* ============================================================================================================= */
/* System Clock Variable for Peripherals to Use                                                                  */
/* ============================================================================================================= */
uint32_t system_clk_freq = 0;

/* ============================================================================================================= */
/* Memory Region Symbols (Provided by Linker Script)                                                             */
/* ============================================================================================================= */
extern uint32_t __vector_end;   /* End of the vector table   */
extern uint32_t __vector_size;  /* Size of the vector table  */
extern uint32_t __etext;        /* End of text segment       */
extern uint32_t __data_start__; /* Start of the data segment */
extern uint32_t __data_end__;   /* End of the data segment   */
extern uint32_t __bss_start__;  /* Start of the bss segment  */
extern uint32_t __bss_end__;    /* End of the bss segment    */
extern uint32_t __heap_base;    /* Base of the heap          */
extern uint32_t __heap_limit;   /* Max address of the heap   */
extern uint32_t __stack_top;    /* Top of stack              */
extern uint32_t __stack_limit;  /* Max address of the stack  */

/* ============================================================================================================= */
/* Main Declaration                                                                                              */
/* ============================================================================================================= */
extern void main(void);

/* ============================================================================================================= */
/* User Initial Stack and Heap Setup                                                                             */
/* ============================================================================================================= */
#ifndef __STACK_SIZE
	#define __STACK_SIZE 0x00000400
#endif /* __STACK_SIZE */
static uint8_t stack[__STACK_SIZE] __attribute__((aligned(8), used, section(".stack")));

#if __HEAP_SIZE > 0
static uint8_t heap[__HEAP_SIZE] __attribute__((aligned(8), used, section(".heap")));
#endif /* __HEAP_SIZE > 0 */

/* ============================================================================================================= */
/* Cortex-M4 Processor Exception Handlers                                                                        */
/* ============================================================================================================= */
/* Default
 *     The default implementation of all exceptions or interrupts besides reset. Serves as a placeholder.
 * Reset
 *     Invoked on power up/warm reset. When asserted processor operation stops. When deasserted, execution restarts
 *     from the address provided by the reset entry in the vector table (or the address in the VTOR).
 * Non Maskable Interrupt (NMI)
 *     Highest priority exception other than reset, CANNOT be masked.
 * Hard Fault
 *     Error during exception processing or when an exception cannot be managed by any other exception mechanism.
 * Memory Manage Fault (MemManage)
 *     Memory protection related fault. Always used to abort instruction accesses to Execute Never (XN) regions.
 * Bus Fault
 *     Memory related fault for an instruction or data memory transaction.
 * Usage Fault
 *     Fault caused by: undefined instruction, illegal unaligned access, invalid state on instruction execution, or
 *     error on exception return.
 * Supervisor Call Fault (SVCall)
 *     Triggered by the SVC instruction.
 * Debug Monitor
 *     Handler to carry out debugging tasks while still allowing higher-priority exceptions to take place.
 * PendSV
 *     Interrupt-drive request for system-level service.
 * SysTick
 *     Exception that the system timer generates when it reaches zero.
 */
void default_handler(void);
void reset_handler(void);
void NMI_handler(void)                 __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void)          __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void)          __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void)           __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void)         __attribute__((weak, alias("default_handler")));
void SVC_handler(void)                 __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void)       __attribute__((weak, alias("default_handler")));
void pend_SV_handler(void)             __attribute__((weak, alias("default_handler")));
void sys_tick_handler(void)            __attribute__((weak, alias("default_handler")));

/* ============================================================================================================= */
/* External Interrupt Handlers                                                                                   */
/* ============================================================================================================= */
void WWDG_handler(void)                __attribute__((weak, alias("default_handler")));
void PVD_handler(void)                 __attribute__((weak, alias("default_handler")));
void TAMP_STAMP_handler(void)          __attribute__((weak, alias("default_handler")));
void RTC_WKUP_handler(void)            __attribute__((weak, alias("default_handler")));
void FLASH_handler(void)               __attribute__((weak, alias("default_handler")));
void RCC_handler(void)                 __attribute__((weak, alias("default_handler")));
void EXTI0_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI1_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI2_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI3_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI4_handler(void)               __attribute__((weak, alias("default_handler")));
void DMA1_Stream0_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream1_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream2_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream3_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream4_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream5_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream6_handler(void)        __attribute__((weak, alias("default_handler")));
void ADC_handler(void)                 __attribute__((weak, alias("default_handler")));
void CAN1_TX_handler(void)             __attribute__((weak, alias("default_handler")));
void CAN1_RX0_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN1_RX1_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN1_SCE_handler(void)            __attribute__((weak, alias("default_handler")));
void EXTI9_5_handler(void)             __attribute__((weak, alias("default_handler")));
void TMI1_BRK_TIM9_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM10_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM11_handler(void)  __attribute__((weak, alias("default_handler")));
void TIM1_CC_handler(void)             __attribute__((weak, alias("default_handler")));
void TIM2_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM3_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM4_handler(void)                __attribute__((weak, alias("default_handler")));
void I2C1_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C1_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C2_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C2_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void SPI1_handler(void)                __attribute__((weak, alias("default_handler")));
void SPI2_handler(void)                __attribute__((weak, alias("default_handler")));
void USART1_handler(void)              __attribute__((weak, alias("default_handler")));
void USART2_handler(void)              __attribute__((weak, alias("default_handler")));
void USART3_handler(void)              __attribute__((weak, alias("default_handler")));
void EXTI15_10_handler(void)           __attribute__((weak, alias("default_handler")));
void RTC_alarm_handler(void)           __attribute__((weak, alias("default_handler")));
void OTG_FS_WKUP_handler(void)         __attribute__((weak, alias("default_handler")));
void TIM8_BRK_TIM12_handler(void)      __attribute__((weak, alias("default_handler")));
void TIM8_UP_TIM13_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM8_TRG_COM_TIM14_handler(void)  __attribute__((weak, alias("default_handler")));
void TIM8_CC_handler(void)             __attribute__((weak, alias("default_handler")));
void DMA1_Stream7_handler(void)        __attribute__((weak, alias("default_handler")));
void FMC_handler(void)                 __attribute__((weak, alias("default_handler")));
void SDIO_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM5_handler(void)                __attribute__((weak, alias("default_handler")));
void SPI3_handler(void)                __attribute__((weak, alias("default_handler")));
void UART4_handler(void)               __attribute__((weak, alias("default_handler")));
void UART5_handler(void)               __attribute__((weak, alias("default_handler")));
void TIM6_DAC_handler(void)            __attribute__((weak, alias("default_handler")));
void TIM7_handler(void)                __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream1_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream2_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream3_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream4_handler(void)        __attribute__((weak, alias("default_handler")));
void CAN2_TX_handler(void)             __attribute__((weak, alias("default_handler")));
void CAN2_RX0_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN2_RX1_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN2_SCE_handler(void)            __attribute__((weak, alias("default_handler")));
void OTG_FS_handler(void)              __attribute__((weak, alias("default_handler")));
void DMA2_Stream5_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream6_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream7_handler(void)        __attribute__((weak, alias("default_handler")));
void USART6_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C3_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C3_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void OTG_HS_EP1_OUT_handler(void)      __attribute__((weak, alias("default_handler")));
void OTG_HS_EP1_IN_handler(void)       __attribute__((weak, alias("default_handler")));
void OTG_HS_WKUP_handler(void)         __attribute__((weak, alias("default_handler")));
void OTG_HS_handler(void)              __attribute__((weak, alias("default_handler")));
void DCMI_handler(void)                __attribute__((weak, alias("default_handler")));
void FPU_handler(void)                 __attribute__((weak, alias("default_handler")));
void SPI4_handler(void)                __attribute__((weak, alias("default_handler")));
void SAI1_handler(void)                __attribute__((weak, alias("default_handler")));
void SAI2_handler(void)                __attribute__((weak, alias("default_handler")));
void QuadSPI_handler(void)             __attribute__((weak, alias("default_handler")));
void HDMI_CEC_handler(void)            __attribute__((weak, alias("default_handler")));
void SPDIF_RX_handler(void)            __attribute__((weak, alias("default_handler")));
void FMPI2C1_handler(void)             __attribute__((weak, alias("default_handler")));
void FMPI2C1_error_handler(void)       __attribute__((weak, alias("default_handler")));

/* ============================================================================================================= */
/* Interrupt Vector Table                                                                                        */
/* ============================================================================================================= */
__attribute__((section(".vector_table"))) void (* const __vector_table[])(void) = {
	/* Processor Exceptions         Description                                     Priority          Address     */
	(void (*)(void))&__stack_top /* Initial Stack Pointer                           N/A               0x0000 0000 */
	, reset_handler              /* Reset Handler                                   -3                0x0000 0004 */
	, NMI_handler                /* Non-maskable Interrupt Handler                  -2                0x0000 0008 */
	, hard_fault_handler         /* Hard Fault Handler                              -1                0x0000 000C */
	, mem_manage_handler         /* Memory Protection Unit Error Handler             0 (settable)     0x0000 0010 */
	, bus_fault_handler          /* Bus Fault Handler                                1 (settable)     0x0000 0014 */
	, usage_fault_handler        /* Usage Fault Handler                              2 (settable)     0x0000 0018 */
	, 0                          /* Reserved                                        N/A               0x0000 001C */
	, 0                          /* Reserved                                        N/A               0x0000 0020 */
	, 0                          /* Reserved                                        N/A               0x0000 0024 */
	, 0                          /* Reserved                                        N/A               0x0000 002B */
	, SVC_handler                /* Supervisor Call Handler                          3 (settable)     0x0000 002C */
	, debug_monitor_handler      /* Debug Monitor Handler                            4 (settable)     0x0000 0030 */
	, 0                          /* Reserved                                        N/A               0x0000 0034 */
	, pend_SV_handler            /* PendSV Handler                                   5 (settable)     0x0000 0038 */
	, sys_tick_handler           /* SysTick Handler                                  6 (settable)     0x0000 003C */

	/* External Interrupts          Description                                     Priority          Address     */
	, WWDG_handler               /* Window Watchdog                                 0-15 (settable)   0x0000 0040 */
	, PVD_handler                /* Programmable Voltage Detector                   0-15 (settable)   0x0000 0044 */
	, TAMP_STAMP_handler         /* Tamper and TimeStamp                            0-15 (settable)   0x0000 0048 */
	, RTC_WKUP_handler           /* Real Time Clock Wakeup                          0-15 (settable)   0x0000 004C */
	, FLASH_handler              /* Flash Global                                    0-15 (settable)   0x0000 0050 */
	, RCC_handler                /* Reset and Clock Control Global                  0-15 (settable)   0x0000 0054 */
	, EXTI0_handler              /* External Interrupt Controller Line 0            0-15 (settable)   0x0000 0058 */
	, EXTI1_handler              /* External Interrupt Controller Line 1            0-15 (settable)   0x0000 005C */
	, EXTI2_handler              /* External Interrupt Controller Line 2            0-15 (settable)   0x0000 0060 */
	, EXTI3_handler              /* External Interrupt Controller Line 3            0-15 (settable)   0x0000 0064 */
	, EXTI4_handler              /* External Interrupt Controller Line 4            0-15 (settable)   0x0000 0068 */
	, DMA1_Stream0_handler       /* DMA1 Stream0 Global                             0-15 (settable)   0x0000 006C */
	, DMA1_Stream1_handler       /* DMA1 Stream1 Global                             0-15 (settable)   0x0000 0070 */
	, DMA1_Stream2_handler       /* DMA1 Stream2 Global                             0-15 (settable)   0x0000 0074 */
	, DMA1_Stream3_handler       /* DMA1 Stream3 Global                             0-15 (settable)   0x0000 0078 */
	, DMA1_Stream4_handler       /* DMA1 Stream4 Global                             0-15 (settable)   0x0000 007C */
	, DMA1_Stream5_handler       /* DMA1 Stream5 Global                             0-15 (settable)   0x0000 0080 */
	, DMA1_Stream6_handler       /* DMA1 Stream6 Global                             0-15 (settable)   0x0000 0084 */
	, ADC_handler                /* ADCs 1,2,3 Global                               0-15 (settable)   0x0000 0088 */
	, CAN1_TX_handler            /* Controller Area Network 1 TX                    0-15 (settable)   0x0000 008C */
	, CAN1_RX0_handler           /* Controller Area Network 1 RX0                   0-15 (settable)   0x0000 0090 */
	, CAN1_RX1_handler           /* Controller Area Network 1 RX1                   0-15 (settable)   0x0000 0094 */
	, CAN1_SCE_handler           /* Controller Area Network 1 SCE                   0-15 (settable)   0x0000 0098 */
	, EXTI9_5_handler            /* External Interrupt Controller Lines 9-5         0-15 (settable)   0x0000 009C */
	, TMI1_BRK_TIM9_handler      /* Timer 1 Break/Timer 9 Global                    0-15 (settable)   0x0000 00A0 */
	, TIM1_UP_TIM10_handler      /* Timer 1 Update/Timer10 Global                   0-15 (settable)   0x0000 00A4 */
	, TIM1_TRG_COM_TIM11_handler /* Timer 1 Trigger & Communication/Timer 11 Global 0-15 (settable)   0x0000 00A8 */
	, TIM1_CC_handler            /* Timer1 Capture Compare                          0-15 (settable)   0x0000 00AC */
	, TIM2_handler               /* Timer 2 Global                                  0-15 (settable)   0x0000 00B0 */
	, TIM3_handler               /* Timer 3 Global                                  0-15 (settable)   0x0000 00B4 */
	, TIM4_handler               /* Timer 4 Global                                  0-15 (settable)   0x0000 00B8 */
	, I2C1_EV_handler            /* I2C1 Event                                      0-15 (settable)   0x0000 00BC */
	, I2C1_ER_handler            /* I2C1 Error                                      0-15 (settable)   0x0000 00C0 */
	, I2C2_EV_handler            /* I2C2 Event                                      0-15 (settable)   0x0000 00C4 */
	, I2C2_ER_handler            /* I2C2 Error                                      0-15 (settable)   0x0000 00C8 */
	, SPI1_handler               /* SPI1 Global                                     0-15 (settable)   0x0000 00CC */
	, SPI2_handler               /* SPI2 Global                                     0-15 (settable)   0x0000 00D0 */
	, USART1_handler             /* USART1 Global                                   0-15 (settable)   0x0000 00D4 */
	, USART2_handler             /* USART2 Global                                   0-15 (settable)   0x0000 00D8 */
	, USART3_handler             /* USART3 Global                                   0-15 (settable)   0x0000 00DC */
	, EXTI15_10_handler          /* External Interrupt Controller Lines 10-15       0-15 (settable)   0x0000 00E0 */
	, RTC_alarm_handler          /* Real Time Clock Alarms (A and B)                0-15 (settable)   0x0000 00E4 */
	, OTG_FS_WKUP_handler        /* USB On-The-Go Full-Speed Wakeup                 0-15 (settable)   0x0000 00E8 */
	, TIM8_BRK_TIM12_handler     /* Timer8 Break/Timer12 Global                     0-15 (settable)   0x0000 00EC */
	, TIM8_UP_TIM13_handler      /* Timer8 Update/Timer 13 Global                   0-15 (settable)   0x0000 00F0 */
	, TIM8_TRG_COM_TIM14_handler /* Timer8 Trigger & Communication/Timer14 Global   0-15 (settable)   0x0000 00F4 */
	, TIM8_CC_handler            /* Timer8 Capture and Compare                      0-15 (settable)   0x0000 00F8 */
	, DMA1_Stream7_handler       /* DMA1 Stream7                                    0-15 (settable)   0x0000 00FC */
	, FMC_handler                /* Flexible Memory Controller Global               0-15 (settable)   0x0000 0100 */
	, SDIO_handler               /* SD Card IO                                      0-15 (settable)   0x0000 0104 */
	, TIM5_handler               /* Timer 5 Global                                  0-15 (settable)   0x0000 0108 */
	, SPI3_handler               /* SPI3 Global                                     0-15 (settable)   0x0000 010C */
	, UART4_handler              /* UART4 Global                                    0-15 (settable)   0x0000 0110 */
	, UART5_handler              /* UART5 Global                                    0-15 (settable)   0x0000 0114 */
	, TIM6_DAC_handler           /* Timer6 Global/DAC1 and 2 Underrun Error         0-15 (settable)   0x0000 0118 */
	, TIM7_handler               /* Timer 7 Global                                  0-15 (settable)   0x0000 011C */
	, DMA2_Stream0_handler       /* DMA2 Stream 0 Global                            0-15 (settable)   0x0000 0120 */
	, DMA2_Stream1_handler       /* DMA2 Stream 1 Global                            0-15 (settable)   0x0000 0124 */
	, DMA2_Stream2_handler       /* DMA2 Stream 2 Global                            0-15 (settable)   0x0000 0128 */
	, DMA2_Stream3_handler       /* DMA2 Stream 3 Global                            0-15 (settable)   0x0000 012C */
	, DMA2_Stream4_handler       /* DMA2 Stream 4 Global                            0-15 (settable)   0x0000 0130 */
	, 0                          /* Reserved                                        N/A               0x0000 0134 */
	, 0                          /* Reserved                                        N/A               0x0000 0138 */
	, CAN2_TX_handler            /* Controller Area Network2 TX                     0-15 (settable)   0x0000 013C */
	, CAN2_RX0_handler           /* Controller Area Network2 RX0                    0-15 (settable)   0x0000 0140 */
	, CAN2_RX1_handler           /* Controller Area Network2 RX1                    0-15 (settable)   0x0000 0144 */
	, CAN2_SCE_handler           /* Controller Area Network2 SCE                    0-15 (settable)   0x0000 0148 */
	, OTG_FS_handler             /* USB On-The-Go Full-Speed Global                 0-15 (settable)   0x0000 014C */
	, DMA2_Stream5_handler       /* DMA2 Stream5 Global                             0-15 (settable)   0x0000 0150 */
	, DMA2_Stream6_handler       /* DMA2 Stream6 Global                             0-15 (settable)   0x0000 0154 */
	, DMA2_Stream7_handler       /* DMA2 Stream7 Global                             0-15 (settable)   0x0000 0158 */
	, USART6_handler             /* USART6 Global                                   0-15 (settable)   0x0000 015C */
	, I2C3_EV_handler            /* I2C3 Event                                      0-15 (settable)   0x0000 0160 */
	, I2C3_ER_handler            /* I2C3 Error                                      0-15 (settable)   0x0000 0164 */
	, OTG_HS_EP1_OUT_handler     /* USB On-The-Go High-Speed End Point 1 Out Global 0-15 (settable)   0x0000 0168 */
	, OTG_HS_EP1_IN_handler      /* USB On-The-Go High-Speed End Point 1 In Global  0-15 (settable)   0x0000 016C */
	, OTG_HS_WKUP_handler        /* USB On-The-Go High-Speed Wakeup                 0-15 (settable)   0x0000 0170 */
	, OTG_HS_handler             /* USB On-The-Go High-Speed Global                 0-15 (settable)   0x0000 0174 */
	, DCMI_handler               /* Digital Camera Interface Global                 0-15 (settable)   0x0000 0178 */
	, 0                          /* Reserved                                        N/A               0x0000 017C */
	, 0                          /* Reserved                                        N/A               0x0000 0180 */
	, FPU_handler                /* FPU Global                                      0-15 (settable)   0x0000 0184 */
	, 0                          /* Reserved                                        N/A               0x0000 0188 */
	, 0                          /* Reserved                                        N/A               0x0000 018C */
	, SPI4_handler               /* SPI4 Global                                     0-15 (settable)   0x0000 0190 */
	, 0                          /* Reserved                                        N/A               0x0000 0194 */
	, 0                          /* Reserved                                        N/A               0x0000 0198 */
	, SAI1_handler               /* Synchronous Audio Interface1                    0-15 (settable)   0x0000 019C */
	, 0                          /* Reserved                                        N/A               0x0000 01A0 */
	, 0                          /* Reserved                                        N/A               0x0000 01A4 */
	, 0                          /* Reserved                                        N/A               0x0000 01A8 */
	, SAI2_handler               /* Synchronous Audio Interface2                    0-15 (settable)   0x0000 01AC */
	, QuadSPI_handler            /* Quad SPI                                        0-15 (settable)   0x0000 01B0 */
	, HDMI_CEC_handler           /* HDMI Consumer Electronics Control               0-15 (settable)   0x0000 01B4 */
	, SPDIF_RX_handler           /* Sony/Phillips Digital Interface                 0-15 (settable)   0x0000 01B8 */
	, FMPI2C1_handler            /* Fast Mode Plus I2C                              0-15 (settable)   0x0000 01BC */
	, FMPI2C1_error_handler      /* Fast Mode Plus I2C                              0-15 (settable)   0x0000 01C0 */
};

/* ============================================================================================================= */
/* System Initialization Code (Called by Reset Handler)                                                          */
/* ============================================================================================================= */
void system_init()
{
	uint8_t  volatile * const rcc_base = (uint8_t *)0x40023800;  //Reset and clock control register
	uint32_t volatile * const scb_vtor = (uint32_t *)0xE000ED04; //System control block vector table offset register

	/* Configure the hard FPU if it is being used */
#if (__FPU_USED == 1)
	uint32_t volatile * const fpu_cpacr = (uint32_t *)0xE000ED88; //FPU coprocessor access control register
	*fpu_cpacr |= 0x3 << 20; //Set CP10 to full access
	*fpu_cpacr |= 0x3 << 22; //Set CP11 to full access
#endif /* __FPU_USED */

	/* Configure the System Clock to be the Internal High-Speed Clock (HSI) */
	*(uint32_t *)(rcc_base + 0x00) |= (uint32_t)0x00000001; //Enable internal high-speed clk (HSI)
	*(uint32_t *)(rcc_base + 0x08) =  (uint32_t)0x00000000; //Reset MCU clks and prescalers
	*(uint32_t *)(rcc_base + 0x00) &= (uint32_t)0xFEF6FFFF; //Disable HSE, main PLL, and clk security system
	*(uint32_t *)(rcc_base + 0x04) =  (uint32_t)0x24003010; //Reset PLL configuration register
	*(uint32_t *)(rcc_base + 0x00) &= (uint32_t)0xFFFBFFFF; //Disable the HSE oscillator being bypassed w/ ext clk
	*(uint32_t *)(rcc_base + 0x0C) =  (uint32_t)0x00000000; //Disable all interrupts

	/* Update the system clock variable */
	system_clk_freq = 16000000;

	/* Configure the vector table location (defaults to 0x0000_0000, which is aliased to 0x0800_0000 BUT
	 * assigning a new value into the VTOR allows this to change) */
#ifndef __VECT_TABLE_OFFSET
	#define __VECT_TABLE_OFFSET 0x00000000
#endif /* __VECT_TABLE_OFFSET */
	*scb_vtor = 0x08000000 | __VECT_TABLE_OFFSET;

	return;
}

/* ============================================================================================================= */
/* Reset Handler (Called on Processor Reset)                                                                     */
/* ============================================================================================================= */
/*! The code to be run on processor power-on.
 *
 * @note When -O3 is enabled, GCC optimizes the for-loops with calls to memcpy. To prevent libc calls ending up in
 *       system startup code, the reset handler is forcibly optimized at -O2.
 */
__attribute__((optimize("O2"))) void reset_handler(void)
{
	uint32_t * p_src = 0, * p_dest = 0;

	/* Copy single ROM .data section (includes vector table) to start of .data section in RAM */
	for (p_src = &__etext, p_dest = &__data_start__; p_dest < &__data_end__;) {
		*p_dest++ = *p_src++;
	}

	/* Clear single BSS section, usually done by the libc */
	for (p_dest = &__bss_start__; p_dest < &__bss_end__;) {
		*p_dest++ = 0ul;
	}

	system_init();

	main();

	while (1);
}

/* ============================================================================================================= */
/* Default Handler for Exceptions/Interrupts                                                                     */
/* ============================================================================================================= */
void default_handler(void)
{
	while (1);
}

/* EOF */
