/*
 * Dio Driver for AVR Atmega128
 *
 *  Created on: Feb 8, 2017
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
//PORT E
#define DDRE   (*(volatile u8*)(0x22))
#define PORTE  (*(volatile u8*)(0x23))
#define PINE   (*(volatile u8*)(0x21))
//PORT F
#define DDRF   (*(volatile u8*)(0x61))
#define PORTF  (*(volatile u8*)(0x62))
#define PINF   (*(volatile u8*)(0x20))
//PORT G
#define DDRG   (*(volatile u8*)(0x64))
#define PORTG  (*(volatile u8*)(0x65))
#define PING   (*(volatile u8*)(0x63))
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
		//Case Port E
	case E:
		if (value == INPUT) {
			CLEAR_BIT(DDRE, pin);
		} else {
			SET_BIT(DDRE, pin);
		}
		break;
		//Case Port F
	case F:
		if (value == INPUT) {
			CLEAR_BIT(DDRF, pin);
		} else {
			SET_BIT(DDRF, pin);
		}
		break;
		//Case Port G
	case G:
		if (value == INPUT) {
			CLEAR_BIT(DDRG, pin);
		} else {
			SET_BIT(DDRG, pin);
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
	case B:
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
		//Case Port E
	case E:
		if (value == 0) {
			CLEAR_BIT(PORTE, pin);
		} else {
			SET_BIT(PORTE, pin);
		}
		break;
		//Case Port F
	case F:
		if (value == 0) {
			CLEAR_BIT(PORTF, pin);
		} else {
			SET_BIT(PORTF, pin);
		}
		break;
		//Case Port G
	case G:
		if (value == 0) {
			CLEAR_BIT(PORTG, pin);
		} else {
			SET_BIT(PORTG, pin);
		}
		break;
	}
}
/***********************************************************************************************************/
//Setting The Direction of the all port
void Dio_vidSetPortDirection(u8 port, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		DDRA = value;
		break;
		//Case Port B
	case B:
		DDRB = value;
		break;
		//Case Port C
	case C:
		DDRC = value;
		break;
		//Case Port D
	case D:
		DDRD = value;
		break;
		//Case Port E
	case E:
		DDRE = value;
		break;
		//Case Port F
	case F:
		DDRF = value;
		break;
		//Case Port G
	case G:
		DDRG = value;
		break;
	}
}
/***********************************************************************************************************/
//Setting The output value of the all port
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
		//Case Port E
	case E:
		PORTE = value;
		break;
		//Case Port F
	case F:
		PORTF = value;
		break;
		//Case Port G
	case G:
		PORTG = value;
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
		//Case Port E
	case E:
		LOC = GET_BIT(PINE, pin);
		break;
		//Case Port F
	case F:
		LOC = GET_BIT(PINF, pin);
		break;
		//Case Port G
	case G:
		LOC = GET_BIT(PING, pin);
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
		//Case Port E
	case E:
		LOC = PINE;
		break;
		//Case Port F
	case F:
		LOC = PINF;
		break;
		//Case Port G
	case G:
		LOC = PING;
		break;
	}
	return (LOC);
}
/***********************************************************************************************************/
//Toggling a specific pin
void DIO_vidTogglePin(u8 port, u8 pin) {
	switch (port) {
	//Case Port A
	case A:
		TOGGLE_BIT(PORTA, pin);
		break;
		//Case Port B
	case B:
		TOGGLE_BIT(PORTB, pin);
		break;
		//Case Port C
	case C:
		TOGGLE_BIT(PORTC, pin);
		break;
		//Case Port D
	case D:
		TOGGLE_BIT(PORTD, pin);
		break;
		//Case Port E
	case E:
		TOGGLE_BIT(PORTE, pin);
		break;
		//Case Port F
	case F:
		TOGGLE_BIT(PORTF, pin);
		break;
		//Case Port G
	case G:
		TOGGLE_BIT(PORTG, pin);
		break;
	}
}
/***********************************************************************************************************/
//Toggling the all Port
void DIO_vidTogglePort(u8 port) {
	switch (port) {
	//Case Port A
	case A:
		TOGGLE_BYTE(PORTA);
		break;
		//Case Port B
	case B:
		TOGGLE_BYTE(PORTB);
		break;
		//Case Port C
	case C:
		TOGGLE_BYTE(PORTC);
		break;
		//Case Port D
	case D:
		TOGGLE_BYTE(PORTD);
		break;
		//Case Port E
	case E:
		TOGGLE_BYTE(PORTE);
		break;
		//Case Port F
	case F:
		TOGGLE_BYTE(PORTF);
		break;
		//Case Port G
	case G:
		TOGGLE_BYTE(PORTG);
		break;
	}
}

/***********************************************************************************************************/
//Setting the value of the Low Nibble
//(0 -> makes the 4 pins of Low Nibble 0 without changing the value of the other pins)
//(1 -> makes the 4 pins of Low Nibble 1 without changing the value of the other pins)
void DIO_vidSetLowNibbleValue(u8 port, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTA);
		} else {
			SET_LOW_NIBBLE(PORTA);
		}
		break;
		//Case Port B
	case B:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTB);
		} else {
			SET_LOW_NIBBLE(PORTB);
		}
		break;
		//Case Port C
	case C:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTC);
		} else {
			SET_LOW_NIBBLE(PORTC);
		}
		break;
		//Case Port D
	case D:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTD);
		} else {
			SET_LOW_NIBBLE(PORTD);
		}
		break;
		//Case Port E
	case E:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTE);
		} else {
			SET_LOW_NIBBLE(PORTE);
		}
		break;
		//Case Port F
	case F:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTF);
		} else {
			SET_LOW_NIBBLE(PORTF);
		}
		break;
		//Case Port G
	case G:
		if (value == 0) {
			CLEAR_LOW_NIBBLE(PORTG);
		} else {
			SET_LOW_NIBBLE(PORTG);
		}
		break;
	}
}
/***********************************************************************************************************/
//Setting the value of the High Nibble
//(0 -> makes the 4 pins of High Nibble 0 without changing the value of the other pins)
//(1 -> makes the 4 pins of High Nibble 1 without changing the value of the other pins)
void DIO_vidSetHighNibbleValue(u8 port, u8 value) {
	switch (port) {
	//Case Port A
	case A:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTA);
		} else {
			SET_HIGH_NIBBLE(PORTA);
		}
		break;
		//Case Port B
	case B:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTB);
		} else {
			SET_HIGH_NIBBLE(PORTB);
		}
		break;
		//Case Port C
	case C:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTC);
		} else {
			SET_HIGH_NIBBLE(PORTC);
		}
		break;
		//Case Port D
	case D:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTD);
		} else {
			SET_HIGH_NIBBLE(PORTD);
		}
		break;
		//Case Port E
	case E:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTE);
		} else {
			SET_HIGH_NIBBLE(PORTE);
		}
		break;
		//Case Port F
	case F:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTF);
		} else {
			SET_HIGH_NIBBLE(PORTF);
		}
		break;
		//Case Port G
	case G:
		if (value == 0) {
			CLEAR_HIGH_NIBBLE(PORTG);
		} else {
			SET_HIGH_NIBBLE(PORTG);
		}
		break;
	}
}
