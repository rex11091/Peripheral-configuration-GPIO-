/*
 * timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */
#include "timer.h"
#include "Rcc.h"
#include "Gpio.h"

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

/*
 * -----------Output Compare mode-------------------------------------------
Configure the Timer8 input capture and output compare as follows:

1. Un-reset and clock Timer 8.

2. Timer8 Output Compare Channel 1 on PC6.

3. Set OC1 pin as active high polarity (in CCER register).

4. Enable OC1 pin to generate an output (CC1E in CCER register).

5. No auto-reload preload of the Output Compare Channel 1 (CCPC in CR2 register).

6. Timer8 Input Capture Channels 3 and 4.

7. Channel3 as input capture direct mode and channel 4 as indirect mode on PC8

(Note: TI3 is mapped on PC8. So choose this mode when configuring IC3 and IC4 on CCMR2 register.)

8. Channel3 captures on rising edge and channel4 captures on falling edge. (No filtering on the input signal.)

9. Configure APB2 to 90MHz (using CubeMX32)

10. Prescale the timer clock frequency by 2

11. Use up-counting mode

12. Enable MOE bit in BDTR register (otherwise the timer Capture/Compare will not work)
 * */
void timer8setCCR1value(){

	enableTimer8();
	toggleOutCompareChannel1();
	Timer8->TIMx_ARR = 125;
	Timer8->TIMx_CCR1 = 11;
	Timer8->TIMx_PSC = 1;
	Timer8->TIMx_SMCR &= ~(7);
	Timer8->TIMx_CR1 |= 0x01;
	//while(!(Timer8->TIMx_SR & CC1Flag)){
	//Timer8->TIMx_CCR1 = 114;
	//Timer8->TIMx_ARR = 125;
	//}

}

void toggleOutCompareChannel1(){
	Timer8->TIMx_CCMR1 &= ~(7<<4);
	Timer8->TIMx_CCMR1 |= TOGGLE;
}




void ConfigureOutputCompare()
{
	Timer8->TIMx_CCER = OUTPUT_ACTIVEHIGH | OUTPUT_ON;
	Timer8->TIMx_CR2 = ARPE_DISABLE;	//No-Auto reload preload
	Timer8->TIMx_BDTR = MOEEnable;

}

void forceOutCompareChannel1High()
{
	Timer8->TIMx_CCMR1 &= ~(7<<4);
	Timer8->TIMx_CCMR1 |= FACTIVE;
}

void forceOutCompareChannel1Low()
{
	Timer8->TIMx_CCMR1 &= ~(7<<4);
	Timer8->TIMx_CCMR1 |= FINACTIVE;
}


void toggleOutCompareChannel1WithForce(){
	forceOutCompareChannel1High();
	forceOutCompareChannel1Low();
}




void initTimer8Channel1(){
	//configure timer8 channel 1 pin (PC6) --enable PORTC , set pin as AltFunc3 out-pp
	gpioConfig(GpioC,6, GPIO_MODE_AF, GPIO_PUSH_PULL, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioC,6,AF3);

}

void initTimer8Channel3(){
	//configure timer8 channel 3 pin (PC8) --enable PORTC , set pin as AltFunc3 in-
	gpioConfig(GpioC,8, GPIO_MODE_AF, GPIO_PUSH_PULL, GPIO_NO_PULL,GPIO_HI_SPEED );
	gpioConfALTFunc(GpioC,8,AF3);

}
