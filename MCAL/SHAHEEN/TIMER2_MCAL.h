/*
 * TIMER2_MCAL.h
 *
 * Created: 4/29/2020 11:26:46 PM
 *  Author: Shaheen
 */ 
#include "Datatypes.h"
#include "stdmacros.h"
#include "Registers.h"
#include <avr/interrupt.h>

#ifndef TIMER2_MCAL_H_
#define TIMER2_MCAL_H_
//*********MODES***********
enum{
		NORMAL2,
		PHASE_CORRECT2,
		CTC2,
		FAST_PWM2
	};

//---------------------
//**************PRESCALING**************
enum{
		 NO_CLK2,
		 NO_PRESCALING2, 
		 PRESCALING2_CLK8, 
		 PRESCALING2_CLK32, 
		 PRESCALING2_CLK64, 
		 PRESCALING2_CLK128, 
		 PRESCALING2_CLK256, 
		 PRESCALING2_CLK1024 
	};

//--------------------------------------

//************timer2 overflow interrupt**********
enum{
		TOIE2_ENABLE,
		TOIE2_DISABLE
	};

//-------------------------------

//************timer2 ctc interrupt*************
 enum{
		OCIE2_ENABLE,
		OCIE2_DISABLE
	 };
//-------------------------
u8 mode2;
u8 prescalar2;
u8 TMR2_OVERFLOW_INTERRUPT;
u8 TMR2_CTC_INTERRUPT;

struct TMR2_CONFIG{
		u8 mode2;
		u8 prescalar2;
		u8 TMR2_OVERFLOW_INTERRUPT;
		u8 TMR2_CTC_INTERRUPT;

	}configration2;
void TMR2_GET_CONFIG(u8 mode,u8 prescalar,u8 overflow_interrupt,u8 ctc_interrupt);//get the timer configrations

void TMR2_INIT(void);//initialize the timer

void TMR2_SET_COMPARE(u8 value);//set a value in OCR register to compare it with TCNT

void TMR2_READ_COUNT(u8 *val);//read the TCNT

void TMR2_SET_COUNTER(u8 value);//SET the TCNT

//*************wave gen***************
void TMR2_COM_NON_PWM_GEN(u8 duty_cycle);//generate a wave in COM mode


void TMR2_FAST_PWD_GEN(u8 duty_cycle);//generate a wave in PWM mode


void TMR2_PHASE_CORRECT_GEN(u8 duty_cycle);//generate a wave in PHASE CORRECT mode

//******callback********************
void TMR2_CALLBACK_OVERFLOW_INTERRUPT(void(*ptr_to_overflow_func)(void));//execute a function when an overflow interrupt happens
void TMR2_CALLBACK_OCM_INTERRUPT(void(*ptr_to_ocm_func)(void));//execute a function when an output compare match interrupt happens

#endif /* TIMER2_MCAL_H_ */