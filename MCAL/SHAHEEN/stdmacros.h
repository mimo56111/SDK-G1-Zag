#ifndef STDMACROS_H_
#define STDMACROS_H_//standard macros

#define SET_BIT(reg,bit) reg|=(1<<bit)

#define RESET_BIT(reg,bit) reg&=~(1<<bit)

#define TOGGLE_BIT(reg,bit) reg^=(1<<bit)

#define READ_BIT(reg,bit) ((reg&=1<<bit)>>bit)

#define IS_BIT_CLR(reg,bit) ((reg&=1<<bit)>>bit)

#endif