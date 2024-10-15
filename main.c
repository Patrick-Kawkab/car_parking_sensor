/*
 * main.c
 *
 *  Created on: Oct 10, 2024
 *      Author: kawka
 */
#include"std_types.h"
#include"Ultrasonic.h"
#include"lcd.h"
#include"BUZZER.h"
#include"led.h"
#include <util/delay.h>

int main(void){
	LCD_init();
	Ultrasonic_init();
	LEDS_init();
	Buzzer_init();
	while(1)
	{
		uint8 distance=Ultrasonic_readDistance();//storing distance in a variable
		LCD_displayStringRowColumn(0,0,"distance =");
		LCD_displayStringRowColumn(1,5,"     ");
		while(distance==1)//to fix the bug when the code first runs
		{
			distance=Ultrasonic_readDistance();
		}
		if (distance>=10)//display distance value
		{
			LCD_moveCursor(0,11);
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_moveCursor(0,11);
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		LCD_displayString("cm  ");
		/*in every condition the code behaves in the required way*/
		if(distance>20)
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();
		}
		else if(distance<=20&&distance>15)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();
		}
		else if(distance<=15&&distance>10)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();

		}
		else if(distance<=10&&distance>5)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			Buzzer_off();
		}
		else if(distance<=5){
			while(distance<=5)
			{
				distance=Ultrasonic_readDistance();
				LCD_moveCursor(0,11);
				LCD_intgerToString(distance);
				LED_on(RED_LED);
				LED_on(GREEN_LED);
				LED_on(BLUE_LED);
				Buzzer_on();
				_delay_ms(200);
				LED_off(RED_LED);
				LED_off(GREEN_LED);
				LED_off(BLUE_LED);
				Buzzer_off();
				_delay_ms(200);
				LCD_displayStringRowColumn(1,5,"STOP ");
			}
		}

	}

}

