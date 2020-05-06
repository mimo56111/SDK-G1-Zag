/*
 * TEMPRATURE_SENSOR_ECU.c
 *
 * Created: 4/27/2020 3:25:34 PM
 *  Author: ibrahim
 */ 

#define Vref 2.56
#include "TEMPRATURE_SENSOR_ECU.h"
#include "GPIO_MCAL.h"

void TEMP_SENSOR_INIT(u8 pinnum){
	u8 array[8]={'0','1','2','3','4','5','6','7'};
	GPIO_vSETPIN_DIR('A',array[pinnum],0);
} 
u16 TEMP_SENSOR_READ(u8 pinnum){
	u16 TEPRATURE;
	u16 v;
	v=ADC_u16READ_Single_Endded(pinnum);
	
	TEPRATURE=(v*Vref*1000)/(1024*10);
	return TEPRATURE;
}