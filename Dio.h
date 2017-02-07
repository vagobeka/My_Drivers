/*
 * Dio.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Vagobeka
 */

#ifndef DIO_H_
#define DIO_H_
// Defining the ports
#define A 0
#define B 1
#define C 2
#define D 3
#define INPUT 0
#define OUTPUT 1
#define PORT_INPUT 0x00          //All port is Input
#define PORT_OUTPUT 0xFF         //All port is Output
//The used functions
void Dio_vidSetPinDirection(u8 Port,u8 Pin,u8 Value);
void Dio_vidSetPortDirection(u8 port,u8 value);

void Dio_vidSetPinValue(u8 port,u8 pin,u8 value);
void Dio_vidSetPortValue(u8 port,u8 value);

u8   Dio_u8GetPinValue(u8 port,u8 pin);
u8   Dio_u8GetPortValue(u8 port);

#endif /* DIO_H_ */
