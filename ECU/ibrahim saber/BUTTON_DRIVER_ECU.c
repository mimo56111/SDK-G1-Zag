#include "BUTTON_DRIVER_ECU.h"
#include "GPIO_MCAL.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void BUTTON_vINIT(u8 portnum,u8 pinnum){
	
	GPIO_vSETPIN_DIR(portnum,pinnum,0);

}

u8 BUTTON_u8read(u8 portnum,u8 pinnum){
	u8 value =0;
	value = GPIO_u8read_PIN(portnum,pinnum);
	return value;
}
