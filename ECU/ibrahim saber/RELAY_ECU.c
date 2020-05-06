/*
 * RELAY_ECU.c
 *
 * Created: 4/24/2020 9:35:14 PM
 *  Author: ibrahim
 */ 

#include "GPIO_MCAL.h"
#include "RELAY_ECU.h"


void RELAY_vINIT(u8 portnum,u8 pinnum){
	
	GPIO_vSETPIN_DIR(portnum,pinnum,1);
	
}


void RELAY_ON(u8 portnum,u8 pinnum){
	
	GPIO_vwrite_PIN(portnum,pinnum,1);
	
}

void RELAY_OFF(u8 portnum,u8 pinnum){
	
	GPIO_vwrite_PIN(portnum,pinnum,0);
	
}
void RELAY_TOGGLE(u8 portnum,u8 pinnum){
	
	GPIO_vtoggle_PIN(portnum,pinnum);
	
}