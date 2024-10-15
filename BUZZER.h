/*
 * BUZZER.h
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include"gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Buzzer_PORT_ID 	PORTC_ID
#define Buzzer_PIN_ID 	PIN5_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initializes the buzzer pin direction and turn off the buzzer
 */
void Buzzer_init(void);
/*
 * Description :
 * Activates the buzzer.
 */
void Buzzer_on(void);
/*
 * Description :
 * Deactivates the buzzer.
 */
void Buzzer_off(void);



#endif /* BUZZER_H_ */
