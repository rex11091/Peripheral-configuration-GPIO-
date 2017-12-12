/*
 * timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */
#include "timer.h"
#include "Rcc.h"

void initTimer8(){
	//enable timer 8 : unreset enable clock
	//......
	enableTimer8();

	// configure the maximum counter value by setting ARR
	Timer8->TIMx_ARR = 0xffff;

	// configure the prescaler by setting  (PSC)
	Timer8->TIMx_PSC = 4;


	// select the clock source (internal clk) ---set SMCR->SMS[2:0]=0
	Timer8->TIMx_SMCR &= ~(7);

	//enable timer 8 CR1->CEN =1
	Timer8->TIMx_CR1 |= 0x01;
}

void oneSecond(){

	enableTimer8();
	Timer8->TIMx_ARR = 5000;
	Timer8->TIMx_PSC = 9000;
	Timer8->TIMx_SMCR &= ~(7);
	Timer8->TIMx_CR1 |= 0x01;

}

void initTimer8Channel1(){
	//configure timer8 channel 1 pin (PC6) --enable PORTC , set pin as AltFunc3 out-pp
	//
	//.....


}

void initTimer8Channel3(){
	//configure timer8 channel 3 pin (PC8) --enable PORTC , set pin as AltFunc3 in-


}
