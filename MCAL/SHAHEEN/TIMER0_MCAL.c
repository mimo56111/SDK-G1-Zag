/*
 * TIMER0_MCAL.c
 *
 * Created: 4/29/2020 4:22:06 PM
 *  Author: Shaheen
 */ 
#include "TIMER0_MCAL.h"
#include "Datatypes.h"
static void (*ptr_to_ovfi)(void);
static void (*ptr_to_ocmi)(void); 
void TMR0_GET_CONFIG(u8 Mode,u8 Prescalar,u8 overflow_interrupt,u8 ctc_interrupt ){
	configration.mode=Mode;
	configration.prescalar=Prescalar;
	configration.TMR0_OVERFLOW_INTERRUPT=overflow_interrupt;
	configration.TMR0_CTC_INTERRUPT=ctc_interrupt;
}
void TMR0_INIT(void){
	if(configration.mode==NORMAL){
		RESET_BIT(XTCCR0,XWGM00);
		RESET_BIT(XTCCR0,XWGM01);
	}else if (configration.mode==CTC)
	{
		SET_BIT(XTCCR0,XWGM01);
		RESET_BIT(XTCCR0,XWGM00);
	}else if (configration.mode==OCM_NOT_PWM)
	{
		SET_BIT(XTCCR0,XWGM01);
		RESET_BIT(XTCCR0,XWGM00);
	}else if (configration.mode==FAST_PWM)
	{
		SET_BIT(XTCCR0,XWGM00);
		SET_BIT(XTCCR0,XWGM01);
	}else if (configration.mode==PHASE_CORRECT)
	{
		SET_BIT(XTCCR0,XWGM00);
		RESET_BIT(XTCCR0,XWGM01);
	}
	
	XTCCR0 |= configration.prescalar;
	
	
	
	
	if (configration.TMR0_OVERFLOW_INTERRUPT==TOIE0_ENABLE)
	{
		SET_BIT(XTIMSK,XTOIE0);
	}else if (configration.TMR0_OVERFLOW_INTERRUPT==TOIE0_DISABLE)
	{
		RESET_BIT(XTIMSK,XTOIE0);
	}
	
	
	if (configration.TMR0_CTC_INTERRUPT==OCIE0_ENABLE)
	{
		SET_BIT(XTIMSK,XOCIE0);
	}else if (configration.TMR0_CTC_INTERRUPT==OCIE0_DISABLE)
	{
		RESET_BIT(XTIMSK,XOCIE0);
	}
}
void TMR0_SET_COMPARE(u32 value){
	XOCR0=value;
}
u8 TMR0_READ_COUNT(void){
	return XTCNT0;
}
void TMR0_SET_COUNTER(u8 value){
	XTCNT0=value;
}
void TMR0_COM_NON_PWM_GEN(u8 duty_cycle){
	u8 val;
	SET_BIT(XDDRB,3);
	val=(duty_cycle * 256)/100;
	TMR0_SET_COMPARE(val);
	SET_BIT(XTCCR0,XCOM00);
	RESET_BIT(XTCCR0,XCOM01);
}
void TMR0_FAST_PWM_GEN(u8 duty_cycle){
	u8 val;
	SET_BIT(XDDRB,3);
	val=(duty_cycle * 256)/100;
	TMR0_SET_COMPARE(val);
	RESET_BIT(XTCCR0,XCOM00);
	SET_BIT(XTCCR0,XCOM01);
}
void TMR0_PHASE_CORRECT_GEN(u8 duty_cycle){
	u8 val;
	SET_BIT(XDDRB,3);
	val=(duty_cycle * 510)/100;
	TMR0_SET_COMPARE(val);
	SET_BIT(XTCCR0,XCOM00);
	SET_BIT(XTCCR0,XCOM01);
}
void TMR0_CALLBACK_OVERFLOW_INTERRUPT(void(*ptr_to_overflow_func)(void)){
	ptr_to_ovfi=ptr_to_overflow_func;
}
void TMR0_CALLBACK_OCM_INTERRUPT(void(*ptr_to_ocm_func)(void)){
	ptr_to_ocmi=ptr_to_ocm_func;
}
ISR(TIMER0_OVF_vect){
	(*ptr_to_ovfi)();
}
ISR(TIMER0_COMP_vect){
	(*ptr_to_ocmi)();
}