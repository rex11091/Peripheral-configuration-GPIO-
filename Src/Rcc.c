/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Rex
 */
#include"Rcc.h"

uint32_t *rccAhb1Rst= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioG(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 6);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 6;

}
