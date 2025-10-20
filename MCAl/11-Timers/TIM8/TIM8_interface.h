/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	24	June	2024				*/
/************************************************/
#ifndef TIM1_INTERFACE_H
#define TIM1_INTERFACE_H


void TIM1_Init_PWM(void);
void TIM1_PWM1_Set_Value(char dutyCycle);
void TIM1_PWM2_Set_Value(char dutyCycle);
void TIM1_PWM3_Set_Value(char dutyCycle);
void TIM1_PWM4_Set_Value(char dutyCycle);

#endif
