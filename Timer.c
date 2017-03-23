/*
 * Timers Driver for AVR Atmega32
 *
 * CLOCK is 16 MHz
 *
 *  Created on: Feb 25, 2017
 *      Author: Vagobeka
 */

#include "Timer.h"
 /* Define New type of (Pointer to function) called (ptr) */
typedef void (*ptr)(void);
/* (callback) is a pointer to function */
ptr callBack;

u16 NoOfFlags;

/*
 ===========================================================================================================
                                        ##### TIMER 0 #####
 ===========================================================================================================
 */

/*########################################### Timer 0 Initialization #####################################*/
void TIMER0_vidInit(void)
{
	/* Global Interrupt Enable */
	SREG |= (1<<7);

	/* Output Compare Match Interrupt Enable */
	TIMSK = 0x02;

	/* Initialization
	COM0      -> Normal port operation, OC0 disconnected.
	WGM0      -> CTC(Clear Timer on Compare Match),TOP is OCR0
	FOC0      -> OFF
    */
	TCCR0 = 0x08;

}
/*########################################### Starting Timer 0 #############################################

 This function MUST be called after setting up all the parameters of initialization  of the timer,
 because when after just assigning any value to(Bit 2:0 – CS02:0: Clock Select) in the register TCCR0
 the timer starting immediately.
*/
void TIMER0_vidStart()
{

	/*CLK is 16 MHz*/
	/*
	  -> Prescaler is 64
	  -> So that [t=(64/16M)= 4 usec]
	  -> So 250 counts makes 1 msec as [T=250*4usec=1000usec=1msec]
	*/

	/*Clearing the first 3 bits of Timer0 (Bit 2:0 – CS02:0: Clock Select)*/
	TCCR0 &= 0xF8;
	/*Starting Timer0 by setting up the prescaler*/
	TCCR0 |= TIMER0_PRESCALER;
}
/*########################################### Stop Timer 0 ###############################################*/
void TIMER0_vidStop()
{

	/*Stopping the timer0 by Clearing the first 3 bits of TCCR0 (Bit 2:0 – CS02:0: Clock Select)*/
	TCCR0 &= 0xF8;

}
/*######################################## No. Of Counts Per Flag ###########################################
This Function is used to Set the period at which the interrupt of Output Compare Match will occur.
*/
void TIMER0_vidNoOfCountsPerFlag(u8 counts)
{
	//The Value of OCR which I want to make Interrupt at.
	OCR0 = counts;
}

/*############################################ No. Of Flags ################################################
This Function is used to Set the Number of Interrupts which give me the desired time.
*/
void TIMER0_vidNoOfFlags(u16 flags)
{
	NoOfFlags = flags;
}

/*############################################ No. Of Flags ################################################
This Function is used to call a function after the time is up.
The argument is a pointer to function with void return and void arguments.
*/
void TIMER0_vidSetCallback(void (*func)(void))
{
	callBack = func;
}

/*########################################### Delay milliseconds  #########################################
 Never use this Function when using the timer.
*/
void TIMER0_Delay_ms(u16 ms)
{
	u16 flags;

	/*Setting OCR0 to 249 so that it can count 250 counts */

	/*
	  -> CLK is 16 MHz
	  -> Prescaler is 64
	  -> So that [t=(64/16M)= 4 usec]
	  -> So 250 counts makes 1 msec as [T=250*4usec=1000usec=1msec]
	*/

	TIMER0_vidNoOfCountsPerFlag(249);

	/*Starting Timer0*/

	/*
	Prescaler -> 64
	COM0      -> Normal port operation, OC0 disconnected.
	WGM0      -> CTC(Clear Timer on Compare Match)
	FOC0      -> OFF
	*/
	TCCR0 = 0x0B;
	//Number of flags to make the desired time equals (ms)
	for (flags = 0; flags < ms; flags++) {
		while ((TIFR & (1 << OCF0)) == 0);     //Wait For Output Compare Match Flag bit

		//Clear Flag by setting 1
		TIFR |= (1 << OCF0);
	}
	/*Stop Timer0*/
	TCCR0 = 0x00;
}
/*########################################### TIMER0 Compare Match ISR  ########################################*/
ISR(TIMER0_COMP_vect)
{
	static volatile u16 counter = 1;

	if (counter < NoOfFlags) {
		counter++;
	} else {
		counter = 1;
		callBack();

	}
}

