ENTRY(reset_handler)

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x0007D000 /* 512 kB */
	RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x0001F400 /* 128 kB */
}

SECTIONS
{
	.text :
	{
		KEEP(*(.vector_table))

		*(.text*)
		*(.rodata*)
	} > FLASH

	.bss (NOLOAD) :
	{
		*(COMMON)
		__stack_top = ORIGIN(RAM) + 0x00000400;
	} > RAM
}

/* EOF */
