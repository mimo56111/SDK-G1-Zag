/*
 * led driver 
 * ECU abstraction layer
 * turning on and turning off a led 

*/

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"

#ifndef LED_DRIVER_ECU_H_
#define LED_DRIVER_ECU_H_

/*
 
 *FUNCTION name        : LED_vINIT
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : initialization the led as output pin 
*/

void LED_vINIT(u8 portnum,u8 pinnum);

/*
 
 *FUNCTION name        : LED_ON
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : turning on a led
*/

void LED_ON(u8 portnum,u8 pinnum);

/*
 *FUNCTION name        : LED_OFF
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : turning off a led
*/

void LED_OFF(u8 portnum,u8 pinnum);

/*
 
 *FUNCTION name        : LED_TOGGLE
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : toggling a led 
*/

void LED_TOGGLE(u8 portnum,u8 pinnum);

#endif 
