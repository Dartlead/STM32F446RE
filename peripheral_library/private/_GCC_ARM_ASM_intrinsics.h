#include <stdint.h>

#ifndef _GCC_ARM_ASM_INTRINSICS_H
#define _GCC_ARM_ASM_INTRINSICS_H

/* ============================================================================================================= */
/* Interrupt-Related                                                                                             */
/* ============================================================================================================= */
/*! Enable IRQ interrupts globally.
 *
 * @brief Enables IRQ interrupts by clearing the I-bit (IRQ mask bit) in the CPSR (Current Program Status
 *        Register).
 */
__attribute__((always_inline)) static inline void _enable_global_irq()
{
	__asm__ volatile ("cpsie i" : : : "memory");
}

/*! Disables IRQ interrupts globally.
 *
 * @brief Disables all IRQ interrupts by setting the I-bit (IRQ mask bit) in the CPSR (Current Program Status
 *        Register).
 */
__attribute__((always_inline)) static inline void _disable_global_irq()
{
	__asm__ volatile ("cpsid i" : : : "memory");
}

/*! Enables FIQ interrupts globally.
 *
 * @brief Enables FIQ interrupts by clearing the F-bit (FIRQ mask bit) in the CPSR (Current Program Status
 *        Register).
 */
__attribute__((always_inline)) static inline void _enable_fiq()
{
	__asm__ volatile ("cpsie f" : : : "memory");
}

/*! Disables FIQ interrupts globally.
 *
 * @brief Disables FIQ interrupts by setting the F-bit (FIRQ mask bit) in the CPSR (Current Program Status
 *        Register).
 */
__attribute__((always_inline)) static inline void _disable_fiq()
{
	__asm__ volatile ("cpsid f" : : : "memory");
}

/*! Gets the priority mask.
 *
 * @brief Gets the current state of the priority mask bit from the priority mask register.
 */
__attribute__((always_inline)) static inline uint32_t _get_PRIMASK()
{
	uint32_t result = 0;
	__asm__ volatile ("MRS %0, primask" : "=r" (result));
	return result;
}

/*! Sets the priority mask.
 *
 * @brief Assigns the provided value to the Priority Mask Register.
 *
 * @param primask
 *    (input) The desired mask for the priority mask register.
 */
__attribute__((always_inline)) static inline void _set_PRIMASK(uint32_t primask)
{
	__asm__ volatile ("MSR primask, %0" : : "r" (primask) : "memory");
}
/* ============================================================================================================= */
/* Synchronization Barriers                                                                                      */
/* ============================================================================================================= */
/*! Instruction synchronization barrier.
 *
 * @brief Flushes the pipeline in the processor so that all instructions following the ISB are fetched from cache
 *        or memory, after the instruction has been completed.
 */
__attribute__((always_inline)) static inline void _isb()
{
	__asm__ volatile ("isb 0xF":::"memory");
}

/*! Data synchronization barrier.
 *
 * @brief Ensures the apparent order of the explicit memory operations before and after the instruction without
 *        ensuring their completion.
 */
__attribute__((always_inline)) static inline void _dmb()
{
	__asm__ volatile ("dmb 0xF":::"memory");
}

/* ============================================================================================================= */
/* Generic                                                                                                       */
/* ============================================================================================================= */
/*! No operation.
 *
 * @brief No operation instruction does nothing.
 */
__attribute__((always_inline)) static inline void _nop()
{
	__asm__ volatile ("nop");
}

/*! Wait for interrupt.
 *
 * @brief Wait for interrupt is a hint instruction that suspends execution until one of a number of events
 *        occurs.
 */
__attribute__((always_inline)) static inline void _wfi()
{
	__asm__ volatile ("wfi");
}

/*! Wait for event.
 *
 * @brief Wait for event is a hint instruction that permits the processor to enter a low-power state until one
 *        of a number of events occurs.
 */
__attribute__((always_inline)) static inline void _wfe()
{
	__asm__ volatile ("wfe");
}

/*! Send event.
 *
 * @brief Send event is a hint instruction that causes an event to be signaled to the CPU.
 */
__attribute__((always_inline)) static inline void _sev()
{
	__asm__ volatile ("sev");
}

#endif /* _GCC_ARM_ASM_INTRINSICS_H */

/* EOF */
