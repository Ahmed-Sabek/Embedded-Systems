/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	29	Jan	2023					*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"



void HSTP_VoidSendSync(u8 Copy_u8DataToSend)
{
	s8 Local_s8counter  ;
	u8 Local_u8Bit
	
	MGPIO_voidSetPinDirection(SERIAL_DATA,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(SHIFT_CLOCK,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(SORAGE_CLOCK,OTPUT_SPEED_2MHZ_GPOPP)  ;
	/*	Send Data Serial	*/
	for(Local_s8counter=7 ; Local_s8counter<=0 ; Local_s8counter--)
	{
		/*Send bit by bit to shift REG	*/
		Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_s8counter)  ;
		MGPIO_voidSetPinValue(SERIAL_DATA,Local_u8Bit)  ;
		/*	Shift REG clock	*/
		MGPIO_voidSetPinValue(SHIFT_CLOCK,GPIO_HIGH)  ;
		MSTK_voidSetBusyWait(1)  ;
		MGPIO_voidSetPinValue(SHIFT_CLOCK,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(1)  ;
		
	}
	
	/*	Send pulse to storage REG	*/
	MGPIO_voidSetPinValue(SORAGE_CLOCK,GPIO_HIGH)  ;
	MSTK_voidSetBusyWait(1)  ;
	MGPIO_voidSetPinValue(SORAGE_CLOCK,GPIO_LOW)  ;
	MSTK_voidSetBusyWait(1)  ;
}