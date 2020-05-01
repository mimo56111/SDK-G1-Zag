#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "LDR_ECU.h"

void LDR_Sensor_vInit(u8 pin){
	ADC_vInit();
	GPIO_vsetPIN_Dir('A',pin,0);
	
}

u16 LDR_Sensor_u16Read(u8 pin){
	u16 intensity;
	intensity = ADC_u16Read_Single_Endded(pin);
    return intensity;
}