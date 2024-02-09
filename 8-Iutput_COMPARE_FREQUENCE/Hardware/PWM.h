#ifndef _PWM_H_
#define _PWM_H_

#include "stm32f10x.h"

void Init_PWM(void);

void setTimePulse(int index);

void setPrescaler(int index);


#endif
