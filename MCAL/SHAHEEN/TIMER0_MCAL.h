/*
 * TIMER0_MCAL.h
 *
 * Created: 4/29/2020 1:07:06 PM
 *  Author: Shaheen
 */ 

#include "Datatypes.h"
#include "stdmacros.h"
#include "Registers.h"
#include <avr/interrupt.h>
#ifndef TIMER0_MCAL_H_
#define TIMER0_MCAL_H_

//**************MODES************

#define NORMAL 0
#define CTC 1
#define OCM_NOT_PWM 2
#define FAST_PWM 3
#define PHASE_CORRECT 4
//------------------------------

//**********overflow interrrupt**********

#define TOIE0_ENABLE 0
#define TOIE0_DISABLE 1
//----------------------------------

//*************ctc interrupt***********

#define OCIE0_ENABLE 0
#define OCIE0_DISABLE 1
//---------------------------------------

//************PRESCALING*****************

#define NO_CLK 0
#define NO_PRESCALING 1
#define PRESCALING_CLK8 2
#define PRESCALING_CLK64 3
#define PRESCALING_CLK256 4
#define PRESCALING_CLK1024 5
#define EXT_CLK_FALL 6
#define EXT_CLK_RIS 7
//--------------------------------------
u8 mode;
u8 prescalar;
u8 TMR0_OVERFLOW_INTERRUPT;
u8 TMR0_CTC_INTERRUPT;


struct TMR0_CONFG{
	u8 mode;
	u8 prescalar;
	u8 TMR0_OVERFLOW_INTERRUPT;
	u8 TMR0_CTC_INTERRUPT;
	}configration;

void TMR0_GET_CONFIG(u8 Mode,u8 Prescalar,u8 overflow_interrupt,u8 ctc_interrupt );//get the timer configrations

void TMR0_INIT(void);//initialize the timer

void TMR0_SET_COMPARE(u32 value);//set a value in OCR register to compare it with TCNT

u8 TMR0_READ_COUNT(void);//read the TCNT

void TMR0_SET_COUNTER(u8 value);//set the TCNT

//****WAVE_GEN****

void TMR0_COM_NON_PWM_GEN(u8 duty_cycle);//generate a wave in COM mode

void TMR0_FAST_PWM_GEN(u8 duty_cycle);//generate a wave in PWM mode

void TMR0_PHASE_CORRECT_GEN(u8 duty_cycle);//generate a wave in PHASE CORRECT mode

//*********************************

void TMR0_CALLBACK_OVERFLOW_INTERRUPT(void(*ptr_to_overflow_func)(void));//execute a function when an overflow interrupt happens

void TMR0_CALLBACK_OCM_INTERRUPT(void(*ptr_to_ocm_func)(void));//execute a function when an output compare match interrupt happens

#endif /* TIMER0_MCAL_H_ */