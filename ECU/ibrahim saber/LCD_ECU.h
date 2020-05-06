/*
 * lcd_final.h
 *
 * Created: 4/21/2020 9:21:56 PM
 *  Author: ibrahim
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DATA_TYPE.h"
#include "stdmacros.h"
#include "GPIO_MCAL.h"
#include "LCD_CONFIG_COM.h"

/*======================LCD commands=================================================================*/
//======================================================================================================

#define LCD_CLEAR_SCREEN                       0x01
#define LCD_RETURN_HOME                        0x02
#define LCD_DISP_OFF_CURSOR_ON				   0x0A
#define LCD_DISP_OFF_CURSOR_OFF                0x08
#define LCD_DISP_ON_CURSOR_ON                  0x0E
#define LCD_DISP_ON_CURSOR_OFF                 0x0C
#define MOVE_DISP_LEFT                         0x18
#define MOVE_DISP_RIGHT                        0x1C
#define MOVE_CURSOR_LEFT                       0x10
#define MOVE_CURSOR_RIGHT                      0x14
#define LCD_DISP_ON_CURSOR_BLINKING            0x0F
#define LCD_ENTRY_DEC                          0x04
#define LCD_ENTRY_INC                          0x06
#define LCD_ENTRY_DEC_SHIFT                    0x05
#define LCD_ENTRY_INC_SHIFT                    0x07
#define LCD_ENTRY_MODE                         0x06
#define LCD_BEGIN_AT_FIRST_RAW                 0x80
#define LCD_BEGIN_AT_SECOND_RAW                0xC0


//==================================================================================================

#define FOUR_BIT      0
#define EIGHT_BIT     1
#define LOW_NIBBLE    0
#define HIGH_NIBBLE   1

#define LCD_FUNCTION_4BIT_2LINES  0x28
#define LCD_FUNCTION_8BIT_2LINES  0x38







#ifndef LCD_ECU_H_
#define LCD_ECU_H_

/*
 Function name         :LCD_vINIT
 Function Description  :initialize the LCD 
 function Arguments    :void
 Function Returns      :void
 
 */


void LCD_vINIT(void);

/*
 Function name         :LCD_vsend_CMD
 Function Description  :send command to IR REGISTER of the LCD micro controller and saved in DDRAM 
 function Arguments    :unsigned char mode ,unsigned char command,unsigned char NIBBLE ,unsigned char (port ,pin,RS_port,RS_PIN,RW_port,RW_pin,EN_port,EN_pin)
 Function Returns      :void
 
 */


void LCD_vsend_CMD(u8 cmd);


static void LCD_vSEND_EN_TRIGGER(void);


void LCD_vSEND_CHAR( u8 data);



void LCD_vSEND_NUMBER( u32 num);



void LCD_vSEND_REAL_NUMBER(s64 num);




void LCD_vSEND_STRING(u8 *data);


void LCD_vCLEAR_SCREEN(void);



void LCD_MOVE_CURSOR(u8 line ,u8 position);


void LCD_vDISP_OFF_CURSOR_OFF();


void LCD_vDISP_ON_CURSOR_OFF();

void LCD_MOVE_DISP_RIGHT();

void LCD_MOVE_DISP_LEFT();


#endif /* LCD_ECU_H_ */