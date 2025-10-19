/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	5	NOV	2023					*/
/************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_privet.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if		RCC_CLOCK_TYPE == RCC_HSE_CRISAL
		RCC_CR 		= 0x00010000;	/*Enable HSE with no bypass*/
		RCC_CFGR	= 0x00000001;

	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR 		= 0x00050000;	/*Enable HSE with bypass*/
		RCC_CFGR	= 0x00000001;

	#elif	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR 		= 0x00000081;	/*Enable HSI , Trimming = 0*/
		RCC_CFGR	= 0x00000000;

	#elif	RCC_CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif

	#else 
		#error("YOu choosed wrong clock type")
	#endif
}



void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHP  :	SET_BIT(RCC_AHBENR,copy_u8PerId);	break;
			case RCC_APB1 :	SET_BIT(RCC_APB1ENR,copy_u8PerId);	break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,copy_u8PerId);	break;
		}
	}
	else
	{
		/*Return Error*/
	}
}

void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHP  :	CLR_BIT(RCC_AHBENR,copy_u8PerId);	break;
			case RCC_APB1 :	CLR_BIT(RCC_APB1ENR,copy_u8PerId);	break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,copy_u8PerId);	break;
		}
	}
	else
	{
		/*Return Error*/
	}
}
