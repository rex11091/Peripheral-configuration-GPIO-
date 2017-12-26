/*
 * USART.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */

#ifndef USART_H_
#define USART_H_


#include "DbgMcu.h"
#include <stdint.h>

#define USARt1_BASE_ADDR		0x40011000

#define Usart 				((UsartReg *)(USARt1_BASE_ADDR))


typedef struct UsartReg UsartReg;
struct UsartReg{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
};

//parity selection
#define EVENPARITY						(~(1<<9))
#define	ODDPARITY						(1<<9)

//parity control enable
#define	 DISABLEPCE						(~(1<<10))
#define  ENABLEPCE						(1<<10)

//UNABLE USART
#define ENABLEUSART						(1<<13)

//databit
#define M8databit					   	(~(1<<12))
#define M9databit						(1<<12)

//stopbit
#define STOPBIT_1						(~(1<<12))
#define STOPBIT_0_5						(1<<12)
#define STOPBIT_2						(2<<12)
#define STOPBIT_1_5						(3<<12)
//oversampling
#define OVERSAMPLING_16					0
#define OVERSAMPLING_8					1
//enable/disable transmitter
#define ENABLETRANSMITTER				(1<<3)
#define DISABLETRANSMITTER				~(1<<3)
//enable/disable receiver
#define ENABLERECEIVER					(1<<2)
#define DISABLERECEIVER					~(1<<2)

//Cr3 configuration
#define DMATransmitEN					(1<<7)
#define DMATransmitRst					~(1<<7)
#define DMAReceiveEn					(1<<6)

#define USART1_SR_TXE					(1<<7)
#define USART1_SR_TC					(1<<6)
#define USART1_SR_RXNE					(1<<5)

#define uart1EnableDmaTx()		(Usart->CR3 |= DMATransmitEN)
#define uart1EnableDmaRx()		(Usart->CR3 |= DMAReceiveEN)


void InitUsart();
void baudRateGeneration(int DIV_Mantissa,int DIV_Fraction);
void UsartTransmitter();
void UsartReceiver();
int DataWrite(uint32_t data);
void StringDataWrite(char* data);
uint8_t ReceiveByte();
void stringReceiveUntilEnter(char *Data);
void serialPrint(char *format,...);
#endif /* USART_H_ */
