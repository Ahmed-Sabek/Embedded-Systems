/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	24	June	2024				*/
/************************************************/
#ifndef TIM1_PRIVET_H
#define TIM1_PRIVET_H

//TIMER1
#define TIM1_BASE                              0x40012C00
#define TIM1_CNT                              *( volatile u32 *)(TIM1_BASE+0x24)
#define TIM1_CR1                              *( volatile u32 *)(TIM1_BASE+0x00)
#define TIM1_PSC                              *( volatile u32 *)(TIM1_BASE+0x28)
#define TIM1_SR                               *( volatile u32 *)(TIM1_BASE+0x10)
#define TIM1_DIER                             *( volatile u32 *)(TIM1_BASE+0x0c)
#define TIM1_ARR                              *( volatile u32 *)(TIM1_BASE+0x2c)
#define TIM1_CCR1                             *( volatile u32 *)(TIM1_BASE+0x34)
#define TIM1_CCR2                             *( volatile u32 *)(TIM1_BASE+0x38)
#define TIM1_CCR3                             *( volatile u32 *)(TIM1_BASE+0x3C)
#define TIM1_CCR4                             *( volatile u32 *)(TIM1_BASE+0x40)
#define TIM1_CCMR1                            *( volatile u32 *)(TIM1_BASE+0x18)
#define TIM1_CCER                             *( volatile u32 *)(TIM1_BASE+0x20)
#define TIM1_BDTR                             *( volatile u32 *)(TIM1_BASE+0x44)
#define TIM1_CCMR2                            *( volatile u32 *)(TIM1_BASE+0x1c)


/*Base Addresses For BUS PERIPHERALS*/
/*==========================================================*/
#define RCC_BASE                                  0x40021000
#define RCC_APB1ENR                           *( volatile u32 *)(RCC_BASE+0x1C)
#define RCC_APB2ENR                           *( volatile u32 *)(RCC_BASE+0x18)







#endif
