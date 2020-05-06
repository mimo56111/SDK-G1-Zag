#include "GPIO_MCAL.h"
#define Four_Bit 0
#define Eight_Bit 1
#define High_Nibble 1
#define Low_Nibble 0

void Seven_Segment_Init(u8 mode, u8 port, u8 Nibble){
	if (mode==0){
		if (Nibble==0){
			GPIO_Low_Nibble_vset_Dir(port,1);
		}else if (Nibble==1){
			GPIO_High_Nibble_vset_Dir(port,1);
		}else{}
		
	}else if(mode==1){
		GPIO_vsetPORT_Dir(port,1);
	}
else{}

}



void Seven_Segment_Display(u8 mode, u8 port , u8 Nibble, u8 value){
	if (mode==0){
		if (Nibble==0){
			GPIO_Low_Nibble_vwrite(port,value);
		}else if (Nibble==1){
			GPIO_High_Nibble_vwrite(port,value);
		}else{}
		
	}else if(mode==1){
		u8 arr[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66 , 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
			#define A 0
			#define B 1
			#define C 2 
			#define D 3
			#define E 4
			#define F 5
		u8 arr1[6]={0x77, 0x1f, 0x39, 0x5e, 0x79, 0x71};
			
			if(value>=0 && value<=9){
				
				GPIO_vwrite_PORT(port,arr[value]);
			}else{
				GPIO_vwrite_PORT(port,arr1[value]);
			}
			}	else{}			
}