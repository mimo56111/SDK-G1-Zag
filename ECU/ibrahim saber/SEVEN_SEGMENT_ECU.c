/*
 * CFile1.c
 *
 * Created: 4/12/2020 3:17:31 AM
 *  Author: ibrahim
 */ 



#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#define EIGHT_BIT   1
#define FOUR_BIT    0
#define HIGH_NIBBLE 1
#define LOW_NIBBLE  0


void SEVEN_SEGMENT_vINIT(u8 port, u8 mode ,u8 nibble ){
	 
	 if(mode==0){
		 if(nibble==0){
			 GPIO_LOW_NIBBLE_vset_dir(port,1);
		 }			 
			 else if (nibble==1){
				 GPIO_HIGH_NIBBLE_vset_dir(port,1);
				 }
			 else{
				 
			 }
	}
		else if( mode){
		GPIO_vSETPORT_DIR(port,1);
		}
		
}


void SEVEN_SEGMENT_vDISPLAY(u8 port, u8 mode ,u8 nibble, u8 value ){
	
	if(mode==0){
		if(nibble==0){
			
			GPIO_LOW_NIBBLE_vwrite(port,value);
		}
		else if (nibble==1){
			
			GPIO_HIGH_NIBBLE_vwrite(port,value);
		}
		else{
		
		}
	}
	else if(mode==1){
		
		if(value>=0 && value<=9){
			u8 array[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
			GPIO_vwrite_PORT(port,array[value]);	
			
			}
			else{
				
				#define A 0
				#define B 1
				#define C 2
				#define D 3
				#define E 4
				#define F 5
				
				u8 arr1[6]={0x77,0x1f,0x39,0x5E,0x79,0x71};
			
				GPIO_vwrite_PORT(port,arr1[value]);
			}
		
		}	
	
	else{
		
	}

}
