/*
 * icu.c
 *
 *  Created on: 3 Jun 2021
 *      Author: A.Rifaat
 */

#include"icu.h"

void ICU_init(void){
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
	TCCR1B |= (1<<ICES1) | (1<<CS10);
	TCNT1 = 0;
	TIMSK = (1 << TOIE1);
}

uint16 ICU_captureSignal(void){
	SET_BIT(TIFR ,ICF1);
	SET_BIT(TIFR ,TOV1);
	TCCR1B |= (1<<ICES1);
	while(BIT_IS_CLEAR(TIFR,ICF1));
	TCNT1 = 0;
	TCCR1B &= ~(1<<ICES1);
	SET_BIT(TIFR,ICF1);
	SET_BIT(TIFR ,TOV1);
	TimerOverflow = 0;
	while(BIT_IS_CLEAR(TIFR,ICF1));
	SET_BIT(TIFR,ICF1);
	return ICR1;
}
