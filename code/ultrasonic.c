/*
 * ultrasonic.c
 *
 *  Created on: 3 Jun 2021
 *      Author: A.Rifaat
 */

#include"ultrasonic.h"

void Sonic_init(void){
	DECLARE_TRIGGER;
	DECLARE_ECCO;
}

void Sonic_sendSignal(void){
	TRIGGER(ON);
	_delay_us(10);
	TRIGGER(OFF);
}

void Sonic_receiveSignal(void){

}
