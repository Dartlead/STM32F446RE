#include "_shared_ISR_TIM6_DAC.h"
#include <stdlib.h>

void (* TIM6_DAC_user_handler)(void) = NULL;

/*! Shared Interrupt Service Routine for TIM 6, DAC 1, and DAC 2 Underrun Errors.
 *
 * @brief The user-provided functionality is only called when the function pointer is not NULL.
 */
__attribute__((interrupt("TIM6_DAC_handler"))) void TIM6_DAC_handler()
{
	if (TIM6_DAC_user_handler != NULL) {
		TIM6_DAC_user_handler();
	} else {
		while (1);
	}
}

/* EOF */
