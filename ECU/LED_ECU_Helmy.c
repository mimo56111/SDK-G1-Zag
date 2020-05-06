#include "GPIO_MCAL.h"

void LED_vInitialize(u8 port , u8 pin){
	GPIO_vsetPIN_Dir(port , pin ,1);
}

void LED_vTurnON(u8 port, u8 pin){
	GPIO_vwrite_PIN(port, pin, 1);
}

void LED_vTurnOFF(u8 port, u8 pin){
	GPIO_vwrite_PIN(port, pin, 0);
}

void LED_vToggle(u8 port, u8 pin){
	GPIO_vtoggle_PIN(port, pin);
}



