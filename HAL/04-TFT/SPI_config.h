/************************************************/
/*	Author	:   Ahmed Sabek						*/
/*	Version :   V02								*/
/*  Date	:	30	JAN	2023					*/
/************************************************/
#ifndef	SPI_CONFIG_H
#define	SPI_CONFIG_H


/*	SPI Mode options:
		1-	MSPI_MODE0		(Clock Phase=	0	&	Clock Polarity=	0	)
		2-	MSPI_MODE1		(Clock Phase=	0	&	Clock Polarity=	1	)
		3-	MSPI_MODE2		(Clock Phase=	1	&	Clock Polarity=	0	)
		4-	MSPI_MODE3		(Clock Phase=	1	&	Clock Polarity=	1	)
*/
#define SPI_MODE	MSPI_MODE0
//////////////////////////////////////////////////


/*	Master or Slave Select Options:
		1-	MASTER
		2-	SLAVE
*/
#define	SPI_MASTER_SLAVE	MASTER
//////////////////////////////////////////////////


/*	Baud Rate Control Options:
		1-	FPCLK_DEVIDED_BY2	
        2-	FPCLK_DEVIDED_BY4	
		3-	FPCLK_DEVIDED_BY8	
        4-	FPCLK_DEVIDED_BY16
        5-	FPCLK_DEVIDED_BY32
        6-	FPCLK_DEVIDED_BY64
        7-	FPCLK_DEVIDED_BY128
        8-	FPCLK_DEVIDED_BY256
*/
#define	SPI_BAUD_RATE	FPCLKD_EVIDED_BY16
//////////////////////////////////////////////////


/*	Frame Format (	MSB or LSB transmitted first) Options:
		1-	LSB_TRANSMITTED_FIRST
		2-	MSB_TRANSMITTED_FIRST
*/
#define	SPI_FRAME_FORMAT	LSB_TRANSMITTED_FIRST
//////////////////////////////////////////////////


/*	Slave Management Options:
		1-	HW_SLAVE_MANAGEMENT
        2-  SW_SLAVE_MANAGEMENT
*/
#define	SPI_SLAVE_MANAGEMENT	HW_SLAVE_MANAGEMENT
//////////////////////////////////////////////////


/*	Date Frame Format (8-bit or 16-bit Transmition OR Reception) Options:
		1-	BYTE
        2-	WORD
*/
#define	SPI_DATA_FRAME_FORMAT	BYTE
//////////////////////////////////////////////////


/*	Slave Select Pin Write PORT Pear with Pin	*/
#define	SPI_SLAVE_SELECT_PIN	GPIOA,5
//////////////////////////////////////////////////

/*	Slave Select Options:
		1-	SLAVE_SELECT_ENABLED
		2-	SLAVE_SELECT_DISABLED
*/
#define	SLAVE_SELECT	SLAVE_SELECT_DISABLED
//////////////////////////////////////////////////


#endif
