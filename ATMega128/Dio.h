/*
 * Dio Driver for AVR Atmega128
 *
 *  Created on: Feb 8, 2017
 *      Author: Vagobeka
 */

#ifndef DIO_H_
#define DIO_H_

// Defining the ports
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

#define INPUT 0
#define OUTPUT 1

#define PORT_INPUT 0x00          //All port is Input
#define PORT_OUTPUT 0xFF         //All port is Output

//Setting The Direction of any Pin or Port
void Dio_vidSetPinDirection (u8 Port,u8 Pin,u8 Value);
void Dio_vidSetPortDirection(u8 port,u8 value);
//Setting The Output Value of any Pin or Port
void Dio_vidSetPinValue (u8 port,u8 pin,u8 value);
void Dio_vidSetPortValue(u8 port,u8 value);
//Setting The Input Value of any Pin or Port
u8   Dio_u8GetPinValue (u8 port,u8 pin);
u8   Dio_u8GetPortValue(u8 port);
//Toggling a specific Pin or all Port
void DIO_vidTogglePin (u8 port, u8 pin);
void DIO_vidTogglePort(u8 port);

//Setting the value of the Low Nibble High or Low
void DIO_vidSetLowNibbleValue (u8 port,u8 value);
//Setting the value of the High Nibble High or Low
void DIO_vidSetHighNibbleValue(u8 port,u8 value);


#endif /* DIO_H_ */
