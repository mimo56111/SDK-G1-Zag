/*
 * TIMER2_MCAL.c
 *
 * Created: 30/04/2020 01:44:47 م
 *  Author: Genius
 */ 
#include "TIMER2_MCAL.h"

struct  TMR2_Configuration TMR2_Configuration;
u8 TOV2_val;
static void (*Ptr_To_OVFI2)(void);

static void (*Ptr_To_OCMI2)(void);



void   TMR2_Init(struct TMR2_Configuration  configuration2){
	
	TMR2_Configuration = configuration2 ;
	
	if (TMR2_Configuration.TMR2_Mode == TMR2_CTC ){
		CLR_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}
	
	
	if (TMR2_Configuration.TMR2_Mode == TMR2_NORMAL ){
		CLR_BIT(myTCCR2,myWGM20);
		CLR_BIT(myTCCR2,myWGM21);
	}
	
	if (TMR2_Configuration.TMR2_Mode == TMR2_Phase_Correct_PWM)
	{
		CLR_BIT(myTCCR2,myWGM21);
		SET_BIT(myTCCR2,myWGM20);
	}
	
	if (TMR2_Configuration.TMR2_Mode == TMR2_NON_PWM ){
		CLR_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}
	if (TMR2_Configuration.TMR2_Mode == TMR2_Fast_PWM ){
		SET_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}
	
	
	
	myTCCR2 = myTCCR2 | TMR2_Configuration.Prescalar2;
	
	
	if (TMR2_Configuration.TMR2_OVFIE2 == TOIE2_enable ){
		SET_BIT(myTIMSK,myTOIE2);
	}else if (TMR2_Configuration.TMR2_OVFIE2 == TOIE2_disable){
		CLR_BIT(myTIMSK,myTOIE2);
	}
	
	
	if (TMR2_Configuration.TMR2_OCIE2 == OCIE2_enable ){
		SET_BIT(myTIMSK,myOCIE2);
	}else if (TMR2_Configuration.TMR2_OCIE2 == OCIE2_disable){
		CLR_BIT(myTIMSK,myOCIE2);
	}
	
	
	
}

u8 TMR2_ReadCounterValue(){
	
	return myTCNT2;
}

void TMR2_Set_Compare_Value(u8 u8Val){
	
	myOCR2 = u8Val;
}

void TMR2_set_TOV_Num(u8 val){
	
	TOV2_val=val;
}

u8 TMR2_get_TOV_Num(){
	return TOV2_val;
	
}


void  TMR2_Fast_PWM_gen(u8 dutycycle){
	
	
SET_BIT(mDDRD,7);
//OC2 PIN 7 IN PORT 'D'
myOCR2=dutycycle * 2.56;

SET_BIT(myTCCR2,myCOM20);
SET_BIT(myTCCR2,myCOM21);	
	
}

void  TMR2_Phase_Correct_PWM_non(u8  dutycycle){
	
	SET_BIT(mDDRD,7);
	myOCR2=dutycycle * 2.56;
	SET_BIT(myTCCR2,myCOM20);
	SET_BIT(myTCCR2,myCOM21);
	
	
}
void TMR2_COM_Non_PWM_Gen(u8 dutycycle){
	SET_BIT(mDDRD,7);
	myOCR2=dutycycle * 2.56;
	SET_BIT(myTCCR2,myCOM20);
	CLR_BIT(myTCCR2,myCOM21);
}

u8   TMR2_GET_NUMof_TICKS(){
	
	
	return (256*TOV2_val + myTCNT2) ;
	
}

void   callback_OCR2(void*(OCR2_pointer)(void)){
	
	Ptr_To_OCMI2= OCR2_pointer;	
}

ISR(TIMER2_COMP_vect){
	
	(*Ptr_To_OCMI2)();
}



void   callback_OVI2(void*(OVI2_pointer)(void)){
	

	Ptr_To_OVFI2=OVI2_pointer;
	
}

ISR(TIMER2_OVF_vect){
	
	TOV2_val ++;
	(*Ptr_To_OVFI2)();
}