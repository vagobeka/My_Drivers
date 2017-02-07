/*
 * Dio Driver for AVR Atmega32
 *
 *  Created on: Jan 28, 2017
 *      Author: Vagobeka
 */

#include "Macros.h"
#include "Types.h"
#include "Dio.h"
/***********************************************************************************************************/
/* Building the registers of all ports */
//PORT A
#define DDRA   (*(volatile u8*)(0x3A))
#define PORTA  (*(volatile u8*)(0x3B))
#define PINA   (*(volatile u8*)(0x39))
//PORT B
#define DDRB   (*(volatile u8*)(0x37))
#define PORTB  (*(volatile u8*)(0x38))
#define PINB   (*(volatile u8*)(0x36))
//PORT C
#define DDRC   (*(volatile u8*)(0x34))
#define PORTC  (*(volatile u8*)(0x35))
#define PINC   (*(volatile u8*)(0x33))
//PORT D
#define DDRD   (*(volatile u8*)(0x31))
#define PORTD  (*(volatile u8*)(0x32))
#define PIND   (*(volatile u8*)(0x30))

/***********************************************************************************************************/
//Setting The Direction of any pin (Making it Input(0) or Output(1) )
void Dio_vidSetPinDirection(u8 port, u8 pin, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		if (value == INPUT) {
			CLEAR_BIT(DDRA, pin); //Making the pin input,as CLEAR_BIT sets 0 to the pin
		} else {
			SET_BIT(DDRA, pin); //Else making the pin output,as SET_BIT sets 1 to the pin
		}
		break;
	//Case Port B
	case B:
		if (value == INPUT) {
			CLEAR_BIT(DDRB, pin);
		} else {
			SET_BIT(DDRB, pin);
		}
		break;
    //Case Port C
	case C:
		if (value == INPUT) {
			CLEAR_BIT(DDRC, pin);
		} else {
			SET_BIT(DDRC, pin);
		}
		break;
   //Case Port D
	case D:
		if (value == INPUT) {
			CLEAR_BIT(DDRD, pin);
		} else {
			SET_BIT(DDRD, pin);
		}
		break;
	}
}
/***********************************************************************************************************/
//Setting The Value of the output pins (High or Low)
void Dio_vidSetPinValue(u8 port, u8 pin, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		if (value == 0) {
			CLEAR_BIT(PORTA, pin);
		} else {
			SET_BIT(PORTA, pin);
		}
		break;
    //Case Port B
	case B:               //Port B
		if (value == 0) {
			CLEAR_BIT(PORTB, pin);
		} else {
			SET_BIT(PORTB, pin);
		}
		break;
		//Case Port C
	case C:
		if (value == 0) {
			CLEAR_BIT(PORTC, pin);
		} else {
			SET_BIT(PORTC, pin);
		}
		break;
		//Case Port D
	case D:
		if (value == 0) {
			CLEAR_BIT(PORTD, pin);
		} else {
			SET_BIT(PORTD, pin);
		}
		break;
	}
}
/***********************************************************************************************************/
//Setting The Direction of the whole port
void Dio_vidSetPortDirection(u8 port, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		DDRA = value;
		break;
	//Case Port B
	case B:               //Port B
		DDRB = value;
		break;
	//Case Port C
	case C:               //Port C
		DDRC = value;
		break;
	//Case Port D
	case D:               //Port D
		DDRD = value;
		break;
	}
}
/***********************************************************************************************************/
//Setting The output value of the whole port
void Dio_vidSetPortValue(u8 port, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		PORTA = value;
		break;
	//Case Port B
	case B:
		PORTB = value;
		break;
	//Case Port C
	case C:
		PORTC = value;
		break;
	//Case Port D
	case D:
		PORTD = value;
		break;
	}
}
/***********************************************************************************************************/
//Getting the value of any pin in case of direction is input
u8 Dio_u8GetPinValue(u8 port, u8 pin) {
	u8 LOC;
	switch (port) {
	//Case Port A
	case A:
		LOC = GET_BIT(PINA, pin);
		break;
	//Case Port B
	case B:
		LOC = GET_BIT(PINB, pin);
		break;
	//Case Port C
	case C:
		LOC = GET_BIT(PINC, pin);
		break;
	//Case Port D
	case D:
		LOC = GET_BIT(PIND, pin);
		break;
	}
	return (LOC);
}
/***********************************************************************************************************/
//Getting the value of all port in case of direction is input
u8 Dio_u8GetPortValue(u8 port) {
	u8 LOC;
	switch (port) {
	//Case Port A
	case A:
		LOC = PINA;
		break;
	//Case Port B
	case B:
		LOC = PINB;
		break;
	//Case Port C
	case C:
		LOC = PINC;
		break;
	//Case Port D
	case D:
		LOC = PIND;
		break;
	}
	return (LOC);
}
