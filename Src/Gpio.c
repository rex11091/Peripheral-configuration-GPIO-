/*
 * Gpio.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#include "GPIO.h"

void gpioConfig(GpioReg *gpio,int pin , int Mode , int outdriveType , int pullType , int Speed){
	gpio->mode &= ~(3<<(pin * 2));			//Clear pin mode to 0 first
	gpio->mode |= Mode <<(pin * 2);			//Set the pin mode

	gpio->outSpeed &= ~(3<<(pin *2));			//Clear pin speed to 0 first
	gpio->outSpeed |= Speed << (pin * 2);		//Set the pin speed

	gpio->pullType &= ~(3<<(pin *2));			//Clear pin pulltype to 0 first
	gpio->pullType |= pullType << (pin * 2);	//Set the pin pulltype

	gpio->outType &= ~(1<<pin);				//Clear pin outdriveType to 0 first
	gpio->outType |= outdriveType << pin;		//Set the pin outdriveType
}

void gpioWrite(GpioReg *gpio,int pin , int state){
	if(state == 1){
	gpio->outData |= 1 << pin;
}	else{
	gpio->outData &= ~(1<<pin);
}
}

int gpioRead(GpioReg *gpio,int pin ){
	return gpio->inData & (1 << pin);

}


void LOCKPIN(GpioReg *gpio ,int pinNum){
   volatile  int state;
	gpio->lock = (1 << 16) | (1 << pinNum);
	gpio->lock = (0 << 16) | (1 << pinNum);
	gpio->lock = (1 << 16) | (1 << pinNum);
	state = gpio->lock;
	state = gpio->lock;

}

void gpioConfALTFunc(GpioReg *gpio,int pin , int AltFunction)
{
	if(pin>8)
	{
		gpio->altFuncHi &= ~(0xf <<(pin-8) * 4);
		gpio->altFuncHi	|= (AltFunction << (pin-8) *4);
	}
	else
	{
		gpio->altFuncLow &= ~(0xf <<pin * 4);
		gpio->altFuncLow |= (AltFunction << pin*4);
	}
}

