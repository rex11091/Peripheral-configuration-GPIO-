/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Rng.h"
#include "USART.h"
#include "timer.h"
#include "systick.h"
#include "NVic.h"
#include "DbgMcu.h"
#include "flash.h"
#include "I2c.h"
#include "exti.h"
#include <stdio.h>
#include <string.h>

/* USER CODE BEGIN Includes */
#define greenLedPin		13
#define redLedPin		14
#define blueButtonPin	0
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
extern void initialise_monitor_handles(void);
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
	initialise_monitor_handles();
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  printf("Hello, world!\n");
  //gpio
  enableRng();
  enableGpioA();
  enableGpioG();
  enableGpioB();
  enableGpioF();
  gpioConfig(GpioA,blueButtonPin, GPIO_MODE_IN, 0, GPIO_NO_PULL, 0);
  gpioConfig(GpioG,redLedPin, GPIO_MODE_OUT, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_HI_SPEED);
  gpioConfig(GpioG,greenLedPin, GPIO_MODE_OUT, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_HI_SPEED);
  gpioConfig(GpioA,8, GPIO_MODE_AF, GPIO_PUSH_PULL, GPIO_NO_PULL,GPIO_HI_SPEED );
  gpioConfALTFunc(GpioA,8,AF8);
  MCO1Sel(MCO_HSE_SRC);
  MCOPrescale(MCO_Division_5);






  //enable I2C1_Event interrupt
  //nvicEnableIrq(31);
  //nvicSetPriority(31,8);	//set this priority of event interrupt to 8
  //disable I2C1_Event interrupt
  //nvicDisableIrq(31);

  //sysTickSetReload(11250000);
  //sysTickIntrDisable();
  //sysTickSetReload(11250000);
  //sysTickPrescaledSpeed();
  //sysTickClrCounter();

  //sysTickIntrEnable();


 // nvicSetPriority(80,4);
  //nvicEnableIrq(80);

 // set this priority of pin 6 interrupt to 8
 // nvicSetPriority(6,9);
  nvicEnableIrq(6);
  nvicSetPriority(6,9);
 // sysTickDisable();

  InterruptEnable(blueButtonPin);
  FTSREnabled(blueButtonPin);
  //RTSRDisabled(blueButtonPin);

/**
 * ENABLE TIMER
 **/
  enableTimer8();
  oneSecond();
  //haltTimer8WhenDebugging();

//  getRandomNumberByInterrupt();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 // Flash->SR = FLASH_PGSERR;


/*
  if(flashEraseSection(12) == 1){
//	  Flash->CR = 1;
	  flashEnableProgramming(FLASH_BYTE_SIZE);
	  writeMessage ("hello World",(char*)0x08080000);
	  flashdisableProgramming();
	  while(1);
  }else{
	  while(1);
  }
*/
  //flashEraseSection(13);

  /*
   * enableUSART
   * baud rate
   * enable transmitter
   * enable receiver
   * */
  //usart
  gpioConfig(GpioA,9, GPIO_MODE_AF, GPIO_PUSH_PULL, GPIO_PULL_UP,GPIO_HI_SPEED );
  gpioConfALTFunc(GpioA,9,AF7);
  gpioConfig(GpioA,10, GPIO_MODE_AF, GPIO_PUSH_PULL, GPIO_PULL_UP,GPIO_HI_SPEED );
  gpioConfALTFunc(GpioA,10,AF7);
  InitUsart();
  baudRateGeneration(48,13);
  UsartTransmitter();
  UsartReceiver();

/*
  while (!(USART1_SR_TXE)){

  DataWrite(55);
  }



  */
 // int Data = 0x55;
 // int Data1 = 0x77;
  char *Data = (char*)malloc(sizeof(char) * 100);
 // volatile char yo=ReceiveByte();
  while (1)
  {

	 // Data =ReceiveByte();
	  //gpioWrite(GpioG,redLedPin,1);

	  //int x[256]=0;
	  stringReceiveUntilEnter(&Data);
//	  volatile int zs=strcmp("turn on", &Data);
	  if(strcmp("turn on", &Data) == 0){
		  gpioWrite(GpioG,redLedPin,1);
	  	  }
	  else if(strcmp("turn off", &Data) == 0){
	  	 gpioWrite(GpioG,redLedPin,0);
	  	  }
	  else if(strcmp("blinky", &Data) == 0){
		  HAL_Delay(250);
		 // waitTimer();
		  gpioWrite(GpioG,redLedPin,1);
		  HAL_Delay(250);
		  //waitTimer();
		  gpioWrite(GpioG,redLedPin,0);
	  }
	  else{}
	 // DataWrite(Data);
	 // DataWrite(Data1);
	  //Data++;
/*
	  StringDataWrite("h");
	  StringDataWrite("e");
	  StringDataWrite("l");
	  StringDataWrite("l");
	  StringDataWrite("O");
	  StringDataWrite("W");
	  StringDataWrite("O");
	  StringDataWrite("R");
	  StringDataWrite("L");
	  StringDataWrite("D");
	  StringDataWrite("\n");
	 // HAL_Delay(1000);*/

  }

	  //waitTimer();
	  //gpioWrite(GpioG,redLedPin,1);
	 // waitTimer();
	//  gpioWrite(GpioG,redLedPin,0);
	  //__WFI();
	  //gpioWrite(GpioG,redLedPin,1);
	  //__WFI();
	  //gpioWrite(GpioG,redLedPin,0);
	  //HAL_Delay(200);

	  //testI2C();


	 // volatile uint32_t flag =1;

	//  gpioWrite(GpioG,redLedPin,1);
/*
	  while(flag){
		  flag = Tick->CTRL;
		  flag = !(flag & SYSTICK_CNTR_OVERFLOW);
	  }
	  */
	  /*
	  while(!sysTickHasExpired());
	  gpioWrite(GpioG,redLedPin,0);
	  while(!sysTickHasExpired());
	  */
	  /*
	  flag=1;
	  while(flag){
			  flag = Tick->CTRL;
			  flag = !(flag & SYSTICK_CNTR_OVERFLOW);
		  }
*/

	  /*volatile int blueButtonState;

	  gpioWrite(GpioG,redLedPin,1);
	  HAL_Delay(200);
	  gpioWrite(GpioG,redLedPin,0);
 	  HAL_Delay(200);

	  blueButtonState = gpioRead(GpioA,blueButtonPin);
	  if(blueButtonState == 1){
		  gpioWrite(GpioG,greenLedPin,1);
		  HAL_Delay(200);

	  }
	  else{
		  gpioWrite(GpioG,greenLedPin,0);
		  HAL_Delay(200);


	  SET_PIN(GpioG,redLedPin);
	  SET_PIN(GpioG,greenLedPin);
	  HAL_Delay(200);
	  RESET_PIN(GpioG,redLedPin);
	  RESET_PIN(GpioG,greenLedPin);
	  HAL_Delay(200);
	  LOCKPIN(GpioG,greenLedPin);
	  gpioConfig(GpioG,greenLedPin, GPIO_MODE_IN, GPIO_PUSH_PULL, GPIO_NO_PULL, GPIO_HI_SPEED);
	  */
  }
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

 // }
  /* USER CODE END 3 */


/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 90;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void EXTI0_IRQHandler(void){
	static volatile int count = 0;

	PRClear();
	count ++;



}

/* WAIT TIMER GO TO MAXIMUM AND CLEAR THE BIT*/
void waitTimer(void){
	while(!((Timer8->TIMx_SR)&1)){
	}
	Timer8->TIMx_SR = 0;
}



void My_SysTick_Handler(void){
	static int ledState = 0;

	// reading the register to clear the CountFLAG
	volatile int flags = Tick->CTRL ;

	  gpioWrite(GpioG,redLedPin,(ledState = !ledState));
}


void HASH_RNG_IRQHandler(void){
	volatile int rand = Rng->DR;
	volatile int i;
	i++;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
