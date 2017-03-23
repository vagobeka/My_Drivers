/*
 * Timers Driver for AVR Atmega32
 *
 * CLOCK is 16 MHz
 *  Created on: Feb 25, 2017
 *      Author: Vagobeka
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Types.h"
#include "Macros.h"
#include "avr/interrupt.h"
/*
 ===========================================================================================================
                                        ##### TIMER 0 #####
 ===========================================================================================================
 */
/*####################################### Timer 0 Prescaler Configuration  #################################*/
#define  TIMER0_No_prescaling      0x01
#define  TIMER0_PRESCALER_8        0x02
#define  TIMER0_PRESCALER_64       0x03
#define  TIMER0_PRESCALER_256      0x04
#define  TIMER0_PRESCALER_1024     0x05

#define  TIMER0_PRESCALER          TIMER0_PRESCALER_64
/*##########################################################################################################*/

void TIMER0_vidInit(void);
void TIMER0_vidNoOfCountsPerFlag(u8 counts);
void TIMER0_vidNoOfFlags(u16 flags);
void TIMER0_vidStart();
void TIMER0_vidStop();
void TIMER0_vidSetCallback(void (*func)(void));
/*Never use TIMER0_Delay_ms Function when using the timer.*/
void TIMER0_Delay_ms(u16 ms);

#endif /* TIMER_H_ */
