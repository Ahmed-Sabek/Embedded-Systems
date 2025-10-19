/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	27	NOV	2023					*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber<=31)
	{
		NVIC_ISER0=  (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber -=32;
		NVIC_ISER1=  (1 << copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
}


void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber<=31)
	{
		NVIC_ICER0=  (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber -=32;
		NVIC_ICER1=  (1 << copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
}


void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber<=31)
	{
		NVIC_ISPR0=  (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber -=32;
		NVIC_ISPR1=  (1 << copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
}


void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber<=31)
	{
		NVIC_ICPR0=  (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber -=32;
		NVIC_ICPR1=  (1 << copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
}


u8 MNVIC_u8GetActiveFlage(u8 copy_u8IntNumber)
{
	u8 Local_u8Result;
	
	if(copy_u8IntNumber<=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber<=59)
	{
		copy_u8IntNumber -=32;
		Local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
	
	return Local_u8Result;
}


void MNVIC_voidSetPriority(s8 copy_s8INTID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32GROUP)
{
	u8 Local_u8Priority = copy_u8SubPriority | copy_u8GroupPriority << ( (copy_u32GROUP - 0x05FA0300) / 256 )  ;
	/*	core pripheral	*/
	
	
	
	/*	external pripheral	*/
	if(copy_s8INTID >= 0)
	{
		NVIC_IPR[copy_s8INTID] = Local_u8Priority << 4  ;	/*	Interrupt Priority Register configuration	*/
	}
	
	SCB_AIRCR = copy_u32GROUP  ;	/*	Application Interrupt and Reset Control Register configuration (core prephiral "System Control Block")	*/
}
