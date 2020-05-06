/*
* has the prototype of the functions
* micro control abstraction layer(MCAL)
* contains microcontroller's built in drivers

*/
#define u8_direction_input 0x00
#define direction_INIT_Default  u8_direction_input
#include "DATA_TYPE.h"
#include "REGISTERS.h"
#include "stdmacros.h"
#define CONNECT     1
#define NOT_CONNECT 0
#ifndef GPIO_MCAL_H_
#define GPIO_MCAL_H_



//==================================================================================
/* ========================= intialization =======================================*/

/*
 * description : initialize the micro controller
*/

	void GPIO_voideInit(void);
	
//==================================================================================	
/*========================= PIN ==================================================*/
 
 /*
 Function name         :GPIO_vSETPIN_DIR
 Function Description  :set the direction of given pin in a given port (1=OUTPUT  ,0=INPUT)
 function Arguments    :unsigned char portnum  ,unsigned char pinnum ,unsigned char direction
 Function Returns      :void
 
 */

void GPIO_vSETPIN_DIR(u8 portnum,u8 pinnum,u8 dir);


/*
 Function name         :GPIO_vwrite_PIN
 Function Description  :write in a given pin in a given port (1=HIGH ,0=LOW)
 function Arguments    :unsigned char portnum  ,unsigned char pinnum ,unsigned char value
 Function Returns      :void
 
 */



void GPIO_vwrite_PIN(u8 portnum,u8 pinnum,u8 val);


/*
 Function name         :GPIO_u8read_PIN
 Function Description  :read a given pin in a given port (1=HIGH ,0=LOW)
 function Arguments    :unsigned char portnum  ,unsigned char pinnum 
 Function Returns      :unsigned char
 
 
 */


u8 GPIO_u8read_PIN(u8 portnum,u8 pinnum);


/*
 Function name         :GPIO_vtoggle_PIN
 Function Description  :toggle a given pin in a given port 
 function Arguments    :unsigned char portnum  ,unsigned char pinnum 
 Function Returns      :void
 
 
 */


void GPIO_vtoggle_PIN(u8 portnum,u8 pinnum);

//=================================================================================
/*================================ PORT ==========================================*/

/*
 Function name         :GPIO_vSETPORT_DIR
 Function Description  :set the direction of given port (1=OUTPUT  ,0=INPUT)
 function Arguments    :unsigned char portnum ,unsigned char direction
 Function Returns      :void
 
 
 */

void GPIO_vSETPORT_DIR(u8 portnum,u8 dir);

/*
 Function name         :GPIO_vwrite_PORT
 Function Description  :write a value on a given port (1=HIGH  ,0=LOW)
 function Arguments    :unsigned char portnum ,unsigned char value
 Function Returns      :void
 
 
 */

void GPIO_vwrite_PORT(u8 portnum,u8 portvalue);


/*
 Function name         :GPIO_vread_PORT
 Function Description  :read a value from a given port (1=HIGH  ,0=LOW)
 function Arguments    :unsigned char portnum ,unsigned char value
 Function Returns      :unsigned char 
 
 
 */


u8 GPIO_u8read_PORT(u8 portnum);


/*
 Function name         :GPIO_vtoggle_PORT
 Function Description  :toggle a given port 
 function Arguments    :unsigned char portnum 
 Function Returns      :void 
 
 
 */


void GPIO_vtoggle_PORT(u8 portnum);



/*

*FUNCTION name         :GPIO_vconnect_pull_up
*FUNCTION description  :*enable the internal pull up resistance 
						*by making the (PIN input && write 1 on the pin && and clear the PUD PIN in the SFIOR register)  

*FUNCTION arguments    :*unsigned char portnum ,unsigned char pinnum ,
					    *unsigned char connect_pullup(CONNECT=1,NOT_CONNECT=0)
                       
*FUNCTION return       :void

*/

void GPIO_vconnect_pull_up(u8 portnum ,u8 pinnum,u8 connect_pullup);


/*===============================LOW NIBBLE======================================================================*/
//===============================================================================================================

/*
 Function name         :GPIO_LOW_NIBBLE_vset_dir
 Function Description  :set the direction of the bits(0..3)
 function Arguments    :unsigned char port ,unsigned char dir
 Function Returns      :void
 
 */
void GPIO_LOW_NIBBLE_vset_dir(u8 port,u8 dir);

/*
 Function name         :GPIO_LOW_NIBBLE_vwrite
 Function Description  :write a value on the bits(0..3)
 function Arguments    :unsigned char port ,unsigned char value 
 Function Returns      :void
 
 */
void GPIO_LOW_NIBBLE_vwrite(u8 port,u8 value);

/*===============================HIGH NIBBLE==================================================================*/
//===============================================================================================================

/*
 Function name         :GPIO_HIGH_NIBBLE_vset_dir
 Function Description  :set the direction of the bits(4..7)
 function Arguments    :unsigned char port ,unsigned char dir
 Function Returns      :void
 
 */
void GPIO_HIGH_NIBBLE_vset_dir(u8 port ,u8 dir);

/*
 Function name         :GPIO_vHIGH_NIBBLE_write
 Function Description  :write a value on the bits(4..7)
 function Arguments    :unsigned char port ,unsigned char value 
 Function Returns      :void
 
 */
void GPIO_HIGH_NIBBLE_vwrite(u8 port ,u8 value);




#endif