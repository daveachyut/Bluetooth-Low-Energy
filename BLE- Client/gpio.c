//***********************************************************************************
// Include files
//***********************************************************************************
#include "gpio.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************


//***********************************************************************************
// functions
//***********************************************************************************
void gpio_init(){

	//Configure SCL Line
	GPIO_PinModeSet( sclport , sclpin , gpioModeWiredAnd , 1 );

	//Configure SDA Line
	GPIO_PinModeSet( sdaport , sdapin , gpioModeWiredAnd , 1 );

	//Configure Sensor Enable Pin Fo Si7021
	GPIO_PinModeSet( sensorport , sensorpin , gpioModePushPull , 1 );

	//Reset I2C Slave if Required
	for (int i=0; i<9 ; i++)
	{
		GPIO_PinOutClear( sclport , sclpin );
		GPIO_PinOutSet( sdaport , sdapin );
	}


	// Set LED ports to be standard output drive with default off (cleared)

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthStrongAlternateStrong);
//	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, LED1_default);


	GPIO_PinModeSet( gpioPortF , 6 , gpioModeInputPull, 1 );

}
