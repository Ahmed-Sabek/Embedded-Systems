/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V01								*/
/*  Date	:	7	NOV	2023					*/
/************************************************/
#ifndef SEVEN_SEG_CONFIG_H
#define SEVEN_SEG_CONFIG_H

/*
7 SEG Enable PORT
Options:	GPIOA
            GPIOB
            GPIOC
*/
#define SEVEN_SEG_ENABLE_PORT GPIOB
//////////////////////////////////////////////////


/*
7 SEG Enable Pin
Options:	PIN0 to PIN15 if you choose PORTA or PORTB
			PIN13 to PIN15 if you choose PORTC	
*/
#define SEVEN_SEG_ENABLE_PIN	PIN0
//////////////////////////////////////////////////


/*7 SEG Type
Options:
			COMMON_CATHODE
			COMMON_ANODE
*/
#define	COMMON_CATHODE
//////////////////////////////////////////////////


/*	Choose 7 SEG Pins
	Options: 	PIN0 to PIN15 if you choose PORTA or PORTB
				PIN13 to PIN15 if you choose PORTC
*/
#define	A	PIN0
#define	B	PIN1
#define	C	PIN2
#define	D	PIN3
#define	E	PIN4
#define	F	PIN5
#define	G	PIN6
//////////////////////////////////////////////////




#endif