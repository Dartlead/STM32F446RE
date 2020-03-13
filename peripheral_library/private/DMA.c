#include "DMA.h"
#include "_stm32f446re_registers.h"
#include "_GCC_ARM_ASM_intrinsics.h"
#include "_NVIC.h"
#include <stdlib.h>

#define _DMA_MAX_NUM_CNTRLRS 2
#define _DMA_MAX_NUM_STREAMS 8

/* ============================================================================================================= */
/* User-Provided Interrupt Service Routines                                                                      */
/* ============================================================================================================= */
/*! The user ISRs for each combination of DMA controller and stream. First dimension is DMA controller number (0
 *  or 1 for DMA1 and DMA2 respectively), second dimension is stream number (0-7).
 */
static void (* DMAx_Streamy_user_handlers[_DMA_MAX_NUM_CNTRLRS][_DMA_MAX_NUM_STREAMS])(void) = {
	  { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }
	, { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }
};

/* ============================================================================================================= */
/* Interrupt Service Routines                                                                                    */
/* ============================================================================================================= */
/*! ISR for DMA Controller 1, Stream 0
 */
__attribute__((interrupt("DMA1_Stream0_handler"))) void DMA1_Stream0_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream0] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream0]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 1
 */
__attribute__((interrupt("DMA1_Stream1_handler"))) void DMA1_Stream1_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream1] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream1]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 2
 */
__attribute__((interrupt("DMA1_Stream2_handler"))) void DMA1_Stream2_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream2] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream2]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 3
 */
__attribute__((interrupt("DMA1_Stream3_handler"))) void DMA1_Stream3_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream3] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream3]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 4
 */
__attribute__((interrupt("DMA1_Stream1_handler"))) void DMA1_Stream4_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream4] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream4]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 5
 */
__attribute__((interrupt("DMA1_Stream5_handler"))) void DMA1_Stream5_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream5] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream5]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 6
 */
__attribute__((interrupt("DMA1_Stream6_handler"))) void DMA1_Stream6_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream6] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream6]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 1, Stream 7
 */
__attribute__((interrupt("DMA1_Stream7_handler"))) void DMA1_Stream7_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream7] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller1][DMA_stream7]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 0
 */
__attribute__((interrupt("DMA2_Stream0_handler"))) void DMA2_Stream0_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream0] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream0]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 1
 */
__attribute__((interrupt("DMA2_Stream1_handler"))) void DMA2_Stream1_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream1] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream1]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 2
 */
__attribute__((interrupt("DMA2_Stream2_handler"))) void DMA2_Stream2_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream2] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream2]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 3
 */
__attribute__((interrupt("DMA2_Stream3_handler"))) void DMA2_Stream3_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream3] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream3]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 4
 */
__attribute__((interrupt("DMA2_Stream4_handler"))) void DMA2_Stream4_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream4] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream4]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 5
 */
__attribute__((interrupt("DMA2_Stream5_handler"))) void DMA2_Stream5_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream5] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream5]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 6
 */
__attribute__((interrupt("DMA2_Stream6_handler"))) void DMA2_Stream6_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream6] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream6]();
	} else {
		while (1);
	}
}

/*! ISR for DMA Controller 2, Stream 7
 */
__attribute__((interrupt("DMA2_Stream7_handler"))) void DMA2_Stream7_handler()
{
	if (DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream7] != NULL) {
		DMAx_Streamy_user_handlers[DMA_controller2][DMA_stream7]();
	} else {
		while (1);
	}
}

/* ============================================================================================================= */
/* Helper Functions                                                                                              */
/* ============================================================================================================= */
/*! Determines if the desired configuration parameters for a stream are compatible.
 *
 * @note  Doesn't check the FIFO threshold levels with burst mode enabled as this is done in hardware and the user
 *        is informed via the FIFO error interrupt.
 *
 * @param cntrlr
 *    (input) The DMA controller of the stream being checked.
 * @param cnfg
 *    (input) The configuration options for the stream being checked.
 * @return 'true' if the configuration parameters are compatible, 'false' otherwise.
 */
static bool _DMA_params_are_valid(DMA_controller const cntrlr
	, DMA_stream_cnfg const cnfg
) {
	bool params_are_valid = false;

	if (  (cnfg.double_buff_cur_tar <= 1)
		&& ((cnfg.peri_data_size == 8) || (cnfg.peri_data_size == 16) || (cnfg.peri_data_size == 32))
		&& ((cnfg.mem_data_size == 8) || (cnfg.mem_data_size == 16) || (cnfg.mem_data_size == 32))
		&& ((cnfg.n_data_to_trans >= 1) && (cnfg.n_data_to_trans <= 65535))
		&& (cnfg.assoc_channel <= 7)
		&& (cnfg.IRQ_priority <= 15)
	) {
		params_are_valid = true;

		/* If this-then that config checks */
		if ((cnfg.transf_complete_IRQ_en || cnfg.half_transf_IRQ_en || cnfg.direct_mode_error_IRQ_en
			|| cnfg.FIFO_error_IRQ_en) && (cnfg.IRQ_handler == NULL)
		) {
			params_are_valid = false;
		}
		if (cnfg.flow_cntrlr_mode_en && (cntrlr != DMA_controller2) && (cnfg.assoc_channel != 4)) {
			params_are_valid = false;
		}
		if (cnfg.flow_cntrlr_mode_en && (cnfg.transf_dir == DMA_transf_dir_mem_mem)) { params_are_valid = false; }
		if (cnfg.flow_cntrlr_mode_en && cnfg.circular_mode_en) { params_are_valid = false; }
		if (cnfg.direct_mode_en && (cnfg.transf_dir == DMA_transf_dir_mem_mem)) { params_are_valid = false; }
		if (cnfg.direct_mode_en && cnfg.burst_mode_en) { params_are_valid = false; }
		if (cnfg.circular_mode_en && (cnfg.transf_dir == DMA_transf_dir_mem_mem)) { params_are_valid = false; }
		if (cnfg.double_buff_mode_en && (cnfg.transf_dir == DMA_transf_dir_mem_mem)) { params_are_valid = false; }
		if (cnfg.double_buff_mode_en && (cnfg.circular_mode_en != true)) { params_are_valid = false; }
		if ((cnfg.transf_dir == DMA_transf_dir_mem_mem) && (cntrlr == DMA_controller1)) { params_are_valid = false; }
	} else {
		//Invalid parameters, boolean is already false so do nothing
	}

	return params_are_valid;
}

/*! Converts a particular DMA controller/stream number combo to the associated NVIC channel.
 *
 * @param cntrlr
 *    (input) The DMA controller of the desired stream.
 * @param stream
 *    (input) The number of the desired stream.
 * @return The NVIC channel number for the controller/stream combo. For an improper controller/stream combo this
 *         returns an invalid 97.
 */
static IRQ_channel_num _DMA_convert_cntrlr_stream_to_NVIC(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	IRQ_channel_num IRQn = NVIC_DMA1_Stream0_IRQn;

	switch (stream) {
		case DMA_stream0:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream0_IRQn : NVIC_DMA2_Stream0_IRQn;
			break;
		case DMA_stream1:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream1_IRQn : NVIC_DMA2_Stream1_IRQn;
			break;
		case DMA_stream2:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream2_IRQn : NVIC_DMA2_Stream2_IRQn;
			break;
		case DMA_stream3:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream3_IRQn : NVIC_DMA2_Stream3_IRQn;
			break;
		case DMA_stream4:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream4_IRQn : NVIC_DMA2_Stream4_IRQn;
			break;
		case DMA_stream5:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream5_IRQn : NVIC_DMA2_Stream5_IRQn;
			break;
		case DMA_stream6:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream6_IRQn : NVIC_DMA2_Stream6_IRQn;
			break;
		case DMA_stream7:
			IRQn = (cntrlr == DMA_controller1) ? NVIC_DMA1_Stream7_IRQn : NVIC_DMA2_Stream7_IRQn;
			break;
		default:
			IRQn = 97; //One more than the last possible NVIC channel, error code
			break;
	}

	return IRQn;
}

/*! Computes a stream's CR, PAR, M0AR, M1AR, FCR, NDTR, LIFCR, HIFCR, LISR, and HISR register addresses.
 *
 * @brief The address of the register of interest is going to be variable, depending on the DMA controller and
 *        stream number for that register. Each DMA controller's register banks are 0x400 apart and within a DMA
 *        controller, each stream's set of registers are 0x18 apart. So to compute the address of the desired
 *        register, we take the address of DMA controller 1's version of that register and offset it by the 
 *        stream number * 0x18 (to get that stream's version of the register) and then offset it again by 0x400 if
 *        the DMA controller is DMA2. This does not apply for the LIFCR, HIFCR, LISR, and HISR as they are not
 *        offset by stream number, only DMA controller number.
 *
 * @param cntrlr
 *    (input) The DMA controller of the desired stream.
 * @param stream
 *    (input) The desired stream whose register address is to be computed.
 * @return The address of the register of interest.
 */
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_CR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0CR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_PAR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0PAR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_M0AR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0M0AR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_M1AR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0M1AR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_NDTR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0NDTR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_FCR_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_S0FCR)) + (uint32_t)(0x18U * stream) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_LIFCR_addr(DMA_controller const cntrlr
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_LIFCR)) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_HIFCR_addr(DMA_controller const cntrlr
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_HIFCR)) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_LISR_addr(DMA_controller const cntrlr
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_LISR)) + (uint32_t)(0x400U * cntrlr));
}
__attribute__((always_inline)) static inline uint32_t * _DMA_compute_HISR_addr(DMA_controller const cntrlr
) {
	return (uint32_t *)((uint8_t *)(&(DMA1_HISR)) + (uint32_t)(0x400U * cntrlr));
}

/* ============================================================================================================= */
/* Interrupt Helper Functions                                                                                    */
/* ============================================================================================================= */
/*! Computes the bit position of a particular IRQ status in the status registers.
 *
 * @brief The status registers (HISR, LISR, HIFCR, LIFCR) have preset bit positions for each type of IRQ status.
 *        This function will take in the desired stream and the type of status and return that stream/status
 *        combo's bit position. It first computes the bit position (for a given stream) of the FIFO error status
 *        and then offsets it by the type of status (0 for FIFO error, 2 for direct mode error, 3 for transfer
 *        error, etc).
 *
 * @param IRQ_status
 *    (input) The IRQ status desired. '0' for FIFO error, '2' for direct mode error, '3' for transfer error,
 *            '4' for half transfer, and '5' for transfer complete.
 * @param stream
 *    (input) The number of the stream's whose IRQ status is being checked.
 * @return The bit position of the IRQ status for the provided stream. '0xFFFF' on an improper IRQ_status input.
 */
static uint32_t _DMA_find_IRQ_status_bit_pos(uint32_t const IRQ_status
	, DMA_stream const stream
) {
	uint32_t IRQ_status_bit_pos = 0xFFFF;

	if (IRQ_status <= 5 && IRQ_status != 2) {
		switch (stream) {
			case DMA_stream0:
			case DMA_stream4:
				IRQ_status_bit_pos = 0;
				break;
			case DMA_stream1:
			case DMA_stream5:
				IRQ_status_bit_pos = 6;
				break;
			case DMA_stream2:
			case DMA_stream6:
				IRQ_status_bit_pos = 16;
				break;
			case DMA_stream3:
			case DMA_stream7:
				IRQ_status_bit_pos = 22;
				break;
			default:
				break;
		}
	} else {
		//Invalid IRQ status selection, do nothing
	}

	if (IRQ_status_bit_pos != 0xFFFF) {
		IRQ_status_bit_pos += IRQ_status;
	} else {
		//IRQ_status_it_pos is already 0xFFFF error code, do nothing
	}

	return IRQ_status_bit_pos;
}

/*! Determines if a particular interrupt request is pending based off of the desired interrupt type.
 *
 * @brief To check if a particular interrupt flag is pending, we simply check the appropriate bit in the HISR or
 *        LISR (HISR for streams 4-7, LISR for streams 0-3). The _DMA_find_IRQ_status_bit_pos() determines the bit
 *        position for the desired interrupt flag.
 *
 * @param cntrlr
 *    (input) The DMA controller of the desired stream.
 * @param stream
 *    (input) The number of the desired stream.
 * @param IRQ_type
 *    (input) The interrupt type. '0' for FIFO error, '2' for direct mode error, '3' for transfer error, '4' for
 *            half transfer, and '5' for transfer complete.
 */
static bool _DMA_XXXX_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const IRQ_type
) {
	uint32_t volatile * const DMAx_SyHISR_addr = _DMA_compute_HISR_addr(cntrlr);
	uint32_t volatile * const DMAx_SyLISR_addr = _DMA_compute_LISR_addr(cntrlr);
	uint32_t IRQ_type_bit_pos = _DMA_find_IRQ_status_bit_pos(IRQ_type, stream);
	bool ret = false;

	if (IRQ_type_bit_pos != 0xFFFF) {
		if (stream >= DMA_stream4) {
			if (*DMAx_SyHISR_addr & (0x1 << IRQ_type_bit_pos)) {
				ret = true;
			} else {
				//ret is already false, do nothing
			}
		} else {
			if (*DMAx_SyLISR_addr & (0x1 << IRQ_type_bit_pos)) {
				ret = true;
			} else {
				//ret is already false, do nothing
			}
		}
	} else {
		//Invalid bit position, do nothing
	}
	return ret;
}

/*! Clears a particular interrupt request based off of the desired interrupt type.
 *
 * @brief To clear a particular interrupt flag, we simply set the appropriate bit in the HISR or LISR (HISR for
 *        streams 4-7, LISR for streams 0-3). The _DMA_find_IRQ_status_bit_pos() determines the bit position for
 *        the desired interrupt flag.
 *
 * @param cntrlr
 *    (input) The DMA controller of the desired stream.
 * @param stream
 *    (input) The number of the desired stream.
 * @param IRQ_type
 *    (input) The interrupt type. '0' for FIFO error, '2' for direct mode error, '3' for transfer error, '4' for
 *            half transfer, and '5' for transfer complete.
 */
static void _DMA_XXXX_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const IRQ_type
) {
	uint32_t volatile * const DMAx_SyHIFCR_addr = _DMA_compute_HIFCR_addr(cntrlr);
	uint32_t volatile * const DMAx_SyLIFCR_addr = _DMA_compute_LIFCR_addr(cntrlr);
	uint32_t IRQ_type_bit_pos = _DMA_find_IRQ_status_bit_pos(IRQ_type, stream);

	if (IRQ_type_bit_pos != 0xFFFF) {
		if (stream >= DMA_stream4) {
			*DMAx_SyHIFCR_addr |= 0x1 << IRQ_type_bit_pos;
		} else {
			*DMAx_SyLIFCR_addr |= 0x1 << IRQ_type_bit_pos;
		}
	} else {
		//Invalid bit position, do nothing
	}
}

/*! Updates a particular interrupt request enable based off the desired interrupt type.
 *
 * @brief To update the interrupt enable for transfer complete, half transfer, transfer error, or direct mode
 *        error, we first have to ensure that the stream being updated is currently disabled (the EN bit, bit 0 of
 *        the CR register is '0'). If so, we are free to write the new interrupt enable to the CR register for
 *        the provided bit position.
 *
 * @param cntrlr
 *    (input) The DMA controller of the desired stream.
 * @param stream
 *    (input) The number of the desired stream.
 * @param new_XXXX_IRQ_en
 *    (input) The interrupt enable that is to be updated.
 * @param IRQ_type
 *    (input) The interrupt type. '1' for direct mode error, '2' for transfer error, '3' for half transfer, and '4'
 *            for transfer complete.
 */
static void _DMA_stream_update_XXXX_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_XXXX_IRQ_en
	, uint32_t const IRQ_type
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);

	if (IRQ_type >= 1 && IRQ_type <= 4) {
		if (*DMAx_SyCR_addr & 0x1) {
			//DMA stream is currently enabled, do nothing
		} else {
			if (new_XXXX_IRQ_en) {
				*DMAx_SyCR_addr |= 0x1 << IRQ_type;
			} else {
				*DMAx_SyCR_addr &= ~(0x1 << IRQ_type);
			}
		}
	} else {
		//Invalid interrupt type, do nothing
	}
}

/* ============================================================================================================= */
/* Stream Configuration Sub-Functions                                                                            */
/* ============================================================================================================= */
/*! Properly disables a particular stream.
 *
 * @brief To properly disable a stream, we have to clear the EN bit in the CR register (whose address is contained
 *        in the DMAx_SyCR_addr) then read the EN bit in order to confirm that there is no ongoing stream
 *        operation. Writing this bit to 0 is not immediately effective since it is actually written to 0 once all
 *        the current transfers are finished. Only when the EN bit is read as 0 is the stream truly disabled.
 *        Therefore it is necessary to wait for the EN bit to be cleared before proceeding. Additionally, all the
 *        bits associated with the desired stream number in the interrupt status register (LISR and HISR) from
 *        any potentially previously active data block DMA transfer must be cleared (via the HIFCR/LIFCR registers)
 *        before proceeding. TECHNICALLY I should read the bits in the status register and check if they are '1'
 *        before clearing them in the H/LIFCR but meh...
 *
 * @note  THIS CALL IS BLOCKING!!!!!
 * 
 * @param cntrlr
 *    (input) The DMA controller associated with the stream being configured.
 * @param stream
 *    (input) The stream that is being configured.
 */
static void _DMA_configure_stream_disable_stream(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * DMAx_SyCR_addr  = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * DMAx_LIFCR_addr = _DMA_compute_LIFCR_addr(cntrlr);
	uint32_t volatile * DMAx_HIFCR_addr = _DMA_compute_HIFCR_addr(cntrlr);

	*DMAx_SyCR_addr &= 0x0; //Clear the stream's EN bit
	while (*DMAx_SyCR_addr & 0x1); //Wait until the EN bit is actually '0'

	/* Clear the TCIF, HTIF, TEIF, DMEIF, and FIEF bits in the HIFCR/LIFCR */
	switch (stream)
	{
		case DMA_stream0:
			*DMAx_LIFCR_addr = 0x3DU;
			break;
		case DMA_stream1:
			*DMAx_LIFCR_addr = 0xF40U;
			break;
		case DMA_stream2:
			*DMAx_LIFCR_addr = 0x3D00000U;
			break;
		case DMA_stream3:
			*DMAx_LIFCR_addr = 0xF400000U;
			break;
		case DMA_stream4:
			*DMAx_HIFCR_addr = 0x3DU;
			break;
		case DMA_stream5:
			*DMAx_HIFCR_addr = 0xF40U;
			break;
		case DMA_stream6:
			*DMAx_HIFCR_addr = 0x3D00000U;
			break;
		case DMA_stream7:
			*DMAx_HIFCR_addr = 0xF400000U;
			break;
		default:
			break;
	}
}

/*! Updates the appropriate registers with the addresses of the source/destination peripheral/memory location.
 *
 * @brief For a given DMA transfer the PAR and M0AR/M1AR registers hold the addresses of the source and destination
 *        of said DMA transfer. The direction of the transfer dictates which of the aforementioned registers is
 *        used for either the source or destination address and the breakdown is seen below:
 *        Peripheral-to-Memory: source = PAR register, destination = M0AR register
 *        Memory-to-Peripheral: source = M0AR register, destination = PAR register
 *        Memory-to-Memory:     source = PAR register, destination = M0AR register
 *        In the case that double-buffer mode is enabled, the M1AR register is used to hold the "sister" memory
 *        location to the memory location held in the M0AR register (i.e. the memory location that is to be
 *        alternated with).
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is being configured.
 * @param cnfg
 *    (input) The configuration options for said stream.
 */
static void _DMA_configure_stream_set_source_dst_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, DMA_stream_cnfg const cnfg
) {
	uint32_t volatile * DMAx_SyPAR_addr  = _DMA_compute_PAR_addr(cntrlr, stream);
	uint32_t volatile * DMAx_SyM0AR_addr = _DMA_compute_M0AR_addr(cntrlr, stream);
	uint32_t volatile * DMAx_SyM1AR_addr = _DMA_compute_M1AR_addr(cntrlr, stream);

	*DMAx_SyPAR_addr = (uint32_t)(cnfg.peri_addr);
	*DMAx_SyM0AR_addr = (uint32_t)(cnfg.mem0_addr);

	if (cnfg.double_buff_mode_en) {
		*DMAx_SyM1AR_addr = (uint32_t)(cnfg.mem1_addr);
	} else {
		//Double buffer mode not enabled, do nothing
	}
}

/*! Updates the NDTR register with the stream configuration's number of data to transfer value.
 *
 * @brief Computes the address of the desired stream's NDTR register and then writes the number of data to transfer
 *        value to said register.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be configured.
 * @param n_data_to_trans
 *    (input) The number of data items that this stream is to transfer.
 */
static void _DMA_configure_stream_set_n_transf_data(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const n_data_to_trans
) {
	uint32_t volatile * DMAx_SyNDTR_addr = _DMA_compute_NDTR_addr(cntrlr, stream);
	*DMAx_SyNDTR_addr = n_data_to_trans & 0xFFFF;
}

/*! Updates an accumulated CR register value with the channel that is to be forwarded to the stream.
 *
 * @brief Updating the CR value with the channel is done by writing the channel number (between 0 and 8) to bits
 *        27:25. The 0x7U is to ensure that we are only writing 3 bits and the 25 is the bitwise shift amount to
 *        ensure the write ends up at CR[27:25]. Additionally, this function writes to an accumulated value for the
 *        CR register and not the CR register itself.
 *
 * @param accum_CR_val
 *    (input/output) The accumulated value that is to be written to the CR register.
 * @param cnfg
 *    (input) The configuration options for stream being configured.
 */
static void _DMA_configure_stream_set_channel(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	*accum_CR_val |= (cnfg.assoc_channel & 0x7U) << 25;
}

/*! Updates an accumulated CR register value with whether or not flow controller mode should be enabled.
 *
 * @brief Updating the CR value with the flow controller mode is done by writing to bit 5 where a '1' enables
 *        the mode and a '0' disables the mode.
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_flow_cntrlr(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	if (cnfg.flow_cntrlr_mode_en) {
		*accum_CR_val |= 0x1 << 5;
	} else {
		//Flow controller mode is not enabled, do nothing
	}
}

/*! Updates an accumulated CR register value with the priority of the stream.
 *
 * @brief Updating the CR value with the stream's priority is done by writing the priority value to bits 17:16. The
 *        0x3U is to ensure that we are only writing 2 bits and the 16 is the bitwise shift amount to ensure that
 *        the write ends up at CR[17:16].
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_stream_prio(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	*accum_CR_val |= (cnfg.stream_prio & 0x3U) << 16;
}

/*! Updates an accumulated CR register value with the transfer direction of the stream.
 *
 * @brief Updating the CR value with the stream's transfer direction is done by writing the transfer direction to
 *        bits 7:6. The 0x3U is to ensure that we are only writing 2 bits and the 6 is the bitwise shift amount to
 *        ensure that the write ends up at CR[17:16].
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_transf_dir(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	*accum_CR_val |= (cnfg.transf_dir & 0x3U) << 6;
}

/*! Updates an accumulated CR register value with the peripheral/memory increment mode options.
 *
 * @brief Updating the CR value with the stream's peripheral/memory increment mode is done by setting/clearing
 *        bits 9 and 10 where 9 is the peripheral increment mode and 10 is the memory increment mode ('0'
 *        disables incrementing, '1' enables incrementing).
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_peri_mem_incr(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	if (cnfg.peri_incr_mode_en) {
		*accum_CR_val |= 0x1 << 9;
	} else {
		*accum_CR_val &= ~(0x1 << 9);
	}
	if (cnfg.mem_incr_mode_en) {
		*accum_CR_val |= 0x1 << 10;
	} else {
		*accum_CR_val &= ~(0x1 << 10);
	}
}

/*! Updates an accumulated CR register with the burst transaction configuration options.
 *
 * @brief Updating the CR value with the stream's burst transaction configuration options is done by writing the
 *        number of desired peripheral or memory beats per burst (bits 22:21 and 24:23 respecitvely).
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_burst(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	if (cnfg.burst_mode_en) {
		*accum_CR_val |= (cnfg.peri_beats & 0x3U) << 21;
		*accum_CR_val |= (cnfg.mem_beats & 0x3U) << 23;
	} else {
		//No burst mode desired, do nothing
	}
}

/*! Updates an accumulated CR register with the peripheral/memory data size.
 *
 * @brief Updating the CR value with the peripheral/memory data size is done by writing one of the following values
 *        to bits 14:13 for the memory data size and 12:11 for the peripheral data size
 *        configuration parameter of '8' for peri/mem_data_size - 0b00
 *        configuration parameter of '16' for peri/mem_data_size - 0b01
 *        configuration parameter of '32' for peri/mem_data_size - 0b10
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_data_size(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	switch (cnfg.peri_data_size) {
		case 8:
			*accum_CR_val &= ~(0x3 << 11);
			break;
		case 16:
			*accum_CR_val &= ~(0x1 << 12);
			*accum_CR_val |= 0x1 << 11;
			break;
		case 32:
			*accum_CR_val |= 0x1 << 12;
			*accum_CR_val &= ~(0x1 << 11);
			break;
		default:
			break;
	}
	switch (cnfg.mem_data_size) {
		case 8:
			*accum_CR_val &= ~(0x3 << 13);
			break;
		case 16:
			*accum_CR_val &= ~(0x1 << 14);
			*accum_CR_val |= 0x1 << 13;
			break;
		case 32:
			*accum_CR_val |= 0x1 << 14;
			*accum_CR_val &= ~(0x1 << 13);
			break;
		default:
			break;
	}
}

/*! Updates an accumulated CR register with the double buffer and circular mode options.:
 *
 * @brief Updating the CR value with the double buffer and circular mode options is done by setting/clearing bits
 *        18 for double buffer mode ('0' disables, '1' enables) and 8 for circular mode ('0' disables, '1'
 *        enables). Additionally if double buffer mode is enabled, circular mode should also be enabled as well as
 *        per the reference manual. Finally, if double buffer mode is enabled the current target for which of the
 *        two buffers to use first must be set via bit 19 ('0' sets M0AR's address as the target, '1' sets M1AR's
 *        address as the target).
 *
 * @param See _DMA_configure_stream_set_channel(). The parameters are the same.
 */
static void _DMA_configure_stream_set_circ_double_buff_mode(uint32_t * const accum_CR_val
	, DMA_stream_cnfg const cnfg
) {
	if (cnfg.double_buff_mode_en) {
		*accum_CR_val |= 0x1 << 18; //Enable double buffer mode
		*accum_CR_val |= 0x1 << 8;  //Also enable circular mode

		if (cnfg.double_buff_cur_tar == 0) {
			*accum_CR_val &= ~(0x1 << 19); //Set the current target to memory 0 (M0AR)
		} else {
			*accum_CR_val |= 0x1 << 19;    //Set the current target to memory 1 (M1AR)
		}
	} else {
		*accum_CR_val &= ~(0x1 << 18); //Disable double buffer mode

		if (cnfg.circular_mode_en) {
			*accum_CR_val |= 0x1 << 8;    //Enable circular mode
		} else {
			*accum_CR_val &= ~(0x1 << 8); //Disable circular mode
		}
	}
}

/*! Configures the transfer complete, half transfer, transfer error, direct mode error, and FIFO error IRQs.
 *
 * @brief Configuring the interrupt requests requires setting/clearing the appropriate bits in the CR and FCR
 *        registers. Bit 4 = '1' in the CR enables the transfer complete IRQ and '0' disables it. Bit 3 = '1' in
 *        the CR enables the half transfer IRQ and '0' disables it. Bit 2 = '1' in the CR enables the transfer
 *        error and '0' disables it. Bit 1 = '1' in the CR enables the direct mode error IRQ and '0' disables it.
 *        Bit 7 = '1' in the FCR enables the FIFO error IRQ and '0' disables it.
 *        Once the status registers have been updated, the NVIC channel associated with the particular controller/
 *        stream combo needs to have its priority set and then enabled. The user ISR for the controller/stream
 *        combo needs to be updated. And finally the global IRQ mask must be lifted to globally enable the IRQ.
 *
 * @param cntrlr
 *    (input) The DMA controller associated with the stream being configured.
 * @param stream
 *    (input) The stream that is being configured.
 * @param accum_CR_val
 *    (input/output) The accumulated value that is to be written to the CR register.
 * @param accum_FCR_val
 *    (input/output) The accumulated value that is to be written to the FCR register.
 * @param cnfg
 *    (input) The configuration options for stream being configured.
 */
static void _DMA_configure_stream_configure_IRQs(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t * const accum_CR_val
	, uint32_t * const accum_FCR_val
	, DMA_stream_cnfg const cnfg
) {
	IRQ_channel_num IRQn = _DMA_convert_cntrlr_stream_to_NVIC(cntrlr, stream);

	if (cnfg.transf_complete_IRQ_en || cnfg.half_transf_IRQ_en || cnfg.transf_error_IRQ_en || cnfg.FIFO_error_IRQ_en
		|| cnfg.direct_mode_error_IRQ_en
	) {
		/* Update the accumulated CR and FCR registers values */
		if (cnfg.transf_complete_IRQ_en  ) { *accum_CR_val |= (0x1 << 4);  } else { *accum_CR_val &= ~(0x1 << 4);  }
		if (cnfg.half_transf_IRQ_en      ) { *accum_CR_val |= (0x1 << 3);  } else { *accum_CR_val &= ~(0x1 << 3);  }
		if (cnfg.transf_error_IRQ_en     ) { *accum_CR_val |= (0x1 << 2);  } else { *accum_CR_val &= ~(0x1 << 2);  }
		if (cnfg.direct_mode_error_IRQ_en) { *accum_CR_val |= (0x1 << 1);  } else { *accum_CR_val &= ~(0x1 << 1);  }
		if (cnfg.FIFO_error_IRQ_en       ) { *accum_FCR_val |= (0x1 << 7); } else { *accum_FCR_val &= ~(0x1 << 7); }

		/* Enable the interrupt's channel in the NVIC */
		if (IRQn >= NVIC_DMA1_Stream0_IRQn && IRQn <= NVIC_DMA2_Stream7_IRQn) {
			_disable_global_irq();
			_NVIC_channel_set_priority(IRQn, cnfg.IRQ_priority);
			_NVIC_channel_enable(IRQn);
			DMAx_Streamy_user_handlers[cntrlr][stream] = cnfg.IRQ_handler;
			_enable_global_irq();
		} else {
			//Invalid NVIC channel, do nothing causing interrupts to go to default handler (a while (1))
		}
	} else {
		//No interrupts have been enabled, do nothing
	}
}

/*! Configures the FCR register as per the stream's configuration parameters.
 *
 * @brief Updating the FCR register involves updating the direct mode enable, FIFO threshold level, and FIFO error
 *        interrupt bits in the register. As there are three things that could be potentially written, an
 *        accumulated value is used to gather all the changes before actually writing to the register.
 *        Updating the direct mode enable is done by setting/clearing bit 2 ('0' is mode enable, '1' is mode
 *        disable). Updating the FIFO threshold level is done by writing the stream configuration's FIFO_thresh
 *        parameter to bits 1:0 thus the AND by 0x3U. Updating the FIFO error interrupt is done by setting/clearing
 *        bit 7 ('0' is IRQ disabled, '1' is IRQ enabled).
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be configured.
 * @param accum_FCR_val
 *    (input/output) The accumulated value that is to be written to the FCR register.
 * @param cnfg
 *    (input) The configuration options for the stream.
 */
static void _DMA_configure_stream_configure_FIFO(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t * const accum_FCR_val
	, DMA_stream_cnfg const cnfg
) {
	if (cnfg.direct_mode_en) {
		*accum_FCR_val &= ~(0x1 << 2); //Enable direct mode
	} else {
		*accum_FCR_val |= 0x1 << 2; //Disable direct mode
		*accum_FCR_val |= cnfg.FIFO_thresh & 0x3U; //Set the FIFO threshold level
	}
	if (cnfg.FIFO_error_IRQ_en) {
		*accum_FCR_val |= 0x1 << 7; //Enable FIFO error interrupt
	} else {
		*accum_FCR_val &= ~(0x1 << 7); //Disable FIFO error interrupt
	}
}

/* ============================================================================================================= */
/* Configuration/Initialization Functions                                                                        */
/* ============================================================================================================= */
/*! Configures a DMA stream for a given DMA controller.
 *
 * @brief Read the comments on each of the sub functions to determine its purpose in the configuration of the
 *        DMA stream.
 *
 * @note  None of the sub-function calls do any boundary checking, thus the need for the _DMA_params_are_valid()
 *        call first.
 */
void DMA_configure_stream(DMA_controller const cntrlr
	, DMA_stream const stream
	, DMA_stream_cnfg const cnfg
) {
	uint32_t accum_CR_val = 0x0U;  //Value that holds accumulated writes to the CR register
	uint32_t accum_FCR_val = 0x0U; //Value that holds accumulated writes to the FCR register

	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyFCR_addr = _DMA_compute_FCR_addr(cntrlr, stream);

	if (_DMA_params_are_valid(cntrlr, cnfg)) {
		RCC_AHB1ENR |= (0x1 << (cntrlr + 21)); //Enable the clock to DMA1 or DMA2

		_DMA_configure_stream_disable_stream(cntrlr, stream);
		_DMA_configure_stream_set_source_dst_addr(cntrlr, stream, cnfg);
		_DMA_configure_stream_set_n_transf_data(cntrlr, stream, cnfg.n_data_to_trans);
		_DMA_configure_stream_set_channel(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_flow_cntrlr(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_stream_prio(&accum_CR_val, cnfg);
		_DMA_configure_stream_configure_FIFO(cntrlr, stream, &accum_FCR_val, cnfg);
		_DMA_configure_stream_set_transf_dir(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_peri_mem_incr(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_burst(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_data_size(&accum_CR_val, cnfg);
		_DMA_configure_stream_set_circ_double_buff_mode(&accum_CR_val, cnfg);
		_DMA_configure_stream_configure_IRQs(cntrlr, stream, &accum_CR_val, &accum_FCR_val, cnfg);

		*DMAx_SyCR_addr = accum_CR_val;   //Write the accumulated CR register values to the actual CR register
		*DMAx_SyFCR_addr = accum_FCR_val; //Write the accumulated FCR register values to the actual FCR register
	} else {
		//Invalid configuration parameter combinations, do nothing
	}
}

/*! Updates the number of data items that the DMA controller will transfer.
 *
 * @brief To properly update the number of data items (the value in the NDTR register) we have to ensure that the
 *        stream being updated is currently disabled (the EN bit, bit 0, is '0'). If so we are free to write the
 *        16-bit value to the NDTR register.
 */
void DMA_stream_update_n_data_to_trans(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const new_n_data_to_trans
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyNDTR_addr = _DMA_compute_NDTR_addr(cntrlr, stream);

	if (*DMAx_SyCR_addr & 0x1) {
		//DMA stream is currently enabled, do nothing
	} else {
		if (new_n_data_to_trans >= 1 && new_n_data_to_trans <= 65535) {
			*DMAx_SyNDTR_addr = new_n_data_to_trans & 0xFFFF;
		} else {
			//Requested n_data_to_trans is out-of-bounds, do nothing
		}
	}
}

/*! Updates the peripheral address of the DMA stream.
 *
 * @brief To properly update the peripheral address (the value in the PAR register) we have to ensure that the
 *        stream being updated is currently disabled (the EN bit, bit 0, is '0'). If so we are free to write the
 *        new peripheral address to the PAR register.
 */
void DMA_stream_update_peri_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_peri_addr
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyPAR_addr = _DMA_compute_PAR_addr(cntrlr, stream);

	if (*DMAx_SyCR_addr & 0x1) {
		//DMA stream is currently enabled, do nothing
	} else {
		*DMAx_SyPAR_addr = (uint32_t)new_peri_addr;
	}
}

/*! Updates the memory0 address of the DMA stream.
 *
 * @brief To properly update the memory 0 location (the value in the M0AR register) we have to ensure that the
 *        stream being updated is currently disabled (the EN bit, bit 0, is '0'). If so we are free to write the
 *        new memory 0 location to the M0AR register.
 */
void DMA_stream_update_mem0_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_mem0_addr
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyM0AR_addr = _DMA_compute_M0AR_addr(cntrlr, stream);

	if (*DMAx_SyCR_addr & 0x1) {
		//DMA stream is currently enabled, do nothing
	} else {
		*DMAx_SyM0AR_addr = (uint32_t)new_mem0_addr;
	}
}

/*! Updates the memory1 address of the DMA stream.
 *
 * @brief To properly update the memory 1 location (the value in the M1AR register) we have to ensure that the
 *        stream being updated is currently disabled (the EN bit, bit 0, is '0'). If so we are free to write the
 *        new memory 1 location to the M0AR register IF the stream has double-buffer mode enabled (bit 18 in the
 *        CR register).
 */
void DMA_stream_update_mem1_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_mem1_addr
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyM1AR_addr = _DMA_compute_M1AR_addr(cntrlr, stream);

	if (*DMAx_SyCR_addr & 0x1) {
		//DMA stream is currently enabled, do nothing
	} else {
		if (*DMAx_SyCR_addr & (0x1 << 18)) {
			*DMAx_SyM1AR_addr = (uint32_t)new_mem1_addr;
		} else {
			//Double buffer mode is not enabled for this stream, do nothing
		}
	}
}

/*! Updates the transfer complete, half transfer, transfer error, direct mode error, or FIFO error IRQ enables.
 *
 */
void DMA_stream_update_transf_complete_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_transf_complete_IRQ_en
) {
	_DMA_stream_update_XXXX_IRQ(cntrlr, stream, new_transf_complete_IRQ_en, 4);
}

void DMA_stream_update_half_transfer_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_half_transf_IRQ_en
) {
	_DMA_stream_update_XXXX_IRQ(cntrlr, stream, new_half_transf_IRQ_en, 3);
}

void DMA_stream_update_transf_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_transf_error_IRQ_en
) {
	_DMA_stream_update_XXXX_IRQ(cntrlr, stream, new_transf_error_IRQ_en, 2);
}

void DMA_stream_update_direct_mode_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_direct_mode_error_IRQ_en
) {
	_DMA_stream_update_XXXX_IRQ(cntrlr, stream, new_direct_mode_error_IRQ_en, 1);
}

void DMA_stream_update_FIFO_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_FIFO_error_IRQ_en
) {
	uint32_t volatile * const DMAx_SyFCR_addr = _DMA_compute_FCR_addr(cntrlr, stream);

	if (*DMAx_SyFCR_addr & 0x1) {
		//DMA stream is currently enabled, do nothing
	} else {
		if (new_FIFO_error_IRQ_en) {
			*DMAx_SyFCR_addr |= 0x1 << 7;
		} else {
			*DMAx_SyFCR_addr &= ~(0x1 << 7);
		}
	}
}


/* ============================================================================================================= */
/* Enable/Disable Functions                                                                                      */
/* ============================================================================================================= */
/*! Enables a DMA stream for a given DMA controller.
 *
 * @brief To enable a DMA stream the EN bit (bit 0) in the CR register must be set to '1'.
 */
void DMA_enable_stream(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	*DMAx_SyCR_addr |= 0x1;
}

/*! Disables a DMA stream for a given DMA controller.
 *
 * @brief To disable a DMA stream, the EN bit (bit 0) in the CR register must be set to '0' which, even after
 *        writing a 0, will only happen when the DMA controller has finished the current transfer. Thus this
 *        function waits until the EN bit is actually 0 before returning. The number of data items left to be
 *        transferred is found by simply reading the NDTR register after the EN bit has been brought to '0'.
 */
uint32_t DMA_disable_stream(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * DMAx_SyCR_addr  = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t volatile * DMAx_SyNDTR_addr = _DMA_compute_NDTR_addr(cntrlr, stream);

	*DMAx_SyCR_addr &= 0x0; //Clear the stream's EN bit
	while (*DMAx_SyCR_addr & 0x1); //Wait until the EN bit is actually '0'

	uint32_t n_data_left = (*DMAx_SyNDTR_addr & 0xFFFF);
	return n_data_left;
}

/* ============================================================================================================= */
/* Status Functions                                                                                              */
/* ============================================================================================================= */
/*! Gets the peripheral, memory location 0, or memory location 1 addresses.
 *
 * @brief Simply reads the contents of the PAR, M0AR, or M1AR for a peripheral, memory location 0, or memory
 *        location 1 address request respectively.
 */
uint32_t * DMA_peri_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyPAR_addr = _DMA_compute_PAR_addr(cntrlr, stream);
	return (uint32_t *)(*DMAx_SyPAR_addr);
}

uint32_t * DMA_mem0_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyM0AR_addr = _DMA_compute_M0AR_addr(cntrlr, stream);
	return (uint32_t *)(*DMAx_SyM0AR_addr);
}

uint32_t * DMA_mem1_addr(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyM1AR_addr = _DMA_compute_M1AR_addr(cntrlr, stream);
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t * M1AR_addr = 0;

	if (*DMAx_SyCR_addr & (0x1 << 18)) {
		M1AR_addr = (uint32_t *)(*DMAx_SyM1AR_addr);
	} else {
		//Stream is not in double-buffer mode, do nothing
	}

	return M1AR_addr;
}

/*! Gets the current target of a double-buffer enabled transfer.
 *
 * @brief Simply reads bit 19 of the CR register. If the bit is '1', then the current target is memory location 1
 *        else the current target is memory location 0.
 */
uint32_t DMA_double_buff_target(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyCR_addr = _DMA_compute_CR_addr(cntrlr, stream);
	uint32_t double_buff_target = 0;

	if (*DMAx_SyCR_addr & (0x1 << 19)) {
		double_buff_target = 1;
	} else {
		double_buff_target = 0;
	}

	return double_buff_target;
}

/* ============================================================================================================= */
/* FIFO Functions                                                                                                */
/* ============================================================================================================= */
/*! Checks a DMA stream's FIFO level.
 *
 * @brief The level a stream's FIFO is given by bits 5:3 of the FCR register. So we read the register, mask out
 *        all bits but 5:3 (the AND by 0x38) and then shift the bits of interest to the beginning of the return
 *        value (the right shift by 3);
 */
uint32_t DMA_FIFO_level(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	uint32_t volatile * const DMAx_SyFCR_addr = _DMA_compute_FCR_addr(cntrlr, stream);
	uint32_t FIFO_level = 0;

	FIFO_level = (*DMAx_SyFCR_addr & 0x38U) >> 3;
	return FIFO_level;
}

/*! Checks if the FIFO error interrupt flag is pending.
 *
 */
bool DMA_FIFO_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	bool FIFO_error = _DMA_XXXX_IRQ_pending(cntrlr, stream, 0);
	return FIFO_error;
}

/*! Clears the FIFO error interrupt flag.
 *
 */
void DMA_FIFO_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	_DMA_XXXX_clear_IRQ(cntrlr, stream, 0);
}

/* ============================================================================================================= */
/* Interrupt/Error Status Functions                                                                              */
/* ============================================================================================================= */
/*! Checks if the transfer complete, half transfer, transfer error, or direct mode error interrupt flags are
 *  pending.
 */
bool DMA_transf_complete_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	bool transf_complete = _DMA_XXXX_IRQ_pending(cntrlr, stream, 5);
	return transf_complete;
}

bool DMA_half_transfer_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	bool half_transf = _DMA_XXXX_IRQ_pending(cntrlr, stream, 4);
	return half_transf;
}

bool DMA_transfer_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	bool transf_error = _DMA_XXXX_IRQ_pending(cntrlr, stream, 3);
	return transf_error;
}

bool DMA_direct_mode_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	bool direct_mode_error = _DMA_XXXX_IRQ_pending(cntrlr, stream , 2);
	return direct_mode_error;
}

/*! Clears the transfer complete, half transfer, transfer error, or direct mode error interrupt flags.
 *
 */
void DMA_transf_complete_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	_DMA_XXXX_clear_IRQ(cntrlr, stream, 5);
}

void DMA_half_transfer_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	_DMA_XXXX_clear_IRQ(cntrlr, stream, 4);
}

void DMA_transf_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	_DMA_XXXX_clear_IRQ(cntrlr, stream, 3);
}

void DMA_direct_mode_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
) {
	_DMA_XXXX_clear_IRQ(cntrlr, stream, 2);
}

/* EOF */
