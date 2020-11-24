#include "onboard_led.h"

int main(void)
{
	unsigned int i = 0;

	onboard_led_init();

	while (1) {
		onboard_led_toggle();

		i = 0;
		while (i < 1000000) {
			i++;
		}

		onboard_led_toggle();
	}

	while (1);
	return 0;
}

/* EOF */
