/*
 * LCD.h
 *
 * Created: 4/10/2020 7:27:29 AM
 *  Author: Shaheen
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Datatypes.h"
#include "stdmacros.h"
#define FOUR_BIT 0
#define EIGHT_BIT 1
#define HIGH_NIBBLE 1
#define LOW_NIBBLE 0
#define LCD_FUNCTION_4BIT_2LINES 0x28
#define LCD_FUNCTION_8BIT_2LINES 0x38
//****************lcd commands***********************
#define LCD_MOVE_DISP_RIGHT				0x1C
#define LCD_MOVE_DISP_LEFT				0x18
#define LCD_MOVE_CURSOR_RIGHT			0x14
#define LCD_MOVE_CURSOR_LEFT			0x10
#define LCD_DISP_OFF_CURSOR_OFF			0x08
#define LCD_DISP_ON_CURSOR_ON			0x0E
#define LCD_DISP_ON_CURSOR_BLINK		0x0F
#define LCD_ENTRY_MODE					0x06
#define LCD_ENTRY_DEC					0x04
#define LCD_ENTRY_DEC_SHIFT				0x05
#define LCD_ENTRY_INC					0x06
#define LCD_ENTRY_INC_SHIFT				0x07
#define LCD_BEGIN_AT_FIRST_RAW			0x80
#define LCD_BEGIN_AT_SECOND_RAW			0xC0
#define LCD_CLEAR_SCREEN				0x01
#define LCD_RETURN_HOME					0x02
//*******************************************************
u8 mode;
u8 nibble;
u8 port;
u8 rs_port;
u8 rs_pin;
u8 rw_port;
u8 rw_pin;
u8 en_port;
u8 en_pin;
//***********************************
void LCD_GET_CONFIG(u8 Mode,u8 Nibble,u8 Port,u8 Rs_port,u8 Rs_pin,u8 Rw_port,u8 Rw_pin,u8 En_port,u8 En_pin);//get the lcd configrations 
//********************
void LCD_INIT(); //intialze the lcd
	
//********
void LCD_SEND_CMD(u8 cmd);//exicute a command

//***************
static void ENABLE_SET();//activate the enable pin


//*************
void LCD_SEND_CHAR(u8 data);//print a character


//********
void LCD_clear_screen();//clear the screen


//*****
void LCD_MOVE_CURSOR(u8 line,u8 position);//move the cursor to a certain position


//*******
void LCD_SEND_STRING(u8 *data);//print a combination of characters


//*******
void LCD_DISP_NUMBER(u32 number);//print a number


//******
void LCD_DISP_REAL_NUMBER(s64 number);//print a signed number or a fraction


#endif /* LCD_H_ */