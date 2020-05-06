#include "KeyPad_ECU.h"

void keypad_vInit(u8 port){
	
	   GPIO_vsetPORT_Dir(port,0x0f);
	   GPIO_vconnectpullup(port, 4, 1);
	   GPIO_vconnectpullup(port, 5, 1);
	   GPIO_vconnectpullup(port, 6, 1);
	   GPIO_vconnectpullup(port, 7, 1);
}

u8 keypad_u8check_press(u8 port){
	
//	u8 arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}; //real 4*4 keypad
    u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}; //proteus 4*4 keypad
	u8 row ,coloumn, x,y=0;
	u8 returnval = NOTPRESSED;	
	for (row = 0; row < 4; row++){
		GPIO_vwrite_PIN(port,0,1);
		GPIO_vwrite_PIN(port,1,1);
		GPIO_vwrite_PIN(port,2,1);
		GPIO_vwrite_PIN(port,3,1);
		GPIO_vwrite_PIN(port,row,0);
		    
			for (coloumn = 0; coloumn < 4; coloumn++){
				x = GPIO_u8read_PIN(port,(coloumn+4));
				if (0 == x && y==0){
					returnval = arr[row][coloumn];
					y=1;
				}else{
					y=0;
					x=1;
				}
				
			}
		if (0 == x){
			break;
		}
	}
		return returnval ;
}