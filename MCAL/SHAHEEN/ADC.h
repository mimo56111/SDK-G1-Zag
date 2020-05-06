/*
 * ADC.h
 *
 * Created: 4/21/2020 7:16:01 AM
 *  Author: Shaheen
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "Datatypes.h"
#include "Registers.h"
#include "stdmacros.h"

void ADC_INIT();//initialize the ADC


u16 ADC_READ_SINGLE_ENDDED(u8 channel_num);//read the signal at the pin



#endif /* ADC_H_ */