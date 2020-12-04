#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! I2C interfaces offered by the system.
 */
typedef enum I2C_interface
{
	  kI2C_interface_1 = 0
	, kI2C_interface_2 = 1
	, kI2C_interface_3 = 2
} I2C_interface_t;

/*! I2C interface pinouts:
 */
typedef enum I2C_pinout
{
	  kI2C_pinout_1 = 0
	, kI2C_pinout_2 = 1
} I2C_pinout_t;

/*! Direction of master and slave transfers.
 */
typedef enum I2C_direction
{
	  kI2C_direction_read  = 0 //Master receive
	, kI2C_direction_write = 1 //Master transmit
} I2C_direction_t;

/*! I2C interface's duty cycle.
 */
typedef enum I2C_duty_cycle
{
	  kI2C_SM_no_duty   = 0 //Standard-Mode, T_low/T_high = 1
	, kI2C_FM_duty_2    = 1 //Fast-Mode T_low/T_high = 2
	, kI2C_FM_duty_16_9 = 2 //Fast-Mode T_low/T_high = 16/9
} I2C_FM_duty_cycle_t;

/*! I2C interface status codes.
 */
typedef enum I2C_status
{
	  kI2C_status_OK             =  0
	, kI2C_status_generic_error  = -1 //Within functions, status is initialized to this
	, kI2C_status_busy           = -1 //Another master is currently utilizing the bus
	, kI2C_status_NAK            = -2 //The slave device sent a NAK in response to a byte
	, kI2C_status_invalid_config = -3 //Interface choice or configuration parameters are invalid
} I2C_status_t;

/* ============================================================================================================= */
/* Driver Capability/Configuration Options                                                                       */
/* ============================================================================================================= */
/*! Capabilities of the driver.
 */
typedef struct I2C_driver_capabilities
{
	uint32_t addressing_10_bit : 1;  //Whether or not the driver supports 10-bit addressing
	uint32_t reserved          : 32; //Reserved (must be 0)
} I2C_driver_capabilities_t;

/*! Configuration parameters for an I2C interface.
 */
typedef struct I2C_config
{
	uint32_t            SCL_freq;
	I2C_FM_duty_cycle_t SCL_duty_cycle;
	I2C_pinout_t        pinout;
} I2C_config_t;

/* ============================================================================================================= */
/* Driver Capability/Configuration Functions                                                                     */
/* ============================================================================================================= */
/*! Gets the capabilities of the I2C driver.
 *
 * @return The capabilities of the driver.
 */
I2C_driver_capabilities_t I2C_get_capabilities(void);

/*! Provides a default configuration for an I2C interface.
 *
 * @brief Default configuration is for a Standard Mode interface with a pin 1 GPIO configuration.
 *        SCL_freq       = 100000
 *        SCL_duty_cycle = kI2C_SM_no_duty
 *        pinout         = kI2C_pinout_1
 *
 * @param config
 *    (input/output) The default configuration struct.
 */
void I2C_get_default_config(I2C_config_t * const config);

/*! Initializes and configures the I2C interface.
 *
 * @note  The GPIO pins for SDA and SCL are configured to be open-drain with a low output speed and no pullup/down
 *        resistors.
 *
 * @param interface
 *    (input) Which I2C interface to initialize.
 * @param config
 *    (input) The configuration parameters for the I2C interface.
 * @return The status of the initialization.
 */
I2C_status_t I2C_init(I2C_interface_t const interface
	, I2C_config_t const * const config
);

/* ============================================================================================================= */
/* Transfer Functions                                                                                            */
/* ============================================================================================================= */
/*! Performs a polling send transfer on the I2C bus.
 *
 * @param interface
 *    (input) Which I2C interface to send the data on.
 * @param slave_addr
 *    (input) The address of the I2C slave receiving the data.
 * @param slave_reg_addr
 *    (input) The address of the I2C slave's register being written to.
 * @param tx_buffer
 *    (input) The data to be written.
 * @param tx_size
 *    (input) How many bytes of data to be written.
 */
void I2C_master_send_blocking(I2C_interface_t const interface
	, uint8_t slave_addr
	, uint8_t const slave_reg_addr
	, void * tx_buffer
	, uint32_t const tx_size
);

/*! Performs a polling receive transfer on the I2C bus.
 *
 * @param interface
 *    (input) Which I2C interface to receive the data from.
 * @param slave_addr
 *    (input) The address of the I2C slave the data will be received from.
 * @param slave_reg_addr
 *    (input) The address of the I2C slave's register whose data is being received.
 * @param rx_buffer
 *    (input) Buffer to hold the data being received.
 * @param rx_size
 *    (input) How many bytes of data to be received.
 * @return The status of the receive transfer.
 */
void I2C_master_receive_blocking(I2C_interface_t const interface
	, uint8_t slave_addr
	, uint8_t const slave_reg_addr
	, void * rx_buffer
	, uint32_t const rx_size
);

#ifdef __cplusplus
}
#endif

#endif /* DRIVER_I2C_H */

/* EOF */
