/*
 * flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user
 */

#include "flash.h"
#include "stm32f429xx.h"
/*
 * 	stm32f429zi MCU only
 *
 * 	section erase the flash
 * 	input
 *
 *
 * 	return
 * 	 0		fail to erase
 * 	 1		successful
 * */
int flashEraseSection(int sectionNum){
	if(sectionNum > 11)
		sectionNum = sectionNum + 4;
	//unlock through pin register
	Flash->KEYR = 0x45670123;
	Flash->KEYR = 0xCDEF89AB;
	// 1)set the section number
	// 2)set to sector erase
	// 3)start erase
	// 4)check for failure or success
	// 5)return status
	Flash->CR = (sectionNum<<3) | FLASH_SECTOR_ERASE | FLASH_START;
	//Flash->CR = FLASH_CR_MER2 | FLASH_CR_STRT;
	return 1;
}

/**
 * enable flash programming with the started program size
 * input:
 * 		program size is the size when writing into the flash
 * 					FLASH size
 *
 * */

int flashEnableProgramming(int Psize){
	Flash->CR |= FLASH_PG;
	Flash->CR |= (Psize << 8);
	return 1;
}

int flashdisableProgramming(){
	Flash->CR &=~(1);
	return 1;
}

int writeMessage(char *message , char *memoryToWrite){
	strcpy(memoryToWrite,message);
}
