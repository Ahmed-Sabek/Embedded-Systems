/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	30	NOV	2023					*/
/************************************************/
#ifndef EXTI_PRIVET_H
#define EXTI_PRIVET_H
/*	Registers Configrations	*/
typedef struct{
	volatile u32	IMR
	volatile u32	EMR
	volatile u32 RTSR 
	volatile u32	FTSR
	volatile u32	SWIER
	volatile u32	PR
}EXTI_Type  ;
#define	EXTI	((volatile EXTI_Type *)0x40010400)
///////////////////////////////////////////////////


/*	EXTI Modes	*/
#define RISING_EDGE    0
#define FALLING_EDGE   1
#define ON_CHANGE      2
///////////////////////////////////////////////////


/*	Global variables	*/
void (*EXTI0_CallBack) (void)  ;
///////////////////////////////////////////////////


#endif