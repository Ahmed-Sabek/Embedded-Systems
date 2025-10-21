/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	7	NOV	2023					*/
/************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "SevenSEG_interface.h"
#include "SevenSEG_config.h"
#include "SevenSEG_privet.h"

#include "GPIO_interface.h"


void HSSEG_voidSSEGInit(u8 Copy_u8PORT)
{
	MGPIO_voidSetPinDirection(Copy_u8PORT , A , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , B , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , C , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , D , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , E , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , F , GPIO_HIGH)  ;
	MGPIO_voidSetPinDirection(Copy_u8PORT , G , GPIO_HIGH)  ;
}


void HSSEG_voidSSEGWrite(u8 Copy_u8PORT , u8 Copy_u8Number)
{
	#if defined 	COMMON_CATHODE
	u8 Local_arr[10][8]={{1,1,1,1,1,1,0,0} , {0,1,1,0,0,0,0,0} , {1,1,0,1,1,0,1,0} , {1,1,1,1,0,0,1,0} , {0,1,1,0,0,1,1,0} , {1,0,1,1,0,1,1,0} , {1,0,1,1,1,1,1,0} , {1,1,1,0,0,0,0,0} , {1,1,1,1,1,1,1,0} , {1,1,1,1,0,1,1,0}}  ;
	#elif defined	COMMON_ANODE
	u8 Local_arr[10][8]={{0,0,0,0,0,0,1,1} , {1,0,0,1,1,1,1,1} , {0,0,1,0,0,1,0,1} , {0,0,0,0,1,1,0,1} , {1,0,0,1,1,0,0,1} , {0,1,0,0,1,0,0,1} , {0,1,0,0,0,0,0,1} , {0,0,0,1,1,1,1,1} , {0,0,0,0,0,0,0,1} , {0,0,0,0,1,0,0,1}}  ;
	#endif
	
	MGPIO_voidSetPinValue(Copy_u8PORT , A , Local_arr[Copy_u8Number][0])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , B , Local_arr[Copy_u8Number][1])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , C , Local_arr[Copy_u8Number][2])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , D , Local_arr[Copy_u8Number][3])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , E , Local_arr[Copy_u8Number][4])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , F , Local_arr[Copy_u8Number][5])  ;
	MGPIO_voidSetPinValue(Copy_u8PORT , G , Local_arr[Copy_u8Number][6])  ;
}