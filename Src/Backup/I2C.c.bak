/*
 * I2C.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user
 */



#include "I2C.h"
#include "Gpio.h"

void initI2C(){

	enabelI2C(I2C1_DEV);
	enabelI2C(I2C2_DEV);
	//conf master
	gpioConfig(GpioB,7, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioB,7,AF4);
	gpioConfig(GpioB,8, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioB,8,AF4);
	//I2c->CR1 &= ~(1<<15);
	//I2c->CR1 |= (1<<15);
	MasterMode();


	//conf slave
	gpioConfig(GpioF,0, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioF,0,AF4);
	gpioConfig(GpioF,1, GPIO_MODE_AF, GPIO_OPEN_DRAIN, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioF,1,AF4);


}

void MasterMode(){
	MasterConfClockControl();
	MasterConfControlRegister();
}
void MasterConfClockControl(){
	I2c->CR2 |= 8; // 8Mhz of SCL Frequency
	I2c->CCR &= ~(1<<15);	// SM mode
	//I2c->CCR |= (1<<15);
	I2c->CCR &= ~(1<<14); //for fast mode duty
	//I2c->CCR |= (1<<14);
	I2c->CCR |= 80;
	I2c->TRISE |=9;
}
void MasterConfControlRegister(){
	I2c->CR1 &= ~(1);
	I2c->CR1 |= 1;
	I2c->CR1 &= ~(1<<8); //start bit
	I2c->CR1 |= (1<<8);
}



void testI2C(){
	initI2C();
	haltI2C1WhenDebugging();
	haltI2C2WhenDebugging();
}
