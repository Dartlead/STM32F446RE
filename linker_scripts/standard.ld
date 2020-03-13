/* Generic Cortex-M4 Memory Model (Cortex-M4 Devices Generic User Guide 2-12)
 *
 * Region                   Memory Type        Execute Never   Address Bounds
 * Vendor-specific          Device             XN              0xE010 0000 - 0xFFFF FFFF
 * Private Peripheral Bus   Strongly-ordered   XN              0xE000 0000 - 0xE00F FFFF
 * External Device          Device             XN              0xA000 0000 - DFFFFF FFFF
 * External RAM             Normal             -               0x6000 0000 - 0x9FFF FFFF
 * Peripheral               Device             XN              0x4000 0000 - 0x5FFF FFFF
 * SRAM                     Normal             -               0x2000 0000 - 0x3FFF FFFF
 * Code                     Normal             -               0x0000 0000 - 0x1FFF FFFF
 *
 * Code, SRAM, and external RAM regions can hold programs; however, it is recommended that programs are always
 *    stored in the code region. Execute Never (XN) refers to a fault exception being thrown on the execution of an
 *    instruction executed from an XN region. Normal memory type allows the processor to re-order transactions. The
 *    device memory type preserves transaction order relative to other transactions in device or strongly- ordered
 *    memory. Strongly-ordered memory preserves the transaction order relative to all other transactions.
 *
 *
 * STM32F446RE Memory Map (stm32f446re reference manual pg. 56)
 *
 * Sub-Regions of Vendor-specific Region          Address Bounds
 * Reserved                                       0xE010 0000 - 0xFFFF FFFF
 *
 * Sub-Regions of Private Peripheral Bus Region   Address Bounds
 * Cortex-M4 Internal Peripherals                 0xE000 0000 - 0xE00F FFFF
 *
 * Sub-Regions of External RAM/Device Region      Address Bounds
 * AHB3                                           0x6000 0000 - 0xDFFF FFFF
 *
 * Sub-Regions of Peripheral Region               Address Bounds
 * Reserved                                       0x5006 0C00 - 0x5FFF FFFF
 * AHB2                                           0x5000 0000 - 0x5006 0BFF
 * Reserved                                       0x4008 0000 - 0x4FFF FFFF
 * AHB1                                           0x4002 0000 - 0x4007 FFFF
 * Reserved                                       0x4001 6C00 - 0x4001 FFFF
 * APB2                                           0x4001 0000 - 0x4001 6BFF
 * Reserved                                       0x4000 8000 - 0x4000 FFFF
 * APB1                                           0x4000 0000 - 0x4000 7FFF
 *
 * Sub-Regions of SRAM Region                     Address Bounds
 * Reserved                                       0x2002 0000 - 0x3FFF FFFF
 * SRAM (16 kB aliased by bit banding)            0x2001 C000 - 0x2001 FFFF
 * SRAM (112 kB aliased by bit banding)           0x2000 0000 - 0x2001 BFFF
 *
 * Sub-Regions of Code Region                     Address Bounds
 * Reserved                                       0x1FFF C008 - 0x1FFF FFFF
 * Option Bytes                                   0x1FFF C000 - 0x1FFF C00F
 * Reserved                                       0x1FFF 7A10 - 0x1FFF 7FFF
 * System Memory                                  0x1FFF 0000 - 0x1FFF 7A0F
 * Reserved                                       0x1FFE C008 - 0x1FFE FFFF
 * Option Bytes                                   0x1FFE C000 - 0x1FFE C00F
 * Reserved                                       0x0820 0000 - 0x1FFE BFFF
 * Flash Memory                                   0x0800 0000 - 0x081F FFFF
 * Reserved                                       0x0020 0000 - 0x07FF FFFF
 * Aliased to Flash, system memory, or SRAM       0x0000 0000 - 0x001F FFFF
 *    depending on BOOT pins
 */

ENTRY(reset_handler)

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x0007D000 /* 512 kB */
	RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x0001F400 /* 128 kB */
}

SECTIONS
{
	/* ========================================================================================================== */
	/* Text Section                                                                                               */
	/* ========================================================================================================== */
	.text :
	{
		KEEP(*(.vector_table))
		__vector_end = .;
		__vector_size = __vector_end - __vector_table;

		*(.text*)
		*(.rodata*)

	} > FLASH

	__etext = .;

	/* ========================================================================================================== */
	/* Data Section                                                                                               */
	/* ========================================================================================================== */
	.data : AT (__etext) /* Sets the LMA of this output section to __etext */
	{
		__data_start__ = .;

		*(.data*)

		. = ALIGN(4);
		__data_end__ = .;
	} > RAM

	/* ========================================================================================================== */
	/* .BSS Section                                                                                               */
	/* ========================================================================================================== */
	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;

		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		__bss_end__ = .;
	} > RAM

	/* ========================================================================================================== */
	/* Heap                                                                                                       */
	/* ========================================================================================================== */
	.heap (COPY): /* Section marked as not allocatble, i.e: no memory allocated for section at runtime */
	{
		__heap_base = .;

		KEEP(*(.heap*))

		__heap_limit = .;
	} > RAM

	/* ========================================================================================================== */
	/* Stack                                                                                                      */
	/* ========================================================================================================== */
	.stack_dummy :
	{
		KEEP(*(.stack*))
	} > RAM

	__stack_top = ORIGIN(RAM) + LENGTH(RAM);
	__stack_limit = __stack_top - SIZEOF(.stack_dummy);

	/* If program references __stack, it gets __stack_top. If program defines __stack, linker uses the
	 * program's def */
	PROVIDE(__stack = __stack_top);

	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__stack_limit >= __heap_limit, "region RAM overflowed with stack")
}

/* EOF */
