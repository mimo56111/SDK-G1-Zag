#include "DATA_TYPE.h"
#include "GPIO_MCAL.h"
#include "PIR_ECU.h"
#include "LED_DRIVER_ECU.h"
#include "LCD_CONFIG_COM.h"
#include "LCD_ECU.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_vINIT();
	LED_vINIT('A',0);
	LED_vINIT('A',5);
	PIR_vINIT('A',1);
	RELAY_vINIT('D',0);

	
	
    while(1)
    {
		if (PIR_u8read('A',1)==1)
		{
			
			LED_ON('A',0);
			LED_OFF('A',5);
			RELAY_ON('D',0);
			LCD_vSEND_STRING("welcome");
			_delay_ms(1000);
			LCD_vCLEAR_SCREEN();
			_delay_ms(500);
			
			
		}else{
			LED_OFF('A',0);
			LED_ON('A',5);
			RELAY_OFF('D',0);
			LCD_vCLEAR_SCREEN();
		}			
    }
}