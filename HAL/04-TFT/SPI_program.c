/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V02								*/
/*  Date	:	30	JAN	2023					*/
/************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_privete.h"
#include "SPI_config.h"



void SPI1_VoidInit(void)
{
	/*	SPI Mode (Clock phase & Clock polarity Configuration)	*/
	#if		SPI_MODE == MSPI_MODE0
		CLR_BIT(SPI -> CR1	,	0);		CLR_BIT(SPI -> CR1	,	1);
	#elif	SPI_MODE == MSPI_MODE1
		CLR_BIT(SPI -> CR1	,	0);		SET_BIT(SPI -> CR1	,	1);
	#elif	SPI_MODE == MSPI_MODE2
		SET_BIT(SPI -> CR1	,	0);		CLR_BIT(SPI -> CR1	,	1);
	#elif	SPI_MODE == MSPI_MODE3
		SET_BIT(SPI -> CR1	,	0);		SET_BIT(SPI -> CR1	,	1);
	#endif
		
	/*	SPI Master or Slave Select	*/
	#if		SPI_MASTER_SLAVE == MASTER
		SET_BIT(SPI -> CR1	,	2);
	#elif	SPI_MASTER_SLAVE == SLAVE
		CLR_BIT(SPI -> CR1	,	2);
	#endif
	
	/*	Baud Rate	*/		
	SPI -> CR1 &= ~((0b111)<<3);
	SPI -> CR1 |= ((SPI_BAUD_RATE)<<3);

	/*	Frame Format (	MSB or LSB transmitted first)	*/
	#if		SPI_FRAME_FORMAT == LSB_TRANSMITTED_FIRST
		SET_BIT(SPI -> CR1	,	7);
	#elif	SPI_FRAME_FORMAT == MSB_TRANSMITTED_FIRST
		CLR_BIT(SPI -> CR1	,	7);
	#endif
	
	/*	Slave Management	*/
	#if		SPI_SLAVE_MANAGEMENT == SW_SLAVE_MANAGEMENT
		SET_BIT(SPI -> CR1	,	9);
		#if		SLAVE_SELECT == SLAVE_SELECT_ENABLED
			CLR_BIT(SPI -> CR1	,	8);
		#if		SLAVE_SELECT == SLAVE_SELECT_DISABLED
			SET_BIT(SPI -> CR1	,	8);
		#endif
	#elif	SPI_SLAVE_MANAGEMENT == HW_SLAVE_MANAGEMENT
		CLR_BIT(SPI -> CR1	,	9);
	#endif
	
	/*	Date Frame Format (8-bit or 16-bit Transmition OR Reception)	*/
	#if		SPI_DATA_FRAME_FORMAT == BYTE
		CLR_BIT(SPI -> CR1	,	11);
	#elif		SPI_DATA_FRAME_FORMAT == WORD
		SET_BIT(SPI -> CR1	,	11);
	#endif
	
	/*	 Bidirectional data mode enable	*/
	SET_BIT(SPI -> CR1	,	15);
}


void MSPI1_voidSendReceiveSynch(u16 Copy_u8DataToTransmit, u16 *Copy_DataToReceive)
{
	/*	SPI enable	*/
	SET_BIT(SPI -> CR1	,	6);
	MGPIO_voidSetPinDirection(SPI_SLAVE_SELECT_PIN,OTPUT_SPEED_10MHZ_GPOPP);
	/*	Clear Slave Select	*/
	MGPIO_voidSetPinValue(SPI_SLAVE_SELECT_PIN,GPIO_LOW);
	/*	Send data	*/
	SPI -> DR = Copy_u8DataToTransmit;
	/* Wait Busy Flag to finish */
	while(GET_BIT(SPI -> SR , 7) == 1);
	/*	Return to the received data 	*/
	*Copy_DataToReceive = SPI -> DR;
	/*	Set Slave Select	*/
	MGPIO_voidSetPinValue(SPI_SLAVE_SELECT_PIN,GPIO_HIGH);
	/*	SPI disable	*/
	CLR_BIT(SPI -> CR1	,	6);
}



