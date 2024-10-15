/*
 * Ultrasonic.c
 *
 *  Created on: Oct 10, 2024
 *      Author: kawka
 */
#include"icu.h"
#include"Ultrasonic.h"
#include <util/delay.h>
#include <avr/io.h> /* To use the SREG register */
uint8 echo_edgeCount = 0;
uint16 Timer_Value = 0;
void Ultrasonic_init(void)
{
	ICU_ConfigType ICU_UltraSonic_Configurations = {F_CPU_8,RAISING};//setting icu configurations
	ICU_init(&ICU_UltraSonic_Configurations);//sending struct address to take it in a pointer
	ICU_setCallBack(Ultrasonic_edgeProcessing);//setting call back function
	SREG |= (1<<7);/*enables Interrupt*/
	/*setup trigger pin as output pin and puts logic low on it*/
	GPIO_setupPinDirection(senor_portID,trig_pinID,PIN_OUTPUT);
	GPIO_writePin(senor_portID,trig_pinID,LOGIC_LOW);

}
void Ultrasonic_Trigger(void)
{
	/*sending a trigger for 10 us to let the sensor send 8 pulses of 40 khz*/
	GPIO_writePin(senor_portID,trig_pinID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(senor_portID,trig_pinID,LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;
	Ultrasonic_Trigger();
	distance = (Timer_Value/ 117.6)+1 ;
	return distance;
}
void Ultrasonic_edgeProcessing(void)
{
	echo_edgeCount++;
	if(echo_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(echo_edgeCount == 2)
	{
		/*captures time measured by icu*/
		Timer_Value=ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		/*resets edge count*/
		echo_edgeCount =0;
	}
}
