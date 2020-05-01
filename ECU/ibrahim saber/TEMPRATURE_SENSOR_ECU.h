/*
 * TEMPRATURE_SENSOR_ECU.h
 *
 * Created: 4/27/2020 3:25:02 PM
 *  Author: ibrahim
 */ 

#include "DATA_TYPE.h"
#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"

#ifndef TEMPRATURE_SENSOR_ECU_H_
#define TEMPRATURE_SENSOR_ECU_H_

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

/*
FUNCTION name          :TEMP_SENSOR_INIT
FUNCTION description   :initialize the temperature sensor as input
FUNCTION arguments     :unsigned char pin number
FUNCTION return        :void
*/

void TEMP_SENSOR_INIT(u8 pinnum);

/*
FUNCTION name          :TEMP_SENSOR_READ
FUNCTION description   :read the temperature sensor  value after being converted from analog to digital
FUNCTION arguments     :unsigned char pin number
FUNCTION return        :unsigned short
*/


u16 TEMP_SENSOR_READ(u8 pinnum);


#endif /* TEMPRATURE_SENSOR_ECU_H_ */