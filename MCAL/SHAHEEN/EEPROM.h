/*
 * EEPROM.h
 *
 * Created: 4/12/2020 3:19:42 AM
 *  Author: Shaheen
 */ 

#include "Registers.h"
#include "Datatypes.h"
#include "stdmacros.h"
#ifndef EEPROM_H_
#define EEPROM_H_
//EEPROM WRITE


void EEPROM_WRITE(u16 address,u8 data);


//EEPROM READ


u8 EEPROM_READ(const u16 address);	


#endif /* EEPROM_H_ */