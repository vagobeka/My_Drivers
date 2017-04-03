/*
 * LCD 2x16 with ATmega32
 *
 * 8-bit Mode
 *
 *  Created on: Feb 4, 2017
 *      Author: Vagobeka
 */

#include "LCD.h"
/*
===========================================================================================================
                                ##### Sending commands to LCD #####
===========================================================================================================
*/
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
/*
===========================================================================================================
                                ##### Writing a character on LCD #####
===========================================================================================================
*/
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
/*
===========================================================================================================
                                ##### Initialization of LCD #####
===========================================================================================================
*/
void LCD_vidInit(void)
{
	/*Setting the directions of LCD ports */

	Dio_vidSetPortDirection(LCD_DATA_Port, PORT_OUTPUT);
	Dio_vidSetPinDirection(LCD_Control_Port, LCD_RS_PIN, OUTPUT);
	Dio_vidSetPinDirection(LCD_Control_Port, LCD_RW_PIN, OUTPUT);
	Dio_vidSetPinDirection(LCD_Control_Port, LCD_EN_PIN, OUTPUT);

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
  LCD_vidSendCommand(0b00001100);

  //Function Set
  //(DL => 1)  8-bit bus mode
  //(N  => 1)  2 line display mode
  //(F  => 0)  5x8 dots format
  LCD_vidSendCommand(0b00111000);
}
/*
===========================================================================================================
                                ##### Writing a Sentence on LCD #####
===========================================================================================================
*/
void LCD_vidWriteSentence(u8* string)
{
 u8 index=0;
 while (string[index]!='\0')
 {
	 LCD_vidWriteCharachter(string[index]);
     index ++;
 }
}
/*
===========================================================================================================
                                ##### Printing the pressed Key on LCD as a word #####
===========================================================================================================
* This function is used when using KeyPad 4X4 with LCD 2x16
* It used to print the pressed Key as a word on LCD
* The entered key must be with in range (1->16)
*/
void  LCD_KPD_vidPrintPressedKey(u8 key) {

  u8 K1[]="K1",K2[]="K2",K3[]="K3",K4[]="K4",K5[]="K5",K6[]="K6";
  u8 K7[]="K7",K8[]="K8",K9[]="K9",K10[]="K10",K11[]="K11";
  u8 K12[]="K12",K13[]="K13",K14[]="K14",K15[]="K15",K16[]="K16";
  u8 Error[]="Error";

	if ((key >=1) && (key <= 16)) {

		switch (key) {
		case 1:
			LCD_vidSendCommand(1);       //Clear Display
			LCD_vidWriteSentence(K1);
			break;
		case 2:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K2);
			break;
		case 3:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K3);
			break;
		case 4:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K4);
			break;
		case 5:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K5);
			break;
		case 6:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K6);
			break;
		case 7:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K7);
			break;
		case 8:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K8);
			break;
		case 9:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K9);
			break;
		case 10:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K10);
			break;
		case 11:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K11);
			break;
		case 12:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K12);
			break;
		case 13:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K13);
			break;
		case 14:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K14);
			break;
		case 15:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K15);
			break;
		case 16:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(K16);
			break;
		default:
			LCD_vidSendCommand(1);
			LCD_vidWriteSentence(Error);
		}
	}
	else{
//		LCD_vidSendCommand(1);
//		LCD_vidWriteSentence("Not Pressed");
	}
}

/*
===========================================================================================================
                                      ##### Printing numbers on LCD #####
===========================================================================================================
This function is used to print numbers on the LCD
The Entered number must be in range of (0 -> 4294967295)
*/
void LCD_vidPrintNumbers(u32 number)
{
	u8 result[10];
	u8 digit=0;
	u8 count=0;
do{
	//Getting the first number of the entered numbers (from the right)
	//and save it in the first element of the array
	result[digit]=number%10;
	//reducing the number
	number=number/10;
	digit++;
}while(number!=0);  // Repeat until the last number

//After ending the loop the value of i has the number of digits of the entered number

 for(count=0,digit--;count<=digit;count++)
 {
	 //Printing the result array from last element to the first.
	 //As the last number entered the first element
	LCD_vidWriteCharachter('0'+result[digit-count]);
 }

}
