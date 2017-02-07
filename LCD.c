/*
 * LCD.c
 *
 *  Created on: Feb 4, 2017
 *      Author: Vagobeka
 */

#include "Types.h"
#include "Macros.h"
#include "Dio.h"
#include "LCD.h"
#include <util/delay.h>

/***********************************************************************************************************/
//Sending commands to LCD
void LCD_vidSendCommand(u8 command)
{
	Dio_vidSetPinValue(LCD_Control_Port,LCD_RS_PIN,0);  // RS is 0 to write a command
	Dio_vidSetPinValue(LCD_Control_Port,LCD_RW_PIN,0);  // R/W   0 to write
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,1);  // E is always active low (Normally High)
	//Put command on the bus
	Dio_vidSetPortValue(LCD_DATA_Port,command);
	_delay_ms(2);
	//Enable is on
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,0);
	_delay_ms(5);
	//Enable is off
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,1);
	_delay_ms(10);
}
/***********************************************************************************************************/
//Sending a character to LCD
void LCD_vidWriteCharachter(u8 character)
{
	Dio_vidSetPinValue(LCD_Control_Port,LCD_RS_PIN,1);  // RS is 1 to write a Data
	Dio_vidSetPinValue(LCD_Control_Port,LCD_RW_PIN,0);  // R/W   0 to write
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,1);  // E is always active low (Normally High)
	//Put character on the bus
	Dio_vidSetPortValue(LCD_DATA_Port,character);
	_delay_ms(2);
	//Enable is on
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,0);
	_delay_ms(5);
	//Enable is off
	Dio_vidSetPinValue(LCD_Control_Port,LCD_EN_PIN,1);
	_delay_ms(10);
}
/***********************************************************************************************************/
void LCD_vidInit(void)
{

  _delay_ms(100);
  //All these values form data sheet of LCD

  //Clear Display
  LCD_vidSendCommand(0b00000001);

  //Return Home
  LCD_vidSendCommand(0b00000010);

  //Entry Mode Set
  // (I/D => 1) Cursor moves from left to right
  // (SH  => 0) Shifting of entire display is off
  LCD_vidSendCommand(0b00000110);

  //Display on/off Control bit
  //(D => 1)  The entire Display is turned on
  //(C => 0)  The Cursor display is turned off
  //(B => 0)  The cursor Blinking is turned off
  LCD_vidSendCommand(0b00001110);

  //Function Set
  //(DL => 1)  8-bit bus mode
  //(N  => 0)  1 line display mode
  //(F  => 0)  5x8 dots format
  LCD_vidSendCommand(0b00110000);
}
/***********************************************************************************************************/
void LCD_vidWriteSentence(u8* string)
{
 u8 index=0;
 while (string[index]!='\0')
 {
	 LCD_vidWriteCharachter(string[index]);
     index ++;
 }
}
