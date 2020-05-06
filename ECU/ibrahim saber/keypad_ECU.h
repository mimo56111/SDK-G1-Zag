/*
 * keypad_ECU.h
 *
 * Created: 4/23/2020 5:04:04 AM
 *  Author: ibrahim
 */ 


#ifndef KEYPAD_ECU_H_
#define KEYPAD_ECU_H_
#include "DATA_TYPE.h"
#include "GPIO_MCAL.h"
#include "REGISTERS.h"



/*
Function name         :keypad_vINIT
Function Description  :initialization the keypad as input
function Arguments    :unsigned char port number
Function Returns      :void
*/
void keypad_vINIT(u8 portnum);

/*
Function name         :keypad_keypressed
Function Description  :checking which button is pressed
function Arguments    :unsigned char port number
Function Returns      :unsigned char value
*/

u8 keypad_keypressed(u8 portnum);





#endif /* KEYPAD_ECU_H_ */