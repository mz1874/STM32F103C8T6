#ifndef __ADC_H
#define __ADC_H
#include "stm32f10x.h"                  // Device header


void Init_ADC1(void);
void Get_ADC_Value();

extern uint16_t data[4];

#endif
