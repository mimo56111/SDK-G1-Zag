/*
 * LDR_ECU.c
 *
 * Created: 5/1/2020 11:38:55 PM
 *  Author: ibrahim
 */ 


#include "LDR_ECU.h"
#include "DATA_TYPE.h"
#include "GPIO_MCAL.h"


void LDR_vINIT(u8 pinnum){
	
	u8 array[8]={'0','1','2','3','4','5','6','7'};
	GPIO_vSETPIN_DIR('A',array[pinnum],0);	
}	

u16 LDR_u16READ(u8 pinnum){
	u16 intensity;
	intensity=ADC_u16READ_Single_Endded(pinnum);
	
	return intensity;
	
}