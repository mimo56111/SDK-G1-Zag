/*
 * LDR_ECU.h
 *
 * Created: 5/1/2020 1:12:11 AM
 *  Author: Shaheen
 */ 

#include "ADC.h"
#include "Datatypes.h"
#include "GPIO_MCAL.h"
enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	};
	
#ifndef LDR_ECU_H_
#define LDR_ECU_H_
/*
-->LDR initialize
-->takes Pin number and return void

*/
void LDR_SENSOR_INIT(u8 pinnum);//initialize the LDR

/*
-->LDR READ
-->takes pin number and return the value on the pin 
*/
u16 LDR_SENSOR_READ(u8 pinnum);//read and return the value given by the LDR

#endif /* LDR_ECU_H_ */