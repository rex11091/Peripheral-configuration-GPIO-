/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef RCC_H_
#define RCC_H_

#include"stdint.h"

#define RCC_BASE_ADDR		0x40023800
#define RCC_AHB1RST_OFF		0x10
#define RCC_AHB1EN_OFF		0x30
#define Rcc					((RccReg *)(RCC_BASE_ADDR))

typedef struct RccReg RccReg;
struct RccReg {
	volatile uint32_t CR;			//0h
	volatile uint32_t PLLCFGR;			//8h
	volatile uint32_t CFGR;			//0h
	volatile uint32_t CIR;			//4h
	volatile uint32_t AHB1RSTR;			//8h
	volatile uint32_t AHB2RSTR;			//8h
	volatile uint32_t AHB3RSTR;			//0h
	volatile uint32_t Reserved1;
	volatile uint32_t APB1RSTR;			//4h
	volatile uint32_t APB2RSTR;	//8h
	volatile uint32_t Reserved2[2];
	volatile uint32_t AHB1ENR;			//8h
	volatile uint32_t AHB2ENR;			//0h
	volatile uint32_t Reserved3;
	volatile uint32_t AHB3ENR;			//4h
	volatile uint32_t APB1ENR;			//8h
	volatile uint32_t APB2ENR;//8h
	volatile uint32_t Reserved4[2];
	volatile uint32_t AHB1LPENR;			//0h
	volatile uint32_t AHB2LPENR;			//4h
	volatile uint32_t AHB3LPENR;//8h
	volatile uint32_t Reserved5;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t Reserved6[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t Reserved7[2];
	volatile uint32_t SSCGR ;
	volatile uint32_t PLLI2SCFGR;

};
//Export variable to other modules
extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAhb1En;

void enableGpioA(void);
void enableGpioB(void);
void enableGpioG(void);
void enableGpioF(void);
void enableRng(void);
void enableTimer8(void);
void enabelI2C(int number);

#define MCO_HSR_SRC				0
#define MCO_LSE_SRC				1
#define MCO_HSE_SRC				2
#define MCO_PLL_SRC				3

#define MCO_No_Division			0
#define MCO_Division_2			4
#define MCO_Division_3			5
#define MCO_Division_4			6
#define MCO_Division_5			7

#define	MCO1Sel(x)				(Rcc->CFGR=(((Rcc->CFGR & ~(3<<21))|(x<<21))))
#define	MCOPrescale(x)			(Rcc->CFGR=(((Rcc->CFGR & ~(7<<24))|(x<<24))))




																					\


#endif /* RCC_H_ */

