/*
 * UART Driver for AVR Atmega3
 *
 * CLK -> 16MHz
 *
 *  Created on: Mar 10, 2017
 *      Author: Vagobeka
 */

#ifndef UART_H_
#define UART_H_

#include "Types.h"
#include "Macros.h"

/*
===========================================================================================================
                                     ##### UART Baud Rates #####
===========================================================================================================
*These are the values of the Baud Rate which we can use in UART with CLK 16MHz
*Use these Macros as an arguments in UART_vidInit function
*/
#define BR_2400_16MHz       416
#define BR_4800_16MHz       207
#define BR_9600_16MHz       103
#define BR_14400_16MHz      68
#define BR_19200_16MHz      51
#define BR_28800_16MHz      34
#define BR_38400_16MHz      25
#define BR_57600_16MHz      16
#define BR_76800_16MHz      12
#define BR_115200_16MHz     8
#define BR_250K_16MHz       3
#define BR_500K_16MHz       1
#define BR_1M_16MHz         0
/*=========================================================================================================*/

void UART_vidInit(u16 BaudRate);
void UART_vidSendchar(u8 data);
u8 UART_u8Receivechar(void);
void UART_vidSendString(u8 * string);
void UART_vidReceiveString(u8 * stringArray,u8 stringArraySize, u8 stop_character);
void UART_vidFlush(void);

#endif /* UART_H_ */
