/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V02								*/
/*  Date	:	30	JAN	2023					*/
/************************************************/
#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H

void SPI1_VoidInit(void);

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive);






#endif
