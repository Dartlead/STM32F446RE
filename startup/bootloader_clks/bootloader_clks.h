#ifndef BOOTLOADER_CLKS_H
#define BOOTLOADER_CLKS_H

/*! Sets the system clock source to either the HSI, PLL_P, or PLL_R.
 *
 * @brief The choice as to which source to use is made in the makefile.
 */
void btldr_set_sys_clk();

#endif /* BOOTLOADER_CLKS_H */

/* EOF */
