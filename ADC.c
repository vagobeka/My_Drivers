/*
 * ADC Driver for AVR Atmega32
 *
 *  Created on: Feb 18, 2017
 *      Author: Vagobeka
 */

#include "Types.h"
#include "ADC.h"
#include "util/delay.h"

/*
===========================================================================================================
                                ##### Building the registers of ADC #####
===========================================================================================================
*/
#define ADMUX    (*(volatile u8*)(0x27))
#define ADCSRA   (*(volatile u8*)(0x26))
#define ADCH     (*(volatile u8*)(0x25))
#define ADCL     (*(volatile u8*)(0x24))
#define SFIOR    (*(volatile u8*)(0x50))

#define ADSC      6
#define ADIF      4
/*
===========================================================================================================
                                ##### ADC 8 bits resolution Initialization #####
===========================================================================================================
*/
void ADC8Bit_vidInit(void)
{
   //Internal AVcc is on (5 Volts),External AREF turned off.
   //ADLAR=1    ->  Left Adjusted
   //Channel(0) ->(ADC0)
   ADMUX=0x60;

   //Enable ADC.
   //Start Conversion is OFF.Enabling it at the beginning of conversion to reduce power consumption
   //Enable Auto Trigger.
   //Prescaler -> divide CLK by 128
   ADCSRA=0xA7;

   //Free Running mode
   SFIOR=0x00;
}
/*
===========================================================================================================
                                ##### ADC 10 bits resolution Initialization #####
===========================================================================================================
*/
void ADC10Bit_vidInit(void)
{
   //Internal AVcc is on (5 Volts),External AREF turned off.
   //ADLAR=0    ->  Right Adjusted
   //Channel(0) ->(ADC0)
   ADMUX=0x40;

   //Enable ADC.
   //Start Conversion is OFF.Enabling it at the beginning of conversion to reduce power consumption
   //Enable Auto Trigger.
   //Prescaler -> divide CLK by 128
   ADCSRA=0xA7;

   //Free Running mode
   SFIOR=0x00;
}
/*
===========================================================================================================
                                ##### ADC 8 bits resolution Start Conversion #####
===========================================================================================================
*/
u8 ADC8Bit_u8StartConversion(u8 channel)
{
	//Clear the first 5 bits of the ADMUX register to start write the desired channel on them
	ADMUX &= 0xE0;
	//Setting the desired channel From (0 to 7)
	ADMUX |= channel;
    _delay_us(10);
    //Start conversion by setting the ADSC bit
    ADCSRA |= (1<<ADSC);
    //Wait until conversion complete -> (ADIF=1)
    while((ADCSRA &(1<<ADIF))==0);
    //Clear the ADIF bit by writing 1 on it
    ADCSRA |= (1<<ADIF);
    //Return the converted data from ADCH to a 8 bit variable
    //After reading the data from the ADCH it will automatically cleared from the registers
    return (ADCH); // The returned value is in range of(0 -> 255)
}
/*
===========================================================================================================
                                ##### ADC 10 bits resolution Start Conversion #####
===========================================================================================================
*/
u16 ADC10Bit_u16StartConversion(u8 channel)
{
	u16 temp_L;
	u16 temp_H;
	u16 value;

	//Clear the first 5 bits of the ADMUX register to start write the desired channel on them
	ADMUX &= 0xE0;
	//Setting the desired channel From (0 to 7)
	ADMUX |= channel;
    _delay_us(10);
    //Start conversion by setting the ADSC bit
    ADCSRA |= (1<<ADSC);
    //Wait until conversion complete -> (ADIF=1)
    while((ADCSRA &(1<<ADIF))==0);
    //Clear the ADIF bit by writing 1 on it
    ADCSRA |= (1<<ADIF);

    //Reading the data from the ADCL to temp_L
    temp_L = ADCL & 0x00FF;   //(&0x00FF)is for more protection to make sure that the other bits are cleared
    //Reading the data from the ADCH to temp_H
    temp_H = ADCH & 0x00FF;
    //ADCL must be read before ADCH
    //After reading the data from the ADCH it will automatically cleared from the registers

    value=(temp_H<<8)|(temp_L);

    return (value); // The returned value is in range of(0 -> 1023)
}
