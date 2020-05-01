/*
* std_Macros.h
* standard macros used setting or clearing or toggling or reading a bit


*/

#ifndef STDMACROS_H_
#define STDMACROS_H_

#define SET_BIT(REG,BIT) REG|=(1<<BIT)

#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)

#define CLR_BIT(REG,BIT) REG&=(~(1<<BIT))

#define READ_BIT(REG,BIT) ((REG&(1<<BIT))>>BIT)


#define IS_BIT_CLEAR(REG,BIT) !((REG&(1<<BIT))>>BIT)




#endif 