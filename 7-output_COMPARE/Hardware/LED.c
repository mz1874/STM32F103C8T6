#include "stm32f10x.h"                  // Device header
#include "LED.h"



void LED_Init(void)
{
    /* ¿ªÆôAPB2Ê±ÖÓ */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct_Output;
    GPIO_InitStruct_Output.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct_Output.GPIO_Mode= GPIO_Mode_Out_PP;
		GPIO_InitStruct_Output.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct_Output);
		GPIO_SetBits(GPIOB, GPIO_Pin_7);
}
void LED1_ON(void)
{
    GPIO_SetBits(GPIOB, GPIO_Pin_7);
}


void LED1_OFF(void)
{
	  GPIO_ResetBits(GPIOB, GPIO_Pin_7);
}
