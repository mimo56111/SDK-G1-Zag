/*
 * LDR_ECU.c
 *
 * Created: 5/1/2020 1:18:07 AM
 *  Author: Shaheen
 */ 
#include "LDR_ECU.h"
#include "Datatypes.h"
u8 arr[8]={0,1,2,3,4,5,6,7};
void LDR_SENSOR_INIT(u8 pinnum){
	ADC_INIT();
	GPIO_SETPIN_DIR('A',arr[pinnum],0);
	
}
u16 LDR_SENSOR_READ(u8 pinnum){
	return ADC_READ_SINGLE_ENDDED(pinnum);
}