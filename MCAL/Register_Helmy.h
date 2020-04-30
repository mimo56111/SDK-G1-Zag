

#ifndef REGISTER_H_
#define REGISTER_H_

//=======================GPIO REGISTER========================//

/*====PORTA====*/

#define iDDRA  *((volatile unsigned char* const)0x3A)
#define iPORTA *((volatile unsigned char* const)0x3B)
#define iPINA  *((volatile unsigned char* const)0x39)

/*====PORTB====*/

#define iDDRB  *((volatile unsigned char* const)0x37)
#define iPORTB *((volatile unsigned char* const)0x38)
#define iPINB  *((volatile unsigned char* const)0x36)

/*====PORTC====*/

#define iDDRC  *((volatile unsigned char* const)0x34)
#define iPORTC *((volatile unsigned char* const)0x35)
#define iPINC  *((volatile unsigned char* const)0x33)

/*====PORTD====*/

#define iDDRD  *((volatile unsigned char* const)0x31)
#define iPORTD *((volatile unsigned char* const)0x32)
#define iPIND  *((volatile unsigned char* const)0x30)

//======================================================

//===================================== Timer Registers ===============================// 
    /* Timer 0 */
#define iTCNT0 *((volatile unsigned char* const)0x52)
/* Timer 0 Control register */
#define iTCCR0 *((volatile unsigned char* const)0x53)
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7

/* Timer 0 Interrupt Flag Register */
#define iTIFR *((volatile unsigned char* const)0x58)
#define TOV0  0
#define OCF0  1

/* Timer 0 Interrupt Mask Register */
#define iTIMSK *((volatile unsigned char* const)0x59)
#define TOIE0  0
#define OCIE0  1

/* Output Compare Register */
#define iOCR0 *((volatile unsigned char* const)0x5C)






















    /* Timer 1 */
#define iSFIOR *((volatile unsigned char* const)0x50)
    #define PUD     2
    #define iADTS0  5
    #define iADTS1  6
    #define iADTS2  7
//============================================
 
 
//===================================== EEPROM Registers ==============================//
#define iEEARH  *((volatile unsigned char* const)0X3F)
#define iEEARL  *((volatile unsigned char* const)0X3E)
#define iEEDR   *((volatile unsigned char* const)0X3D)
#define iEECR   *((volatile unsigned char* const)0X3C)

/* EEPROM Control Register */
#define iEERIE   3
#define iEEMWE   2
#define iEEWE    1
#define iEERE    0
//================================================================

//========================================= ADC Registers ===================================//
/*======= Port A =======*/
 /* ADC Multiplexer Selection Registers */
 #define iADMUX   *((volatile unsigned char* const)0X27)
    #define iMUX0   0
    #define iMUX1   1
    #define iMUX2   2
    #define iMUX3   3 
    #define iMUX4   4
	#define iADLAR  5
	#define iREFS0  6 
	#define iREFS1  7

 /* ADC	Control and Status Register A */
 #define iADCSRA *((volatile unsigned char* const)0X26)
   #define iADPS0  0
   #define iADPS1  1
   #define iADPS2  2
   #define iADIE   3
   #define iADIF   4
   #define iADATE  5
   #define iADSC   6
   #define iADEN   7
   
  /* ADC Data Registers */
  #define iADCH *((volatile unsigned char* const)0X25)
  #define iADCL *((volatile unsigned char* const)0X24)
  
 //======================================================
   
   
   
   
   
   
   
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


































#endif /* REGISTER_H_ */