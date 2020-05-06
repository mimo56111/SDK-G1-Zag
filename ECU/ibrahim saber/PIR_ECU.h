/*
 * PIR_ECU.h
 *
 * Created: 4/24/2020 9:27:41 PM
 *  Author: ibrahim
 */ 

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#include "stdmacros.h"

#ifndef PIR_ECU_H_
#define PIR_ECU_H_



/*
* FUNCTION name         : PIR_vINIT
* FUNCTION return       : void
* FUNCTION arguments    : unsigned char portnum  ,unsigned char pinnum
* FUNCTION description  : initialize the button as input pin
*/

void PIR_vINIT(u8 portnum,u8 pinnum);


/*
* FUNCTION name         : PIR_u8read
* FUNCTION return       : unsigned char
* FUNCTION arguments    : unsigned char portnum  ,unsigned char pinnum
* FUNCTION description  : reading the state of the button
*/

u8 PIR_u8read(u8 portnum,u8 pinnum);

#endif /* PIR_ECU_H_ */