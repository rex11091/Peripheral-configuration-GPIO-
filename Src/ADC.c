/*
 * ADC.c
 *
 *  Created on: Jan 2, 2018
 *      Author: user
 */

#include "ADC.h"


void initADC(){
	enableADC1();
	adc1->CR2 = ENABLEA_D_CONVERTER | Continuous_conversion_mode;
	adc1->SQR1 = Conv_channel_2;
	adc1->SQR3 = SQRchannel_5 |SQR2channel_13 ;
	adc1->SMPR2 = LoadCycleInChannel_5(CYCLES_480);										//channel 5
	adc1->SMPR1 = LoadCycleInChannel_13(CYCLES_3);									//channel 13
	adc1->CR2 |= START_CONV_RGL_CHANNEL;
}


/*
Write a function to configure the ADC1 to the following configuration:

a) 10-bit resolution

b) Scan mode.

c) Configure the to read channels 1, 6, 10, and 14 in that sequence continuously

d) Data is left aligned

e) Start the conversion

In your answer, you MUST also configure the respective pin of the ADC channels to analog.
*/

void CongfADC(){
	adc1->CR1 = RESOLUTION_10 | ENABLE_SCAN_MODE;
	adc1->SQR1 = Conv_channel_4;
	adc1->SQR3 = SQRchannel_1 |SQRchannel_6|SQRchannel_10|SQRchannel_14 ;
	adc1->CR2 = LEFT_ALIGNMENT;
	adc1->CR2 |= START_CONV_RGL_CHANNEL;
}




/**

* @desc Configure the sampling sequence of ADC channel

* @param adc is the pointer to the registers

* @param channel is an array of channels (the first element is the first in

* sequence)

* @param numOfChan is the number of channels in the array

*/

void adcSetChannelSamplingSequence(ADCReg *adc, int channels[], int numOfChan){
	adc->SQR1 = numOfChan;
	for(int i=0;i<numOfChan;i++){
		if(channels[i]<7){
		adc1->SQR3 |= (channels[i]<<(channels[i])*5);
		}
		else if((channels[i]>6 && channels[i]<13)){
		adc1->SQR2 |= (channels[i]<<(channels[i]-6)*5);
		}
		else if((channels[i]>12)){
		adc1->SQR1 |= (channels[i]<<(channels[i]-12)*5);
		}

	}
	adc1->CR2 |= START_CONV_RGL_CHANNEL;
}

/**

* @desc Configure the sampling time (in cycles) of a ADC channel

* @param adc is the pointer to the registers

* @param channel is the channel to configure

* @param cycles is the sampling time in number of cycles:

* ADC_3_CYCLES

* ADC_15_CYCLES

* ADC_28_CYCLES

* ADC_56_CYCLES

* ADC_84_CYCLES

* ADC_112_CYCLES

* ADC_144_CYCLES

* ADC_480_CYCLES
**/

void adcChannelSamplingTime(ADCReg *adc, int channel, int cycles){
	if(channel < 9){
		adc->SMPR2 = (cycles <<(channel)*3);
	}
	else if(channel > 9){
		adc->SMPR1 = (cycles<<(channel-10)*3);
		}
	adc1->CR2 |= START_CONV_RGL_CHANNEL;
}




