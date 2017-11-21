/*
 * timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */

#ifndef TIMER_H_
#define TIMER_H_

#include"stdint.h"

#define TIMER8_BASE_ADDR			0x40010400
#define Timer8					((TimerReg *)(TIMER8_BASE_ADDR))



typedef struct TimerReg TimerReg;
struct TimerReg {
	volatile uint32_t TIMx_CR1;			//0h
	volatile uint32_t TIMx_CR2;			//4h
	volatile uint32_t TIMx_SMCR;		//8h
	volatile uint32_t TIMx_DIER;		//Ch
	volatile uint32_t TIMx_SR;			//10h
	volatile uint32_t TIMx_EGR;			//14h
	volatile uint32_t TIMx_CCMR1;		//18h
	volatile uint32_t TIMx_CCMR2;		//1Ch
	volatile uint32_t TIMx_CCER;	    //20h
	volatile uint32_t TIMx_CNT;			//24h
	volatile uint32_t TIMx_PSC;			//28h
	volatile uint32_t TIMx_ARR;			//2ch
	volatile uint32_t TIMx_RCR;			//30h
	volatile uint32_t TIMx_CCR1;		//34h
	volatile uint32_t TIMx_CCR2;		//38h
	volatile uint32_t TIMx_CCR3;		//3Ch
	volatile uint32_t TIMx_CCR4;		//40h
	volatile uint32_t TIMx_BDTR;		//44h
	volatile uint32_t TIMx_DCR;			//48h
	volatile uint32_t TIMx_DMAR;		//4Ch

};

void initTimer8();
void oneSecond();
#endif /* TIMER_H_ */
