

#include "GPIO_MCAL.h"
#include "Data_type.h"
#include "stdmacros.h"

#ifndef LCD_ECU_H_
#define LCD_ECU_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#define LCD_Function_4BIT_2Lines   0x28
#define LCD_Function_8BIT_2Lines   0x38

//===================LCD Commands===================
#define LCD_MOVE_DISP_RIGHT            0x1C
#define LCD_MOVE_DISP_LEFT             0x18
#define LCD_MOVE_CURSOR_RIGHT          0x14
#define LCD_MOVE_CURSOR_LEFT           0x10
#define LCD_DISP_OFF_CURSOR_OFF        0X08
#define LCD_DISP_ON_CURSOR_ON          0x0E
#define LCD_DISP_ON_CURSOR_BLINK       0x0F
#define LCD_ENTRY_MODE				   0x06
#define LCD_ENTRY_DEC				   0x04
#define LCD_ENTRY_DEC_SHIFT			   0x05
#define LCD_ENTRY_INC				   0x06
#define LCD_ENTRY_INC_SHIFT			   0x07
#define LCD_BEGIN_AT_FIRST_RAW		   0x80
#define LCD_BEGIN_AT_SECOND_RAW		   0xC0
#define LCD_CLEAR_SCREEN			   0X01
#define LCD_RETURN_HOME                0x02
//=================================================
#define  Four_bit 0
#define  Eight_bit 1
#define  High_Nibble 1
#define  LOW_Nibble 0
/*
	Function Name        : LCD_vInit
	Function Returns     : void
	Function Arguments   : unsigned char Mode ,Nibble , port , RS_(pin & port) , RW_(pin & port) & EN_(pin & port) 
    Function Description : Initialize the LCD to work even at 8-bit mode or 4-bit mode on a specific port  
*/
	void LCD_vInit(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin, u8 RW_port, u8 RW_pin,u8 EN_port,u8 EN_pin);

/*
	Function Name        : LCD_vsend_cmd
	Function Returns     : void
	Function Arguments   : unsigned char Mode ,Nibble , port , RS_(pin & port) , command &EN_(pin &port)
    Function Description : Send the command desired to the LCD in 8-bit mode and 4-bit mode
*/
	void LCD_vsend_cmd(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 cmd,u8 EN_port,u8 EN_pin);
/*
	Function Name        : send_falling_edge
	Function Returns     : void
	Function Arguments   : unsigned char EN_(pin & port)
    Function Description : send a pulse to Enable pin in the LCD 
*/
	static void send_falling_edge(u8 EN_port,u8 EN_pin);
	
/*
	Function Name        : LCD_clear_screen
	Function Returns     : void
	Function Arguments   : unsigned char Mode ,Nibble , port , RS_(pin & port) &EN_(pin &port)
    Function Description : Clear the screen and the DDRAM and return the cursor to the first location 
*/
	void LCD_clear_screen(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 EN_port,u8 EN_pin);

/*
	Function Name        : LCD_Move_Cursor
	Function Returns     : void
	Function Arguments   : unsigned char line number ,unsigned char position required ,unsigned char Mode ,Nibble ,port ,RS_(pin & port) &EN_(pin &port)
    Function Description : Move the cursor to a specific position in any line in the LCD
*/
	void LCD_Move_Cursor(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 EN_port,u8 EN_pin,u8 line ,u8 position);
	
/*
	Function Name        : LCD_vsend_char
	Function Returns     : void
	Function Arguments   : unsigned char data & unsigned char Mode ,Nibble ,port ,RS_(pin & port) &EN_(pin &port) 
    Function Description : Send the character desired to display on the LCD in 8-bit mode and 4-bit mode to the LCD
*/
	void LCD_vsend_char(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u8 data);
	/*
	Function Name        : LCD_vsend_string
	Function Returns     : void
	Function Arguments   : unsigned pointer to char data & unsigned char Mode ,Nibble ,port ,RS_(pin & port) &EN_(pin &port) 
    Function Description : Send string desired to display on  the LCD in 8-bit mode and 4-bit mode to the LCD
*/  
	void LCD_vsend_string(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u8 *data);
	/*
	Function Name        : LCD_display_number
	Function Returns     : void
	Function Arguments   : integer Number & unsigned char Mode ,Nibble ,port ,RS_(pin & port) &EN_(pin &port)
    Function Description : Send an integer Number desired to display on the LCD to the LCD 
*/
	void LCD_display_number(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u32 Number);
	/*
	Function Name        : LCD_display_real_number
	Function Returns     : void
	Function Arguments   : double Number & unsigned char Mode ,Nibble ,port ,RS_(pin & port) &EN_(pin &port) 
    Function Description : Send a real Number desired to display on the LCD to the LCD 
*/
void LCD_display_real_number(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,f64 Number);
 
 
 
#endif /* LCD_ECU_H_ */