#ifndef REGISTERS_H_
#define REGISTERS_H_
//---GPIO_REGISTERS---


//PORTA
#define XDDRA *((volatile unsigned char * const )0x3A)
#define XPORTA *((volatile unsigned char * const )0x3B)
#define XPINA *((volatile unsigned char * const )0x39)


//PORTB
#define XDDRB *((volatile unsigned char * const )0x37)
#define XPORTB *((volatile unsigned char * const )0x38)
#define XPINB *((volatile unsigned char * const )0x36)


//PORTC
#define XDDRC *((volatile unsigned char * const )0x34)
#define XPORTC *((volatile unsigned char * const )0x35)
#define XPINC *((volatile unsigned char * const )0x33)


//PORTD
#define XDDRD *((volatile unsigned char * const )0x31)
#define XPORTD *((volatile unsigned char * const )0x32)
#define XPIND *((volatile unsigned char * const )0x30)
//---------------------



//**************************************

//****************EEPROM REGISTERS***************

#define XEEARH *((volatile unsigned char * const)0x3F)
#define XEEARL *((volatile unsigned char * const)0x3E)
#define XEEDR  *((volatile unsigned char * const)0x3D)
#define XEECR  *((volatile unsigned char * const)0x3C)

//EEPROM contror register bits

#define XEERIE 3
#define XEEMWE 2
#define XEEWE  1
#define XEERE  0

//**************
// ADC Multiplexer selection regester
#define xADMUX *((volatile unsigned char *const)0x27)
#define xMUX0 0
#define xMUX1 1
#define xMUX2 2
#define xMUX3 3
#define xMUX4 4
#define xADLAR 5
#define xREFS0 6
#define xREFS1 7
// ADC control and status register
#define XADCSRA *((volatile unsigned char *const )0x26)
#define XADPS0 0
#define XADPS1 1
#define XADPS2 2
#define XADIE 3
#define XADIF 4
#define XADATE 5
#define XADSC 6
#define XADEN 7
//ADC Data Registers
#define XADCH *((volatile unsigned char *const)0x25)
#define XADCL *((volatile unsigned char *const)0x24) 
//Timer registers ---------------------------------------------
#define XTIMSK *((volatile unsigned char *const)0x59)
#define XTOIE0 0
#define XOCIE0 1
#define XTOIE2 6
#define XOCIE2 7

#define XTIFR *((volatile unsigned char *const)0x58)
#define XTOV0 0
#define XOCF0 1
#define XTOV2 6
#define XOCF2 7
/*TIMER0*/
#define XTCNT0 *((volatile unsigned char *const)0x52)
#define XOCR0  *((volatile unsigned char *const)0x5C)

#define XTCCR0 *((volatile unsigned char *const)0x53)
#define XFOC0 7
#define XWGM00 6
#define XCOM01 5
#define XCOM00 4
#define XWGM01 3
#define XCS02 2
#define XCS01 1
#define XCS00 0
/*timer1*/
#define XSFIOR *((volatile unsigned char * const)0x50)
#define PUD 2
#define XADTS0 5
#define XADTS1 6
#define XADTS2 7

//**********************
/*timer2*/
#define XTCNT2 *((volatile unsigned char *const)0x44)
#define XOCR2  *((volatile unsigned char *const)0x43)

#define XTCCR2 *((volatile unsigned char *const)0x45)
#define XFOC2 7
#define XWGM20 6
#define XCOM21 5
#define XCOM20 4
#define XWGM21 3
#define XCS22 2
#define XCS21 1
#define XCS20 0

//ACCR
#define XACCR *((volatile unsigned char *const)0x42)
#define XAS2 3
#define XTCN2UB 2
#define XOCR2UB 1
#define XTCR2UB 0
//----------------------------------------------
#endif