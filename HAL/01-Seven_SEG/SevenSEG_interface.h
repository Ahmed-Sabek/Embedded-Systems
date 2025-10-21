/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	7	NOV	2023					*/
/************************************************/
#ifndef SEVEN_SEG_INTERFACE_H
#define SEVEN_SEG_INTERFACE_H

/*	7 SEG PORT Configurations	*/
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2
//////////////////////////////////////////////////

/*	7 SEG Pin configurations	*/
#define PIN0		0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15
//////////////////////////////////////////////////


void HSSEG_voidSSEGInit(u8 Copy_u8PORT)  ;

void HSSEG_voidSSEGWrite(u8 Copy_u8PORT , u8 Copy_u8Number)  ;

#endif