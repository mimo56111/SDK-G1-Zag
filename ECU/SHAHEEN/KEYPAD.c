/*
 * KEYPAD.c
 *
 * Created: 4/16/2020 12:37:53 AM
 *  Author: Shaheen
 */
#include "KEYPAD.h"
void KEYPAD_INIT(u8 port){
									
									GPIO_SETPORT_DIR(port,0x0f);
									GPIO_CONNECT_PULLUP(port,4,1);
									GPIO_CONNECT_PULLUP(port,5,1);
									GPIO_CONNECT_PULLUP(port,6,1);
									GPIO_CONNECT_PULLUP(port,7,1);
}
u8 KEYPAD_CKECK_PRESS(u8 port){
//u8 arr[4][4]={{'1','2','3','+'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};  //real 4*4 keypad
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};  //proteus 4*4 keypad
	u8 row, coloumn, x;
	u8 returnval = NOTPRESSED;
	for (row = 0; row < 4; row++){									
		GPIO_WRITE_PIN(port,0,1);								
		GPIO_WRITE_PIN(port,1,1);
		GPIO_WRITE_PIN(port,2,1);
		GPIO_WRITE_PIN(port,3,1);
		GPIO_WRITE_PIN(port,row,0);
		
			for (coloumn=0; coloumn < 4; coloumn++){
				x=GPIO_READ_PIN(port,(coloumn+4));
				if(0==x){
					returnval = arr[row][coloumn];
					break;
				}
			}
		if(0==x){
			break;
		}
	}	
	return returnval;
}