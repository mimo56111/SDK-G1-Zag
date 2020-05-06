#ifndef PIR_ECU_H_
#define PIR_ECU_H_

#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Data_Type.h"

/*
Function Name        : PIR_Sensor_vInit
Function Returns     : void
Function Arguments   : unsigned char port name , unsigned char pin number
Function Description : Initialize the pin at the given port which PIR sensor connected with it as input
*/
  void PIR_Sensor_vInit(u8 port, u8 pin);



/*
Function Name        : LDR_Sensor_u8Read 
Function Returns     : unsigned char
Function Arguments   : unsigned char port name , unsigned char pin number
Function Description : Return 1 or 0 depend on motion 
*/
  u8 PIR_Sensor_u8Read(u8 port, u8 pin);




#endif /* PIR_ECU_H_ */