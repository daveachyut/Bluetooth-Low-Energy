/*
 * i2c.h
 *
 *  Created on: Sep 20, 2018
 *      Author: Admin
 */

#include "em_i2c.h"

#ifndef I2C_H_
#define I2C_H_

uint16_t temp;

#endif /* I2C_H_ */

void i2c_init(void);
void i2c_disable (void);
float i2c_driver (void);
