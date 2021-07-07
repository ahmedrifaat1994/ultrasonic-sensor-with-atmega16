/*
 * icu.h
 *
 *  Created on: 3 Jun 2021
 *      Author: A.Rifaat
 */

#ifndef ICU_H_
#define ICU_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

extern int TimerOverflow;

void ICU_init(void);
uint16 ICU_captureSignal(void);

#endif /* ICU_H_ */
