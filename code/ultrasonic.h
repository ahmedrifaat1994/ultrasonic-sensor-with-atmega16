/*
 * ultrasonic.h
 *
 *  Created on: 3 Jun 2021
 *      Author: A.Rifaat
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"


#define DECLARE_TRIGGER (DDRA = 0x01)
#define TRIGGER(STATE) (PORTA = STATE)

#define DECLARE_ECCO (DDRD = 0x00)
#define ECOO PIND

#define ON 1
#define OFF 0

void Sonic_init(void);
void Sonic_sendSignal(void);
void Sonic_receiveSignal(void);

#endif /* ULTRASONIC_H_ */
