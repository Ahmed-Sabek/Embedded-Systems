/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	5	NOV	2023					*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*	Peripheral Bus (BusID)	*/
#define RCC_AHP		0
#define RCC_APB1	1
#define RCC_APB2	2
///////////////////////////////////////////////////

/*	Peripheral Clock Enable (PerID)	*/
#define AFIO		0
#define	PORTA		2
#define	PORTB		3
#define	PORTC		4
///////////////////////////////////////////////////




void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId);
void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId);

#endif
