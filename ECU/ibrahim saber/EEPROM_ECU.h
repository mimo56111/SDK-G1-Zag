/*
 * EEPROM_ECU.h
 *
 * Created: 4/23/2020 2:56:51 AM
 *  Author: ibrahim
 */ 

#include "GPIO_MCAL.h"
#include "DATA_TYPE.h"
#include "stdmacros.h"
#include "REGISTERS.h"

#ifndef EEPROM_ECU_H_
#define EEPROM_ECU_H_


/*
Function name         :EEPROM_vWRITE
Function Description  :write the data that i want to keep after the power is off 
function Arguments    :unsigned short address ,unsigned char value
Function Returns      :void
*/

void EEPROM_vWRITE(u16 address,u8 value);


/*
Function name         :EEPROM_u8READ
Function Description  :reading from the EEPROM
function Arguments    :unsigned short address 
Function Returns      :unsigned char value
*/

u8 EEPROM_u8READ(const u16 address);




#endif /* EEPROM_ECU_H_ */