#ifndef __ADC_H
#define __ADC_H
#include "stm32f10x.h"                  // Device header


void Init_ADC1(void);
uint16_t Get_ADC_Value(uint8_t ADC_Channel);

#endif
