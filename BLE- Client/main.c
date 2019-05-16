
/***********************************************************************************************//**
 * \file   main.c
 * \brief  Silicon Labs Empty Example Project
 *
 * This example demonstrates the bare minimum needed for a Blue Gecko C application
 * that allows Over-the-Air Device Firmware Upgrading (OTA DFU). The application
 * starts advertising after boot and restarts advertising after a connection is closed.
 ***************************************************************************************************
 * <b> (C) Copyright 2016 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

/* Board headers */
#include "init_mcu.h"
#include "init_board.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "infrastructure.h"
#include "gatt_db.h"

/* Libraries containing default Gecko configuration values */
#include "em_emu.h"
#include "em_cmu.h"
#include "math.h"

/* Device initialization header */
#include "hal-config.h"

/*#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif*/

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup app
 * @{
 **************************************************************************************************/

#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 4
#define EnM 3<-----------EnergyMode
#define UINT32_TO_FLT(data)       (((float)((int32_t)(data) & 0x00FFFFFFU)) * (float)pow(10, ((int32_t)(data) >> 24)))
#endif
uint8_t bluetooth_stack_heap[DEFAULT_BLUETOOTH_HEAP(MAX_CONNECTIONS)];


// Gecko configuration parameters (see gecko_configuration.h)


// Flag for indicating DFU Reset must be performed
uint8_t boot_to_dfu = 0;
//***********************************************************************************
// Include files
//***********************************************************************************

#include "main.h"
#include "gpio.h"
#include "cmu.h"
#include "sleep.h"
#include "letimer.h"
#include "i2c.h"
#include "tempsen.h"
#include "timer.h"
#include <stdio.h>
#include "retargetserial.h"
#include "lcdGraphics/lcd_driver.h"
//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
int sleep_enter[5];

int enm;

//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
static const gecko_configuration_t config = {
  .config_flags = 0,
  .sleep.flags = SLEEP_FLAGS_DEEP_SLEEP_ENABLE,
  .bluetooth.max_connections = MAX_CONNECTIONS,
  .bluetooth.heap = bluetooth_stack_heap,
  .bluetooth.heap_size = sizeof(bluetooth_stack_heap),
  .bluetooth.sleep_clock_accuracy = 100, // ppm
  .gattdb = &bg_gattdb_data,
  .ota.flags = 0,
  .ota.device_name_len = 3,
  .ota.device_name_ptr = "OTA",
#if (HAL_PA_ENABLE) && defined(FEATURE_PA_HIGH_POWER)
  .pa.config_enable = 1, // Enable high power PA
  .pa.input = GECKO_RADIO_PA_INPUT_VBAT, // Configure PA input to VBAT
#endif // (HAL_PA_ENABLE) && defined(FEATURE_PA_HIGH_POWER)
};


//***********************************************************************************
// functions
/*void temperatureMeasure()
{
  uint8_t htmTempBuffer[5]; /* Stores the temperature data in the Health Thermometer (HTM) format. */
  /*uint8_t flags = 0x00;   /* HTM flags set as 0 for Celsius, no time stamp and no temperature type. */
  //int32_t tempData;     /* Stores the Temperature data read from the RHT sensor. */
  //uint32_t rhData = 0;    /* Dummy needed for storing Relative Humidity data. */
  //uint32_t temperature;   /* Stores the temperature data read from the sensor in the correct format */
  //uint8_t *p = htmTempBuffer; /* Pointer to HTM temperature buffer needed for converting values to bitstream. */

  /* Convert flags to bitstream and append them in the HTM temperature data buffer (htmTempBuffer) */
  //UINT8_TO_BITSTREAM(p, flags);

  /* Sensor relative humidity and temperature measurement returns 0 on success, nonzero otherwise */
  //if (Si7013_MeasureRHAndTemp(I2C0, SI7021_ADDR, &rhData, &tempData) == 0) {
    /* Convert sensor data to correct temperature format */
    //temperature = FLT_TO_UINT32(tempData, -3);
    /* Convert temperature to bitstream and place it in the HTM temperature data buffer (htmTempBuffer) */
    //UINT32_TO_BITSTREAM(p, temperature);
    /* Send indication of the temperature in htmTempBuffer to all "listening" clients.
     * This enables the Health Thermometer in the Blue Gecko app to display the temperature.
     *  0xFF as connection ID will send indications to all connections. */
    /*gecko_cmd_gatt_server_send_characteristic_notification(
      0xFF, gattdb_temperature_measurement, 5, htmTempBuffer);
  }
}*/
//***********************************************************************************


//***********************************************************************************
// main
//***********************************************************************************

/**
 * @brief  Main function
 */

int connect;
bd_addr serveraddress= {.addr= {0x6e, 0xf2, 0xb5, 0x57, 0x0b, 0x00}};//<----------Server Address
const uint8_t thermoService[2]={0x09, 0x18};
const uint8_t thermoChar[2]={0x1c, 0x2a};
uint32_t service, character;
int var=0;

int main(void)
{
  //enm=EnM;variable with value of EnergyMode
  // Initialize device
  initMcu();
  // Initialize board
  initBoard();

  /* Initialize GPIO */
  gpio_init();

  // Initialize clocks
  cmu_init();

  // Initialize stack
  gecko_init(&config);

  LETimer0Setup();

  TIMER0_setup();//LETIMER Setup

  //event_scheduler=0;

  //Si7013_Detect(I2C0, SI7021_ADDR, NULL);
  //	           /* This event is generated when the software timer has ticked. In this example the temperature
  /* Measure the temperature as defined in the function temperatureMeasure() */
  //temperatureMeasure();

  LCD_init("BLE Client");//OR LCD_init("BLE Client");

    RETARGET_SerialInit();
    RETARGET_SerialCrLf(true);
    struct gecko_msg_system_get_bt_address_rsp_t *add;
    char address[40] = {0};
    char TEMP[8]={0};
    float tempcelsius;
    bool Random=false;
    uint8_t Node[5]={};

  while(1)
  {
	  /* Event pointer for handling events */
	     struct gecko_cmd_packet* evt;

	     /* Check for stack event. */
	     evt = gecko_wait_event();

	     /* Handle events */
	     switch (BGLIB_MSG_ID(evt->header)) {
	       /* This boot event is generated when the system boots up after reset.




	     */
	     	 /* Event structure */
	     	 /*struct gecko_msg_le_connection_opened_evt_t
	     	 {
	      	  bd_addr address;,
	      	  uint8 address_type;,
	      	  uint8 master;,
	      	  uint8 connection;,
	      	  uint8 bonding;
	     	 };*/

	     case gecko_evt_system_boot_id:

	    	 printf("Boot\r\n");
	    	 gecko_cmd_sm_delete_bondings();
	    	 printf("Delete all bondings\n");
	    	 gecko_cmd_sm_configure(0x0F,sm_io_capability_displayyesno);
	    	 gecko_cmd_sm_set_bondable_mode(1);
	    	 add = gecko_cmd_system_get_bt_address();
	    	 LCD_write("ADDRESS", LCD_ROW_BTADDR1);
	    	 snprintf(address, 40, "%02x:%02x:%02x:%02x:%02x:%02x",
	    	    		  add->address.addr[5],
	    	  			  add->address.addr[4],
	    	  			  add->address.addr[3],
	    	  			  add->address.addr[2],
	    	  			  add->address.addr[1],
	    	  			  add->address.addr[0]
	    	 );
	    	 LCD_write(address, LCD_ROW_BTADDR2);
	    	  /* Set advertising parameters. 100ms advertisement interval.
	          * The last two parameters are duration and maxevents left as default. */
	         gecko_cmd_le_gap_set_discovery_timing(5, 0x10, 0x10);
	         gecko_cmd_le_gap_set_discovery_type(5, 0x01);
	         //gecko_cmd_le_gap_discover(le_gap_discover_observation);

	         gecko_cmd_le_gap_connect(serveraddress, le_gap_address_type_public, 0x01);
	         /* Start general advertising and enable connections. */
	         //gecko_cmd_le_gap_set_scan_parameters(160, 112, 0);
	         break;

	     case gecko_evt_le_connection_opened_id:
	         /*if(evt->data.evt_le_connection_opened.bonding != 0xFF)
	         {
	        	 gecko_cmd_gatt_discover_primary_services_by_uuid(evt->data.evt_sm_confirm_bonding.connection, 2, (const uint8_t)thermoService);
	         }*/
	    	 gecko_cmd_le_connection_set_parameters(evt->data.evt_le_connection_opened.connection, 60, 60, 3, 400);
	         LCD_write("Connected", LCD_ROW_CONNECTION);
	         break;



/*
	     case gecko_evt_system_external_signal_id:
	    	 if (Random==true)
	    	 {
	    	     i2c_init();
	    	     tempcelsius=i2c_driver();
	    	     // The last two parameters are duration and maxevents left as default.
	    	     //gecko_cmd_le_gap_set_advertise_timing(0, 400, 400, 0, 0);

	    	     // Start general advertising and enable connections.
	    	     //gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);
	    	     //i2c_disable();

	    	     LCD_write("Connected", LCD_ROW_CONNECTION);
	    	     snprintf(TEMP, 8 , "%2.2f" , tempcelsius);
	    	     LCD_write(TEMP, LCD_ROW_TEMPVALUE);
	    	 }
	    	 break;
*/

	     case gecko_evt_le_connection_closed_id:
	    	 /* Check if need to boot to dfu mode */
	         if (boot_to_dfu) {
	           /* Enter to DFU OTA mode */
	           gecko_cmd_system_reset(2);
	         } else {
	           /* Restart advertising after client has disconnected */
	           gecko_cmd_system_set_tx_power(0);
	           gecko_cmd_le_gap_set_mode(le_gap_general_discoverable, le_gap_connectable_scannable);
	         }
	         gecko_cmd_le_gap_discover(le_gap_discover_observation);
	         gecko_cmd_le_gap_set_scan_parameters(160,112,0);
	         break;

	     case gecko_evt_sm_bonding_failed_id:
	     	 LCD_write("Bonding Failed", LCD_ROW_ACTION);
	     	 break;

	     case gecko_evt_sm_confirm_bonding_id:
	    	 gecko_cmd_sm_bonding_confirm(evt->data.evt_sm_confirm_bonding.connection, 1);
	    	 break;

		 case gecko_evt_sm_passkey_display_id:
	    	 printf("Passkey display\r\n");
	     	 printf("Enter this passkey on the tablet:\r\n%lu\r\n", evt->data.evt_sm_passkey_display.passkey);
	     	 break;

	     case gecko_evt_sm_confirm_passkey_id:
	         /*	printf("Confirm passkey\r\n");
	         printf("Are you see the same passkey on the tablet: %d (y/n)?\r\n", evt->data.evt_sm_confirm_passkey.passkey);
	         bool read_y_n = true;*/
	         printf("Confirm passkey\r\n");
	         char KEY[20]={0};
	         printf("Are you able to see the same passkey on the tablet: %lu (y/n)?\r\n", evt->data.evt_sm_confirm_passkey.passkey);
	         snprintf(KEY,sizeof(KEY),"%lu",evt->data.evt_sm_confirm_passkey.passkey);
	         LCD_write(KEY,LCD_ROW_PASSKEY);
	         LCD_write("Press PB0", LCD_ROW_ACTION);
	         while(GPIO_PinInGet(gpioPortF,6)!=0);
	         printf("Passkey Confirmed\r\n");
	         LCD_write("Passkey Confirmed", LCD_ROW_ACTION);
	         LCD_write("",LCD_ROW_PASSKEY);
	         gecko_cmd_sm_passkey_confirm(evt->data.evt_sm_confirm_passkey.connection, 1);
	         //gecko_cmd_gatt_discover_primary_services_by_uuid(evt->data.evt_sm_confirm_bonding.connection, 2, (const uint8_t)thermoService);
	         break;

	     case gecko_evt_sm_bonded_id:

	     	 printf("Bonded");
	     	 LCD_write("Bonded", LCD_ROW_ACTION);
	     	 Random = true;
	     	 gecko_cmd_gatt_discover_primary_services_by_uuid(evt->data.evt_sm_bonded.connection, 2, (const uint8_t*)thermoService);
	     	 break;

	     case gecko_evt_gatt_procedure_completed_id:
	    	 if(var==1)
	    	 {
	    		 gecko_cmd_gatt_discover_characteristics_by_uuid(evt->data.evt_gatt_procedure_completed.connection, service, 2, (const uint8_t*)thermoChar);
	    	 }
	    	 if(var==2)
	    	 {
	    		 gecko_cmd_gatt_set_characteristic_notification(evt->data.evt_gatt_procedure_completed.connection, character, 2);
	    	 }
	    	 break;

	     case gecko_evt_gatt_service_id:
	     	 service= evt->data.evt_gatt_service.service;
	     	 var=1;
	     	 break;

	     case gecko_evt_gatt_characteristic_id:
	     	 character= evt->data.evt_gatt_characteristic.characteristic;
	     	 LCD_write("Characteristic", LCD_ROW_CLIENTADDR);
	     	 var=2;
	     	 break;

	     case gecko_evt_gatt_characteristic_value_id:
	     	  gecko_cmd_gatt_send_characteristic_confirmation(evt->data.evt_gatt_characteristic_value.connection);
			  uint8_t * STRI= &evt->data.evt_gatt_characteristic_value.value.data[0] ;
	     	  memcpy(Node, STRI, 5);
			  uint32_t Node2= *((uint32_t *) &Node[1]);
			  float TempDis = (float) UINT32_TO_FLT(Node2);
			  char fire[20]={};
			  snprintf(fire, 20, "%2.2f", TempDis);
			  LCD_write(fire, LCD_ROW_TEMPVALUE);
			  break;


/*	     case gecko_evt_le_gap_scan_response_id:
	     	 memmove(scanned_addr,evt->data.evt_le_gap_scan_response.address.addr,6);
	     	 //Check whether the scan response is from the desired address
	     	 if (memcmp(node1_addr,evt->data.evt_le_gap_scan_response.address.addr,6)==0)
	     	 {
	     	 	 struct gecko_msg_le_gap_open_rsp_t *pResp= gecko_cmd_le_gap_open(evt->data.evt_le_gap_scan_response.address, evt->data.evt_le_gap_scan_response.address_type);
	     	 	 evt->data.evt_sm_confirm_bonding.connection= pResp->connection;
	     		 gecko_cmd_le_gap_end_procedure();
	     		 scanned_node= NODE1;
	     	  }
	     	 else if (memcmp(node2_addr,evt->data.evt_le_gap_scan_response.address.addr,6)==0)
	     	 {
	     		  struct gecko_msg_le_gap_open_rsp_t *pResp= gecko_cmd_le_gap_open(evt->data.evt_le_gap_scan_response.address, evt->data.evt_le_gap_scan_response.address_type);
	     		  evt->data.evt_sm_confirm_bonding.connection= pResp->connection;
	     		  gecko_cmd_le_gap_end_procedure();
	     		  scanned_node= NODE2;
	     	  }
	     	  else
	     		  scanned_node= NONE;

	     	 break;

	     case gecko_evt_gatt_service_id:
	     	 service= evt->data.evt_gatt_service.service;
	     	 if (memcmp((const uint8_t)thermoService, evt->data.evt_gatt_service.uuid.data, 2)==0)
	     	 {
	     	     uuidlen= 2;
	     	     memmove(serviceuuid,(const uint8_t)thermoService,uuidlen);
	     	     memmove(characuuid,characuuid_heartrate,uuidlen);
	     	  }
	     	  break;

	     case gecko_evt_gatt_characteristic_id:
	     	 if (memcmp(characuuid_heartrate,evt->data.evt_gatt_characteristic.uuid.data,2)==0)
	     	 {
	     	     characteristic= evt->data.evt_gatt_characteristic.characteristic;
	     	  }
	     	  break;

	     case gecko_evt_gatt_characteristic_value_id:
	     	 characteristic= evt->data.evt_gatt_characteristic_value.characteristic;
	     	 if (characteristic==CHARACTERISTIC_HEARTRATE)
	     	 {
	     	     data[0]= evt->data.evt_gatt_characteristic_value.value.data[1];
	     	  }
	     	  break;*/
	         /* Events related to OTA upgrading
	          ----------------------------------------------------------------------------- */


	       /* Check if the user-type OTA Control Characteristic was written.
	        * If ota_control was written, boot the device into Device Firmware Upgrade (DFU) mode. */
	     case gecko_evt_gatt_server_user_write_request_id:

	         if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_control) {
	           /* Set flag to enter to OTA mode */
	           boot_to_dfu = 1;
	           /* Send response to Write Request */
	           gecko_cmd_gatt_server_send_user_write_response(
	             evt->data.evt_gatt_server_user_write_request.connection,
	             gattdb_ota_control,
	             bg_err_success);
	           /* Close connection to enter to DFU OTA mode */
	           gecko_cmd_le_connection_close(evt->data.evt_gatt_server_user_write_request.connection);
	         }
	         break;

	     /* This event is generated when a connected client has either
	      * sent a confirmation upon a successful reception of the indication. */

	     default:
	         break;
	     }
  }
}
