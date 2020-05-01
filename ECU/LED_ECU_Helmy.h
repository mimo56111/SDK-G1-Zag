/*
* LED_ECU.c
* It has functions used in initialize , turn on , turn off , toggle
* It is in ECU abstraction layer
*/

#include "GPIO_MCAL.h"

#ifndef LED_ECU_H_
#define LED_ECU_H_

/*
Function Name        : LED_vInitialize
Function Returns     : void
Function Arguments   : unsigned char port name , unsigned char pin number
Function Description : Initialize the pin as output pin to connect the led
*/
 void LED_vInitialize(u8 port , u8 pin);
 
 /*
 Function Name        : LED_vTurnON
 Function Returns     : void
 Function Arguments   : unsigned char port name , unsigned char pin number
 Function Description : Turn on the led
 */
 void LED_vTurnON(u8 port , u8 pin);
 
 /*
 Function Name        : LED_vTurnOFF
 Function Returns     : void
 Function Arguments   : unsigned char port name , unsigned char pin number
 Function Description : Turn off the led
 */
 void LED_vTurnOFF(u8 port , u8 pin);
 
 /*
 
 Function Name        : LED_vToggle
 Function Returns     : void
 Function Arguments   : unsigned char port name , unsigned char pin number
 Function Description : Toggle the led
 */
 void LED_vToggle(u8 port, u8 pin);
 
#endif /* LED_ECU_H_ */