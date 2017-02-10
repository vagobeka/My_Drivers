/*
 * LCD 2x16
 *
 *  Created on: Feb 4, 2017
 *      Author: Vagobeka
 */

#ifndef LCD_H_
#define LCD_H_

#include "Types.h"
#include "Macros.h"
#include "Dio.h"
//#include "Keypad.h"
//Connections with ATmega32
//8-bit Mode

//Setting up the Data Port
//(DB0 -> Port_Pin0)...(DB7 -> Port_Pin7)
#define  LCD_DATA_Port      A      //Data Port is A


//Setting up the Control Port
#define  LCD_Control_Port   B      //Control Port is B
#define  LCD_RS_PIN         0      // RS    ->     PIN  B0
#define  LCD_RW_PIN         1      // R/W   ->     PIN  B1
#define  LCD_EN_PIN         2      // E     ->     PIN  B2

//When setting the directions of LCD ports in main just copy and paste these lines

//	Dio_vidSetPortDirection(LCD_DATA_Port, PORT_OUTPUT);
//	Dio_vidSetPinDirection(LCD_Control_Port, LCD_RS_PIN, OUTPUT);
//	Dio_vidSetPinDirection(LCD_Control_Port, LCD_EN_PIN, OUTPUT);
//	Dio_vidSetPinDirection(LCD_Control_Port, LCD_RW_PIN, OUTPUT);
//	LCD_vidInit();

void LCD_vidSendCommand(u8 command);
void LCD_vidWriteCharachter(u8 character);
void LCD_vidInit(void);
void LCD_vidWriteSentence(u8* string);
void LCD_KPD_vidPrintPressedKey(u8 key);

#endif /* LCD_H_ */
