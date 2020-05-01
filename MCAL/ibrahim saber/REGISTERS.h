/* 

*REGISTER.h

*/
 
#ifndef REGISTER_H_
#define REGISTER_H_


/*=========================GPIO REGISTERS==================*/
         
		    /* PORTA*/
			
 #define MYDDRA   *((volatile unsigned char* const)0x3A)
 #define MYPORTA  *((volatile unsigned char* const)0x3B)
 #define MYPINA   *((volatile unsigned char* const)0x39)
 
           /*PORTB*/
		   
#define MYDDRB   *((volatile unsigned char* const)0x37)
#define MYPORTB  *((volatile unsigned char* const)0x38)
#define MYPINB   *((volatile unsigned char* const)0x36)

           /*PORTC*/

#define MYDDRC   *((volatile unsigned char* const)0x34)		   
#define MYPORTC  *((volatile unsigned char* const)0x35)
#define MYPINC   *((volatile unsigned char* const)0x33)

          /*PORTD*/
		  
#define MYDDRD   *((volatile unsigned char* const)0x31)
#define MYPORTD  *((volatile unsigned char* const)0x32)
#define MYPIND   *((volatile unsigned char* const)0x30)		  
		
/*========================================== TIMER REGISTERS========================================================*/
//=============================================================================================================

           /* TIMER 1*/

#define MYSFIOR    *((volatile unsigned char* const)0x50)
	#define PUD			2
	#define MYADTS0		5
	#define MYADTS1		6
	#define MYADTS2		7


/*=========================================EEPROM REGISTERS=============================================================*/
//=========================================================================================================================

#define MYEEARL    *((volatile unsigned char* const)0x3E)
#define MYEEARH    *((volatile unsigned char* const)0x3F)
#define MYEECR     *((volatile unsigned char* const)0x3C)
#define MYEEDR     *((volatile unsigned char* const)0x3D)

	#define MYEERE     0
	#define MYEEWE     1 
	#define MYEEMWE    2
	#define MYEERIE    3


/*==============================================ADC REGISTER===========================================================================*/
//=================================================================================================================================

/*===========data register===================================*/

#define	MYADCL			 *((volatile unsigned char* const)0x24)
#define MYADCH			 *((volatile unsigned char* const)0x25)

/*===========Multiplixer selsction===================================*/

#define MYADMUX           *((volatile unsigned char* const)0x27)
	#define MYMUX0	  0
	#define MYMUX1    1
	#define MYMUX2    2
	#define MYMUX3    3
	#define MYMUX4	  4
	#define MYADLAR   5
	#define MYREFS0   6
	#define MYREFS1   7
	


/*==========================ADC controle and status register=============*/

#define MYADCSRA 		    *((volatile unsigned char* const)0x26)

	#define MYADPS0		0
	#define MYADPS1		1
	#define MYADPS2		2
	#define MYADIE		3
	#define MYADIF		4
	#define MYADATE		5
	#define MYADSC		6	
	#define MYADEN		7
	
		   
#endif		   