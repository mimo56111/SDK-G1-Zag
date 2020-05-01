/*
 * SEVEN_SEGMENT_ECU
 *
 * Created: 4/12/2020 3:16:04 AM
 *  Author: IBRAHIM SABER
 * 
 */ 

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#define EIGHT_BIT   1
#define FOUR_BIT    0
#define HIGH_NIBBLE 1
#define LOW_NIBBLE  0

#ifndef SEVEN_SEGMENT_ECU_H_
#define SEVEN_SEGMENT_ECU_H_
 
 
/*
FUNCTION name          :SEVEN_SEGMENT_vINIT
FUNCTION description   :initialize the 7-segment as OUTPUT
FUNCTION arguments     :unsigned char port ,unsigned char mode ,unsigned char nibble
FUNCTION return        :void 
*/

void SEVEN_SEGMENT_vINIT(u8 port, u8 mode ,u8 nibble );

/*
FUNCTION name          :SEVEN_SEGMENT_vDISPLAY
FUNCTION description   :display a value on the 7-segment
FUNCTION arguments     :unsigned char port ,unsigned char mode ,unsigned char nibble,unsigned char value
FUNCTION return        :void
*/


void SEVEN_SEGMENT_vDISPLAY(u8 port, u8 mode ,u8 nibble, u8 value );



#endif /* SEVEN_SEGMENT_ECU_H_ */