#include "GPIO_MCAL.h"

void LED_INIT(u8 port,u8 pinnum){
	GPIO_SETPIN_DIR(port,pinnum,1);
}
void LED_ON(u8 port,u8 pinnum){
	GPIO_WRITE_PIN(port,pinnum,1);
}
void LED_OFF(u8 port,u8 pinnum){
	GPIO_WRITE_PIN(port,pinnum,0);
}
void LED_TOGGLE(u8 port,u8 pinnum){
	GPIO_TOGGLE_PIN(port,pinnum);
}