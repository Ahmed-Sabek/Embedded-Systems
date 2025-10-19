/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V02								*/
/*  Date	:	7	NOV	2023					*/
/************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*	GPIO value Configurations	*/
#define GPIO_HIGH	1
#define GPIO_LOW	0
//////////////////////////////////////////////////


/*	GPIO PORT Configurations	*/
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2
//////////////////////////////////////////////////


/*	GPIO PIN Configurations	*/
#define PIN0		0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15
//////////////////////////////////////////////////


/*	GPIO Output Mode And Speed 10MHZ	*/
#define OTPUT_SPEED_10MHZ_GPOPP				0b0001
#define OTPUT_SPEED_10MHZ_GPOOD				0b0101
#define OTPUT_SPEED_10MHZ_AFOPP				0b1001
#define OTPUT_SPEED_10MHZ_AFOOD				0b1101
//////////////////////////////////////////////////


/*	GPIO Output Mode And Speed 2MHZ	*/
#define OTPUT_SPEED_2MHZ_GPOPP				0b0010
#define OTPUT_SPEED_2MHZ_GPOOD				0b0110
#define OTPUT_SPEED_2MHZ_AFOPP				0b1010
#define OTPUT_SPEED_2MHZ_AFOOD				0b1110
//////////////////////////////////////////////////


/*	GPIO Output Mode And Speed 50MHZ	*/
#define OTPUT_SPEED_50MHZ_GPOPP				0b0011
#define OTPUT_SPEED_50MHZ_GPOOD				0b0111
#define OTPUT_SPEED_50MHZ_AFOPP				0b1011
#define OTPUT_SPEED_50MHZ_AFOOD				0b1111
//////////////////////////////////////////////////


/*	GPIO Input Mode	*/
#define INPUT_ANALOGE						0b0000
#define INPUT_FLOATING						0b0100
#define INPUT_PULL_UP_OR_PULL_DOWEN			0b1000
//////////////////////////////////////////////////


void MGPIO_voidSetPinDirection(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Mode);
void MGPIO_voidSetPinValue(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Value);
u8   MGPIO_u8GetPinValue(u8 copy_u8PORT,u8 copy_u8PIN);




#endif
