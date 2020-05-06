/*
 * LDR_ECU.h
 *
 * Created: 5/1/2020 11:38:37 PM
 *  Author: ibrahim
 */ 

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#include "ADC_MCAL.h"

#ifndef LDR_ECU_H_
#define LDR_ECU_H_

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

/*
FUNCTION name          :LDR_vINIT
FUNCTION description   :initialize the LDR sensor as input
FUNCTION arguments     :unsigned char pin number
FUNCTION return        :void
*/

void LDR_vINIT(u8 pinnum);

/*
FUNCTION name          :LDR_u16READ
FUNCTION description   :read the LDR sensor  value
FUNCTION arguments     :unsigned char pin number
FUNCTION return        :unsigned short
*/

u16 LDR_u16READ(u8 pinnum);


#endif /* LDR_ECU_H_ */