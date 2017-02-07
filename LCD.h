/*
 * LCD.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Vagobeka
 */

#ifndef LCD_H_
#define LCD_H_

#include "Types.h"
#include "Macros.h"
#include "Dio.h"
//Connections with ATmega32
//8-bit Mode

//Setting up the Data Port
//(DB0 -> Port_Pin0)...(DB7 -> Port_Pin7)
#define  LCD_DATA_Port      A      //Data Port is B


//Setting up the Control Port
#define  LCD_Control_Port   B      //Control Port is A
#define  LCD_RS_PIN         0      // RS    ->     PIN  A0
#define  LCD_RW_PIN         1      // R/W   ->     PIN  A1
#define  LCD_EN_PIN         2      // E     ->     PIN  A2


void LCD_vidSendCommand(u8 command);
void LCD_vidWriteCharachter(u8 character);
void LCD_vidInit(void);
void LCD_vidWriteSentence(u8* string);

#endif /* LCD_H_ */
