/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include"Gpio.h"



void gpioConfig(GpioReg *gpio, int pin, int mode, int outDriveType, int pullType, int speed){
	gpio->mode &= ~(3 << (pin * 2));					//clear pin mode to zero first
	gpio->mode |= mode << (pin * 2);					//set pin mode


	gpio->outSpeed &= ~(3 << (pin * 2));					//clear pin speed to zero first
	gpio->outSpeed |= speed << (pin * 2);					// set pin speed

	gpio->pullType &= ~(3 << (pin * 2));					//clear pin pull type to zero first
	gpio->pullType |= pullType << (pin * 2);			 	// set pin pull type

	gpio->outType &= ~(1 << pin);							//clear pin outDriveType to zero first
	gpio->outType |= (outDriveType << pin);				// set pin outDriveType
}

void gpioWrite(GpioReg *gpio,int pin, int state){
	if(state ==1){
		gpio->outData |= (1<< pin);
	}else{
		gpio->outData &= ~(1 << pin);
	}
}

int gpioRead(GpioReg *gpio,int pin){
	return gpio->inData & (1 << pin);
}
