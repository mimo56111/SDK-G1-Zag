#include "GPIO_MCAL.h"
#ifndef LED_H_
#define LED_H_
/*
->initialize the pin connected to the led
-> takes 2 arguments
->return void*/
void LED_INIT(u8 port,u8 pinnum);

/*
->LED ON
->takes 2 arguments
->return void*/
void LED_ON(u8 port,u8 pinnum);
/*
->LED OFF
->takes 2 arguments
->return void*/
void LED_OFF(u8 port,u8 pinnum);
/*
->LED TOGGLE
->takes 2 arguments
->return void*/
void LED_TOGGLE(u8 port,u8 pinnum);
#endif