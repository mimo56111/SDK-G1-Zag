#define u8_direction_input 0x00
#define default_direction u8_direction_input
#define connected 1
#define notconnected 0
#include "GPIO_MCAL.h"

//*-----INITIALIZATION-----*
void GPIO_INIT(void){
	XDDRA= default_direction;
	XDDRB= default_direction;
	XDDRC= default_direction;
	XDDRD= default_direction;
}

//*-----PIN-------*

void GPIO_SETPIN_DIR(u8 port,u8 pinnum,u8 dir){
	switch(port){
		case 'A':
		case 'a':
			if(dir==1){
				SET_BIT(XDDRA,pinnum);
			}
			else{
				RESET_BIT(XDDRA,pinnum);
			
			}
			break;
		case 'B':
		case 'b':
			if(dir==1){
				SET_BIT(XDDRB,pinnum);
			}else{
				RESET_BIT(XDDRB,pinnum);
			}
			break;
		case 'C':
		case 'c':
			if(dir==1){
				SET_BIT(XDDRC,pinnum);
			}else{
				RESET_BIT(XDDRC,pinnum);
			}
			break;
		case 'D':
		case 'd':
			if(dir==1){
				SET_BIT(XDDRD,pinnum);
			}else{
				RESET_BIT(XDDRD,pinnum);
			}
			break;
		default: break;
	
	}		
	
}
void GPIO_WRITE_PIN(u8 port,u8 pinnum,u8 val){
	switch(port){
		case 'A':
		case 'a':
		if(val==1){
			SET_BIT(XPORTA,pinnum);
		}
		else{
			RESET_BIT(XPORTA,pinnum);
			
		}
		break;
		case 'B':
		case 'b':
		if(val==1){
			SET_BIT(XPORTB,pinnum);
		}else{
			RESET_BIT(XPORTB,pinnum);
		}
		break;
		case 'C':
		case 'c':
		if(val==1){
			SET_BIT(XPORTC,pinnum);
		}else{
			RESET_BIT(XPORTC,pinnum);
		}
		break;
		case 'D':
		case 'd':
		if(val==1){
			SET_BIT(XPORTD,pinnum);
		}else{
			RESET_BIT(XPORTD,pinnum);
		}
		break;
		default: break;
		
	}
	
	
	}
u8 GPIO_READ_PIN(u8 port,u8 pinnum){
	u8 x=0;
	switch(port){
		case 'A':
		case 'a':
			x=READ_BIT(XPINA,pinnum);
			break;
		case 'B':
		case 'b':
			x=READ_BIT(XPINB,pinnum);
			break;
		case 'C':
		case 'c':
			x=READ_BIT(XPINB,pinnum);
			break;
		case 'D':
		case 'd':
			x=READ_BIT(XPIND,pinnum);
			break;	
			default: break;
					
	}
	return x;
}

void GPIO_TOGGLE_PIN(u8 port,u8 pinnum){
	switch(port){
		case 'A':
		case 'a':
		TOGGLE_BIT(XPORTA,pinnum);
		break;
		case 'B':
		case 'b':
		TOGGLE_BIT(XPORTB,pinnum);
		break;
		case 'C':
		case 'c':
		TOGGLE_BIT(XPORTB,pinnum);
		break;
		case 'D':
		case 'd':
		TOGGLE_BIT(XPORTD,pinnum);
		break;
		default: break;
	}		
}

void GPIO_CONNECT_PULLUP(u8 port,u8 pinnum,u8 pullup_state){
	switch(port){
		case 'A':
		case 'a':
		if(connect==pullup_state){
			SET_BIT(XPORTA,pinnum);
			RESET_BIT(XSFIOR,PUD);
		}
		else{
			RESET_BIT(XPORTA,pinnum);
			
		}
		break;
		case 'B':
		case 'b':
		if(connect==pullup_state){
			SET_BIT(XPORTB,pinnum);
			RESET_BIT(XSFIOR,PUD);
		}
		else{
			RESET_BIT(XPORTB,pinnum);
			
		}
		break;
		case 'C':
		case 'c':
		if(connect==pullup_state){
			SET_BIT(XPORTC,pinnum);
			RESET_BIT(XSFIOR,PUD);
		}
		else{
			RESET_BIT(XPORTC,pinnum);
			
		}
		break;
		case 'D':
		case 'd':
		if(connect==pullup_state){
			SET_BIT(XPORTD,pinnum);
			RESET_BIT(XSFIOR,PUD);
		}
		else{
			RESET_BIT(XPORTD,pinnum);
			
		}
		break;
		default: break;
		
	}
}

//**********************PORT********************
void GPIO_SETPORT_DIR(u8 port,u8 dir){
	
	switch(port){
		case 'A':
		case 'a':
			XDDRA=dir;
		break;
		case 'B':
		case 'b':
			XDDRB=dir;
		break;
		case 'C':
		case 'c':
			XDDRC=dir;
		break;
		case 'D':
		case 'd':
			XDDRD=dir;
		break;
		default: break;
		}
	
	
		
}

void GPIO_WRITE_PORT(u8 port,u8 val){
	switch(port){
		case 'A':
		case 'a':
			XPORTA=val;
			break;
		case 'B':
		case 'b':
			XPORTB=val;
			break;
		case 'C':
		case 'c':
			XPORTC=val;
			break;
		case 'D':
		case 'd':
			XPORTD=val;
			break;
		default: break;
		
}	

u8 GPIO_READ_PORT(u8 port){
	u8 y=0;
	switch(port){
		case 'A':
		case 'a':
			y=XPINA;
			break;
		case 'B':
		case 'b':
			y=XPINB;
			break;
		case 'C':
		case 'c':
			y=XPINC;
			break;
		case 'D':
		case 'd':
			y=XPIND;
			break;
		default: break;
		
	}
	return y;	
}

void GPIO_TOGGLE_PORT(u8 port){
		
		switch(port){
			case 'A':
			case 'a':
				XPORTA = ~XPORTA;
				break;
			case 'B':
			case 'b':
				XPORTB = ~XPORTB;
				break;
			case 'C':
			case 'c':
				XPORTC = ~XPORTC;
				break;
			case 'D':
			case 'd':
				XPORTD = ~XPORTD;
				break;
			default: break;
		}
					
}}

//HIGH NIBBLE
void GPIO_HIGH_NIBBLE_SETDIR(u8 port,u8 dir){
	if(dir==1){
		GPIO_SETPIN_DIR(port,4,1);
		GPIO_SETPIN_DIR(port,5,1);
		GPIO_SETPIN_DIR(port,6,1);
		GPIO_SETPIN_DIR(port,7,1);
	}else{
		GPIO_SETPIN_DIR(port,4,0);
		GPIO_SETPIN_DIR(port,5,0);
		GPIO_SETPIN_DIR(port,6,0);
		GPIO_SETPIN_DIR(port,7,0);
	}
}
void GPIO_HIGH_NIBBLE_WRITE(u8 port,u8 value){
	value <<=4;
	switch(port){
		case'A':
		case'a':
			XPORTA &=0x0f;
			XPORTA |=value;
			break;
		case'B':
		case'b':
			XPORTB &=0x0f;
			XPORTB |=value;	
			break;
		case'C':
		case'c':
			XPORTC &=0x0f;
			XPORTC|=value;
			break;
		case'D':
		case'd':
			XPORTD&=0x0f;
			XPORTD |=value;
			break;
		default: break;
					
	}	
	
	
}
//LOW NIBBLE
void GPIO_LOW_NIBBLE_SETDIR(u8 port,u8 dir){
	if(dir==1){
		GPIO_SETPIN_DIR(port,0,1);
		GPIO_SETPIN_DIR(port,1,1);
		GPIO_SETPIN_DIR(port,2,1);
		GPIO_SETPIN_DIR(port,3,1);
	}else{
		GPIO_SETPIN_DIR(port,0,0);
		GPIO_SETPIN_DIR(port,1,0);
		GPIO_SETPIN_DIR(port,2,0);
		GPIO_SETPIN_DIR(port,3,0);
	}	
}
void GPIO_LOW_NIBBLE_WRITE(u8 port,u8 value){
	value &=0x0f;
	switch(port){
		case'A':
		case'a':
			XPORTA &=0xf0;
			XPORTA |=value;
			break;
		case'B':
		case'b':
			XPORTB &=0xf0;
			XPORTB |=value;
			break;
		case'C':
		case'c':
			XPORTC &=0xf0;
			XPORTC|=value;
			break;
		case'D':
		case'd':
			XPORTD&=0xf0;
			XPORTD |=value;
			break;
		default: break;
	}	
}