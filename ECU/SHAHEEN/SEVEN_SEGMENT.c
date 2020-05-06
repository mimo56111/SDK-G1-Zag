/*
 * _7_SEGMENT.c
 *
 * Created: 4/9/2020 2:08:14 AM
 *  Author: Shaheen
 */ 
#include "GPIO_MCAL.h"
#include "SEVEN_SEGMENT.h"
#include "Datatypes.h"
#define FOUR_BIT 0
#define EIGHT_BIT 1
#define HIGH_NIBBLE 1
#define LOW_NIBBLE 0
void SEVEN_SEGMENT_INIT(u8 mode,u8 port,u8 nibble){
	if(mode==0){
		if(nibble==0){
			GPIO_LOW_NIBBLE_SETDIR(port,1);
		}else if(nibble==1){
			GPIO_HIGH_NIBBLE_SETDIR(port,1);
		}
	}else if(mode==1){
		GPIO_SETPORT_DIR(port,0xff);
	}else{
		
	}
}
void SEVEN_SEGMENT_DISP(u8 mode,u8 port,u8 nibble,u8 value){
	if(mode==0){
		if(nibble==0){
			GPIO_LOW_NIBBLE_WRITE(port,value);
		}else if(nibble==1){
			GPIO_HIGH_NIBBLE_WRITE(port,value);
		}
		else{
			
		}
		
	}else if(mode==1){
		
		
		if(value>=0 && value<=9)
		{
			u8 arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
			GPIO_WRITE_PORT(port,arr[value]);
		}
		else {
			#define A 0
			#define B 1
			#define C 2
			#define D 3
			#define E 4
			#define F 5
			u8 arr1[6]={0x77,0x1f,0x39,0x5E,0x79,0x71};
			GPIO_WRITE_PORT(port,arr1[value]);
		}		
	}
	else{
		
	}
}