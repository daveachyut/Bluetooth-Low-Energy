//***********************************************************************************
// Include files
//***********************************************************************************
#include "cmu.h"
#include "em_cmu.h"
#include "em_letimer.h"
#include "i2c.h"


//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************
int enm;

//***********************************************************************************
// function prototypes
//***********************************************************************************
void cmu_init()
{
	// Peripheral clocks enabled
	CMU_ClockEnable(cmuClock_GPIO, true);

	CMU_OscillatorEnable(cmuOsc_LFXO,true,true);
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);
	CMU_ClockEnable(cmuClock_LFA,true);

	//CMU_ULFRCOInit(&ulfrcoInit);
	CMU_OscillatorEnable(cmuOsc_ULFRCO,true,true);
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);
	CMU_ClockEnable(cmuClock_LFA,true);
	CMU_ClockEnable(cmuClock_CORELE,true);
	CMU_ClockEnable(cmuClock_LETIMER0,true);
	CMU_ClockEnable(cmuClock_HFPER, true);
	//CLOCK Enable For I2C
	CMU_ClockEnable(cmuClock_I2C0, true);
}
