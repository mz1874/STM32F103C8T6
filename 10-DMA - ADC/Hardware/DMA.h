#ifndef __DMA__
#define __DMA__
#include "stm32f10x.h"                  // Device header


void Init_DMA(uint32_t sourceAddr, uint32_t memoryAddr);
void startTransfer(uint8_t size);

#endif
