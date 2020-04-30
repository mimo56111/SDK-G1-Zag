#include "GPIO_MCAL.h"
#include "ADC_MCAL.h"
#include "PIR_ECU.h"

void PIR_Sensor_vInit(u8 port, u8 pin){
	GPIO_vsetPIN_Dir(port,pin,0);
	
}


u8 PIR_Sensor_u8Read(u8 port, u8 pin){
	u8 x;
	x = GPIO_u8read_PIN(port,pin);

	return x;
}
