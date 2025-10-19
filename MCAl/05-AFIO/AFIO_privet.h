/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	30	NOV	2023					*/
/************************************************/
#ifndef AFIO_PRIVET_H
#define AFIO_PRIVET_H
/*	Registers Configrations	*/
typedef struct{
	volatile u32 AFIO_EVCR  ;
	volatile u32 AFIO_MAPR;
	volatile u32 AFIO_EXTICRx[4]  ;
	volatile u32 AFIO_MAPR2  ;
}AFIO_Type  ;
#define	AFIO	((AFIO_Type *)0x40010000)
///////////////////////////////////////////////////











#endif