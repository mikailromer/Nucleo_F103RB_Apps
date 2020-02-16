/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#define SYSCLOCK_FREQ 8000000
#include "stm32f1xx.h"
#include "stm32f1xx_nucleo.h"
#include "stm32_assert.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"


void clock_setup()
{
	// Set AHB, APB1, APB2 clock prescalers.
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	// Set HSI as system clock.
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
	// Wait, until HSI is set as clock source
	while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_HSI);
	// Enable HSI.
	LL_RCC_HSI_Enable();
	// Wait for HSI enabling.
	while(LL_RCC_HSI_IsReady()!= 1);
	// Set 1ms time base for SysTick.
	LL_Init1msTick(SYSCLOCK_FREQ);
	// Set SysTick clock source.
	LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
	// Set 8 MHz as system clock's frequency.
	LL_SetSystemCoreClock(SYSCLOCK_FREQ);
}

void uart_setup();

int main(void)
{
	// Set FLASH latency cycle
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
	if(LL_FLASH_GetLatency()!= 0)
	{
		printf("ERROR: FLASH Latency set has failed!!!\n");
	}

	clock_setup();

	while(1)
	{

	}
	return 0;
}

void uart_setup()
{

}
