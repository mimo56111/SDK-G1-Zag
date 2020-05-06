/*
 * _7_SEGMENT.h
 *
 * Created: 4/9/2020 12:18:53 AM
 *  Author: Shaheen
 */ 

#include "GPIO_MCAL.h"
#include "Datatypes.h"

#define FOUR_BIT 0
#define EIGHT_BIT 1
#define HIGH_NIBBLE 1
#define LOW_NIBBLE 0

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
void SEVEN_SEGMENT_INIT(u8 mode,u8 port,u8 nibble);//initialize the 7 SEG


void SEVEN_SEGMENT_DISP(u8 mode,u8 port,u8 nibble,u8 value);//print a number on the 7 SEG 




#endif /* 7_SEGMENT_H_ */