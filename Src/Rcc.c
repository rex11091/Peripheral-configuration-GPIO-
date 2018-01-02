/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Rex
 */
#include"Rcc.h"

uint32_t *rccAhb1Rst= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);


void enableGpioA(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~1;
	//Start clock of GPIOG
	*rccAhb1En |= 1;
}

void enableGpioB(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 1);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 1;
}

void enableGpioC(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 2);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 2;
}


void enableGpioG(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 6);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 6;
}
void enableGpioF(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 7);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 7;
}

void enableRng(void){
	//unreset
	Rcc->AHB2RSTR &= ~(1<<6);
	//start clock
	Rcc->AHB2ENR |= 1<<6;
}

void enableTimer8(void){
	//unreset
	Rcc->APB2RSTR &= ~(1<<1);
	//enable timer8
	Rcc->APB2ENR |= 1<<1;
}

void enabelI2C(int number){
	//unreset
	Rcc->APB1RSTR &= ~(1<<number);
	//reset
	Rcc->APB1ENR |= (1<<number);

}

void enableUsart1(void){
	//unreset
	Rcc->APB2RSTR &= ~(1<<4);
	//enable timer8
	Rcc->APB2ENR |= 1<<4;
}


/**
 * Enable and clock DMA
 * @parameter dmaNumber is one of the following :
 * 						DMA1_DEV or DMA2_DEV
 *
 */

void enableDMA(int dmaNumber){
	//Unreset USART1
	Rcc->AHB1RSTR &= ~(1 <<(21 + dmaNumber));
	//Start clock of USART1
	Rcc->AHB1ENR |= 1 << (21 + dmaNumber);
}

void enableADC1(void){
	//unreset
	Rcc->APB2RSTR &= ~(1<<8);
	//enable timer8
	Rcc->APB2ENR |= 1<<8;
}

