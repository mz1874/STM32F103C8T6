#include "stm32f10x.h"                  // Device header
#ifndef __SERIAL__
#define __SERIAL__
#include <stdio.h>


void Init_UART(void);

void SendData(uint8_t Data);

void Send_Array(uint8_t *Data);

void Send_String(char *string);

void sendNumber(uint32_t number);

void sendFloat(float value, uint8_t decimalPlaces);
#endif

