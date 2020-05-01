/*
* ADC_MCAL.h
	*
* Created: 4/27/2020 3:24:12 PM
*  Author: ibrahim
*/

#include "DATA_TYPE.h"
#include "stdmacros.h"
#include "REGISTERS.h"

#ifndef ADC_MCAL_H_
#define ADC_MCAL_H_

#define ADC0	0
#define ADC1	1	
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

/*
Function name         :ADC_vINIT
Function Description  :enable the ADC , choosing ADC frequency and choosing the Vref
function Arguments    :void
Function Returns      :void
*/

void ADC_vINIT();

/*
Function name         :ADC_u16READ
Function Description  :reading the converted data (data converted from analog to digital)
function Arguments    :unsigned char channel_number
Function Returns      :unsigned short data
*/

u16 ADC_u16READ_Single_Endded(u8 channel_number);




#endif /* ADC_MCAL_H_ */