/*
 * tempsen.h
 *
 *  Created on: Sep 22, 2018
 *      Author: Achyut
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#define threshold_temp 15 		// Set Threshold Temperature


#endif /* TEMPSENSOR_H_ */

#include "em_i2c.h"
#include "i2cspm.h"
#include "tempsens.h"


void tempsensor (uint16_t temp);
