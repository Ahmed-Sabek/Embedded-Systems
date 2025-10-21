/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	8	December	2023			*/
/************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_Matrix_interface.h"
#include "LED_Matrix_config.h"
#include "LED_Matrix_privet.h"

void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PORT_AND_PIN,OTPUT_SPEED_2MHZ_GPOPP)  ;
}



void HLEDMRX_voidDisableAllCols(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL1_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL2_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL3_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL4_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL5_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL6_PORT_AND_PIN,GPIO_HIGH)  ;
	MGPIO_voidSetPinValue(LEDMRX_COL7_PORT_AND_PIN,GPIO_HIGH)  ;
}


void HLEDMRX_voidSetRowValue(u8 Copy_u8Value)
{
	u8 Local_u8BIT  ;
	Local_u8BIT = GET_BIT(Copy_u8Value,0)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PORT_AND_PIN,Local_u8BIT)  ;
	
	u8 Local_u8BIT  ;
	Local_u8BIT = GET_BIT(Copy_u8Value,4)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PORT_AND_PIN,Local_u8BIT)  ;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7)  ;
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PORT_AND_PIN,Local_u8BIT)  ;
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 0	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[0])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL0_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 1	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[1])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL1_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 2	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[2])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL2_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 3	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[3])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL3_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 4	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[4])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL4_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 5	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[5])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL5_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 6	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[6])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL6_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
		
		
		/*		Disable All Columns	*/
		HLEDMRX_voidDisableAllCols()  ;
		/*	Enable Column 7	*/
		HLEDMRX_voidSetRowValue(Copy_u8Data[7])  ;
		MGPIO_voidSetPinValue(LEDMRX_COL7_PORT_AND_PIN,GPIO_LOW)  ;
		MSTK_voidSetBusyWait(2500)  ;
	}
	
	
}