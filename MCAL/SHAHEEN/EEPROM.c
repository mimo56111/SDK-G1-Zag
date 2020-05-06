/*
 * EEPROM.c
 *
 * Created: 4/12/2020 3:19:55 AM
 *  Author: Shaheen
 */ 
#include "EEPROM.h"
void EEPROM_WRITE(u16 address,u8 data){
	XEEARL=(u8)address;
	XEEARH=(u8)(address>>8);
	XEEDR=data;
	SET_BIT(XEECR,XEEMWE);
	SET_BIT(XEECR,XEEWE);
	while((READ_BIT(XEECR,XEEWE))==1);
}
u8 EEPROM_READ(const u16 address){
	XEEARL=(u8)address;
	XEEARH=(u8)(address>>8);
	SET_BIT(XEECR,XEERE);
	return XEEDR;
}

