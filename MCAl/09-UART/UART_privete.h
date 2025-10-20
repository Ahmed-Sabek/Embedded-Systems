/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	10	Feb	2023					*/
/************************************************/
#ifndef UART_PRIVETE_H
#define UART_PRIVETE_H

typedef struct{
	volatile u32	SR		;
	volatile u32	DR		;
	volatile u32	BRR		;
	volatile u32	CR1		;
	volatile u32	CR2		;
	volatile u32	CR3		;
	volatile u32	GTPR	;
}UART_REG;

#define	MUART1	((volatile UART_REG *)0x40013800)


#endif