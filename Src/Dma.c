/*
 * Dma.c
 *
 *  Created on: Dec 26, 2017
 *      Author: user
 */

/*
 * DMA2.stream2.channel4 = USART1.Rx
 * DMA2.stream7.channel4 = USART1.Tx
 *
 * PSIZE = 1 byte
 * MSIZE = 1 byte
 *
 * MBURST = In 8 bits increment
 * FIFO_BURST = 1/2 threshold
 *
 * PINC = no
 * MINC = yes
 *
 * Circular mode = no
 * Double buffer = no
 *
 * priority = high
 *
 * flow controller = DMA
 *
 * Transfer direction = memory to peripheral (Tx)
 * Transfer direction = peripheral to memory (Rx)
 *
 */
#include "Dma.h"
#include "timer.h"

void DmainitForUsart1(char *str){

	dma2->S[7].CR &= ~(StreamEN);
	dma2->S[7].CR = DMAFlowControl | MemoryPointerIn | PSIZE_ONEBYTE | MSIZE_onebyte | HighPrio | channel_4 | MBURST_INCR8;
	//dma2->S[7].CR = DMAFlowControl | MemoryPointerIn | PSIZE_ONEBYTE | MSIZE_onebyte | HighPrio | channel_4 | MBURST_INCR8 | CIRC_EN;
	dma2->S[7].FCR = FIFO_HALF;
	dma2->S[7].CR |= Memory_To_Peripheral;
	dma2->S[7].PAR = &(Usart->DR);
	dma2->S[7].M0AR = str;
	dma2->S[7].NDTR = 7;
	dma2->S[7].CR |= StreamEN;
}
/*
 * *****************************************receive*********************************************************
 * 	dma2->S[2].CR &= ~(StreamEN);
	dma2->S[2].CR = DMAFlowControl | MemoryPointerIn | PSIZE_ONEBYTE | MSIZE_onebyte | HighPrio | channel_4 | MBURST_INCR8;
	dma2->S[2].FCR = FIFO_HALF;
	dma2->S[2].CR |= Peripheral_To_Memory;
	dma2->S[2].PAR = &(Usart->DR);
	dma2->S[2].M0AR = str;
	dma2->S[2].CR |= StreamEN;
 * */

int dmaStreamCheckFlag(DmaReg *dma , int streamNum , int flag){
	int isUpper16 = FALSE;
	volatile uint32_t *intrStatusReg = dma->LISR;
	if(streamNum >= 4){
		intrStatusReg = &dma->HISR;
		streamNum -= 4;
	}
	if(streamNum >= 2){
		streamNum -= 2;
		isUpper16 = TRUE;
	}
	return *intrStatusReg & (flag << (6 * streamNum + 16*isUpper16));
}



void DmainitForTimer8(){
	Timer8->TIMx_CCER = OUTPUT_ACTIVEHIGH | OUTPUT_ON;
	Timer8->TIMx_SMCR &= ~(7);
	Timer8->TIMx_CCMR1 = TOGGLE;
	Timer8->TIMx_ARR	=125;
	Timer8->TIMx_CCR1	=125;
	Timer8->TIMx_CNT	=124;
	Timer8->TIMx_CR1	|=0x1;
	Timer8->TIMx_PSC	=2;
	Timer8->TIMx_DIER	|= (1<<9);

	dma2->S[2].CR &= ~(StreamEN);
	dma2->S[2].CR = DMAFlowControl | MemoryPointerIn | PSIZE_HALFWORD | MSIZE_HALFWORD | VHPrio | channel_7 | MBURST_INCR4 |MINC_EN;
	dma2->S[2].FCR = FIFO_FULL;
	dma2->S[2].CR |= Memory_To_Peripheral;
	//dma2->S[2].PAR = &(Timer8->TIMx_DCR);
	//dma2->S[2].M0AR = data;
	//dma2->S[2].NDTR = 13;

}


void DmasetAddressesAndSize(uint32_t memory , uint32_t peripheralAddr , uint32_t size){
	dma2->S[2].M0AR = memory;
	dma2->S[2].PAR = peripheralAddr;
	dma2->S[2].NDTR = size;
	dma2->S[2].CR |= StreamEN;

}
