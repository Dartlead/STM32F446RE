#include <stdint.h>
#include <stdbool.h>

#ifndef DMA_H
#define DMA_H

/*! An enumeration of the two DMA controllers offered by the system.
 */
typedef enum DMA_controller {
	  DMA_controller1 = 0
	, DMA_controller2 = 1
} DMA_controller;

/*! An enumeration of all the different streams offered by a single DMA controller.
 */
typedef enum DMA_stream {
	  DMA_stream0 = 0
	, DMA_stream1 = 1
	, DMA_stream2 = 2
	, DMA_stream3 = 3
	, DMA_stream4 = 4
	, DMA_stream5 = 5
	, DMA_stream6 = 6
	, DMA_stream7 = 7
} DMA_stream;

/*! An enumeration of all the different transfer directions offered by a stream.
 */
typedef enum DMA_transf_dir {
	  DMA_transf_dir_peri_mem = 0 //peripheral-to-memory transfer direction
	, DMA_transf_dir_mem_peri = 1 //memory-to-peripheral transfer direction
	, DMA_transf_dir_mem_mem  = 2 //memory-to-memory transfer direction
} DMA_transf_dir;

/*! An enumeration of all the different burst transaction types offered by a stream while in burst mode.
 */
typedef enum DMA_burst_beats {
	  DMA_transf_type_single       = 0 //single transfer, no burst
	, DMA_transf_type_4beat_burst  = 1 //incremental burst of 4 beats
	, DMA_transf_type_8beat_burst  = 2 //incremental burst of 8 beats
	, DMA_transf_type_16beat_burst = 3 //incremental burst of 16 beats
} DMA_burst_beats;

/*! An enumeration of all the different priority levels offered by a DMA stream.
 */
typedef enum DMA_stream_prio {
	  DMA_stream_prio_low       = 0
	, DMA_stream_prio_medium    = 1
	, DMA_stream_prio_high      = 2
	, DMA_stream_prio_very_high = 3
} DMA_stream_prio;

/*! An enumeration of all the different FIFO threshold levels offered by a stream.
 */
typedef enum DMA_FIFO_thresh {
	  DMA_FIFO_1_4_full = 0 //4-word FIFO 1/4 full
	, DMA_FIFO_1_2_full = 1 //4-word FIFO 1/2 full
	, DMA_FIFO_3_4_full = 2 //4-word FIFO 3/4 full
	, DMA_FIFO_full     = 3 //4-word FIFO full
} DMA_FIFO_thresh;

/*! Configuration parameters for a stream in a DMA controller. An explanation of each is found in DMA_driver.txt.
 */
typedef struct DMA_stream_cnfg {
	bool flow_cntrlr_mode_en;
	bool direct_mode_en;
	bool circular_mode_en;
	bool double_buff_mode_en;
	bool peri_incr_mode_en;
	bool mem_incr_mode_en;
	bool burst_mode_en;
	bool transf_complete_IRQ_en;
	bool half_transf_IRQ_en;
	bool transf_error_IRQ_en;
	bool direct_mode_error_IRQ_en;
	bool FIFO_error_IRQ_en;
	DMA_transf_dir transf_dir;
	DMA_stream_prio stream_prio;
	DMA_FIFO_thresh FIFO_thresh;
	DMA_burst_beats peri_beats;
	DMA_burst_beats mem_beats;
	uint32_t double_buff_cur_tar;
	uint32_t peri_data_size;
	uint32_t mem_data_size;
	uint32_t n_data_to_trans;
	uint32_t assoc_channel;
	uint32_t IRQ_priority;
	uint32_t * peri_addr;
	uint32_t * mem0_addr;
	uint32_t * mem1_addr;
	void (* IRQ_handler)(void);
} DMA_stream_cnfg;

/* ============================================================================================================= */
/* Configuration/Configuration Update Functions                                                                  */
/* ============================================================================================================= */
/*! Configures a DMA stream for a given DMA controller.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be configured.
 * @param cnfg
 *    (input) The configuration options for the stream.
 */
void DMA_configure_stream(DMA_controller const cntrlr
	, DMA_stream const stream
	, DMA_stream_cnfg const cnfg
);

/*! Updates the number of data items that the DMA controller will transfer.
 *
 * @brief This call will do nothing unless the stream is currently disabled (after calling DMA_disable_stream() or
 *        while configuring a stream with DMA_configure_stream()).
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose data to transfer option is to be updated.
 * @param new_n_data_to_trans
 *    (input) The new value of the number of data items to transfer. Must be between 1 and 65535.
 */
void DMA_stream_update_n_data_to_trans(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const new_n_data_to_trans
);

/*! Updates the peripheral, memory 0, or memory 1 addresses of the desired DMA stream.
 *
 * @brief This call will do nothing unless the stream is currently disabled (after calling DMA_disable_stream() or
 *        while configuring a stream with DMA_configure_stream()).
 * @note  The DMA_stream_update_mem1_addr() should only be called if double buffer mode has been enabled on the
 *        desired stream.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose transfer peripheral/memory addresses are to be updated.
 * @param new_XXXX_addr
 *    (input) The new peripheral/memory addresses.
 */
void DMA_stream_update_peri_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_peri_addr
);
void DMA_stream_update_mem0_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_mem0_addr
);
void DMA_stream_update_mem1_addr(DMA_controller const cntrlr
	, DMA_stream const stream
	, uint32_t const * const new_mem1_addr
);

/*! Updates the transfer complete, half transfer, transfer error, direct mode error, or FIFO error IRQ enables.
 *
 * @brief This call will do nothing unless the stream is currently disabled (after calling DMA_disable_stream() or
 *        while configuring a stream with DMA_configure_stream()).
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose interrupt enable options are to be updated.
 * @param new_XXXX_IRQ_en
 *    (input) The interrupt enable that is to be updated.
 */
void DMA_stream_update_transf_complete_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_transf_complete_IRQ_en
);
void DMA_stream_update_half_transfer_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_half_transf_IRQ_en
);
void DMA_stream_update_transf_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_transf_error_IRQ_en
);
void DMA_stream_update_direct_mode_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_direct_mode_error_IRQ_en
);
void DMA_stream_update_FIFO_error_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
	, bool const new_FIFO_error_IRQ_en
);

/* ============================================================================================================= */
/* Enable/Disable Functions                                                                                      */
/* ============================================================================================================= */
/*! Enables a DMA stream for a given DMA controller.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be enabled.
 */
void DMA_enable_stream(DMA_controller const cntrlr
	, DMA_stream const stream
);

/*! Disables a DMA stream for a given DMA controller.
 *
 * @brief This call is blocking because the DMA controller will not be truly disabled until the current transfer is
 *        finished (the current transfer does not mean the *entire* transfer, just whatever bus transactions would
 *        happen given the state of the FIFO at the time). Thus this call waits until this has happened.
 * @note  This call's "side-effects" set the transfer complete flag and clear the interrupt enables.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be enabled.
 * @return The number of data items left to be transferred at the time of disabling.
 */
uint32_t DMA_disable_stream(DMA_controller const cntrlr
	, DMA_stream const stream
);

/* ============================================================================================================= */
/* Status Functions                                                                                              */
/* ============================================================================================================= */
/*! Gets the peripheral, memory location 0, or memory location 1 addresses.
 *
 * @brief Gets the DMA source/destination addresses that could be the peripheral, memory location 0, or memory
 *        location 1.
 * @note  The DMA_mem1_addr() call will ony return a value if the stream is configured for double-buffer mode.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose source/destination address is desired.
 * @return The address of the peripheral, memory location 0, or memory location 1.
 */
uint32_t * DMA_peri_addr(DMA_controller const cntrlr
	, DMA_stream const stream
);
uint32_t * DMA_mem0_addr(DMA_controller const cntrlr
	, DMA_stream const stream
);
uint32_t * DMA_mem1_addr(DMA_controller const cntrlr
	, DMA_stream const stream
);

/*! Gets the current target of a double-buffer enabled transfer.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose current target is desired.
 * @return '0' if the current target is memory location 0, '1' if the current target is memory location 1.
 */
uint32_t DMA_double_buff_target(DMA_controller const cntrlr
	, DMA_stream const stream
);

/* ============================================================================================================= */
/* FIFO Functions                                                                                                */
/* ============================================================================================================= */
/*! Checks a DMA stream's FIFO level.
 *
 * @brief The FIFO level represents the amount of data from the DMA transfer source that is currently in the FIFO.
 *        If the DMA stream whose FIFO is being queried has direct mode enabled, the results of this function are
 *        meaningless.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream that is to be enabled.
 * @return '0' for empty    <  FIFO level <  1/4 full
 *         '1' for 1/4 full <= FIFO level <= 1/2 full
 *         '2' for 1/2 full <= FIFO level <  3/4 full
 *         '3' for 3/4 full <= FIFO level <  full
 *         '4' for FIFO is empty
 *         '5' for FIFO is full
 */
uint32_t DMA_FIFO_level(DMA_controller const cntrlr
	, DMA_stream const stream
);

/*! Checks if the FIFO error interrupt flag is pending.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose interrupt status is to be checked.
 * @return 'true' if a FIFO error is pending, 'false' if a FIFO error is pending or an invalid cntrlr or stream is
 *         input.
 */
bool DMA_FIFO_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
);

/*! Clears the FIFO error interrupt flag.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose interrupt status is to be checked.
 */
void DMA_FIFO_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
);

/* ============================================================================================================= */
/* Interrupt/Error Status Functions                                                                              */
/* ============================================================================================================= */
/*! Checks if the transfer complete, half transfer, transfer error, or direct mode error interrupt flags are
 *  pending.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose interrupt status is to be checked.
 */
bool DMA_transf_complete_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
);
bool DMA_half_transfer_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
);
bool DMA_transfer_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
);
bool DMA_direct_mode_error_IRQ_pending(DMA_controller const cntrlr
	, DMA_stream const stream
);

/*! Clears the transfer complete, half transfer, transfer error, or direct mode error interrupt flags.
 *
 * @param cntrlr
 *    (input) Which of the two onboard DMA controllers the desired stream is associated with.
 * @param stream
 *    (input) The stream whose interrupt status is to be checked.
 */
void DMA_transf_complete_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
);
void DMA_half_transfer_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
);
void DMA_transf_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
);
void DMA_direct_mode_error_clear_IRQ(DMA_controller const cntrlr
	, DMA_stream const stream
);

#endif /* DMA_H */

/* EOF */
