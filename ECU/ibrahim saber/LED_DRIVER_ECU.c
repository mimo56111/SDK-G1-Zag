
#include "GPIO_MCAL.h"



void LED_vINIT(u8 portnum,u8 pinnum){
	
	GPIO_vSETPIN_DIR(portnum,pinnum,1);
	
}


void LED_ON(u8 portnum,u8 pinnum){
	
	GPIO_vwrite_PIN(portnum,pinnum,1);
	
}

void LED_OFF(u8 portnum,u8 pinnum){
	
	GPIO_vwrite_PIN(portnum,pinnum,0);
	
}
void LED_TOGGLE(u8 portnum,u8 pinnum){
	
	GPIO_vtoggle_PIN(portnum,pinnum);
	
}