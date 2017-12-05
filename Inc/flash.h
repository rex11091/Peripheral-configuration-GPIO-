/*
 * flash.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "DbgMcu.h"
#include <stdint.h>

#define FLASH_BASE_ADDR		0x40023C00
#define Flash 				((FlashReg *)(FLASH_BASE_ADDR))


typedef struct FlashReg FlashReg;
struct FlashReg{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR; 	// option key register
	volatile uint32_t SR;		// status register
	volatile uint32_t CR;		// control register
	volatile uint32_t OPTCR;	//
	volatile uint32_t OPTCR1;
};


#define	FLASH_BYTE_SIZE					0
#define	FLASH_HALFWORD_SIZE				1
#define	FLASH_WORD_SIZE					2
#define	FLASH_DOUBLEWORD_SIZE			3

#define FLASH_SECTOR_ERASE				 (1<<1)
#define FLASH_START						 (1<<16)
#define FLASH_PGSERR					 (1<<7)
#define FLASH_PG						 (1)


int flashEraseSection(int sectionNum);
int flashEnableProgramming(int Psize);
int flashdisableProgramming();
int writeMessage(char *message , char *memoryToWrite);

#endif /* FLASH_H_ */
