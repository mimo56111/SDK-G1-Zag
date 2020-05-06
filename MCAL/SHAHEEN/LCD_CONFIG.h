/*
 * LCD_CONFIG.h
 *
 * Created: 4/21/2020 2:54:26 PM
 *  Author: Shaheen
 */ 
#define FOUR_BIT 0
#define EIGHT_BIT 1
#define HIGH_NIBBLE 1
#define LOW_NIBBLE 0

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#define mode FOUR_BIT
#define nibble HIGH_NIBBLE
#define port 'A'
#define rs_port 'B'
#define rs_pin 0
#define rw_port 'B'
#define rw_pin 1
#define en_port 'B'
#define en_pin 2




#endif /* LCD_CONFIG_H_ */