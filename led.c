/*
 * led.c
 *
 *  Created on: Oct 5, 2024
 *      Author: kawka
 */
#include "led.h"
/*
 * Description :
 * Initialize the LEDS:
 * 1. Setup the LEDS pins directions by use the GPIO driver.
 * 2. Setup the LEDS to be logic low at the first
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_PORT,RED_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT,GREEN_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT,BLUE_LED,PIN_OUTPUT);
	GPIO_writePin(LED_PORT,RED_LED,LOGIC_LOW);
	GPIO_writePin(LED_PORT,GREEN_LED,LOGIC_LOW);
	GPIO_writePin(LED_PORT,BLUE_LED,LOGIC_LOW);
}
/*
 * Description :
 * Turns on the required LED with it's ID using GPIO driver
 */
void LED_on(uint8 LED_ID)
{
	GPIO_writePin(LED_PORT,LED_ID,LOGIC_HIGH);
}
/*
 * Description :
 * Turns off the required LED with it's ID using GPIO driver
 */
void LED_off(uint8 LED_ID)
{
	GPIO_writePin(LED_PORT,LED_ID,LOGIC_LOW);
}
