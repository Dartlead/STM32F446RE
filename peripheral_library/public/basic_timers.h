#include <stdint.h>
#include <stdbool.h>

#ifndef BASIC_TIMERS_H
#define BASIC_TIMERS_H

/*! An enumeration of the two basic timers (timer modules TIM6 and TIM7) available in the system.
 */
typedef enum BTIM_module
{
	  BTIM_module_TIM6 = 6
	, BTIM_module_TIM7 = 7
} BTIM_module;

/*! Configuration parameters for a basic timer. An explanation of each is found in basic_timers_driver.txt.
 */
typedef struct BTIM_cnfg
{
	bool auto_reload_preload_en;
	bool one_pulse_mode_en;
	bool update_request_src_en;
	bool update_event_dis;
	bool DMA_request_en;
	bool IRQ_en;
	uint32_t auto_reload_val;
	uint32_t timer_freq;
	uint32_t IRQ_priority;
	void (*IRQ_handler)(void);
} BTIM_cnfg;

/* ============================================================================================================= */
/* Configuration/Initialization Functions                                                                        */
/* ============================================================================================================= */
/*! Initializes one of the two onboard basic timer modules with the desired configuration.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules to initialize.
 * @param cnfg
 *    (input) The configuration for the basic timer module.
 */
void BTIM_init_timer(BTIM_module const timer
	, BTIM_cnfg const cnfg
);

/*! Updates the frequency of the clock driving the specified basic timer module.
 *
 * @brief The frequency change can be applied even if the timer is currently running but it will only take effect
 *        after the next update event from said timer module (i.e. after the timer overflows).
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules to initialize.
 * @param timer_freq
 *    (input) The new desired frequency of the timer's clock.
 */
void BTIM_update_timer_freq(BTIM_module const timer
	, uint32_t const timer_freq
);

/* ============================================================================================================= */
/* Start/Stop/Read Functions                                                                                     */
/* ============================================================================================================= */
/*! Starts one of the two onboard basic timer modules.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules to start.
 */
void BTIM_start_timer(BTIM_module const timer);

/*! Stops one of the two onboard basic timer modules.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules to stop.
 */
void BTIM_stop_timer(BTIM_module const timer);

/*! Reads the current value of one of the two onboard basic timers.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules to stop.
 * @return The current value of the desired timer.
 */
uint32_t BTIM_read_timer(BTIM_module const timer);

/* ============================================================================================================= */
/* Interupt/DMA Functionality                                                                                    */
/* ============================================================================================================= */
/*! Clears an update event (i.e. IRQ) of one of the two onboard basic timers.
 *
 * @note  This must be called during the associated service routine for the timer's interrupt.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules whose update event shall be cleared.
 */
void BTIM_clear_update_event(BTIM_module const timer);

/*! Provides the address of the count register of one of the two onboard basic timers.
 *
 * @brief Intended for peripherals like the DMA controller that need access to the basic timer's internal
 *        register's addresses.
 *
 * @param timer
 *    (input) Which of the two onboard basic timer modules whose count register address is desired.
 * @return The address of the count register for the specified timer.
 */
uint32_t * BTIM_count_reg_addr(BTIM_module const timer);

#endif /* BASIC_TIMERS_H */

/* EOF */
