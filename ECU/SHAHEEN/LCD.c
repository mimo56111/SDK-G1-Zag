/*
 * LCD.c
 *
 * Created: 4/10/2020 7:49:43 AM
 *  Author: Shaheen
 */ 

#include "LCD.h"

#define F_CPU 8000000UL
#include <util//delay.h>
void LCD_GET_CONFIG(u8 Mode,u8 Nibble,u8 Port,u8 Rs_port,u8 Rs_pin,u8 Rw_port,u8 Rw_pin,u8 En_port,u8 En_pin){
	mode=Mode;
	nibble=Nibble;
	port=Port;
	rs_port=Rs_port;
	rs_pin=Rs_pin;
	rw_port=Rw_port;
	rw_pin=Rw_pin;
	en_port=En_port;
	en_pin=En_pin;
}
void LCD_INIT(){
	_delay_ms(200);
	GPIO_SETPIN_DIR(rs_port,rs_pin,1);
	GPIO_SETPIN_DIR(rw_port,rw_pin,1);
	GPIO_SETPIN_DIR(en_port,en_pin,1);
	if(mode==1){
		GPIO_SETPORT_DIR(port,1);
		GPIO_WRITE_PIN(rw_port,rw_pin,0);
		LCD_SEND_CMD(LCD_RETURN_HOME);
		_delay_ms(15);
		LCD_SEND_CMD(LCD_FUNCTION_8BIT_2LINES);
		_delay_ms(1);
		LCD_SEND_CMD(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_SEND_CMD(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_SEND_CMD(LCD_ENTRY_MODE);
		_delay_ms(1);
	}else{
		if(nibble==1){
			GPIO_HIGH_NIBBLE_SETDIR(port,1);
			GPIO_WRITE_PIN(rw_port,rw_pin,0);
			LCD_SEND_CMD(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_SEND_CMD(LCD_FUNCTION_4BIT_2LINES);
			_delay_ms(1);
			LCD_SEND_CMD(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_SEND_CMD(LCD_CLEAR_SCREEN);
			_delay_ms(10);
			LCD_SEND_CMD(LCD_ENTRY_MODE);
			_delay_ms(1);
		}else{
			GPIO_LOW_NIBBLE_SETDIR(port,1);
			GPIO_WRITE_PIN(rw_port,rw_pin,0);
			LCD_SEND_CMD(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_SEND_CMD(LCD_FUNCTION_4BIT_2LINES);
			_delay_ms(1);
			LCD_SEND_CMD(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_SEND_CMD(LCD_CLEAR_SCREEN);
			_delay_ms(10);
			LCD_SEND_CMD(LCD_ENTRY_MODE);
			_delay_ms(1);
		}
	}
}
static void ENABLE_SET(){
	GPIO_WRITE_PIN(en_port,en_pin,1);
	_delay_ms(2);
	GPIO_WRITE_PIN(en_port,en_pin,0);
}
void LCD_SEND_CMD(u8 cmd){
	if(mode==1){
		GPIO_WRITE_PORT(port,cmd);
		GPIO_WRITE_PIN(rs_port,rs_pin,0);
		ENABLE_SET();
	}else{
		if(nibble==1){
			GPIO_HIGH_NIBBLE_WRITE(port,cmd>>4);
			GPIO_WRITE_PIN(rs_port,rs_pin,0);
			ENABLE_SET();
			GPIO_HIGH_NIBBLE_WRITE(port,cmd);
			GPIO_WRITE_PIN(rs_port,rs_pin,0);
			ENABLE_SET();
			_delay_ms(1);
		}else{
			GPIO_LOW_NIBBLE_WRITE(port,cmd>>4);
			GPIO_WRITE_PIN(rs_port,rs_pin,0);
			ENABLE_SET();
			GPIO_LOW_NIBBLE_WRITE(port,cmd);
			GPIO_WRITE_PIN(rs_port,rs_pin,0);
			ENABLE_SET();
			_delay_ms(1);
		}
	}
}
void LCD_SEND_CHAR(u8 data){
	if(mode==1){
		GPIO_WRITE_PORT(port,data);
		GPIO_WRITE_PIN(rs_port,rs_pin,1);
		ENABLE_SET();
		_delay_ms(1);
	}else{
		if(nibble==1){
			GPIO_HIGH_NIBBLE_WRITE(port,data>>4);
			GPIO_WRITE_PIN(rs_port,rs_pin,1);
			ENABLE_SET();
			GPIO_HIGH_NIBBLE_WRITE(port,data);
			GPIO_WRITE_PIN(rs_port,rs_pin,1);
			ENABLE_SET();
			_delay_ms(1);
		}else{
			
			GPIO_LOW_NIBBLE_WRITE(port,data>>4);
			GPIO_WRITE_PIN(rs_port,rs_pin,1);
			ENABLE_SET();
			GPIO_LOW_NIBBLE_WRITE(port,data);
			GPIO_WRITE_PIN(rs_port,rs_pin,1);
			ENABLE_SET();
			_delay_ms(1);
			}
				
		}
}
void LCD_clear_screen(){
	LCD_SEND_CMD(LCD_CLEAR_SCREEN);
	_delay_ms(10);
}
void LCD_MOVE_CURSOR(u8 line,u8 position){
	u8 data;
	if(line>3 || line<1 || position>16 || position<1){
		data=0x80;
		
	}else if(line==1){
		data=0x80+(position-1);	
	}else if(line==2){
		data=0xC0+(position-1);
	}
	LCD_SEND_CMD(data);
	_delay_ms(1);
}
void LCD_SEND_STRING(u8 *data){
	while((*data)!='\0'){
		LCD_SEND_CHAR(*data);
		data++;
	}
}
void LCD_DISP_NUMBER(u32 number){
	u8 str[7];
	sprintf(str,"%d",number);
	LCD_SEND_STRING(str);
}
void LCD_DISP_REAL_NUMBER(s64 number){
	u8 str[16];
	u8 *tmpsign= (number<0) ? "-":"";
	f32 tmpval= (number<0) ? -number : number;
	s32 tmpint1=tmpval;
	f32 tmpfrac=tmpval-tmpint1;
	s32 tmpint2=tmpfrac * 10000;
	sprintf(str,"%s%d.%04d",tmpsign,tmpint1,tmpint2);
	LCD_SEND_STRING(str);
}