/*
 * Keypad 4X4
 *
 *  Created on: Feb 3, 2017
 *      Author: Vagobeka
 */

#include "Types.h"
#include "Macros.h"
#include "Dio.h"
#include "Keypad.h"
#include <util/delay.h>

u8 KPD_u8GetPressedKey(void) {
	u8 col, row;
	u8 loc = NOT_PRESSED;

	u8 key[4][4] = { { 1, 2, 3, 4 },
			         { 5, 6, 7, 8 },
			         { 9, 10, 11, 12 },
			         { 13,14, 15, 16 } };

	for (col = 0; col <= 3; col++) {
	   //initialization by making all Columns KPD_Port(0 -> 3) High
		DIO_vidSetLowNibbleValue(KPD_Port, 1);
	  // Generate 0 in Column 0 and repeat
		Dio_vidSetPinValue(KPD_Port, col, 0);

		for (row = 4; row <= 7; row++) {
			//IF the switch is pressed
			//(Active Low. Internal pull up resistors)
			if (!(Dio_u8GetPinValue(KPD_Port, row))) // if ((Dio_u8GetPinValue(KPD_Port,row))==0)
			{
				//wait until the key is released (Single press mode)
				while (Dio_u8GetPinValue(KPD_Port, row) == 0);
				loc = key[(row - 4)][col];
				_delay_ms(10);          //Delay for debouncing
			}

		}
	}
	//The return Value will be a number from 1 to 16 according to the Key array
	return loc;
}

