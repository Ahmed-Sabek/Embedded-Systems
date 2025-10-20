/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  2 December 2023               */
/********************************************/
#ifndef	ADC_PRIVETE_H
#define	ADC_PRIVETE_H

#define	BASE_ADDRESS	0x40012400

#define	ADC_SR  	*((volatile u32*)(BASE_ADDRESS+0x00))
#define	ADC_CR1 	*((volatile u32*)(BASE_ADDRESS+0x04))
#define	ADC_CR2 	*((volatile u32*)(BASE_ADDRESS+0x08))
#define	ADC_SMPR1	*((volatile u32*)(BASE_ADDRESS+0x0C))
#define	ADC_SMPR2	*((volatile u32*)(BASE_ADDRESS+0x10))
#define	ADC_HTR		*((volatile u32*)(BASE_ADDRESS+0x24))
#define	ADC_LTR		*((volatile u32*)(BASE_ADDRESS+0x28))
#define	ADC_SQR1	*((volatile u32*)(BASE_ADDRESS+0x2C))
#define	ADC_SQR2	*((volatile u32*)(BASE_ADDRESS+0x30))
#define	ADC_SQR3	*((volatile u32*)(BASE_ADDRESS+0x34))
#define	ADC_DR		*((volatile u32*)(BASE_ADDRESS+0x4C))


#endif