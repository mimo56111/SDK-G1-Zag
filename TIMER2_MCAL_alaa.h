/*
 * TIMER2_MCAL.h
 *
 *  Author: Genius
 */ 


#ifndef TIMER2_MCAL_H_
#define TIMER2_MCAL_H_

#include "Register.h"
#include "stdmacros.h"
#include "Data_type.h"
#include <avr/interrupt.h>

#define NO_CLK              0
#define NO_prescalling       1
#define PRESCALING_8        2
#define PRESCALING_32       3
#define PRESCALING_64       4
#define PRESCALING_128      5
#define PRESCALING_256      6 
#define PRESCALING_1024     7


#define   TMR2_CTC  0
#define   TMR2_Fast_PWM    2
#define   TMR2_NORMAL    1
#define   TMR2_NON_PWM   4 
#define   TMR2_Phase_Correct_PWM   3



#define   OCIE2_enable  0
#define   OCIE2_disable  1

#define   TOIE2_enable  0
#define   TOIE2_disable  1

u8 TMR2_Mode;
u8 TMR2_OCIE2 ;
u8 TMR2_OVFIE2 ;
u8 Prescalar2 ;

struct TMR2_Configuration{
	u8 TMR2_Mode;
	u8 TMR2_OCIE2 ;
	u8 TMR2_OVFIE2 ;
	u8 Prescalar2 ;
}configuration2;


// set or write>>> varible
//get or read >>> pointer
//U8>> unsigned char

void   TMR2_Init(struct TMR2_Configuration  configuration2);
u8    TMR2_ReadCounterValue();
void  TMR2_Set_Compare_Value(u8 u8Val);
void  TMR2_set_TOV_Num(u8  val);
u8    TMR2_get_TOV_Num();
void  TMR2_Fast_PWM_gen(u8 dutycycle);
void  TMR2_Phase_Correct_PWM_non(u8  dutycycle);
void TMR2_COM_Non_PWM_Gen(u8 duty_cycle);

u8   TMR2_GET_NUMof_TICKS();


void   callback_OCR2(void*(OCR2_pointer)(void));
void   callback_OVI2(void*(OVI2_pointer)(void));





#endif /* TIMER2_MCAL_H_ */