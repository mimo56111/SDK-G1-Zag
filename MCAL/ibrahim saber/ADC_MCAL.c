/*
 * ADC_MCAL.c
 *
 * Created: 4/27/2020 3:24:33 PM
 *  Author: ibrahim
 */ 


#include "ADC_MCAL.h"
#include "DATA_TYPE.h"
#include "REGISTERS.h"
#include "stdmacros.h"



void ADC_vINIT(){
	
/*configure the Vref(Vcc with external capacitor at Vref PIN)*/
	SET_BIT(MYADMUX,MYREFS0);
	CLR_BIT(MYADMUX,MYREFS1);
/*ENABLE THE ADC*/
	SET_BIT(MYADCSRA,MYADEN);
/* choosing ADC frequency by choosing prescaler 64 (8M/64=125KHz) */
	SET_BIT(MYADCSRA,MYADPS1);
	SET_BIT(MYADCSRA,MYADPS2);
	CLR_BIT(MYADCSRA,MYADPS0);
	
}	

u16 ADC_u16READ_Single_Endded(u8 channel_number){
	u16 READ_VAL;
	
	/*must be ranged between(0...7) to select on of (ADC0..ADC2)PINS*/

	channel_number&=0x07;
	/*clearing the MUX0...MUX4 */
	MYADMUX &=0xE0;
	/*to choose the required channel number in bits MUX0....MUX4*/
	MYADMUX |= channel_number;
	/*start the conversion*/
	SET_BIT(MYADCSRA,MYADSC);
	/* pooling to check if the conversion has been endded*/
	while(IS_BIT_CLEAR(MYADCSRA,MYADIF));
	/*clearing the ADIF by writing '1'*/
	SET_BIT(MYADCSRA,MYADIF);
	/* combine the ADCL+ADCH */
	READ_VAL=MYADCL;
	READ_VAL|=(MYADCH<<8);
	
	return READ_VAL;
	
}