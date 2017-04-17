/*
 * SPI Driver for AVR Atmega32
 *
 *  Created on: Apr, 11, 2017
 *      Author: Vagobeka
 */

#include "SPI.h"

/*Building SPI Registers*/
#define SPCR  (*((volatile u8*)(0x2D)))
#define SPSR  (*((volatile u8*)(0x2E)))
#define SPDR  (*((volatile u8*)(0x2F)))
/*
===========================================================================================================
                                ##### SPI Master Initialization #####
===========================================================================================================
*/
void SPI_vidMasterInit(void)
{
	//SPE    -> SPI Enable
	//DORD   -> Data Order (MSB of the data word is transmitted first).
	//MSTR   -> Master
	//CPOL   -> Clock Polarity [CPOL = 0,Sample (Rising)]
	//CPHA   -> Clock Phase    [CPHA = 0,Setup (Falling)]
	//SPR1:0 -> Prescaler (16)
	SPCR = 0x51;
	//SPI2X  -> Normal Mode
	SPSR = 0x00;
	/*Set SPI Pins Direction*/
	Dio_vidSetPinDirection(SPI_PORT, SPI_SS, OUTPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_MOSI, OUTPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_MISO, INPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_SCK, OUTPUT);
}
/*
===========================================================================================================
                                ##### SPI Slave Initialization #####
===========================================================================================================
*/
void SPI_vidSlaveInit(void)
{
	//SPE    -> SPI Enable
	//DORD   -> Data Order (MSB of the data word is transmitted first).
	//MSTR   -> Slave
	//CPOL   -> Clock Polarity [CPOL = 0,Sample (Rising)]
	//CPHA   -> Clock Phase    [CPHA = 0,Setup (Falling)]
	//SPR1:0 -> These two bits have no effect on the Slave.
	SPCR = 0x41;
	//SPI2X  -> Normal Mode
	SPSR = 0x00;
	/*Set SPI Pins Direction*/
	Dio_vidSetPinDirection(SPI_PORT, SPI_SS, INPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_MOSI, INPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_MISO, OUTPUT);
	Dio_vidSetPinDirection(SPI_PORT, SPI_SCK, INPUT);
}
/*
===========================================================================================================
                                ##### SPI Transmission  #####
===========================================================================================================
*/
u8 SPI_u8Transmit(u8 value)
{
	/*Master Must send any data to initiate the transmission*/
	SPDR=value;
	/*Wait for SPIF flag*/
	while((SPSR&0x80)==0);  
	return(SPDR);
	/*	The SPIF bit is cleared by:
    	First, reading the SPI Status Register with SPIF set.
	    Then, accessing the SPI Data Register (SPDR).
	 */
}

