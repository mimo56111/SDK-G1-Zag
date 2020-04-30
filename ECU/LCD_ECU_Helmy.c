
#include "LCD_ECU.h"

void LCD_vInit(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin, u8 RW_port, u8 RW_pin,u8 EN_port,u8 EN_pin){
	_delay_ms(200);
	GPIO_vsetPIN_Dir(RS_port,RS_pin,1);
	GPIO_vsetPIN_Dir(RW_port,RW_pin,1);
	GPIO_vsetPIN_Dir(EN_port,EN_pin,1);
	if (1==Mode){
		GPIO_vsetPORT_Dir(port,0xff);
		GPIO_vwrite_PIN(RW_port,RW_pin,0);
		_delay_ms(15);
		LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_Function_8BIT_2Lines,EN_port,EN_pin);
		_delay_ms(1);
		LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_DISP_ON_CURSOR_ON,EN_port,EN_pin);
		_delay_ms(1);
		LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_CLEAR_SCREEN,EN_port,EN_pin);
		_delay_ms(10);
		LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_ENTRY_MODE,EN_port,EN_pin);
		_delay_ms(1);
		
	}else{
		if (1==Nibble){
			GPIO_High_Nibble_vset_Dir(port,1);
			GPIO_vwrite_PIN(RW_port,RW_pin,0);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_RETURN_HOME,EN_port,EN_pin);
			_delay_ms(15);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_Function_4BIT_2Lines,EN_port,EN_pin);
			_delay_ms(1);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_DISP_ON_CURSOR_ON,EN_port,EN_pin);
			_delay_ms(1);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_CLEAR_SCREEN,EN_port,EN_pin);
			_delay_ms(10);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_ENTRY_MODE,EN_port,EN_pin);
			_delay_ms(1);
		}else{
			GPIO_Low_Nibble_vset_Dir(port,1);
			GPIO_vwrite_PIN(RW_port,RW_pin,0);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_RETURN_HOME,EN_port,EN_pin);
			_delay_ms(15);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_Function_4BIT_2Lines,EN_port,EN_pin);
			_delay_ms(1);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_DISP_ON_CURSOR_ON,EN_port,EN_pin);
			_delay_ms(1);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_CLEAR_SCREEN,EN_port,EN_pin);
			_delay_ms(10);
			LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_ENTRY_MODE,EN_port,EN_pin);
			_delay_ms(1);
		}
	}
}

void LCD_vsend_cmd(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 cmd,u8 EN_port,u8 EN_pin){
	if(1==Mode){
		GPIO_vwrite_PORT(port,cmd);
		GPIO_vwrite_PIN(RS_port,RS_pin,0);
		send_falling_edge(EN_port,EN_pin);
	}else {
		if (1==Nibble){
			GPIO_High_Nibble_vwrite(port,cmd>>4);
			GPIO_vwrite_PIN(RS_port,RS_pin,0);
			send_falling_edge(EN_port,EN_pin);
			GPIO_High_Nibble_vwrite(port,cmd);
			GPIO_vwrite_PIN(RS_port,RS_pin,0);
			send_falling_edge(EN_port,EN_pin);
			_delay_ms(1);
		}else{
			GPIO_Low_Nibble_vwrite(port,cmd>>4);
			GPIO_vwrite_PIN(RS_port,RS_pin,0);
			send_falling_edge(EN_port,EN_pin);
			GPIO_Low_Nibble_vwrite(port,cmd);
			GPIO_vwrite_PIN(RS_port,RS_pin,0);
			send_falling_edge(EN_port,EN_pin);
			_delay_ms(1);
		}
	}
}

static void send_falling_edge(u8 EN_port,u8 EN_pin){
	GPIO_vwrite_PIN(EN_port,EN_pin,1);
	_delay_ms(2);
	GPIO_vwrite_PIN(EN_port,EN_pin,0);
}

void LCD_clear_screen(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 EN_port,u8 EN_pin){
	LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,LCD_CLEAR_SCREEN,EN_port,EN_pin);
	_delay_ms(10);
}

void LCD_Move_Cursor(u8 Mode, u8 Nibble ,u8 port, u8 RS_port,u8 RS_pin,u8 EN_port,u8 EN_pin,u8 line ,u8 position){
	u8 data;
	if(line > 3 || line < 1 || position >16 || position <1){
		data = 0x80;
	}else if (1 == line ){
		data = 0x80 + (position - 1);
	}else if (2 == line){
		data = 0xC0 + (position - 1);
	}
	LCD_vsend_cmd(Mode,Nibble,port,RS_port,RS_pin,data,EN_port,EN_pin);
	_delay_ms(1);
}

void LCD_vsend_char(u8 Mood , u8 Nibble,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u8 data){
	if (1==Mood){
		GPIO_vwrite_PORT(port,data);
		GPIO_vwrite_PIN(RS_port,RS_pin,1);
		send_falling_edge(EN_port,EN_pin);
		_delay_ms(1);
	}else{
		if (1==Nibble){
			GPIO_High_Nibble_vwrite(port,data>>4);
			GPIO_vwrite_PIN(RS_port,RS_pin,1);
			send_falling_edge(EN_port,EN_pin);
			GPIO_High_Nibble_vwrite(port,data);
			GPIO_vwrite_PIN(RS_port,RS_pin,1);
			send_falling_edge(EN_port,EN_pin);
			_delay_ms(1);
		}else{
			GPIO_Low_Nibble_vwrite(port,data>>4);
			GPIO_vwrite_PIN(RS_port,RS_pin,1);
			send_falling_edge(EN_port,EN_pin);
			GPIO_Low_Nibble_vwrite(port,data);
			GPIO_vwrite_PIN(RS_port,RS_pin,1);
			send_falling_edge(EN_port,EN_pin);
			_delay_ms(1);
		}
	}
}

void LCD_vsend_string(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u8 *data){
	while((*data)!='\0'){
		LCD_vsend_char(Mood,Nibble,port,RS_port,RS_pin,EN_port,EN_pin,*data);
		data++;
	}
}

void LCD_display_number(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,u32 Number){
	u8 str[7];
	sprintf(str,"%d",Number);
	LCD_vsend_string(Mood,Nibble,port,RS_port,RS_pin,EN_port,EN_pin,str);
}

void LCD_display_real_number(u8 Mood , u8 Nibble ,u8 port ,u8 RS_port ,u8 RS_pin ,u8 EN_port,u8 EN_pin,f64 Number){
	u8 str [16];
	u8 *tmpsign = (Number < 0) ? "-": "";
	f32 tmpval = (Number < 0) ? -Number : Number;
	s32 tmpInt1 = tmpval;
	f32 tmpFrac = tmpval - tmpInt1;
	s32 tmpInt2 = tmpFrac * 10000;
	sprintf(str, "%s%d.%04d", tmpsign,tmpInt1,tmpInt2);
	LCD_vsend_string(Mood,Nibble,port,RS_port,RS_pin,EN_port,EN_pin,str);
}
 