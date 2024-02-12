#include "DMA.h"



void Init_DMA(uint32_t sourceAddr, uint32_t memoryAddr)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    DMA_InitTypeDef DMA_InitStruct;
	
	
	
		DMA_InitStruct.DMA_PeripheralBaseAddr= sourceAddr;
	
//		DMA_InitStruct.DMA_BufferSize= 4;

    DMA_InitStruct.DMA_DIR= DMA_DIR_PeripheralSRC;

    DMA_InitStruct.DMA_M2M= DMA_M2M_Enable ;

    DMA_InitStruct.DMA_MemoryBaseAddr= memoryAddr;

    DMA_InitStruct.DMA_MemoryDataSize= DMA_MemoryDataSize_Byte;

    DMA_InitStruct.DMA_MemoryInc= DMA_MemoryInc_Enable;
		
    DMA_InitStruct.DMA_Mode= DMA_Mode_Normal;

    DMA_InitStruct.DMA_PeripheralDataSize= DMA_PeripheralDataSize_Byte;

    DMA_InitStruct.DMA_PeripheralInc= DMA_PeripheralInc_Enable;

    DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;

    DMA_Init(DMA1_Channel1, &DMA_InitStruct);
		
		

}

void startTransfer(uint8_t size)
{
		DMA_Cmd(DMA1_Channel1, DISABLE);
		DMA_SetCurrDataCounter(DMA1_Channel1, size);
		DMA_Cmd(DMA1_Channel1, ENABLE);
		while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
}