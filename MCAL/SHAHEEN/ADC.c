/*
 * ADC.c
 *
 * Created: 4/21/2020 7:29:21 AM
 *  Author: Shaheen
 */ 
#include "ADC.h"
void ADC_INIT(){
	SET_BIT(xADMUX,xREFS0);
	SET_BIT(xADMUX,xREFS1);
	//enable ADC
	SET_BIT(XADCSRA,XADEN);
	//adjust adc clock
	SET_BIT(XADCSRA,XADPS2);
	SET_BIT(XADCSRA,XADPS1);
	RESET_BIT(XADCSRA,XADPS0);
	
}
u16 ADC_READ_SINGLE_ENDDED(u8 channel_num){
	u16 read_value;
	channel_num &=0x07;
	//clear from mux4 to mux0 before set the required bit
	xADMUX &=0xE0;
	//choose the correct channel by setting the channel num in mux4:0 bits
	xADMUX = xADMUX | channel_num;
	//start conversion by setting bit ADSC
	SET_BIT(XADCSRA,XADSC);
	//wait for the convertion to complete and ADIF(bit4) ==1
	while(IS_BIT_CLR(XADCSRA,XADIF));
	//lear ADIF by writting 1 to it
	SET_BIT(XADCSRA,XADIF);
	//combine ADCH ,ADCL
	read_value=XADCL;
	read_value |=(XADCH<<8);
	return read_value;
}