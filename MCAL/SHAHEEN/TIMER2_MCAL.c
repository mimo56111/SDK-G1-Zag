/*
 * TIMER2_MCAL.c
 *
 * Created: 4/30/2020 12:11:43 AM
 *  Author: Shaheen
 */ 
#include "TIMER2_MCAL.h"
#include "Datatypes.h"
static void (*ptr_to_ovfi2)(void);
static void (*ptr_to_ocmi2)(void);

void TMR2_GET_CONFIG(u8 mode,u8 prescalar,u8 overflow_interrupt,u8 ctc_interrupt){
	configration2.mode2=mode;
	configration2.prescalar2=prescalar;
	configration2.TMR2_OVERFLOW_INTERRUPT=overflow_interrupt;
	configration2.TMR2_CTC_INTERRUPT=ctc_interrupt;
}
void TMR2_INIT(void){
	if(configration2.mode2==NORMAL2){
		RESET_BIT(XTCCR2,XWGM20);
		RESET_BIT(XTCCR2,XWGM21);
	}if(configration2.mode2==CTC2){
		RESET_BIT(XTCCR2,XWGM20);
		SET_BIT(XTCCR2,XWGM21);
	}if(configration2.mode2==FAST_PWM2){
		SET_BIT(XTCCR2,XWGM20);
		SET_BIT(XTCCR2,XWGM21);
	}if(configration2.mode2==PHASE_CORRECT2){
		SET_BIT(XTCCR2,XWGM20);
		RESET_BIT(XTCCR2,XWGM21);
	}
	
	XTCCR2 |= configration2.prescalar2;
	
	if(configration2.TMR2_OVERFLOW_INTERRUPT==TOIE2_ENABLE){
		SET_BIT(XTIMSK,XTOIE2);
	}else if(configration2.TMR2_OVERFLOW_INTERRUPT==TOIE2_DISABLE){
		RESET_BIT(XTIMSK,XTOIE2);
	}
	
	if(configration2.TMR2_CTC_INTERRUPT==OCIE2_ENABLE){
		SET_BIT(XTIMSK,XOCIE2);
	}else if(configration2.TMR2_CTC_INTERRUPT==OCIE2_DISABLE){
		RESET_BIT(XTIMSK,XOCIE2);
	}
}

void TMR2_SET_COMPARE(u8 value){
	XOCR2=value;
}
void TMR2_READ_COUNT(u8 *val){
	*val=XTCNT2;
}
void TMR2_SET_COUNTER(u8 value){
	XTCNT2=value;
}
void TMR2_COM_NON_PWM_GEN(u8 duty_cycle){
	SET_BIT(XDDRD,7);
	XOCR2=(duty_cycle * 256)/100;
	SET_BIT(XTCCR2,XCOM20);
	RESET_BIT(XTCCR2,XCOM21);
	
}
void TMR2_FAST_PWD_GEN(u8 duty_cycle){
	SET_BIT(XDDRD,7);
	XOCR2=(duty_cycle * 256)/100;
	SET_BIT(XTCCR2,XCOM20);
	SET_BIT(XTCCR2,XCOM21);
}
void TMR2_PHASE_CORRECT_GEN(u8 duty_cycle){
	SET_BIT(XDDRD,7);
	XOCR2=(duty_cycle * 510)/100;
	SET_BIT(XTCCR2,XCOM20);
	SET_BIT(XTCCR2,XCOM21);
}
void TMR2_CALLBACK_OVERFLOW_INTERRUPT(void(*ptr_to_overflow_func)(void)){
	ptr_to_ovfi2=ptr_to_overflow_func;
}
void TMR2_CALLBACK_OCM_INTERRUPT(void(*ptr_to_ocm_func)(void)){
	ptr_to_ocmi2=ptr_to_ocm_func;
}
ISR(TIMER2_OVF_vect){
	(*ptr_to_ovfi2)();
}
ISR(TIMER2_COMP_vect){
	(*ptr_to_ocmi2)();
}