/*
 * ADC.h
 *
 *  Created on: Jan 2, 2018
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_


#include <stdint.h>
#include"Rcc.h"
#include "common.h"


#define ADC1_BASE_ADDR		0x40012000
#define ADC2_BASE_ADDR		0x40012100
#define ADC3_BASE_ADDR		0x40012200
#define ADC_COMMON_ADDR		0x40012300

#define adc1				((ADCReg *)(ADC1_BASE_ADDR))
#define adc2				((ADCReg *)(ADC2_BASE_ADDR))
#define adc3				((ADCReg *)(ADC3_BASE_ADDR))
#define ADC_COMMON			((ADCCOMMONReg *)(ADC_COMMON_ADDR))


typedef struct ADCReg ADCReg;
struct ADCReg {
	volatile uint32_t SR;			//0h		status
	volatile uint32_t CR1;			//04h		control
	volatile uint32_t CR2;			//08h
	volatile uint32_t SMPR1;		//0ch		sampling file register
	volatile uint32_t SMPR2;		//10h
	volatile uint32_t JOFR1;		//14h		injected channel data offsets
	volatile uint32_t JOFR2;		//18h
	volatile uint32_t JOFR3;		//1ch
	volatile uint32_t JOFR4;		//20h
	volatile uint32_t HTR;			//24h		watchdog Higher threshold register
	volatile uint32_t LTR;			//28h		watchdog lower threshold register
	volatile uint32_t SQR1;			//2ch		regular sequence register
	volatile uint32_t SQR2;			//30h
	volatile uint32_t SQR3;			//34h
	volatile uint32_t JSQR;			//38h		injected sequence register
	volatile uint32_t JDR1;			//3ch		injected data register
	volatile uint32_t JDR2;			//40h
	volatile uint32_t JDR3;			//44h
	volatile uint32_t JDR4;			//48h
	volatile uint32_t DR;			//4ch		regular Data register
};


typedef struct ADCCOMMONReg ADCCOMMONReg;
struct ADCCOMMONReg {
	volatile uint32_t CSR;			//0h		common status register
	volatile uint32_t CCR;			//4h		common control register
	volatile uint32_t CDR;			//8h		common data register
};

//a/d converter on/off  on ADC->CR2
#define ENABLEA_D_CONVERTER			1
#define DISABLEA_D_CONVERTER		0

//Start conversion of regular channels ADC->CR2
#define	START_CONV_RGL_CHANNEL		(1<<30)
#define	RESET_CONV_RGL_CHANNEL		(0<<30)

// Continuous conversion (adc->cr2->cont)
#define Single_conversion_mode 			(0<<1)
#define Continuous_conversion_mode 		(1<<1)


//regular channel sequence length	ADC->SQR

#define Conv_channel_1			(0<<20)
#define Conv_channel_2			(1<<20)
#define Conv_channel_3			(2<<20)
#define Conv_channel_4			(3<<20)
#define Conv_channel_5			(4<<20)


//ADC regular sequence register 3 (ADC_SQR3)

#define SQRchannel_5					5
#define SQR2channel_13					(13<<5)



//SAMPLING TIME in ADC->SPR1
#define LoadCycleInChannel_13(cycle)	(cycle<<9)
#define LoadCycleInChannel_5(cycle)		(cycle<<15)

//cycles
#define CYCLES_3					0
#define CYCLES_15					1
#define CYCLES_28					2
#define CYCLES_56					3
#define CYCLES_84					4
#define CYCLES_112					5
#define CYCLES_144					6
#define CYCLES_480					7


#define RESOLUTION_10				(1<<24)
#define ENABLE_SCAN_MODE			(1<<8)
#define LEFT_ALIGNMENT				(1<<11)
#define SQRchannel_1				(1)
#define SQRchannel_6				(6<<5)
#define SQRchannel_10				(10<<10)
#define SQRchannel_14				(14<<15)



#define ADC_3_CYCLES				0
#define ADC_15_CYCLES				1
#define ADC_28_CYCLES				2
#define ADC_56_CYCLES				3
#define ADC_84_CYCLES				4
#define ADC_112_CYCLES				5
#define ADC_144_CYCLES				6
#define ADC_480_CYCLES				7

void adcSetChannelSamplingSequence(ADCReg *adc, int channels[], int numOfChan);
void adcChannelSamplingTime(ADCReg *adc, int channel, int cycles);

void initADC();

#endif /* ADC_H_ */
