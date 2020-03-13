#ifndef _SHARED_ISR_TIM6_DAC_H
#define _SHARED_ISR_TIM6_DAC_H

/*! The user-provided functionality that will be called by the shared ISR.
 */
extern void (* TIM6_DAC_user_handler)(void);

/*! Shared Interrupt Service Routine for TIM 6, DAC 1, and DAC 2 Underrun Errors.
 *
 * @brief The ISR for the Timer Module 6, Digital-to-Analog Module 1 Underrun Error, and Digital-to-Analog Module
 *        2 Underrun Error. This ISR calls the function pointed to by the TIM6_DAC_user_handler function pointer.
 *        If the function pointer is NULL when any of the interrupt sources trigger, this ISR contains a while (1)
 *        that will cause the system to spin.
 */
void TIM6_DAC_handler(void);

#endif /* _SHARED_ISR_TIM6_DAC_H */

/* EOF */
