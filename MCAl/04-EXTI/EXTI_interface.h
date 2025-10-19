/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	30	NOV	2023					*/
/************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/*	Functions Decleration	*/
void MEXTI_voidInit(u8 copy_u8EXTILine , u8 copy_u8EXTIMode)  ;

void MEXTI_voidEnable(u8 copy_u8EXTILine)  ;

void MEXTI_voidDisable(u8 copy_u8EXTILine)  ;

void EXTI_VoidSoftWareTrigger( u8 copy_u8EXTILine)  ;

void EXTI0_VidSetCallBack( void (*ptr) (void) )  ;
///////////////////////////////////////////////////

#endif