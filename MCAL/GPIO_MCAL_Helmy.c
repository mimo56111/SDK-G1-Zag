/*
 * GPIO.c
 * It has Functions that used in ( set & clear & toggle & read & port
 * It is in MCAL
 */ 

#include "GPIO_MCAL.h"
//=============================== Initialization ============================//

 void GPIO_voidInit(void){
	 /* DDR  Initialization */
 iDDRA = Init_Direction_default;
 iDDRB = Init_Direction_default;
 iDDRC = Init_Direction_default; 
 iDDRD = Init_Direction_default; 
 }
//==========================================================//
 
//==================================== PIN ===================================//

void GPIO_vsetPIN_Dir(u8 portname, u8 pinnum, u8 dir){
	switch(portname){
		case 'A' :
		case 'a' :
		   if (dir==1){
			   SET_BIT(iDDRA,pinnum);
		   }else{
			   CLR_BIT(iDDRA,pinnum);
		   }
		   break;
		 case 'B' :
		 case 'b' :
		   if (dir==1){
			   SET_BIT(iDDRB,pinnum);
		   }else{
			   CLR_BIT(iDDRB,pinnum);
		   }
		   break;
		 case 'C' :
		 case 'c' :
		   if (dir==1){
			   SET_BIT(iDDRC,pinnum);
		   }else{
			   CLR_BIT(iDDRC,pinnum);
		   }
		   break;
		 case 'D' :
		 case 'd' :
		   if (dir==1){
			   SET_BIT(iDDRD,pinnum);
		   }else{
			   CLR_BIT(iDDRD,pinnum);
		   }
		   break;
		   default: break;
		   }		 
}

void GPIO_vwrite_PIN(u8 portname, u8 pinnum, u8 value){
	switch(portname){
		case 'A':
		case 'a':
	       if (value==1){
		       SET_BIT(iPORTA,pinnum);
	       }else{
		       CLR_BIT(iPORTA,pinnum);
	       }
	       break;
		case 'B':
	    case 'b':
		   if (value==1){
			   SET_BIT(iPORTB,pinnum);
		   }else{
			   CLR_BIT(iPORTB,pinnum);
		   }
		   break;
	    case 'C':
		case 'c':
		   if (value==1){
			   SET_BIT(iPORTC,pinnum);
		   }else{
			   CLR_BIT(iPORTC,pinnum);
		   }
		   break;  
		case 'D':
		case 'd':
		   if (value==1){
			   SET_BIT(iPORTD,pinnum);
		   }else{
			   CLR_BIT(iPORTD,pinnum);
		   }
		   break;
		   default:break;	   	   
	}	
}

void GPIO_vtoggle_PIN(u8 portname, u8 pinnum){
	switch(portname){
		case 'A':
		case 'a':
		   TOGGLE_BIT(iPORTA,pinnum);
		   break;
	    case 'B':
		case 'b':
		   TOGGLE_BIT(iPORTB,pinnum);
		   break;
		case 'C':
		case 'c':
			TOGGLE_BIT(iPORTC,pinnum);
			break;	
		case 'D':
		case 'd':
			TOGGLE_BIT(iPORTD,pinnum);
			break;
			default:break;			
	}
}

u8 GPIO_u8read_PIN(u8 portname , u8 pinnum){
	u8 x=0;
	switch(portname){
		case 'A':
		case 'a':
		    x = READ_BIT(iPINA , pinnum);
			break;
		case 'B':
		case 'b':
			x = READ_BIT(iPINB , pinnum);
			break;
		case 'C':
		case 'c':
			x = READ_BIT(iPINC , pinnum);	
			break;
		case 'D':
		case 'd':
			x = READ_BIT(iPIND , pinnum);	
			break;
			default: break;	
	}
	return x;
}


void GPIO_vconnectpullup( u8 port, u8 pin , u8 connect_pullup ){
	switch (port){
		case 'A' :
		case 'a' :
		if (Connect==connect_pullup){
			SET_BIT(iPORTA,pin);
			CLR_BIT(iSFIOR,PUD);
		}else{
			CLR_BIT(iPORTA,pin);
		}
		break;
		case 'B' :
		case 'b' :
		if (Connect==connect_pullup){
			SET_BIT(iPORTB,pin);
			CLR_BIT(iSFIOR,PUD);
		}else{
			CLR_BIT(iPORTB,pin);
		}
		break;
		case 'C' :
		case 'c' :
		if (Connect==connect_pullup){
			SET_BIT(iPORTC,pin);
			CLR_BIT(iSFIOR,PUD);
		}else{
			CLR_BIT(iPORTC,pin);
		}
		break;
		case 'D' :
		case 'd' :
		if (Connect==connect_pullup){
			SET_BIT(iPORTD,pin);
			CLR_BIT(iSFIOR,PUD);
		}else{
			CLR_BIT(iPORTD,pin);
		}
		default:break;
	}
	
}



//==========================================================//

//=========================================== PORT ======================================//


void GPIO_vsetPORT_Dir(u8 portname, u8 dir){
	switch(portname){
		case 'A' :
		case 'a' :
		        iDDRA=dir;
			    break;
		case 'B' :
		case 'b' :
		        iDDRB=dir;
				break;
		case 'C' :
		case 'c' :
	            iDDRC=dir;
				break;
		case 'D' : 
		case 'd' :
		        iDDRD=dir;
		        break;
		default: break;
	}
}


void GPIO_vwrite_PORT(u8 portname, u8 value){
	switch(portname){
		case 'A' :
		case 'a' :
		   iPORTA=value;
		break;
		case 'B' :
		case 'b' :
		   iPORTB=value;
		break;
		case 'C' :
		case 'c' :
		   iPORTC=value;
		break;
		case 'D' :
		case 'd' :
		   iPORTD=value;
		break;
		default: break;
	}
}

void GPIO_vtoggle_PORT(u8 portname){
	switch(portname){
		case 'A' :
		case 'a' :
		   iPORTA = ~iPORTA;
		break;
		case 'B' :
		case 'b' :
		   iPORTB = ~iPORTB;
		break;
		case 'C' :
		case 'c' :
		   iPORTC = ~iPORTC;
		break;
		case 'D' :
		case 'd' :
		   iPORTD = ~iPORTD;
		break;
		default: break;
	}
}

u8 GPIO_u8read_PORT(u8 portname){
	volatile u8 val=0;
	switch(portname){
		case 'A':
		case 'a':
		    val = iPINA;
			break;
		case 'B':
		case 'b':
		    val = iPINB;
		    break;
		case 'C':
		case 'c':
		    val = iPINC;
		    break;
		case 'D':
		case 'd':
		   val = iPIND;
		   break;	
	}
	return val;
}
//============================================ NIBBLE =========================================//
//========================================= HIGH NIBBLE =======================================//
 
 void GPIO_High_Nibble_vset_Dir(u8 port,u8 dir){
	 if (dir==1){
	 GPIO_vsetPIN_Dir(port,4,1);
	 GPIO_vsetPIN_Dir(port,5,1);
	 GPIO_vsetPIN_Dir(port,6,1);
	 GPIO_vsetPIN_Dir(port,7,1);
	 }else{}	 
 }

void GPIO_High_Nibble_vwrite(u8 port, u8 value){
	value <<= 4;
	switch(port){
		case 'A':
		case 'a':
		     iPORTA &= 0x0f;
			 iPORTA |= value;
			 break;
		case 'B':
		case 'b':
		    iPORTB &= 0x0f;
		    iPORTB |= value;
		    break;
		case 'C':
		case 'c':
		    iPORTC &= 0x0f;
		    iPORTC |= value;
		    break;
		case 'D':
		case 'd':
		    iPORTD &= 0x0f;
		    iPORTD |= value;
		break;
	default: break;
}
}

//===============================================//
//=========================================== LOW NIBBLE =====================================//

 
 void GPIO_Low_Nibble_vset_Dir(u8 port,u8 dir){
	 if (dir==1){
	 GPIO_vsetPIN_Dir(port,0,1);
	 GPIO_vsetPIN_Dir(port,1,1);
	 GPIO_vsetPIN_Dir(port,2,1);
	 GPIO_vsetPIN_Dir(port,3,1);
	 }else{}	 
 }
 
 void GPIO_Low_Nibble_vwrite(u8 port, u8 value){
	  value &= 0x0f;
	 switch(port){
		 case 'A':
		 case 'a':
		     iPORTA &= 0xf0;
		     iPORTA |= value;
		     break;
		 case 'B':
		 case 'b':
		     iPORTB &= 0xf0;
		     iPORTB |= value;
		     break;
		 case 'C':
		 case 'c':
		     iPORTC &= 0xf0;
		     iPORTC |= value;
		     break;
		 case 'D':
		 case 'd':
		     iPORTD &= 0xf0;
		     iPORTD |= value;
		     break;
	 default: break;
 }
 } 
 
//============================================================//


