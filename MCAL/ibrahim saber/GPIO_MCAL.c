
 
#include "GPIO_MCAL.h "

/*===============================================INITIALIZATION===============================*/
//==============================================================================================
  void GPIO_voideInit(void){
	
	// choose the default value to data direction registers as INPUT
	
	MYDDRA = direction_INIT_Default ;
	MYDDRB = direction_INIT_Default ;
	MYDDRC = direction_INIT_Default ;
	MYDDRD=  direction_INIT_Default ;
		
}


/*===================================================PIN=================================*/
//=========================================================================================

void GPIO_vSETPIN_DIR(u8 portnum,u8 pinnum,u8 dir){
	switch (portnum){
	
		case 'A':
		case 'a':
			if (dir==1)
			{
		
			SET_BIT(MYDDRA,pinnum);
			}
			else
			{
			CLR_BIT(MYDDRA,pinnum);
			}				
			break;
		
		case 'B':
		case 'b':
			if (dir==1)
			{
				
			SET_BIT(MYDDRB,pinnum);
			}
			else
			{
			CLR_BIT(MYDDRB,pinnum);
			}	
			break;
				
		case 'C':
		case 'c':
			if (dir==1)
			{
				
				SET_BIT(MYDDRC,pinnum);
			}
			else
			{
				CLR_BIT(MYDDRC,pinnum);
			}
	
			break;	
			
		case 'D':
		case 'd':
			if (dir==1)
			{
				
				SET_BIT(MYDDRD,pinnum);
			}
			else
			{
				CLR_BIT(MYDDRD,pinnum);
			}
	
			break;	
			
		default: break;
	}
	
}

void GPIO_vwrite_PIN(u8 portnum,u8 pinnum,u8 val){
	switch (portnum){
		
		case 'A':
		case 'a':
			if(val==1)
			{
			SET_BIT(MYPORTA,pinnum);
			}
			else{
			
			CLR_BIT(MYPORTA,pinnum)	;
			
			}		
			break;
		case 'B':
		case 'b':
			if (val==1)
			{
			SET_BIT(MYPORTB,pinnum);
			} 
			else
			{
			CLR_BIT(MYPORTB,pinnum);
			}
				
			break;
		case 'C':
		case 'c':
			if (val==1)
			{
			SET_BIT(MYPORTC,pinnum);
			}
			else
			{
			CLR_BIT(MYPORTC,pinnum);
			}
		
			break;
		
		case 'D':
		case 'd':
			if (val==1)
			{
			SET_BIT(MYPORTD,pinnum);
			}
			else
			{
			CLR_BIT(MYPORTD,pinnum);
			}
		
			break;
	default: break;
	}
	
}

u8 GPIO_u8read_PIN(u8 portnum,u8 pinnum){
	u8 value = 0 ;
	
	switch (portnum){
		
		case 'A':
		case 'a':
		
			value = READ_BIT(MYPINA,pinnum);
	
			break;
		case 'B':
		case 'b':
		
			value = READ_BIT(MYPINB,pinnum);
		
			break;
		case 'C':
		case 'c':
		
			value = READ_BIT(MYPINC,pinnum);
		
			break;
		
		case 'D':
		case 'd':
		
			value = READ_BIT(MYPIND,pinnum);

			break;
		
	default: break;
	
	}
	
	return value;
}


void GPIO_vtoggle_PIN(u8 portnum,u8 pinnum){
	
	switch (portnum){
		
		case 'A':
		case 'a':
		
			 TOGGLE_BIT(MYPORTA,pinnum);
		
		break;
		case 'B':
		case 'b':
		
			  TOGGLE_BIT(MYPORTB,pinnum);
		
		break;
		case 'C':
		case 'c':
		
			  TOGGLE_BIT(MYPORTC,pinnum);
		
		break;
		
		case 'D':
		case 'd':
		
			 TOGGLE_BIT(MYPORTD,pinnum);

		break;
		
		default: break;
		
	}
	
	
}

/*=================================================PORT==============================*/
//======================================================================================

void GPIO_vSETPORT_DIR(u8 portnum,u8 dir){
	
	switch (portnum){
		
		case 'A':
		case 'a':
			MYDDRA=dir;
			break;
		
		case 'B':
		case 'b':
			MYDDRB=dir;
			break;

		case 'C':
		case 'c':
			MYDDRC=dir;
			break;
		
		case 'D':
		case 'd':
			MYDDRD=dir;
			break;
		
		default: break;
	}
	
}	
	
void GPIO_vwrite_PORT(u8 portnum,u8 portvalue) {
	
	switch (portnum){
		
		case 'A':
		case 'a':
			MYPORTA = portvalue;
			break;
		
		case 'B':
		case 'b':
			MYPORTB = portvalue;
			break;

		case 'C':
		case 'c':
			MYPORTC = portvalue;
			break;
		
		case 'D':
		case 'd':
			MYPORTD = portvalue;
			break;
		
		default: break;
	}
	
}
 
 u8 GPIO_u8read_PORT(u8 portnum){
	volatile u8 value = 0;
	 
	 switch (portnum){
		 
		 case 'A':
		 case 'a':
			 value = MYPINA;
			 break;
		 
		 case 'B':
		 case 'b':
			 value = MYPINB;
			 break;

		 case 'C':
		 case 'c':
			 value = MYPINC;
			break;
		 
		 case 'D':
		 case 'd':
			 value = MYPIND;
			 break;
		 
		 default: break;
	 }
	 
	 return value;
 }
 void GPIO_vtoggle_PORT(u8 portnum){
	 
	 switch (portnum){
		 
		 case 'A':
		 case 'a':
			 MYPORTA = ~MYPORTA;
			 break;
		 
		 case 'B':
		 case 'b':
			 MYPORTB = ~MYPORTB;
			 break;

		 case 'C':
		 case 'c':
			 MYPORTC = ~MYPORTC;
			 break;
		 
		 case 'D':
		 case 'd':
			 MYPORTD = ~MYPORTD;
			 break;
		 
		 default: break;
	 }	 
	 
 }
 
 
 void GPIO_vconnect_pull_up(u8 portnum ,u8 pinnum,u8 connect_pullup){
	
	switch(portnum){
			
		case 'A':
		case 'a':
			if (CONNECT==connect_pullup)
			{
				SET_BIT(MYPORTA,pinnum);
				CLR_BIT(MYSFIOR,PUD);
				
			}
			else
			{
				CLR_BIT(MYPORTA,pinnum);
			}
			break;
		
		case 'B':
		case 'b':
			if (CONNECT==connect_pullup)
			{
				SET_BIT(MYPORTB,pinnum);
				CLR_BIT(MYSFIOR,PUD);
			}
			else
			{
				CLR_BIT(MYPORTB,pinnum);
			}
			break;
		
		case 'C':
		case 'c':
			if (CONNECT==connect_pullup)
			{
				SET_BIT(MYPORTC,pinnum);
				CLR_BIT(MYSFIOR,PUD);
			}
			else
			{
				CLR_BIT(MYPORTC,pinnum);
			}
			break;
		
		case 'D':
		case 'd':
			if (CONNECT==connect_pullup)
			{
				SET_BIT(MYPORTD,pinnum);
				CLR_BIT(MYSFIOR,PUD);
			}
			else
			{
				CLR_BIT(MYPORTD,pinnum);
			}
			break;
		
		default: break;
	}

 }
 
  
 void GPIO_LOW_NIBBLE_vset_dir(u8 port ,u8 dir){
	
			if (dir==1){
				
				GPIO_vSETPIN_DIR(port,0,1);
				GPIO_vSETPIN_DIR(port,1,1);
				GPIO_vSETPIN_DIR(port,2,1);
				GPIO_vSETPIN_DIR(port,3,1);
			}
			else{
				
				GPIO_vSETPIN_DIR(port,0,0);
				GPIO_vSETPIN_DIR(port,1,0);
				GPIO_vSETPIN_DIR(port,2,0);
				GPIO_vSETPIN_DIR(port,3,0);				
				
			}
 }
 
 void GPIO_LOW_NIBBLE_vwrite(u8 port ,u8 value){
	 
	 value &=0x0f ;
	 
	switch (port){
	
		case 'A':
		case 'a':
		
				MYPORTA &= 0xf0 ;
				MYPORTA |= value ;
			break;
	
		case 'B':
		case 'b':
				MYPORTB &= 0xf0 ;
				MYPORTB	|= value ;
			break;

		case 'C':
		case 'c':
				MYPORTC &= 0xf0 ;
				MYPORTC	|= value ;
			break;
	
		case 'D':
		case 'd':
				MYPORTD &= 0xf0 ;
				MYPORTD	|= value ;
			break;
	
		default: break;
	} 
 
	 
 }
 
 
  
  void GPIO_HIGH_NIBBLE_vset_dir(u8 port ,u8 dir){
	  
	  if (dir==1){
		  
		  GPIO_vSETPIN_DIR(port,4,1);
		  GPIO_vSETPIN_DIR(port,5,1);
		  GPIO_vSETPIN_DIR(port,6,1);
		  GPIO_vSETPIN_DIR(port,7,1);
	  }
	  else{
		  
		  GPIO_vSETPIN_DIR(port,4,0);
		  GPIO_vSETPIN_DIR(port,5,0);
		  GPIO_vSETPIN_DIR(port,6,0);
		  GPIO_vSETPIN_DIR(port,7,0);
		  
	  }
  }
  void GPIO_HIGH_NIBBLE_vwrite(u8 port ,u8 value){
	   value <<=4 ;
	  
	  switch (port){
		  
		  case 'A':
		  case 'a':
		  
		  MYPORTA &= 0x0f ;
		  MYPORTA |= value ;
		  break;
		  
		  case 'B':
		  case 'b':
		  MYPORTB &= 0x0f ;
		  MYPORTB	|= value ;
		  break;

		  case 'C':
		  case 'c':
		  MYPORTC &= 0x0f ;
		  MYPORTC	|= value ;
		  break;
		  
		  case 'D':
		  case 'd':
		  MYPORTD &= 0x0f ;
		  MYPORTD	|= value ;
		  break;
		  
		  default: break;
	  }
	  
	  
  }