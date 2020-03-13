#include "onboard_led.h"
#include "GPIO.h"

/*! Initializes the onboard LED.
 *
 * @brief Initializing the LED entails initializing and configuring GPIO port A pin 5 as an output port as port
 *        A pin 5 has been wired to the onboard LED.
 */
void onboard_led_init()
{
	GPIO_cnfg PA5_cnfg = { 
		  .mode = GPIO_mode_output
		, .type  = GPIO_output_type_push_pull
		, .speed = GPIO_output_speed_low
		, .pull  = GPIO_pull_none
	};
	GPIO_configure_port_pin(GPIO_port_A, 5, PA5_cnfg);
}

/*! Turns on the onboard LED.
 *
 * @brief Turning on the LED requires writing a 1 to GPIO port A pin 5.
 */
void onboard_led_turn_on()
{
	GPIO_write(GPIO_port_A, 5, 1);
}

/*! Turns off the onboard LED.
 *
 * @brief Turning off the LED requires writing a 0 to GPIO port A pin 5.
 */
void onboard_led_turn_off()
{
	GPIO_write(GPIO_port_A, 5, 0);
}

/*! Toggles the onboard LED.
 *
 * @brief Toggling the LED requires XORing bit 5 (ODR5) of the GPIOA output data register.
 */
void onboard_led_toggle()
{
	GPIO_toggle(GPIO_port_A, 5);
}

/* EOF */
