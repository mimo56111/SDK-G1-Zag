
#ifndef STDMACROS_H_
#define STDMACROS_H_

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)

#endif /* STDMACROS_H_ */