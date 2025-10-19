/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  24 January 2024               */
/********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_privete.h"


void MDMA_VoidSetConfiguration(u8 Copy_u8Channel,u8 COpy_u8Direction,u8 Copy_u8Mode,u8 Copy_u8PINC,u8 Copy_u8MINC,u8 Copy_u8PerSize,u8 Copy_u8MemSize,u8 Copy_u8Priority)
{
	/*	Disable DMA	*/
	CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 0)  ;
	/*	Wait untill DMA disable	*/
	while(GET_BIT(MDMA->Channel[Copy_u8Channel].CCR,0)==1)  ;
	//////////////////////////////////////////////
	
	/*	Transfer direction	*/
	if(COpy_u8Direction ==MEMORY_TO_MEMORY)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 14)  ;
	}
	else if(COpy_u8Direction ==MEMORY_TO_PERIPHERAL)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 4)  ;
	}
	else if(COpy_u8Direction ==PERIPHERAL_TO_MEMORY)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 4)  ;
	}
	//////////////////////////////////////////////
	
	/*	Circuler Mode	*/
	if(Copy_u8Mode == CIRCULER_MODE)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 5)  ;
	}
	else if(Copy_u8Mode == NOT_CIRCULER_MODE)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 5)  ;
	}
	//////////////////////////////////////////////
	
	/*	Peripheral increment	*/
	if(Copy_u8PINC == INC)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 6)  ;
	}
	else if(Copy_u8PINC == NOT_INC)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 6)  ;
	}
	//////////////////////////////////////////////
	
	/*	Memory increment	*/
	if(Copy_u8MINC == INC)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 7)  ;
	}
	else if(Copy_u8MINC == NOT_INC)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 7)  ;
	}
	//////////////////////////////////////////////
	
	/*	Peripheral Size	*/
	if(Copy_u8PerSize == BYTE)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 8)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 9)  ;
	}
	else if(Copy_u8PerSize == HALF_WORD)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 8)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 9)  ;
	}
	else if(Copy_u8PerSize == WORD)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 10)  ;
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 11)  ;
	}
	//////////////////////////////////////////////
	
	/*	Memory Size	*/
	if(Copy_u8MemSize == BYTE)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 10)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 11)  ;
	}
	else if(Copy_u8MemSize == HALF_WORD)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 10)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 11)  ;
	}
	else if(Copy_u8MemSize == WORD)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 10)  ;
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 11)  ;
	}
	//////////////////////////////////////////////
	
	/*	Channel priority	*/
	if(Copy_u8Priority == LOW)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 12)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 13)  ;
	}
	else if(Copy_u8Priority == MEDIUM)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 12)  ;
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 13)  ;
	}
	else if(Copy_u8Priority == HIGH)
	{
		CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 12)  ;
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 13)  ;
	}
	else if(Copy_u8Priority == VERU_HIGH)
	{
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 12)  ;
		SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 13)  ;
	}
	//////////////////////////////////////////////
}


void MDMA_VoidEnable(u8 Copy_u8Channel)
{
	/*	Clear Flages	*/
	Copy_u8Channel *=4  ;
	SET_BIT(MDMA->IFCR , Copy_u8Channel)  ;
	SET_BIT(MDMA->IFCR , (Copy_u8Channel + 1))  ;
	SET_BIT(MDMA->IFCR , (Copy_u8Channel + 2))  ;
	SET_BIT(MDMA->IFCR , (Copy_u8Channel + 3))  ;
	/*	Enable DMA	*/
	SET_BIT(MDMA->Channel[Copy_u8Channel].CCR , 0)  ;
}


void MDMA_VoidDisable(u8 Copy_u8Channel)
{
	/*	Disable DMA	*/
	CLR_BIT(MDMA->Channel[Copy_u8Channel].CCR , 0)  ;
}


void MDMA_VoidInterruptEnable(u8 Copy_u8Channel,u8 Copy_u8INTSource)
{
	SET_BIT(MDMA->Channel[Copy_u8Channel].CCR,Copy_u8INTSource)  ;
}


void MDMA_VoidSetAddress(u8 Copy_u8Channel,u32 Copy_u32PerAddress,u32 Copy_u32MemAddress,u16 Copy_u16NDT)
{
	/*	Write Peripheral Address	*/
	MDMA->Channel[Copy_u8Channel].CPAR = (u32)Copy_u32PerAddress  ;
	/*	Write Memory Address	*/
	MDMA->Channel[Copy_u8Channel].CMAR = (u32)Copy_u32MemAddress  ;
	/*	Write Number Of Data Transfer	*/
	MDMA->Channel[Copy_u8Channel].CNDTR = Copy_u16NDT  ;
}


u8   MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag )  ;
void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) )  ;