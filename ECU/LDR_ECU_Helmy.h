#ifndef LDR_ECU_H_
#define LDR_ECU_H_

#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Data_Type.h"

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7


/*
 Function name        : LDR_Sensor_vInit
 Function return      : Void
 Function Arguments   : unsigned char pin number
 Function Description : Initialize the pin which LDR sensor connected with it as input
*/
  void LDR_Sensor_vInit(u8 pin);
  

/*
 Function name        : LDR_Sensor_u16Read        
 Function return      : unsigned short Light Intensity
 Function Arguments   : unsigned char pin number
 Function Description : Read Light Intensity Sensor value
*/
 u16 LDR_Sensor_u16Read(u8 pin);


#endif /* LDR_ECU_H_ */