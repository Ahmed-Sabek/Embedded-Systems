/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	27	NOV	2023					*/
/************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define NVIC_GROUP_4_SUB_0     0x05FA0300		/* 0 bit for sub priority & 4 bit For group priority   << 0 */
#define NVIC_GROUP_3_SUB_1     0x05FA0400		/* 1 bit for sub priority & 3 bit For group priority   << 1 */
#define NVIC_GROUP_2_SUB_2     0x05FA0500		/* 2 bit for sub priority & 2 bit For group priority   << 2 */
#define NVIC_GROUP_1_SUB_3     0x05FA0600		/* 3 bit for sub priority & 1 bit For group priority   << 3 */
#define NVIC_GROUP_0_SUB_4     0x05FA0700		/* 4 bit for sub priority & 0 bit For group priority   << 4 */


/*	#define For Interrupt ID =  POsition In Vector Table	*/
#define WWDG   0
#define EXT0   6
#define EXT1   7
#define DMA_ID 11
//////////////////////////


void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber)  ;

void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber)  ;

void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)  ;

void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber)  ;

u8 MNVIC_u8GetActiveFlage(u8 copy_u8IntNumber)  ;

void MNVIC_voidSetPriority(s8 copy_s8INTID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32GROUP)  ;

#endif