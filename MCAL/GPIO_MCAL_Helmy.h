#define u8_Direction_input 0x00
//the default initialization for GPIO//
#define Init_Direction_default u8_Direction_input


#include "Data_Type.h"
#include "Register.h"
#include "StdMacros.h"
#define Connect 1
#define Notconnect 0


#ifndef GPIO_MCAL_H_
#define GPIO_MCAL_H_
 
//=============================== Initialization ============================//
 
 /* Initialization all ports */
    void GPIO_voidInit(void);
 
 //=============================================//
 /********************************************************/
 
 //==================================== PIN =================================//
 /*
 Function name        : GPIO_vsetPIN_Dir    
 Function return      : void
 Function Arguments   : unsigned char port name , unsigned char pin number , unsigned char pin direction
 Function Description : set the direction of the given pin in the given port (direction : output = 1 , input = 0 )
 */
 void GPIO_vsetPIN_Dir(u8 portname , u8 pinnum , u8 dir );
 
 /*
 Function name        : GPIO_vwrite_PIN
 Function return      : void
 Function Arguments   : unsigned char port name , unsigned char pin number , unsigned char value
 Function Description :set the value of the given pin in the given port (output value : high = 1 , low = 0 )
 */
 void GPIO_vwrite_PIN(u8 portname, u8 pinnum, u8 value);
 
 /*
 Function name        : GPIO_vtoggle_PIN
 Function return      : void
 Function Arguments   : unsigned char port name, unsigned char pin number
 Function Description : reverse the value of the given pin in the given port
 */
   void GPIO_vtoggle_PIN(u8 portname, u8 pinnum);
   
 /*
 Function name        : GPIO_u8read_PIN
 Function return      : unsigned char
 Function Arguments   : unsigned char port name , unsigned char pin number
 Function Description : return 1 if the value of the pin is HIGH and 0 if the value is LOW
 */
  u8 GPIO_u8read_PIN(u8 portname , u8 pinnum);
  
  
/*
 Function Name        : GPIO_vconnectpullup
 Function Returns     : void
 Function Arguments   : char port name ,char pin number, char connect_pullup
 Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
  void GPIO_vconnectpullup(u8 port, u8 pin , u8 connect_pullup);	
  


//==========================================================//

//==================================== PORT =================================//
 /*
 Function name        : GPIO_vsetPORT_Dir    
 Function return      : void
 Function Arguments   : unsigned char port name , unsigned char pin direction
 Function Description : set the direction of the given port (direction : output = 1 , input = 0 )
 */
   void GPIO_vsetPORT_Dir(u8 portname , u8 dir);
	

 /*
 Function name        : GPIO_vwrite_PORT
 Function return      : void
 Function Arguments   : unsigned char port name , unsigned char port value
 Function Description :set the value of the given port (output value : high = 1 , low = 0 )
 */
    void GPIO_vwrite_PORT(u8 portname, u8 value);
   
/*
Function name        : GPIO_vtoggle_PORT
Function return      : void
Function Arguments   : unsigned char port name
Function Description : reverse the value of the port
*/
  void GPIO_vtoggle_PORT(u8 portname);
  
/*
Function name        : GPIO_u8read_PORT
Function return      : unsigned char
Function Arguments   : unsigned char port name 
Function Description : return 1 if the value of the port is HIGH and 0 if the value is LOW
*/
 u8 GPIO_u8read_PORT(u8 portname);

//=========================================================//

//============================================ NIBBLE =========================================//
//========================================= HIGH NIBBLE =======================================//

/*
* Function name        : GPIO_High_Nibble_vset_Dir
* Function return      : void
* Function Arguments   : unsigned char port name , unsigned char pin direction
* Function Description : set the four bit (4,5,6,7) as output pin
*/
  void GPIO_High_Nibble_vset_Dir(u8 port,u8 dir);


/*
* Function name        : GPIO_High_Nibble_vwrite
* Function return      : void
* Function Arguments   : unsigned char port name , unsigned char value
* Function Description : write the four bit (4,5,6,7) as high
*/
  void GPIO_High_Nibble_vwrite(u8 port, u8 value);

//==================================================//
//=========================================== LOW NIBBLE =====================================//

/*
* Function name        : GPIO_High_Nibble_vset_Dir
* Function return      : void
* Function Arguments   : unsigned char port name , unsigned char pin direction
* Function Description : set the four bit (0,1,2,3) as output pin
*/
   void GPIO_Low_Nibble_vset_Dir(u8 port,u8 dir);

/*
* Function name        : GPIO_High_Nibble_vwrite
* Function return      : void
* Function Arguments   : unsigned char port name , unsigned char value
* Function Description : write the four bit (0,1,2,3) as high
*/
  void GPIO_Low_Nibble_vwrite(u8 port,u8 value);
  
//=========================================================//

#endif /* GPIO_MCAL_H_ */