/*
*Button_ECU.h
*It has function used in initialize and read the button
*It is in ECU abstraction layer
*/

#include "GPIO_MCAL.h"

#ifndef BUTTON_ECU_H_
#define BUTTON_ECU_H_

/*
Function Name        : Button_vInit
Function Returns     : void
Function Arguments   : unsigned char port name , unsigned char pin number
Function Description : Initialize the pin as input pin to connect the button
*/

   void Button_vInit(u8 port, u8 pin);
 

 /*
 Function Name        : Button_u8Read
 Function Returns     : unsigned char
 Function Arguments   : unsigned char port name , unsigned char pin number
 Function Description : Read the pin which the button connected with it
 */
   u8 Button_u8Read(u8 port, u8 pin);

#endif /* BUTTON_ECU_H_ */