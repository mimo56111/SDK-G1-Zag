/*
 * EEPROM_ECU.c
 *
 * Created: 4/23/2020 2:59:43 AM
 *  Author: ibrahim
 */ 

#include "EEPROM_ECU.h"
#include "DATA_TYPE.h"
#include "REGISTERS.h"

void EEPROM_vWRITE(u16 address,u8 value){
	
	MYEEARL = (u8)address;
	MYEEARH = (u8)(address>>8);
	MYEEDR  = value;
	SET_BIT(MYEECR,MYEEMWE);
	SET_BIT(MYEECR,MYEEWE);
	while(READ_BIT(MYEECR,MYEEWE)==1);
	
}

u8 EEPROM_u8READ( const u16 address){
	MYEEARL = (u8)address;
	MYEEARH = (u8) (address>>8);
	SET_BIT(MYEECR,MYEERE);
	
	return MYEEDR;
}