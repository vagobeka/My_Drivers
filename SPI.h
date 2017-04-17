/*
 * SPI Driver for AVR Atmega32
 *
 *  Created on: Apr, 11, 2017
 *      Author: Vagobeka
 */

#ifndef SPI_H_
#define SPI_H_
#include "Types.h"
#include "Dio.h"


/*SPI Port*/
#define SPI_PORT  B
/*SPI Pins*/
#define SPI_SS    4
#define SPI_MOSI  5
#define SPI_MISO  6
#define SPI_SCK   7

/*SPI APIs*/
void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
u8 SPI_u8Transmit(u8 value);
#endif /* SPI_H_ */
