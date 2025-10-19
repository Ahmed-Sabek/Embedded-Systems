/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  24 January 2024               */
/********************************************/

#ifndef DMA_PRIVET_H
#define DMA_PRIVET_H

typedef struct{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
}DMA_Channel;

typedef struct{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA;

#define MDMA	((volatile DMA *)0x40020000)
//////////////////////////////////////////////






#endif