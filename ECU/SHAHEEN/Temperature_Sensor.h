/*
 * Temperature_Sensor.h
 *
 * Created: 5/3/2020 6:51:06 AM
 *  Author: Shaheen
 */ 

#include "Datatypes.h"
#include "stdmacros.h"
#include "GPIO_MCAL.h"
#include "ADC.h"
#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

// initialize the analog pin connected to the sensor

void TEMP_SENSOR_INIT(u8 pinnum);


//read the value of temperature 

u16 TEMP_SENSOR_READ(u8 pinnum);

#endif /* TEMPERATURE_SENSOR_H_ */