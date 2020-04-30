#ifndef TEMP_SENSOR_ECU_H_
#define TEMP_SENSOR_ECU_H_


/*
 Function name        : Temp_Sensoe_vInit
 Function return      : Void
 Function Arguments   : unsigned char pin number
 Function Description : Initialize the pin which sensor connected with it as input
*/
  void Temp_Sensor_vInit(u8 pin);

/*
 Function name        : Temp_Sense_u16Read        
 Function return      : unsigned short Temperature
 Function Arguments   : unsigned char pin number
 Function Description : Read Temperature Sensor value
*/
  u16 Temp_Sensor_u16Read(u8 pin);



#endif /* TEMP_SENSOR_ECU_H_ */