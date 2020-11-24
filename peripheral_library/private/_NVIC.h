#include <stdint.h>
#include "registers_stm32f446re.h"

#ifndef _NVIC_H
#define _NVIC_H

/*! Enumeration describing the NVIC's channels.
 */
typedef enum IRQ_channel_num
{
	/* Processor Exception IRQ Numbers */
	  NVIC_non_maskable_int_IRQn   = -14
	, NVIC_memory_management_IRQn  = -12
	, NVIC_bus_fault_IRQn          = -11
	, NVIC_usage_fault_IRQn        = -10
	, NVIC_SVcall_IRQn             = -5
	, NVIC_debug_monitor_IRQn      = -4
	, NVIC_pend_SV_IRQn            = -2
	, NVIC_sys_tick_IRQn           = -1

	/* Interrupt IRQ Numbers */
	, NVIC_WWDG_IRQn               = 0
	, NVIC_PVD_IRQn                = 1
	, NVIC_TAMP_STAMP_IRQn         = 2
	, NVIC_RTC_WKUP_IRQn           = 3
	, NVIC_FLASH_IRQn              = 4
	, NVIC_RCC_IRQn                = 5
	, NVIC_EXTI0_IRQn              = 6
	, NVIC_EXTI1_IRQn              = 7
	, NVIC_EXTI2_IRQn              = 8
	, NVIC_EXTI3_IRQn              = 9
	, NVIC_EXTI4_IRQn              = 10
	, NVIC_DMA1_Stream0_IRQn       = 11
	, NVIC_DMA1_Stream1_IRQn       = 12
	, NVIC_DMA1_Stream2_IRQn       = 13
	, NVIC_DMA1_Stream3_IRQn       = 14
	, NVIC_DMA1_Stream4_IRQn       = 15
	, NVIC_DMA1_Stream5_IRQn       = 16
	, NVIC_DMA1_Stream6_IRQn       = 17
	, NVIC_ADC_IRQn                = 18
	, NVIC_CAN1_TX_IRQn            = 19
	, NVIC_CAN1_RX0_IRQn           = 20
	, NVIC_CAN1_RX1_IRQn           = 21
	, NVIC_CAN1_SCE_IRQn           = 22
	, NVIC_EXTI9_5_IRQn            = 23
	, NVIC_TIM1_BRK_TIM9_IRQn      = 24
	, NVIC_TIM1_UP_TIM10_IRQn      = 25
	, NVIC_TIM1_TRG_COM_TIM11_IRQn = 26
	, NVIC_TIM1_CC_IRQn            = 27
	, NVIC_TIM2_IRQn               = 28
	, NVIC_TIM3_IRQn               = 29
	, NVIC_TIM4_IRQn               = 30
	, NVIC_I2C1_EV_IRQn            = 31
	, NVIC_I2C1_ER_IRQn            = 32
	, NVIC_I2C2_EV_IRQn            = 33
	, NVIC_I2C2_ER_IRQn            = 34
	, NVIC_SPI1_IRQn               = 35
	, NVIC_SPI2_IRQn               = 36
	, NVIC_USART1_IRQn             = 37
	, NVIC_USART2_IRQn             = 38
	, NVIC_USART3_IRQn             = 39
	, NVIC_EXTI15_10_IRQn          = 40
	, NVIC_RTC_Alarm_IRQn          = 41
	, NVIC_OTG_FS_WKUP_IRQn        = 42
	, NVIC_TIM8_BRK_TIM12_IRQn     = 43
	, NVIC_TIM8_UP_TIM13_IRQn      = 44
	, NVIC_TIM8_TRG_COM_TIM14_IRQn = 45
	, NVIC_TIM8_CC_IRQn            = 46
	, NVIC_DMA1_Stream7_IRQn       = 47
	, NVIC_FMC_IRQn                = 48
	, NVIC_SDIO_IRQn               = 49
	, NVIC_TIM5_IRQn               = 50
	, NVIC_SPI3_IRQn               = 51
	, NVIC_UART4_IRQn              = 52
	, NVIC_UART5_IRQn              = 53
	, NVIC_TIM6_DAC_IRQn           = 54
	, NVIC_TIM7_IRQn               = 55
	, NVIC_DMA2_Stream0_IRQn       = 56
	, NVIC_DMA2_Stream1_IRQn       = 57
	, NVIC_DMA2_Stream2_IRQn       = 58
	, NVIC_DMA2_Stream3_IRQn       = 59
	, NVIC_DMA2_Stream4_IRQn       = 60
	, NVIC_CAN2_TX_IRQn            = 63
	, NVIC_CAN2_RX0_IRQn           = 64
	, NVIC_CAN2_RX1_IRQn           = 65
	, NVIC_CAN2_SCE_IRQn           = 66
	, NVIC_OTG_FS_IRQn             = 67
	, NVIC_DMA2_Stream5_IRQn       = 68
	, NVIC_DMA2_Stream6_IRQn       = 69
	, NVIC_DMA2_Stream7_IRQn       = 70
	, NVIC_USART6_IRQn             = 71
	, NVIC_I2C3_EV_IRQn            = 72
	, NVIC_I2C3_ER_IRQn            = 73
	, NVIC_OTG_HS_EP1_OUT_IRQn     = 74
	, NVIC_OTG_HS_EP1_IN_IRQn      = 75
	, NVIC_OTG_HS_WKUP_IRQn        = 76
	, NVIC_OTG_HS_IRQn             = 77
	, NVIC_DCMI_IRQn               = 78
	, NVIC_FPU_IRQn                = 81
	, NVIC_SPI4_IRQn               = 84
	, NVIC_SAI1_IRQn               = 87
	, NVIC_SAI2_IRQn               = 91
	, NVIC_QUADSPI_IRQn            = 92
	, NVIC_CEC_IRQn                = 93
	, NVIC_SPDIF_RX_IRQn           = 94
	, NVIC_FMPI2C1_EV_IRQn         = 95
	, NVIC_FMPI2C1_ER_IRQn         = 96
} IRQ_channel_num;

/*! Sets the priority of the desired interrupt.
 *
 * @brief To configure the priority of an interrupt on this system we need to interface with the Nested Vector
 *        Interrupt Controller (NVIC). The NVIC has 96 channels that correspond to the 96 possible interrupt
 *        sources (some peripherals/GPIO pins share a single channel to make this work). Of these 96 channels, the
 *        non-processor exceptions share 60 Interrupt Priority (IP) registers where each IP register has four 8-bit
 *        fields. Each one of these fields corresponds to a single interrupt channel and its priority. To find
 *        which IP register corresponds to the desired IRQ channel we simply take the IRQ channel and divide by 4
 *        (via integer operation). To find which 8-bit priority field within the IP register we need for the
 *        desired IRQ channel, we take the IRQ channel and modulo by 4.
 *
 *        In the case where the desired channel is a processor exception, we can't use the NVIC's IP registers.
 *        Instead we have to interface with System Control Block's (SCB) System Handler Priority (SHP) registers.
 *        These registers have pre-defined spots for the processor exception priorities shown below:
 *        Usage Fault    SHP0 register bits 23:16
 *        Bus Fault      SHP0 register bits 15:8
 *        Mem Management SHP0 register bits 7:0
 *        SVCall         SHP1 register bits 31:24
 *        SysTick        SHP2 register bits 31:24
 *        PendSV         SHP2 register bits 23:16
 *
 *        Note that of the 8 bits available in both the IP register's 4 fields and the SHP registers pre-defined
 *        fields, only the 4 most signficant bits have been implemented on this particular board thus the priority
 *        values are always shifted to the left by 4 (and masked with 0xFF to ensure that we are only getting what
 *        was originally the 8-bit value).
 *
 * @note  For syntactical simplicity, there is no big if-else or switch statement for each one of the 60 NVIC IP
 *        registers. Instead, the address of the register necessary for the desired IRQ channel is calculated by
 *        taking the address of the first (0th) IP register and offsetting it by the IP register number * 4 (where
 *        the 4 represents the 4 byte offset each IP register has with each other).
 *
 * @param IRQ_channel
 *    (input) The NVIC channel whose priority is to be set.
 * @param priority
 *    (input) The desired priority for the NVIC channel. Must be between 0 and 15. The higher the number, the lower
 *            the priority.
 */
__attribute__((always_inline)) inline void _NVIC_channel_set_priority(IRQ_channel_num const IRQ_channel
	, uint32_t const priority
) {
	uint32_t const max_priority = 15;
	uint32_t const NVIC_IP_reg_num = (uint32_t)IRQ_channel / 4U;
	uint32_t const NVIC_IP_reg_field = (uint32_t)IRQ_channel % 4U;
	uint32_t volatile * const NVIC_IPn_addr = \
		(uint32_t *)((uint8_t *)(&(NVIC_IP0)) + (uint32_t)(0x4U * NVIC_IP_reg_num));

	if ((int32_t)IRQ_channel >= 0) { //Not a processor exception
		if (priority <= max_priority) {
			*NVIC_IPn_addr |= ((priority << 4U) & 0xFFU) << (8 * NVIC_IP_reg_field);
		} else {
			//Priority is an invalid value, do nothing
		}
	} else {
		switch (IRQ_channel)
		{
			case NVIC_usage_fault_IRQn:
				SCB_SHP0 |= ((priority << 4U) & 0xFFU) << 16;
				break;
			case NVIC_bus_fault_IRQn:
				SCB_SHP0 |= ((priority << 4U) & 0xFFU) << 8;
				break;
			case NVIC_memory_management_IRQn:
				SCB_SHP0 |= (priority << 4U) & 0xFFU;
				break;
			case NVIC_SVcall_IRQn:
				SCB_SHP1 |= ((priority << 4U) & 0xFFU) << 24;
				break;
			case NVIC_sys_tick_IRQn:
				SCB_SHP2 |= ((priority << 4U) & 0xFFU) << 24;
				break;
			case NVIC_pend_SV_IRQn:
				SCB_SHP2 |= ((priority << 4U) & 0xFFU) << 16;
				break;
			default:
				break;
		}
	}
}

/*! Enables an interrupt channel in the NVIC.
 *
 * @brief To enable one of the 96 channels in the NVIC we have to set the correct bit in one of the 8 Interrupt
 *        Set Enable Registers (ISER). The bits in these registers are organized in the following manner:
 *        Bit 0 of ISER0 -> IRQ channel 0
 *        Bit 1 of ISER0 -> IRQ channel 1
 *        Bit 2 of ISER0 -> IRQ channel 2
 *        ...
 *        Bit 0 of ISER1 -> IRQ_channel 32
 *        Bit 1 of ISER1 -> IRQ_channel 33
 *        ...
 *        Bit 0 of ISER2 -> IRQ_channel 64
 *        ...
 *
 *        So to find which ISER register the desired IRQ channel is associated with we take the channel number and
 *        divide by 32 (via integer operation). The bit position in said register is the calculated by taking the
 *        desired channel number and subtracting by a multiple of 32 equal to the ISER register number. For
 *        instance, a desired IRQ channel number of 54 would result in an ISER register number of 54 / 32 = 1
 *        (i.e. ISER1) and a bit position in that register of 54 - (32 * 1) = 22.
 *
 *        The check to see if the desired IRQ channel is greater than or equal to zero is to prevent this function
 *        from being called on a processor exception. The processor exceptions, from what I understand, are always
 *        enabled.
 *
 * @note  There are memory barriers surrounding the write to the NVIC ISER register so as to inform the compiler
 *        (at compile time) to not move loads or stores beyond this point.
 *
 * @param IRQ_channel
 *    (input) The NVIC channel that is to be enabled.
 */
__attribute__((always_inline)) inline void _NVIC_channel_enable(IRQ_channel_num const IRQ_channel)
{
	uint32_t NVIC_ISERn = (uint32_t)IRQ_channel / 32U;
	uint32_t NVIC_ISERn_bit_pos = (uint32_t)IRQ_channel - (32U * NVIC_ISERn);
	uint32_t volatile * const NVIC_ISERn_addr = \
		(uint32_t *)((uint8_t *)(&(NVIC_ISER0)) + (uint32_t)(0x4U * NVIC_ISERn));

	if ((int32_t)IRQ_channel >= 0) {
		__asm__ volatile ("": : : "memory");
		*NVIC_ISERn_addr |= 0x1 << NVIC_ISERn_bit_pos;
		__asm__ volatile ("": : : "memory");
	} else {
		//Desired IRQ channel is a processor exception, do nothing
	}
}

/*! Disables an interrupt channel in the NVIC.
 *
 * @brief To disable one of the 96 channels in the NVIC we have to set the correct bit in one of the 8 Interrupt
 *        Clear Enable Registers (ICER). The bits in these registers are organized in the following manner:
 *        Bit 0 of ICER0 -> IRQ channel 0
 *        Bit 1 of ICER0 -> IRQ channel 1
 *        Bit 2 of ICER0 -> IRQ channel 2
 *        ...
 *        Bit 0 of ICER1 -> IRQ_channel 32
 *        Bit 1 of ICER1 -> IRQ_channel 33
 *        ...
 *        Bit 0 of ICER2 -> IRQ_channel 64
 *        ...
 *
 *        So to find which ICER register the desired IRQ channel is associated with we take the channel number and
 *        divide by 32 (via integer operation). The bit position in said register is the calculated by taking the
 *        desired channel number and subtracting by a multiple of 32 equal to the ICER register number. For
 *        instance, a desired IRQ channel number of 54 would result in an ICER register number of 54 / 32 = 1
 *        (i.e. ICER1) and a bit position in that register of 54 - (32 * 1) = 22.
 *
 *        The check to see if the desired IRQ channel is greater than or equal to zero is to prevent this function
 *        from being called on a processor exception. The processor exceptions, from what I understand, are always
 *        enabled.
 *
 * @note  There are memory barriers surrounding the write to the NVIC ICER register so as to inform the compiler
 *        (at compile time) to not move loads or stores beyond this point.
 *
 * @param IRQ_channel
 *    (input) The NVIC channel that is to be disabled.
 */
__attribute__((always_inline)) inline void _NVIC_channel_disable(IRQ_channel_num const IRQ_channel)
{
	uint32_t NVIC_ICERn = (uint32_t)IRQ_channel / 32U;
	uint32_t NVIC_ICERn_bit_pos = (uint32_t)IRQ_channel - (32U * NVIC_ICERn);
	uint32_t volatile * const NVIC_ICERn_addr = \
		(uint32_t *)((uint8_t *)(&(NVIC_ICER0)) + (uint32_t)(0x4U * NVIC_ICERn));

	if ((int32_t)IRQ_channel >= 0) {
		__asm__ volatile ("": : : "memory");
		*NVIC_ICERn_addr |= 0x1 << NVIC_ICERn_bit_pos;
		__asm__ volatile ("": : : "memory");
	} else {
		//Desired IRQ channel is a processor exception, do nothing
	}
}

#endif /* _NVIC_H */

/* EOF */
