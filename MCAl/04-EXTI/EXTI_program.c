/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	30	NOV	2023					*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_privet.h"


void MEXTI_voidInit(u8 copy_u8EXTILine , u8 copy_u8EXTIMode)
{
	switch(copy_u8EXTIMode)
	{
		case RISING_EDGE:
			SET_BIT(EXTI->RTSR,copy_u8EXTILine)  ;
			break  ;
			
		case FALLING_EDGE:
			SET_BIT(EXTI->FTSR,copy_u8EXTILine)  ;
			break  ;
			
		case ON_CHANGE:
			SET_BIT(EXTI->RTSR,copy_u8EXTILine)  ;
			SET_BIT(EXTI->FTSR,copy_u8EXTILine)  ;
			break  ;
		
	}
	
	CLR_BIT(EXTI->IMR,copy_u8EXTILine)  ;
}


void MEXTI_voidEnable(u8 copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR,copy_u8EXTILine)  ;
}


void MEXTI_voidDisable(u8 copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR,copy_u8EXTILine)  ;
}


void EXTI_VoidSoftWareTrigger( u8 copy_u8EXTILine)
{
	SET_BIT(EXTI->SWIER,copy_u8EXTILine)  ;
}


void EXTI0_VidSetCallBack( void (*ptr) (void) )
{
	EXTI0_CallBack = ptr  ;
}



void EXTI0_IRQHandler(void){

	EXTI0_CallBack()  ;
	SET_BIT( EXTI->PR , 0 )  ;

}