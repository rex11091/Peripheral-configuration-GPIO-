/*
 * USART.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */
/*
 * 	Usart.c
 *
 * The connection between UART1 Pins on STM32F429ZIT6 abd the USB-to-serial
 * (CH340) are as follow
 *
 *
 * 	STM32F429ZIT6	|   CH340
 * 	Name	  Pin	|	Name
 * -----------------------------
 * 	TX		 PA9	|	RX
 *	RX		 PA10	|	TX
 *-------------------------------
 */



#include "USART.h"
#include "Rcc.h"
#include <stdio.h>
#include <stdarg.h>

//------------------------------------------transmitter--------------------------------------------------------------------
//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
//2. Program the M bit in USART_CR1 to define the word length.
//3. Program the number of stop bits in USART_CR2
//4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
//5. Select the desired baud rate using the USART_BRR register.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission
//7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this for each data to be transmitted in case of single buffer
//8. After writing the last data into the USART_DR register, wait until TC=1. This indicates that the transmission of the last frame is complete.
//   This is required for instance when the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.



/*
 * ------------------------------------------receiver--------------------------------------------------------------
 * 1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
 * 2. Program the M bit in USART_CR1 to define the word length.
 * 3. Program the number of stop bits in USART_CR2.
 * 4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take place.
 *      Configure the DMA register as explained in multibuffer communication. STEP 3
 * 5. Select the desired baud rate using the baud rate register USART_BRR
 * 6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a start bit.
 * */

/*
 * 1. 115,200bps
 * 2. Odd parity
 * 3. 9-bit data
 * 4. Oversampling by 16
 * 5. 2 stop bit
 * 6. Configure APB2 to run at 90MHz
 * */
void InitUsart(){
	enableUsart1();
	Usart->CR1 = ENABLEUSART | M9databit |OVERSAMPLING_16 |ENABLEPCE|ODDPARITY;
	Usart->CR2 |= STOPBIT_2;			// stopbit
}

void baudRateGeneration (int DIV_Mantissa,int DIV_Fraction){
	Usart->BRR = DIV_Fraction;						//set brr->DIV_MAntissa
	Usart->BRR |= (DIV_Mantissa<<4);				//set brr->DIV_Fraction
}

void UsartTransmitter(){
	Usart->CR1 |= ENABLETRANSMITTER;	// enable transmitter
}

void StringDataWrite(char *data){
	Usart->DR =*data;
	while(!(Usart->SR & USART1_SR_TXE));
}

void UsartReceiver(){
	Usart->CR1 |= ENABLERECEIVER;	//enable receiver
}

int DataWrite(uint32_t data){
	Usart->DR = data ;
	while(!(Usart->SR & USART1_SR_TXE));
	//return 1;
}

uint8_t ReceiveByte(){
	while(!(Usart->SR & USART1_SR_RXNE));
	return (uint8_t)Usart->DR;
}

void stringReceiveUntilEnter(char *Data){
	*(Data) = ReceiveByte();
	while(*(Data)!=0xA){
		Data++;
		*(Data) = ReceiveByte();
	}
	*Data=0;
}

//serialPrint
void serialPrint(char *format,...){
	va_list	args;
	char* buffer;
	int i,length;

	va_start(args,format);

	length = vsnprintf(buffer,0,format,args);
	buffer = malloc(length + 1);
	vsnprintf(buffer,length+1,format,args);

	while(i<length){
		StringDataWrite(&(buffer[i]));
		i++;
	}
/*
	for(i = 0 ; i< length ; i++){
		// Send the character byte-by-byte
		StringDataWrite(buffer[i]);
	}
	*/
	free(buffer);
}



