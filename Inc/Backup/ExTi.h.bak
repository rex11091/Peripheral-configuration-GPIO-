/*
 * ExTi.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef EXTI_H_
#define EXTI_H_


#include <stdint.h>


#define EXTI_BASE_ADDR		0x40013C00
#define ExTi				((ExTiReg *)(EXTI_BASE_ADDR))


typedef struct ExTiReg ExTiReg;
struct ExTiReg {
	volatile uint32_t IMR;				// Interrupt mask register
	volatile uint32_t EMR;				// Event mask register
	volatile uint32_t RTSR;				// Rising trigger selection register
	volatile uint32_t FTSR;				// Falling trigger selection register
	volatile uint32_t SWIER;			// Software interrupt event register
	volatile uint32_t PR;				// Pending register
};

#define InterruptDisable(bit)			(ExTi->IMR &= ~(1<<bit) )
#define InterruptEnable(bit)			(ExTi->IMR |= (1<<bit) )
#define EventEnable(bit)				(ExTi->EMR |= (1<<bit) )
#define EventDisable(bit)				(ExTi->EMR &= ~(1<<bit) )
#define RTSRDisabled(bit)				(ExTi->RTSR &= ~(1<<bit) )
#define RTSREnabled(bit)				(ExTi->RTSR |= (1<<bit) )
#define FTSRDisabled(bit)				(ExTi->FTSR &= ~(1<<bit) )
#define FTSREnabled(bit)				(ExTi->FTSR |= (1<<bit) )
#define SWIEREnabled(bit)				(ExTi->SWIER |= (bit))
#define PRClear()						(ExTi->PR = 1)
#define PRread()						(ExTi->PR )


#endif /* EXTI_H_ */
