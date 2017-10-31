/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

#define NVIC_BASE_ADDR		0xE000E100
#define Nvic				((NvicReg *)(NVIC_BASE_ADDR))

typedef struct NvicReg NvicReg;
struct NvicReg{
	volatile uint32_t ISER[3];				//interrupt Set-enable register		(0h)
	volatile uint32_t reserved[29];
	volatile uint32_t ICER[3];				//interrupt clear-enable register	(80h)
	volatile uint32_t reserved1[29];
	volatile uint32_t ISPR[3];					//interrupt set-pending register	(100h)
	volatile uint32_t reserved2[29];
	volatile uint32_t ICPR[3];					//interrupt clear-pending register	(180h)
	volatile uint32_t reserved3[29];
	volatile uint32_t IABR[3];					//interrupt active bit register	(200h)
	volatile uint32_t reserved4[61];
	volatile uint32_t IPR[21];					//interrupt priority register	(300h)
	volatile uint32_t reserved5[683];
	volatile uint32_t STR;						//software trigger-interrupt register	(e00h)
};

#define nvicEnableIrq(irqNum)					(Nvic->ISER[irqNum>>5] |= (1<< (irqNum &0x1f)))
#define nvicDnableIrq(irqNum)					(Nvic->ICER[irqNum>>5] |= 1<< (irqNum &0x1f))

#define nvicSetPriority(irqNum,priority) 		(Nvic->IPR[irqNum>>2] |= priority<<((irqNum &0x3) *8 +4))

#endif /* NVIC_H_ */
