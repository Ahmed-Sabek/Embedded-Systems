/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	27	NOV	2023					*/
/************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define  NVIC_ISER0		*((u32*)0xE000E100)				/*Enable External Interrupt From 0 To 31 */
#define  NVIC_ISER1		*((u32*)0xE000E104)				/*Enable External Interrupt From 32 To 63 */
#define	 NVIC_ICER0		*((u32*)0xE000E180)				/*Disable External Interrupt From 0 To 31 */
#define	 NVIC_ICER1		*((u32*)0xE000E184)				/*Disable External Interrupt From 32 To 63 */
#define  NVIC_ISPR0		*((u32*)0xE000E200)				/*Set Pending Flag From 0 To 31 */
#define  NVIC_ISPR1		*((u32*)0xE000E204)				/*Set Pending Flag From 32 To 63 */
#define  NVIC_ICPR0		*((u32*)0xE000E280)				/*Clear Pending Flag From 0 To 31 */
#define  NVIC_ICPR1		*((u32*)0xE000E284)				/*Clear Pending Flag From 32 To 63 */
#define	 NVIC_IABR0		*((volatile u32*)0xE000E300)	/*Read Active Flag From 0 To 31*/
#define	 NVIC_IABR1		*((volatile u32*)0xE000E304)	/*Read Active Flag From 32 To 63*/

#define NVIC_IPR		((volatile u8*)0xE000E400)
#define SCB_AIRCR 		*((volatile u32*)0xE000ED0C)

#endif