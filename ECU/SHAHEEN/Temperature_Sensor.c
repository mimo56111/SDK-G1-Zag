/*
 * Temperature_Sensor.c
 *
 * Created: 5/3/2020 6:54:49 AM
 *  Author: Shaheen
 */ 
#include "Temperature_Sensor.h"
#define Vref 2.56
void TEMP_SENSOR_INIT(u8 pin){
	GPIO_SETPIN_DIR('A',pin,0);
	ADC_INIT();
}

u16 TEMP_SENSOR_READ(u8 pinnum){
	u16 temperature;
	u16 val;
	val = ADC_READ_SINGLE_ENDDED(pinnum);
	temperature= (val*Vref*1000)/(1024 * 10);
	return temperature;
}