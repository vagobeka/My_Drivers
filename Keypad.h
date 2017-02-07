/*
 * Keypad 4X4
 *
 *  Created on: Feb 3, 2017
 *      Author: Vagobeka
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

//Setting up the connections.
//        KPD_Port Pins(0->3) Output for (Columns).
//        KPD_Port Pins(4->7) Input  for (Rows).
//Activation of pull up resistors of KPD_Port(rows 4->7)
#define KPD_Port            C       //KPD_Port
#define KPD_Port_direction  0x0F    //KPD_Port_direction (columns 0-3)output  (rows 4->7)input
#define PULLUP              0xFF    //Activation of pull up resistors

//The default value when the Keypad is not pressed. Here it is (0x40)
#define NOT_PRESSED 0x00

//Getting the pressed key and return it as a number in range of (1 -> 16)
u8 KPD_u8GetPressedKey(void);


#endif /* KEYPAD_H_ */
