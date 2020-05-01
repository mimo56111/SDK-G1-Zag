/*
* BUTTON DRIVER
* ECU abstraction layer
* reading the state of a button 
*/

#include "GPIO_MCAL.h"
#ifndef BUTTON_DRIVER_ECU_H_
#define BUTTON_DRIVER_ECU_H_


/*
* FUNCTION name         : BUTTON_vINIT
* FUNCTION return       : void
* FUNCTION arguments    : unsigned char portnum  ,unsigned char pinnum
* FUNCTION description  : initialize the button as input pin
*/

void BUTTON_vINIT(u8 portnum,u8 pinnum);


/*
* FUNCTION name         : BUTTON_u8read
* FUNCTION return       : unsigned char 
* FUNCTION arguments    : unsigned char portnum  ,unsigned char pinnum
* FUNCTION description  : reading the state of the button 
*/

u8 BUTTON_u8read(u8 portnum,u8 pinnum);


#endif