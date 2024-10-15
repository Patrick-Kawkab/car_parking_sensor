/*
 * Ultrasonic.h
 *
 *  Created on: Oct 10, 2024
 *      Author: kawka
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include"gpio.h"
#include"std_types.h"
#define senor_portID	PORTD_ID
#define trig_pinID		PIN7_ID
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
