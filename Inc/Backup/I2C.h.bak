/*
 * I2C.h
 *
 *  Created on: Nov 28, 2017
 *      Author: user
 */

#ifndef I2C_H_
#define I2C_H_

#include "DbgMcu.h"
#include <stdint.h>

#define I2C_BASE_ADDR		0x40005400
#define I2c 				((I2cReg *)(I2C_BASE_ADDR))


typedef struct I2cReg I2cReg;
struct I2cReg{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
};

#define I2C1_DEV			21
#define I2C2_DEV			22
#define I2C3_DEV			23



void MasterMode();
void MasterConfClockControl();
void MasterConfControlRegister();

#endif /* I2C_H_ */
