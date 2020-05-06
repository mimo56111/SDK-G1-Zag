/*
 * KEYPAD.h
 *
 * Created: 4/16/2020 12:36:04 AM
 *  Author: Shaheen
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Datatypes.h"
#include "GPIO_MCAL.h"
#include "Registers.h"
#define NOTPRESSED  0xff

void KEYPAD_INIT(u8 port);//initialize the keypad


u8 KEYPAD_CKECK_PRESS(u8 port);//check if a character is pressed and return it




#endif /* KEYPAD_H_ */