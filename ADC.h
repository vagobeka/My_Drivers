/*
 * ADC Driver for AVR Atmega32
 *
 *  Created on: Feb 18, 2017
 *      Author: Vagobeka
 */

#ifndef ADC_H_
#define ADC_H_
#include "Types.h"

void ADC8Bit_vidInit(void);
void ADC10Bit_vidInit(void);

u8 ADC8Bit_u8StartConversion(u8 channel);
u16 ADC10Bit_u16StartConversion(u8 channel);

#endif /* ADC_H_ */
