

#include "GPIO_MCAL.h"
#define Four_Bit 0
#define Eight_Bit 1
#define High_Nibble 1
#define Low_Nibble 0



#ifndef SEVEN_SEGMENT_ECU_H_
#define SEVEN_SEGMENT_ECU_H_

/*
Function name        : Seven_Segment_Init
Function return      : void
Function Arguments   : unsigned char port mode , unsigned char port name , unsigned char Nibble
Function Description : Define pins as output
*/
void Seven_Segment_Init(u8 mode, u8 port, u8 Nibble);

/*
Function name        : Seven_Segment_Display
Function return      : void
Function Arguments   : unsigned char port mode , unsigned char port name , unsigned char Nibble , unsigned char value
Function Description : Display
*/
void Seven_Segment_Display(u8 mode, u8 port , u8 Nibble, u8 value);








#endif /* SEVEN_SEGMENT_ECU_H_ */