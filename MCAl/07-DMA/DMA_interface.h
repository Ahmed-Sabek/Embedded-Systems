/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  24 January 2024               */
/********************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/*	Transfer Direction	*/
#define MEMORY_TO_MEMORY	 0
#define MEMORY_TO_PERIPHERAL 1
#define PERIPHERAL_TO_MEMORY 2
//////////////////////////////////////////////

/*	Circuler Mode	*/
#define NOT_CIRCULER_MODE	0
#define CIRCULER_MODE	1
//////////////////////////////////////////////

/*	Peripheral Or Memory increment	*/
#define NOT_INC	0
#define INC		1
//////////////////////////////////////////////

/*	Peripheral Or Memory Size	*/
#define BYTE		0
#define	HALF_WORD	1
#define	WORD		2
//////////////////////////////////////////////

/*	Channel priority	*/
#define	VERU_HIGH	0
#define	HIGH		1
#define	MEDIUM		2
#define	LOW			3
//////////////////////////////////////////////

/*	Interrupt source	*/
#define TCI		1
#define HTCI	2
#define TEI		3
//////////////////////////////////////////////



void MDMA_VoidSetConfiguration(u8 Copy_u8Channel,u8 COpy_u8Direction,u8 Copy_u8Mode,u8 Copy_u8PINC,u8 Copy_u8MINC,u8 Copy_u8PerSize,u8 Copy_u8MemSize,u8 Copy_u8Priority,)  ;
void MDMA_VoidEnable(u8 Copy_u8Channel)  ;
void MDMA_VoidDisable(u8 Copy_u8Channel)  ;
void MDMA_VoidInterruptEnable(u8 Copy_u8Channel,u8 Copy_u8INTSource)  ;
void MDMA_VoidSetAddress(u8 Copy_u8Channel,u32 Copy_u32PerAddress,u32 Copy_u32MemAddress,u16 Copy_u16NDT) ;
u8   MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag )  ;
void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) )  ;






#endif