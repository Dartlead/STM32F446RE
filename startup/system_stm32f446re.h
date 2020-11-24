#ifndef SYSTEM_STM32F446RE_H
#define SYSTEM_STM32F446RE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! References to the device's various clocks.
 */
extern uint32_t core_clock;
extern uint32_t AHB_bus_clock;
extern uint32_t APB1_bus_clock;
extern uint32_t APB2_bus_clock;

/*! Return status codes.
 * status
 *    '0' - Successful system initialization.
 *    '1' - Unsuccessful system initialization. Some default values for sys, AHB, APB1, or APB2 clocks may have
 *          been set.
 * sys_clk_src
 *    '0' - Valid system clock source chosen (via preprocessor define).
 *    '1' - Invalid system clock source chosen (via preprocessor define).
 * PLLP_factor
 *    '0' - Valid PLLP factor chosen (via preprocessor define).
 *    '1' - Invalid PLLP factor chosen (via preprocessor define).
 * PLLR_factor
 *    '0' - Valid PLLR factor chosen (via preprocessor define).
 *    '1' - Invalid PLLR factor chosen (via preprocessor define).
 * PLL_lock
 *    '0' - If a PLL-based system clock source is chosen, the PLL successfully locked it's frequency.
 *    '1' - If a PLL-based system clock source is chosen, the PLL failed to lock it's frequency.
 * sys_clk_accept
 *    '0' - System successfully accepted the desired source for the system clock.
 *    '1' - System failed to accept the desired source for the system clock.
 * HSE_stabilize
 *    '0' - If a HSE-based (or PLL clocked by the HSE) system clock source is chosen, the HSE successfully
 *          stabilized.
 *    '1' - If a HSE-based (or PLL clocked by the HSE) system clock source is chosen, the HSE failed to
 *          stabilize.
 * overdrive
 *    '0' - If the desired AHB prescaler chosen (via preprocessor define) results in an AHB bus frequency > 120
 *          MHz, over-drive mode was successfully entered.
 *    '1' - Over-drive mode failed to be ready.
 *    '2' - Over-drive switching failed to be ready.
 * voltage_scale
 *    '0' - The voltage scale change was accepted.
 *    '1' - The voltage scale was attempted to be changed while the main PLL was on.
 * AHB_prescaler
 *    '0' - Valid AHB prescaler chosen (via preprocessor define).
 *    '1' - Invalid AHB prescaler chosen (via preprocessor define), AHB bus frequency will be equivalent to the
 *          system clock.
 * APB1_prescaler
 *    '0' - Valid APB1 prescaler chosen (via preprocessor define).
 *    '1' - Invalid APB1 prescaler chosen (via preprocessor define).
 * APB2_prescaler
 *    '0' - Valid APB2 prescaler chosen (via preprocessor define).
 *    '1' - Invalid APB2 prescaler chosen (via preprocessor define).
 */
typedef struct system_init_status {
	uint32_t init_status    : 1;
	uint32_t sys_clk_src    : 1;
	uint32_t PLLP_factor    : 1;
	uint32_t PLLR_factor    : 1;
	uint32_t PLL_lock       : 1;
	uint32_t sys_clk_accept : 1;
	uint32_t HSE_stabilize  : 1;
	uint32_t overdrive      : 1;
	uint32_t voltage_scale  : 1;
	uint32_t AHB_prescaler  : 1;
	uint32_t APB1_prescaler : 1;
	uint32_t APB2_prescaler : 1;
} system_init_status;

/*! Initializes the system clock and the AHB, APB1, and APB2 bus clocks.
 *
 * @brief The parameters controlling the configuration of all of the clocks are provided preprocessor #defines as
 *        stipulated in the makefile. The configuration options are provided assuming a VDD of 2.7 to 3.6V (the
 *        VDD range when the board is powered via USB).
 *
 * @note  If a bypassed HSE is selected as the system clock source, the reference to the system clock will always
 *        be 0.
 * @note  If there is an error setting up the system clock, the default behavior sets the reference to the system
 *        clock to 16 MHz.
 * @note  If there is an error setting up the AHB bus clock, the default behavior sets the reference to the AHB bus
 *        clock to the frequency of the system clock.
 * @note  IF there is an error setting up the APB1 or APB2, the default behavior sets the reference to the APB1 and
 *        APB2 bus clocks to the highest frequency that fulfills the frequency constraints instituted by the APB1
 *        and APB2 buses.
 *
 * @return The status of the initialization of the system's clocks.
 */
system_init_status system_init(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_STM32F446RE_H */

/* EOF */
