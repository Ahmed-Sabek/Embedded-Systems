/********************************************/
/* Author  :  Ahmed Sabek                   */
/* Version :  V01                           */
/* Date    :  2 December 2023               */
/********************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*	Registers Definations	*/
typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}MSTK_Type;

#define     MSTK    ((MSTK_Type*)0xE000E010)
//////////////////////////////////////////////

/*	STC Clock Source (AHB or AHB/8)	*/
#define MSTC_SRC_AHB	0
#define MSTC_SRC_AHB_8	1
//////////////////////////////////////////////

/*	Mode Of Interval	*/
#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1
//////////////////////////////////////////////

#endif
