/*
 * LCD 2x16 with ATmega32
 *
 * 8-bit Mode
 *
 *  Created on: Feb 4, 2017
 *      Author: Vagobeka
 */

#ifndef LCD_H_
#define LCD_H_

#include "Types.h"
#include "Macros.h"
#include "Dio.h"
#include <util/delay.h>

//Setting up the Data Port
//(D0 -> Port_Pin0)...(D7 -> Port_Pin7)
#define  LCD_DATA_Port      C


//Setting up the Control Port
#define  LCD_Control_Port   D      //Control Port
#define  LCD_RS_PIN         5      // RS    ->   The number of the desired pin
#define  LCD_RW_PIN         6      // R/W   ->   The number of the desired pin
#define  LCD_EN_PIN         7      // E     ->   The number of the desired pin

void LCD_vidSendCommand(u8 command);
void LCD_vidWriteCharachter(u8 character);
void LCD_vidInit(void);
void LCD_vidWriteSentence(u8* string);
void LCD_KPD_vidPrintPressedKey(u8 key);
void LCD_vidPrintNumbers(u32 number);

#endif /* LCD_H_ */
