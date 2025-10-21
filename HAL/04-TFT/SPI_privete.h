/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V02								*/
/*  Date	:	30	JAN	2023					*/
/************************************************/
#ifndef SPI_PRIVETE_H
#define SPI_PRIVETE_H

typedef struct{
	volatile u32	CR1;
	volatile u32	CR2;
	volatile u32	SR;
	volatile u32	DR;
	volatile u32	CRCPR;
	volatile u32	RXCRCR;
	volatile u32	TXCRCR;
	volatile u32	I2SCFGR;
	volatile u32	I2SPR;
}SPI_REG;

#define	SPI		((SPI_REG *)0x40013000)

/*	SPI Mode (Clock phase & Clock polarity Configuration)	*/
#define	MSPI_MODE0	0
#define	MSPI_MODE1	1
#define	MSPI_MODE2	2
#define	MSPI_MODE3	3
//////////////////////////////////////////////////


/*	Master or Slave Select	*/
#define	MASTER	0
#define	SLAVE	1
//////////////////////////////////////////////////


/*	Baud Rate Control	*/
#define	FPCLKD_EVIDED_BY2		0b000
#define	FPCLKD_EVIDED_BY4		0b001
#define	FPCLKD_EVIDED_BY8		0b010
#define	FPCLKD_EVIDED_BY16		0b011
#define	FPCLKD_EVIDED_BY32		0b100
#define	FPCLKD_EVIDED_BY64		0b101
#define	FPCLKD_EVIDED_BY128		0b110
#define	FPCLKD_EVIDED_BY256		0b111
//////////////////////////////////////////////////


/*	Frame Format (	MSB or LSB transmitted first)	*/
#define	LSB_TRANSMITTED_FIRST	0
#define	MSB_TRANSMITTED_FIRST	1
//////////////////////////////////////////////////


/*	Slave Management	*/
#define	HW_SLAVE_MANAGEMENT		0
#define	SW_SLAVE_MANAGEMENT		1
//////////////////////////////////////////////////


/*	Date Frame Format (8-bit or 16-bit Transmition OR Reception)	*/
#define	BYTE	0
#define	WORD	1
//////////////////////////////////////////////////

/*	Slave Select	*/
#define	SLAVE_SELECT_ENABLED	0
#define	SLAVE_SELECT_DISABLED	1
//////////////////////////////////////////////////


#endif
