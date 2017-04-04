/*
 * UART Driver for AVR Atmega3
 *
 * CLK -> 16MHz
 *
 *  Created on: Mar 10, 2017
 *      Author: Vagobeka
 */
#include "UART.h"
/*
===========================================================================================================
                                ##### Building the registers of UART #####
===========================================================================================================
*/
#define UDR     (*((volatile u8*)(0x2C)))
#define UCSRA   (*((volatile u8*)(0x2B)))
#define UCSRB   (*((volatile u8*)(0x2A)))
//The same address as UBRRH
//The URSEL bit must be one when writing the UCSRC.
#define UCSRC   (*((volatile u8*)(0x40)))
#define UBRRL   (*((volatile u8*)(0x29)))
#define UBRRH   (*((volatile u8*)(0x40)))

/*
===========================================================================================================
                                ##### UART Initialization #####
===========================================================================================================
* BaudRate -> Will be one of the Macros with the desired Baud Rate in the UART.h file
*/
void UART_vidInit(u16 BaudRate)
{

	UBRRL = (u8) BaudRate;
	UBRRH = (u8) (BaudRate >> 8);

	/*
	 * TXEN -> Enable Transmitter
	 * RXEN -> Enable Receiver
	 */
	UCSRB = 0x18;
	/*
	 * URSEL    -> Select the UCSRC register
	 * UMSEL    -> Asynchronous Operation
	 * UPM1:0   -> Parity ModeDisabled
	 * USBS     -> 1 Stop Bit
	 * UCSZ1:0  -> 8-bit Character Size
	 */
	UCSRC = 0x86;
}
/*
===========================================================================================================
                                ##### Sending a character to UART #####
===========================================================================================================
*/
void UART_vidSendchar(u8 data)
{
//Wait for the UDRE to be 1 (UDR is Empty)
  while((UCSRA&0x20)==0);
  UDR=data;
}

/*
===========================================================================================================
                                ##### Receiving a character from UART #####
===========================================================================================================
*/
u8 UART_u8Receivechar(void)
{
  //Wait for RXC to be 1 (Receive complete)
  while((UCSRA&0x80)==0);
  return (UDR);
}
/*
===========================================================================================================
                                ##### Sending a string to UART #####
===========================================================================================================
*/
void UART_vidSendString(u8 * string)
{
	u8 index;
	for (index=0;string[index];index++)
	{
		UART_vidSendchar(string[index]);
	}
}
/*
===========================================================================================================
                                ##### Receiving a string from UART #####
===========================================================================================================
*stringArray     -> Is the array which the received sting will be stored in.
*
*stringArraySize -> The size of the stringArray
*
*stop_character  -> The character that will be at the end of the received string
*                   which will be the terminator (MUST BE) the last character or there will be error.
*/
void UART_vidReceiveString(u8 * stringArray,u8 stringArraySize, u8 stop_character)
{

	u8 index;
	u8 clear;
	stringArray[0] = UART_u8Receivechar();
	for (index = 0; (stringArray[index] != stop_character); index++)
	{
		stringArray[index + 1] = UART_u8Receivechar();
	}

	//Clear the rest of array
	for (clear = index + 1; clear < stringArraySize; clear++)
	{
		stringArray[clear] = '\0';
	}

}
/*
===========================================================================================================
                                ##### Flush the UART #####
===========================================================================================================
*/
 void UART_vidFlush(void)
{
	u8 dummy;
	  //Wait for RXC to be 1 (Receive complete)
	  while((UCSRA&0x80)==0);
	  dummy=UDR;
}
