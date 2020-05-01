#ifndef ADC_MCAL_H_
#define ADC_MCAL_H_

#include "Register.h"
#include "Data_Type.h"
#include "StdMacros.h"

#define ADC0 0 
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7


/*
 Function name        : ADC_vInit
 Function return      : Void
 Function Arguments   : Void
 Function Description : INit ADC to work
*/
   void ADC_vInit();
   
/*
	Function Name        : ADC_u16Read_Single_Endded
	Function Returns     : unsigned short data
	Function Arguments   : unsigned char channel_number
    Function Description : Read the data after conversion from analog to digital  
*/
	u16 ADC_u16Read_Single_Endded(u8 channel_number);
	
	





#endif /* ADC_MCAL_H_ */