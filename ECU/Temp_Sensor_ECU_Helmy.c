#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Temp_Sensor_ECU.h"
#define Vref 2.56

void Temp_Sensor_vInit(u8 pin){
	ADC_vInit();
    GPIO_vsetPIN_Dir('A',pin,0);	
	
}

u16 Temp_Sensor_u16Read(u8 pin){
	u16 Temperature;
	u16 v;
	v = ADC_u16Read_Single_Endded(pin);
	Temperature = (v*Vref*1000)/(1024*10);
	return Temperature;
}
