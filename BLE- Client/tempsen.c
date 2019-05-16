/*
 * tempsensor.c
 *
 *  Created on: Sep 22, 2018
 *      Author: Admin
 */

#include "tempsen.h"
#include "gpio.h"
#include "i2c.h"
#include "infrastructure.h"
#include "native_gecko.h"
#include "gatt_db.h"



float tempsensor (uint16_t temp)
{
	uint8_t htmTempBuffer[5]; /* Stores the temperature data in the Health Thermometer (HTM) format. */
	uint8_t flags = 0x00;   /* HTM flags set as 0 for Celsius, no time stamp and no temperature type. */
	uint32_t temperature;   /* Stores the temperature data read from the sensor in the correct format */
	uint8_t *p = htmTempBuffer; /* Pointer to HTM temperature buffer needed for converting values to bitstream. *///TEMPSENS_TemperatureGet(I2C0,)
	UINT8_TO_BITSTREAM(p, flags);
	float tempcelsius = (float)temp;
	tempcelsius=((175.72 * tempcelsius)/65536)-46.85;
	/* Convert sensor data to correct temperature format */
	temperature = FLT_TO_UINT32(tempcelsius*1000, -3);
	/* Convert temperature to bitstream and place it in the HTM temperature data buffer (htmTempBuffer) */
	UINT32_TO_BITSTREAM(p, temperature);
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_temperature_measurement, 5, htmTempBuffer);
		/* Send indication of the temperature in htmTempBuffer to all "listening" clients.*/
	return tempcelsius;
}
