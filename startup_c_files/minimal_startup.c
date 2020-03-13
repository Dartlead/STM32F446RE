extern void main(void);

void reset_handler(void)
{
	main();

	while (1);
}

extern unsigned int const __stack_top;

__attribute__((section(".vector_table"))) void (*const vector_table[])(void) = {
	  (void (*)(void))&__stack_top
	, reset_handler
};

/* EOF */
