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


#define Timer8_CCR1					0x40010434

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

//MOE: Main output enable
#define MOEEnable		(1<<15)

// Output Polarity CC1 (active/low)
#define OUTPUT_ACTIVEHIGH		(0<<1)
#define	OUTPUT_ACTIVELOW		(1<<1)
//CC1E: Capture/Compare 1 output enable
#define OUTPUT_Off		0
#define OUTPUT_ON		1

//Bit 7 ARPE: Auto-reload preload enable
#define ARPE_ENABLE		(1<<7)
#define	ARPE_DISABLE	(0<<7)

//CC1S: Capture/Compare 1 selection
#define Selection_output	0

//output compare mode
#define ACTIVE			(1<<4)
#define INACTIVE		(2<<4)
#define TOGGLE			(3<<4)
#define FACTIVE			(5<<4)
#define FINACTIVE		(4<<4)

#define CC1Flag			(1<<1)
void initTimer8();
void oneSecond();


void ConfigureOutputCompare();

void forceOutCompareChannel1High();
void timer8setCCR1value();
void forceOutCompareChannel1Low();
void toggleOutCompareChannel1WithForce();
void toggleOutCompareChannel1();
void initTimer8Channel1();

#endif /* TIMER_H_ */
