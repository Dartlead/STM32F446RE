#include <stdint.h>
#include <stdbool.h>

#ifndef GPIO_H
#define GPIO_H

/*! An enumeration of all the different ports available in the system.
 */
typedef enum GPIO_port
{
	  GPIO_port_A = 0
	, GPIO_port_B = 1
	, GPIO_port_C = 2
	, GPIO_port_D = 3
	, GPIO_port_E = 4
	, GPIO_port_F = 5
	, GPIO_port_G = 6
	, GPIO_port_H = 7
} GPIO_port;

/*! An enumeration of all of the different modes a pin can be configured with.
 */
typedef enum GPIO_mode
{
	  GPIO_mode_altrnt_func_0  = 0
	, GPIO_mode_altrnt_func_1  = 1
	, GPIO_mode_altrnt_func_2  = 2
	, GPIO_mode_altrnt_func_3  = 3
	, GPIO_mode_altrnt_func_4  = 4
	, GPIO_mode_altrnt_func_5  = 5
	, GPIO_mode_altrnt_func_6  = 6
	, GPIO_mode_altrnt_func_7  = 7
	, GPIO_mode_altrnt_func_8  = 8
	, GPIO_mode_altrnt_func_9  = 9
	, GPIO_mode_altrnt_func_10 = 10
	, GPIO_mode_altrnt_func_11 = 11
	, GPIO_mode_altrnt_func_12 = 12
	, GPIO_mode_altrnt_func_13 = 13
	, GPIO_mode_altrnt_func_14 = 14
	, GPIO_mode_altrnt_func_15 = 15
	, GPIO_mode_input          = 16
	, GPIO_mode_output         = 17
	, GPIO_mode_analog         = 18
} GPIO_mode;

/*! An enumeration of all the different types that an output port can be.
 */
typedef enum GPIO_output_type
{
	  GPIO_output_type_push_pull  = 0
	, GPIO_output_type_open_drain = 1
} GPIO_output_type;

/*! An enumeration of all the different output speeds for an output port.
 */
typedef enum GPIO_output_speed
{
	  GPIO_output_speed_low    = 0
	, GPIO_output_speed_medium = 1
	, GPIO_output_speed_fast   = 2
	, GPIO_output_speed_high   = 3
} GPIO_output_speed;

/*! An enumeration of all the different pin pull options for a port.
 */
typedef enum GPIO_pull
{
	  GPIO_pull_none      = 0
	, GPIO_pull_pull_up   = 1
	, GPIO_pull_pull_down = 2
} GPIO_pull;

/*! Configuration parameters for a GPIO pin. An explanation of each is found in GPIO_driver.txt.
 */
typedef struct GPIO_cnfg
{
	GPIO_mode         mode;
	GPIO_output_type  type;
	GPIO_output_speed speed;
	GPIO_pull         pull;
} GPIO_cnfg;

/* ============================================================================================================= */
/* Configuration Functions                                                                                       */
/* ============================================================================================================= */
/*! Configures and initializes the desired GPIO port and pin with the desired configuration.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @param cnfg
 *    (input) The configuration for the desired port/pin combo.
 */
void GPIO_configure_port_pin(GPIO_port const port
	, uint32_t const pin
	, GPIO_cnfg const cnfg
);

/* ============================================================================================================= */
/* GPIO Write Functions                                                                                          */
/* ============================================================================================================= */
/*! Writes a binary 0 or 1 to the desired GPIO port and pin.
 *
 * @note Behavior if the desired port/pin combo is configured as an input port is undefined.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @param write_val
 *    (input) The value to write. Must be either 0 or 1.
 */
void GPIO_write(GPIO_port const port
	, uint32_t const pin
	, uint32_t const write_val
);

/*! Writes (atomically) a binary 0 or 1 to the desired GPIO port and pin.
 *
 * @brief The atomic nature of this function ensures that no interrupt will happen between the read and the modify
 *        access.
 * @note  Behavior if the desired port/pin combo is configured as an input port is undefined.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @param write_val
 *    (input) The value to write. Must be either 0 or 1.
 */
void GPIO_write_atomic(GPIO_port const port
	, uint32_t const pin
	, uint32_t const write_val
);

/*! Toggles the value on the desired GPIO port and pin.
 *
 * @note Behavior if the desired port/pin combo is configured as an input port is undefined.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 */
void GPIO_toggle(GPIO_port const port
	, uint32_t const pin
);

/* ============================================================================================================= */
/* GPIO Read Functions                                                                                           */
/* ============================================================================================================= */
/*! Reads the value on a GPIO port and pin.
 *
 * @note Behavior if the desired port/pin combo is configured as an output port is undefined.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @return The input value of the port/pin combo, either a 0 or 1.
 */
uint32_t GPIO_read(GPIO_port const port
	, uint32_t const pin
);

/* ============================================================================================================= */
/* GPIO Miscellaneous Functions                                                                                  */
/* ============================================================================================================= */
/*! Locks a GPIO port/pin combo's configuration from changing until after a system reset.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 */
void GPIO_lock(GPIO_port const port
	, uint32_t const pin
);

/*! Checks if a GPIO port/pin combo is locked.
 *
 * @param port
 *    (input) The desired port.
 * @param pin
 *    (input) The desired pin. Must be between 0 and 15.
 * @return 'true' if the pin is locked, 'false' otherwise.
 */
bool GPIO_is_pin_locked(GPIO_port const port
	, uint32_t const pin
);

#endif /* GPIO_H */

/* EOF */
