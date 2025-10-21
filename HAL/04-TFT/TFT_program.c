/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	1	Feb	2023					*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_VoidInit(void)
{
		/*	Reset Pulse	*/
		MGPIO_voidSetPinDirection(TFT_RESET_PIN,OTPUT_SPEED_2MHZ_GPOPP);
		MGPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_LOW);
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
		MSTK_voidSetBusyWait(120000);
		/*	Sleep out command	*/
		VoidWriteCommand(0x11);
		/*	Wait 150ms	*/
		MSTK_voidSetBusyWait(150000);
		/*	Color mode command	*/
		VoidWriteCommand(0x3A);
		VoidWriteData(0x05);
		/*	Display on command	*/
		VoidWriteCommand(0x29);
		
		
}


void HTFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	VoidWriteCommand(0x2A);
	VoidWriteData(0);
	VoidWriteData(0);
	VoidWriteData(0);
	VoidWriteData(127);

	/* Set Y Address */
	VoidWriteCommand(0x2B);
	VoidWriteData(0);
	VoidWriteData(0);
	VoidWriteData(0);
	VoidWriteData(159);

	/* RAM Write */
	VoidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		VoidWriteData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		VoidWriteData(Data);
	}


}


static void VoidWriteCommand(u8 Copy_U8Command)
{
	u8 Local_Temp;
	/* Set A0 Pin to Low */
	MGPIO_voidSetPinDirection(TFT_A0_PIN,OTPUT_SPEED_2MHZ_GPOPP);
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_LOW);
	/* Send Command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_U8Command,&Local_Temp);
}


static void VoidWriteData(u8 Copy_U8Data)
{
	u8 Local_Temp;
	/* Set A0 Pin to High */
	MGPIO_voidSetPinDirection(TFT_A0_PIN,OTPUT_SPEED_2MHZ_GPOPP);
	MGPIO_voidSetPinValue(TFT_A0_PIN,GPIO_HIGH);
	/* Send Date over SPI */
	MSPI1_voidSendReceiveSynch(Copy_U8Data,&Local_Temp);
}
