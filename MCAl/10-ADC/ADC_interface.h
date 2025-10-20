/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  2 December 2023               */
/********************************************/

#ifndef	ADC_INTERFACE_H
#define	ADC_INTERFACE_H



/*NOTE: Configure RCC for ADC1 and GPIOA in main file	*/


void MADC_VoidInit(void);
void MADC_VoidStartConversion(void);
u16 MADC_U16GetData(void);

#endif