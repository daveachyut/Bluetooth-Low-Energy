/*
 * letimer.c
 *
 *  Created on: 15-Sep-2018
 *      Author: Achyut
 */
#include "em_letimer.h"
#include "letimer.h"
#include "gpio.h"
#include "em_core.h"
#include "cmu.h"
#include "em_cmu.h"
#include "math.h"
#include "i2c.h"
#include "main.h"
#include "sleep.h"
#include "tempsen.h"
#include "native_gecko.h"
#include "gatt_db.h"


float f, p, c;//Define freq, per, count
int n;//exponent n.
#define p 3;//<----------Define Period, i.e. Total Period

/* Set configurations for LETIMER 0 */
void LETimer0Setup()
{
	//blockSleepMode(4);
	LETIMER_IntClear(LETIMER0,LETIMER_IFC_COMP0);
	const LETIMER_Init_TypeDef letimerInit =
	{
		.enable         = false,                   /* Start counting when init completed. */
		.debugRun       = false,                  /* Counter shall not keep running during debug halt. */
		//.rtcComp0Enable = false,                  /* Don't start counting on RTC COMP0 match. */
		//.rtcComp1Enable = false,                  /* Don't start counting on RTC COMP1 match. */
		.comp0Top       = true,                   /* Load COMP0 register into CNT when counter underflows. COMP0 is used as TOP */
		.bufTop         = false,                  /* Don't load COMP1 into COMP0 when REP0 reaches 0. */
		.out0Pol        = 0,                      /* Idle value for output 0. */
		.out1Pol        = 0,                      /* Idle value for output 1. */
		.ufoa0          = letimerUFOANone,         /* no PWM output on output 0 */
		.ufoa1          = letimerUFOANone,       /* no Pulse output on output 1*/
		.repMode        = letimerRepeatFree       /* Count until stopped */
	};
	f=1000;//Frequency for EnergyMode=3
	c=f*p;//Count1 for COMP0
	n=(c/65536);//Value of Exponent n
	c=(c/pow(2,n));
	/* Initialize LETIMER */
	LETIMER_Init(LETIMER0, &letimerInit);

	//CMU->LFAPRESC0=CMU_LFAPRESC0_
	LETIMER_CompareSet(LETIMER0, 0, c);
	CMU_ClockDivSet(cmuClock_LETIMER0, pow(2, n));
	LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP0);//BlockSleepMode
	NVIC_EnableIRQ(LETIMER0_IRQn);

	LETIMER_Enable(LETIMER0, true);
}

void LETIMER0_IRQHandler(void)
{
	CORE_ATOMIC_IRQ_DISABLE();
	//blockSleepMode(2);
	int flag;
	flag=LETIMER_IntGet(LETIMER0);
	gecko_external_signal(LETIMER_IF_COMP0);
	LETIMER_IntClear(LETIMER0,flag);
	CORE_ATOMIC_IRQ_ENABLE();
}
