
#ifndef KEYPAD_ECU_H_
#define KEYPAD_ECU_H_

#include "Data_type.h"
#include "GPIO_MCAL.h"
#include "Register.h"
#define NOTPRESSED  0xff 


/*
	Function Name        : keypad_vInit
	Function Returns     : void
	Function Arguments   : unsigned char port which connect the keypad 
    Function Description : Initialize the keypad to work on a specific port  
*/
	void keypad_vInit(u8 port);
	
/*
	Function Name        : keypad_u8check_press
	Function Returns     : unsigned char 
	Function Arguments   : unsigned char port which connect the keypad
    Function Description : Check which button from the keypad is pressed and returns its ASCII code  
*/
	u8 keypad_u8check_press(u8 port);


#endif /* KEYPAD_ECU_H_ */