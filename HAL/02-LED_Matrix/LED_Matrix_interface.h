/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	8	December	2023			*/
/************************************************/
#ifndef LED_MATRIX_INTERFACE_H
#define LED_MATRIX_INTERFACE_H


void HLEDMRX_voidInit(void)  ;

void HLEDMRX_voidDisableAllCols(void)  ;

void HLEDMRX_voidSetRowValue(u8 Copy_u8Value)  ;

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)  ;

#endif