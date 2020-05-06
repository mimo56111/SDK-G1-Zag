/*
 * keypad_ecu.c
 *
 * Created: 4/23/2020 5:06:57 AM
 *  Author: ibrahim
 */ 

#include "keypad_ECU.h"
#define NOTPRESSED 0xff

void keypad_vINIT(u8 portnum){
	GPIO_vSETPORT_DIR(portnum,0x0F);
	GPIO_vSETPIN_DIR(portnum,4,0);
	GPIO_vSETPIN_DIR(portnum,5,0);
	GPIO_vSETPIN_DIR(portnum,6,0);
	GPIO_vSETPIN_DIR(portnum,7,0);
	GPIO_vconnect_pull_up(portnum,4,CONNECT);
	GPIO_vconnect_pull_up(portnum,5,CONNECT);
	GPIO_vconnect_pull_up(portnum,6,CONNECT);
	GPIO_vconnect_pull_up(portnum,7,CONNECT);
}


u8 keypad_keypressed(u8 portnum){
	u8 array[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}} ;// proteus keypad
	
	// u8 array[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
	u8 row;
	u8  coloum,X;
	u8 returnval =NOTPRESSED;	
	for (row=0;row<4;row++){
		GPIO_vwrite_PIN(portnum,0,1);
		GPIO_vwrite_PIN(portnum,1,1);
		GPIO_vwrite_PIN(portnum,2,1);
		GPIO_vwrite_PIN(portnum,3,1);
		GPIO_vwrite_PIN(portnum,row,0);
		
		for(coloum=0;coloum<4;coloum++){
			X=GPIO_u8read_PIN(portnum,(coloum+4));
			if(X==0){
			returnval=array[row][coloum];
			break;
			}			
		}
			
		if(X==0){
			
			break;
		}
		}		
	
	return returnval;
}