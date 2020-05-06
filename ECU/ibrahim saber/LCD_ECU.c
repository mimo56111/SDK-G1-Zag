/*
 * lcd_final.c
 *
 * Created: 4/21/2020 9:23:05 PM
 *  Author: ibrahim
 */ 

#include "LCD_ECU.h"
#include "DATA_TYPE.h"
#include "LCD_CONFIG_COM.h"


void LCD_vINIT(void){

		
		_delay_ms(200);
		GPIO_vSETPIN_DIR(RS_PORT,RS_PIN,1);
		GPIO_vSETPIN_DIR(RW_PORT,RW_PIN,1);
		GPIO_vSETPIN_DIR(EN_PORT,EN_PIN,1);
		
		if (mode==1){
		GPIO_vSETPORT_DIR(port,0xFF);
		GPIO_vwrite_PIN(RW_PORT,RW_PIN,0);
		_delay_ms(15);
		LCD_vsend_CMD(LCD_FUNCTION_8BIT_2LINES);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_vsend_CMD(LCD_ENTRY_MODE);
		_delay_ms(1);
			
		}else{
		if(NIBBLE==1){
		GPIO_HIGH_NIBBLE_vset_dir(port,1);
		GPIO_vwrite_PIN(RW_PORT,RW_PIN,0);
		LCD_vsend_CMD(LCD_RETURN_HOME);
		_delay_ms(15);
		LCD_vsend_CMD(LCD_FUNCTION_8BIT_2LINES);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_vsend_CMD(LCD_ENTRY_MODE);
		_delay_ms(1);
				
		}else{
				
		GPIO_LOW_NIBBLE_vset_dir(port,1);
		GPIO_vwrite_PIN(RW_PORT,RW_PIN,0);
		LCD_vsend_CMD(LCD_RETURN_HOME);
		_delay_ms(15);
		LCD_vsend_CMD(LCD_FUNCTION_8BIT_2LINES);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_vsend_CMD(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_vsend_CMD(LCD_ENTRY_MODE);
		_delay_ms(1);
				
		}
			
		}
		
}


void LCD_vsend_CMD(u8 cmd){
	if (mode){
		GPIO_vwrite_PORT(port,cmd);
		GPIO_vwrite_PIN(RS_PORT,RS_PIN,0);
		LCD_vSEND_EN_TRIGGER();
		
		}else{
		if(NIBBLE==1){
			GPIO_HIGH_NIBBLE_vwrite(port,cmd>>4);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,0);
			LCD_vSEND_EN_TRIGGER();
			GPIO_HIGH_NIBBLE_vwrite(port,cmd);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,0);
			LCD_vSEND_EN_TRIGGER();
			_delay_ms(1);
			}else{
			
			GPIO_LOW_NIBBLE_vwrite(port,cmd>>4);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,0);
			LCD_vSEND_EN_TRIGGER();
			GPIO_LOW_NIBBLE_vwrite(port,cmd);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,0);
			LCD_vSEND_EN_TRIGGER();
			_delay_ms(1);
			
		}
	}
}


static void LCD_vSEND_EN_TRIGGER(void){
		GPIO_vwrite_PIN(EN_PORT,EN_PIN,1);
		_delay_ms(2);
		GPIO_vwrite_PIN(EN_PORT,EN_PIN,0);
				
}


void LCD_vCLEAR_SCREEN(void){
					
		LCD_vsend_CMD(LCD_CLEAR_SCREEN);
					
		_delay_ms(10);
}


void LCD_vDISP_OFF_CURSOR_OFF(){
	LCD_vsend_CMD(LCD_DISP_OFF_CURSOR_OFF);
	_delay_ms(10);
}

void LCD_vDISP_ON_CURSOR_OFF(){
	LCD_vsend_CMD(LCD_DISP_ON_CURSOR_OFF);
	_delay_ms(10);
}
void LCD_MOVE_DISP_RIGHT(){
	LCD_vsend_CMD(MOVE_DISP_RIGHT);
	_delay_ms(10);
}

void LCD_MOVE_DISP_LEFT(){
	LCD_vsend_CMD(MOVE_DISP_LEFT);
	_delay_ms(10);
}


void LCD_vSEND_CHAR( u8 data){
					
		if(mode==1){
		GPIO_vwrite_PORT(port,data);
		GPIO_vwrite_PIN(RS_PORT,RS_PIN,1);
		LCD_vSEND_EN_TRIGGER();
		_delay_ms(1);
						
		}else{
		if(NIBBLE==1){
							
			GPIO_HIGH_NIBBLE_vwrite(port,data>>4);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,1);
			LCD_vSEND_EN_TRIGGER();
			GPIO_HIGH_NIBBLE_vwrite(port,data);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,1);
			LCD_vSEND_EN_TRIGGER();
			_delay_ms(1);
							
		}else{
							
			GPIO_LOW_NIBBLE_vwrite(port,data>>4);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,1);
			LCD_vSEND_EN_TRIGGER();
			GPIO_LOW_NIBBLE_vwrite(port,data);
			GPIO_vwrite_PIN(RS_PORT,RS_PIN,1);
			LCD_vSEND_EN_TRIGGER();
			_delay_ms(1);
		}
						
		}
					
}


void LCD_vSEND_STRING( u8 *data){
					
			while((*data)!='\0'){
			LCD_vSEND_CHAR(*data);
			data++;
			}

}


void LCD_vSEND_NUMBER(u32 num){
		u8 str[7];
		sprintf(str,"%d",num);
		LCD_vSEND_STRING(str);
						
}


void LCD_MOVE_CURSOR(u8 line ,u8 position){
			u8 data;
			if (line>3 || line<1 || position>16 || position<1){
				data=0x80;
								
			}
			else if(line==1){
				data=0x80+(position-1);
			}else if(line==2){
				data=0xC0+(position-1);
			}
			LCD_vsend_CMD(data);
			_delay_ms(1);
							
}


void LCD_vSEND_REAL_NUMBER(s64 num){
			u8 str[16];
			u8 *tmpsign = (num<0)? "-" :""  ;
			f32 tmpval = (num<0)? -num : num;
			s32 tmpInt = tmpval;
			f32 tmpfrac = tmpval-tmpInt;
			s32 tmpInt2 = tmpfrac*10000;
			sprintf(str,"%s%d.%04d",tmpsign,tmpInt,tmpInt2);
			LCD_vSEND_STRING(str);
	}
