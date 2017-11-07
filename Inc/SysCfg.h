/*
 * SysCfg.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_


#include <stdint.h>


#define SysCfg_BASE_ADDR		0x400013800
#define SysCfg					((SysCfgReg *)(SysCfg_BASE_ADDR))


typedef struct SysCfgReg SysCfgReg;
struct SysCfgReg {
	volatile uint32_t MEMRMP;				// control and status register
	volatile uint32_t PMC;				// reload value register
	volatile uint32_t VAL;				// current value register
	volatile uint32_t CALIB;			// calibration value register
};
#endif /* SYSCFG_H_ */
