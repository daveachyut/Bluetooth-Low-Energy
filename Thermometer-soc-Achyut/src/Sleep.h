/*
 * sleep.h
 *
 *  Created on: Sep 14, 2018
 *      Author: admin
 *
 */
#include "em_emu.h"
#include "em_core.h"

#ifndef SRC_SLEEP_H_
#define SRC_SLEEP_H_

extern int enm;
extern int sleep_enter[5];


typedef enum {
		EM0,
		EM1,
		EM2,
		EM3,
		EM4
	} sleepstate_enum;


void sleep(void);
extern void blockSleepMode(sleepstate_enum minimumMode);
extern void unblockSleepMode(sleepstate_enum minimumMode);


#endif /* SRC_SLEEP_H_ */
