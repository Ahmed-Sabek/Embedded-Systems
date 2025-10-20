/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	5	NOV	2023					*/
/************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "TIM1_interface.h"
#include "TIM1_privet.h"
#include "TIM1_config.h"
#include "GPIO_interface.h"

unsigned short Frequancy = 0xC350;

void TIM1_Init_PWM(void)
{
	/*GPIO Configuration */
	//PA8 CH1 PWM1
	MGPIO_voidSetPinDirection(GPIOA,PIN8,OTPUT_SPEED_10MHZ_AFOPP);
	
	//PA9 CH2 PWM2
	MGPIO_voidSetPinDirection(GPIOA,PIN9,OTPUT_SPEED_10MHZ_AFOPP);

	//PA10 CH3 PWM3
	MGPIO_voidSetPinDirection(GPIOA,PIN10,OTPUT_SPEED_10MHZ_AFOPP);


	//A11 CH4 PWM4
	MGPIO_voidSetPinDirection(GPIOA,PIN11,OTPUT_SPEED_10MHZ_AFOPP);
	
	/*Timer1 Configuration*/
	//Bit 11 TIM1EN: TIM1 timer clock enable
	RCC_APB2ENR |=(1<<11);

	//Bit 7 ARPE: Auto-reload preload enable
	TIM1_CR1 |=(1<<7);
	
	//Upcounting is active when the DIR bit in the TIMx_CR1 register is low
	//Bit 4 DIR: Direction
	TIM1_CR1 &=~(1<<4);

	TIM1_PSC=3;

	//allows generating a signal with a frequency determined by the value of the TIMx_ARR register
	TIM1_ARR = Frequancy;
	
	/****************************Channel 1 *********************************/
	//Bits 6:4 OC1M: Output Compare 1 mode
	//110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	TIM1_CCMR1 &=~(0b111<<4);
	TIM1_CCMR1 |=(0b110<<4);

	/*The corresponding preload register must be enabled by setting the
    OCxPE bit in the TIMx_CCMRx register*/
	//Bit 3 OC1PE: Output Compare 1 preload enable
	TIM1_CCMR1 |=(1<<3);

	//Bit 0 CC1E: Capture/Compare 1 output enable
	TIM1_CCER |=(1<<0);

		/****************************Channel 2 *********************************/
		//Bits 14:12 OC2M: Output Compare 2 mode
		//110: PWM mode 1 - In upcounting, channel 2 is active as long as TIMx_CNT<TIMx_CCR1
		TIM1_CCMR1 &=~(0b111<<12);
		TIM1_CCMR1 |=(0b110<<12);

		/*The corresponding preload register must be enabled by setting the
	    OCxPE bit in the TIMx_CCMRx register*/
		//Bit 11 OC2PE: Output Compare 2 preload enable
		TIM1_CCMR1 |=(1<<11);

		//Bit 4 CC2E: Capture/Compare 2 output enable
		TIM1_CCER |=(1<<4);

		/****************************Channel 3 *********************************/
				//Bits 6:4 OC2M: Output Compare 2 mode
				//110: PWM mode 1 - In upcounting, channel 2 is active as long as TIMx_CNT<TIMx_CCR1
				TIM1_CCMR2 &=~(0b111<<4);
				TIM1_CCMR2 |=(0b110<<4);

				/*The corresponding preload register must be enabled by setting the
			    OCxPE bit in the TIMx_CCMRx register*/
				//Bit 3 OC3PE: Output Compare 2 preload enable
				TIM1_CCMR2 |=(1<<3);

				//Bit 8 CC3E: Capture/Compare 3 output enable
				TIM1_CCER |=(1<<8);

		/****************************Channel 4 *********************************/
	//Bits 12:14 OC4M: Output Compare 4 mode
	//110: PWM mode 1 - In upcounting, channel 4 is active as long as TIM1_CNT<TIM1_CCR4
	TIM1_CCMR2 &=~(0b111<<12);
	TIM1_CCMR2 |=(0b110<<12);

	//Bit 11 OC4PE: Output compare 4 preload enable
	TIM1_CCMR2 |=(1<<11);

	//Bit 12 CC4E: Capture/Compare 4 output enable
	TIM1_CCER |=(1<<12);

	//Bit 13 CC14P: Capture/Compare 4 output polarity
	//1: OC1 active low
	//TIM1_CCER |=(1<<13);




	//Bit 15 MOE: Main output enable
	TIM1_BDTR |=(1<<15);

	//Bit 0 CEN: Counter enable
	//TIM1_CR1 |=(1<<0);


}



void TIM1_PWM1_Set_Value(char dutyCycle)
{
	unsigned short PWM;
	PWM = ((Frequancy*dutyCycle)/100);
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR1 = PWM;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}


void TIM1_PWM2_Set_Value(char dutyCycle)
{
	unsigned short PWM;
	PWM = ((Frequancy*dutyCycle)/100);
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR2 = PWM;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}


void TIM1_PWM3_Set_Value(char dutyCycle)
{
	unsigned short PWM;
	PWM = ((Frequancy*dutyCycle)/100);
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR3 = PWM;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}

void TIM1_PWM4_Set_Value(char dutyCycle)
{
	unsigned short PWM;
	PWM = ((Frequancy*dutyCycle)/100);
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR4 = PWM;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}













