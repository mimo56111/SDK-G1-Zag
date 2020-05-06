#define u8_direction_input 0x00
#define default_direction u8_direction_input

#include "Registers.h"
#include "Datatypes.h"
#include "stdmacros.h"

#define connect 1
#define notconnect 0
#ifndef	GPIO_H_
#define GPIO_H_

// --Initialzation---

// ->initializes the ports

void GPIO_INIT(void);

//****************PIN*************
/*
->it defines the pin direction eather input 0 or output 1
->takes 3 arguments 
->return void*/

void GPIO_SETPIN_DIR(u8 port,u8 pinnum,u8 dir);

/*
->it writes a value to the pin eather high 1 or low 0
->takes 3 arguments 
->return void*/
void GPIO_WRITE_PIN(u8 port,u8 pinnum,u8 val);

/*
->reads the pin
->takes 2 arguments
->return the value of the pin*/
u8 GPIO_READ_PIN(u8 port,u8 pinnum);

/*
->toggles the pin
->takes 2 arguments
->return void*/
void GPIO_TOGGLE_PIN(u8 port,u8 pinnum);

/*
->activates  pullup resistance in the pin
->takes 3 arguments
->return void*/

void GPIO_CONNECT_PULLUP(u8 port,u8 pinnum,u8 connect_pullup);



//------------------------------PORT-------------------------------------

/*
->defines the port direction
->takes 2 arguments
->return void*/
void GPIO_SETPORT_DIR(u8 port,u8 dir);

/*
->writes a value to the port
->takes 2 arguments
->return void*/
void GPIO_WRITE_PORT(u8 port,u8 val);

/*
->reads the value of the port
->takes 1 argument
->return void*/
u8 GPIO_READ_PORT(u8 port);

/*
->toggles the port
->takes 1 argument
->return the value of the port*/
void GPIO_TOGGLE_PORT(u8 port);
/**************************/
//HIGH NIBBLE
void GPIO_HIGH_NIBBLE_SETDIR(u8 port,u8 dir);
void GPIO_HIGH_NIBBLE_WRITE(u8 port,u8 val);

//LOW NIBBLE
void GPIO_LOW_NIBBLE_SETDIR(u8 port,u8 dir);
void GPIO_LOW_NIBBLE_WRITE(u8 port,u8 val);

#endif
