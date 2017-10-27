/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include"Gpio.h"



void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed){
	GpioG->mode &= ~(3 << (pin * 2));					//clear pin mode to zero first
	GpioG->mode |= mode << (pin * 2);					//set pin mode


	GpioG->outSpeed &= ~(3 << (pin * 2));					//clear pin speed to zero first
	GpioG->outSpeed |= speed << (pin * 2);					// set pin speed

	GpioG->pullType &= ~(3 << (pin * 2));					//clear pin pull type to zero first
	GpioG->pullType |= pullType << (pin * 2);			 	// set pin pull type

	GpioG->outType &= ~(1 << pin);							//clear pin outDriveType to zero first
	GpioG->outType |= (outDriveType << pin);				// set pin outDriveType
}

void gpioGWrite(int pin, int state){
	if(state ==1){
		GpioG->outData |= (1<< pin);
	}else{
		GpioG->outData &= ~(1 << pin);
	}
}

