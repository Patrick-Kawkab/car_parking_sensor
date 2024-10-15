/*
 * BUZZER.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include"BUZZER.h"
/*
 * Description :
 * Initializes the buzzer pin direction and turn off the buzzer
 */
void Buzzer_init(void)
{
	GPIO_setupPinDirection(Buzzer_PORT_ID,Buzzer_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_LOW);
}
/*
 * Description :
 * Activates the buzzer.
 */
void Buzzer_on(void)
{
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_HIGH);
}
/*
 * Description :
 * Deactivates the buzzer.
 */
void Buzzer_off(void)
{
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_LOW);
}
