/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  2 December 2023               */
/********************************************/

#include	"TYPES.h"
#include	"MACROS.h"

#include	"ADC_interface.h"
#include	"ADC_privete.h"
#include	"ADC_config.h"

#include	"GPIO_INTERFACE.h"

void MADC_VoidInit(void)
{
	/*Configure PA0 as analog input (input mode)*/
	MGPIO_VidSetPinDirection(GPIOA,PIN0,INPUT_ANLOG);
	/*clear status reg*/
	ADC_SR	=	0;
	/*Continuous conversion	enable*/
	SET_BIT(ADC_CR2,1);
	/*Left Alignment enable*/
	SET_BIT(ADC_CR2,11);
	/*	Sample time selection for channel 0 (239.5 cycles)	*/
	ADC_SMPR2 |= (0x7 << 0);
	/*	Clear bits 20:23 to select Regular channel sequence length 1 conversion	*/
	ADC_SQR1	&= ~(0xF << 20);
	/*	Clear bits 4:0	*/
	ADC_SQR3	&= ~(0x1F << 0);
	/*	Set channel 0 as 1st conversion in regular sequence	*/
	ADC_SQR3 |= (0 << 0);
	/*ADC on*/
	SET_BIT(ADC_CR2,0);
}
	
	


u16 MADC_U16ReadData(void)
{

	/*	Start ADC conversion	*/
    ADC_CR2 |= (1 << 22);
	/*wait for end coversion*/
	while(GET_BIT(ADC_SR,1)==0);
	
	return	ADC_DR;
}