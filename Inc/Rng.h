/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#include <stdint.h>
#ifndef RNG_H_
#define RNG_H_

#define RNG_BASE_ADDR 	0x50060800
#define Rng		((RngReg *)(RNG_BASE_ADDR))

typedef struct RngReg RngReg;
struct RngReg{
	volatile uint32_t CR;			//0h
	volatile uint32_t SR;		//4h
	volatile uint32_t DR;		//8h
};
//sr
#define RNG_FAULTY_SEQUENCE			(1<<6)
#define RNG_FAULTY_CLK				(1<<5)
#define RNG_DRDY			1
//CR
#define RNG_RNGEN			(1 << 2)
#define RNG_IE				(1 << 3)


void generateRandomNunber();
int isRandomNumberAvailable();
int isAnyError();
int isFaultyRandomSequence(void);
int getRandomNumber(void);
void getRandomNumberByInterrupt(void);


#endif /* RNG_H_ */

