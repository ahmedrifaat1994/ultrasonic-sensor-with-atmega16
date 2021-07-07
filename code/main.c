
/*
 * main.c
 *
 *  Created on: 3 Jun 2021
 *      Author: A.Rifaat
 */

#define F_CPU 8000000UL

#include "lcd.h"
#include "icu.h"
#include "ultrasonic.h"

extern int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void main(){
	uint16 signalTime = 0;
	double distance = 0;
	char buffer[16];
	long count;

	LCD_init();
	ICU_init();
	Sonic_init();
	LCD_displayString("Dis = ");

	while(1){
		Sonic_sendSignal(); /*send trigger signal*/
		signalTime = ICU_captureSignal(); /*capture the signal*/
		count = signalTime + (65535 * TimerOverflow); /*count the time of the signal*/
		distance = ((double)count / 466.47) + 1; /*count the distance*/
		
		itoa(distance,buffer,10); /*convert integer to string*/
		LCD_displayStringRowColumn(0, 6, buffer); /*Display distance on screen*/
		LCD_displayString(" cm"); /*Display "cm" on screen*/
		_delay_ms(200);

	}
}
