/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	30	NOV	2023					*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_privet.h"

#include "GPIO_interface.h"

void AFIO_VidSetEXTIConfiguration( u8 copy_u8EXTI_Line , u8 copy_u8PortMap )
{
	u8 Local_u8RegIndex = 0;

	if( copy_u8EXTI_Line <= 3 ){
		Local_u8RegIndex = 0 ;
	}
	else if( copy_u8EXTI_Line <= 7 ){
		Local_u8RegIndex   = 1 ;
		copy_u8EXTI_Line -= 4 ;
	}
	else if( copy_u8EXTI_Line <= 11 ){
		Local_u8RegIndex   = 2 ;
		copy_u8EXTI_Line -= 8 ;
	}
	else if( copy_u8EXTI_Line <= 15 ){
		Local_u8RegIndex   = 3 ;
		copy_u8EXTI_Line -= 12 ;
	}

	AFIO->EXTICRx[Local_u8RegIndex] &= ~ ( ( 0b1111 )    << ( copy_u8EXTI_Line * 4 ));// R M W
	AFIO->EXTICRx[Local_u8RegIndex] |= ( copy_u8PortMap ) << ( copy_u8EXTI_Line * 4 );
}

