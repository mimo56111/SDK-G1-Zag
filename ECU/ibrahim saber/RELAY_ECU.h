/*
 * RELAY_ECU.h
 *
 * Created: 4/24/2020 9:32:26 PM
 *  Author: ibrahim
 */ 

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#ifndef RELAY_ECU_H_
#define RELAY_ECU_H_


/*
 
 *FUNCTION name        : RELAY_vINIT
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : initialization the led as output pin 
*/

void RELAY_vINIT(u8 portnum,u8 pinnum);

/*
 
 *FUNCTION name        : RELAY_ON
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : turning on a led
*/

void RELAY_ON(u8 portnum,u8 pinnum);

/*
 *FUNCTION name        : RELAY_OFF
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : turning off a led
*/

void RELAY_OFF(u8 portnum,u8 pinnum);

/*
 
 *FUNCTION name        : RELAY_TOGGLE
 *FUNCTION return      : void 
 *FUNCTION arguments   : unsigned char portnum , unsigned char pinnum
 *FUNCTION description : toggling a led 
*/

void RELAY_TOGGLE(u8 portnum,u8 pinnum);



#endif /* RELAY_ECU_H_ */