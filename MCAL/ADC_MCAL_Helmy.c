#include "Register.h"
#include "Data_Type.h"
#include "StdMacros.h"
#include "ADC_MCAL.h"

void ADC_vInit(){
/* Configure Vref (Vcc on AVCC with external capacitor at Vref pin)*/
	SET_BIT(iADMUX,iREFS0);
	SET_BIT(iADMUX,iREFS1);
/* Enable ADC */
	SET_BIT(iADCSRA,iADEN);
/* Adjust ADC Clock make the division factor 64 because we use freq. 8M so 8M/64=125KHz */
	SET_BIT(iADCSRA,iADPS2);
	SET_BIT(iADCSRA,iADPS1);
	CLR_BIT(iADCSRA,iADPS0);
}


u16 ADC_u16Read_Single_Endded(u8 channel_number){
		u16 read_val;
		/* Must be from 0>>7 to select one of these pin ADC0,1,2 */
		channel_number &= 0x07;
		/* Clear from MUX4 to MUX0 before set the required bit */
		iADMUX &= 0xE0;
		/* Choose the correct channel by setting the channel number in MUX4:0 bits */
		iADMUX = iADMUX | channel_number;
		/* Start the conversion by set Bit (ADSC) */
		SET_BIT(iADCSRA,iADSC);
		/*Wait for the conversion to complete and ADIF(Bit 4) become 1 */
		while(IS_BIT_CLR(iADCSRA,iADIF));
		/* Clear ADIF by write'1' to it */
		SET_BIT(iADCSRA,iADIF);
		/* Combine ADCL +ADCH */
		read_val = (iADCH<<8);
		read_val |= iADCL ;
		/* Return value*/
		return read_val;	
}

