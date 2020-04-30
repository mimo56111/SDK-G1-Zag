#include "GPIO_MCAL.h"
#include <util/delay.h>
#define F_CPU 8000000UL


void Button_vInit(u8 port, u8 pin){
	GPIO_vsetPIN_Dir(port,pin,0);
}


u8 Button_u8Read(u8 port, u8 pin){
	u8 x;
	x = GPIO_u8read_PIN(port,pin);
	_delay_ms(5);
	x = GPIO_u8read_PIN(port,pin);
	
	return x;
}



