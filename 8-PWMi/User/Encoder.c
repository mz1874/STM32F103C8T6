#include "Encoder.h"

void Init_Encorder(void){
	/********************************START CONFIG TIME BASE UNIT**********************************/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    // INIT GPIOA PA0
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;

    // !!!!
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    //INIT TIME BASE UINT
    TIM_TimeBaseInitTypeDef TimeBaseInitStruct;

    // SER CLOCK DIVISION
    TimeBaseInitStruct.TIM_ClockDivision= TIM_CKD_DIV1;
    // UP DOWN OR CENTER A
    TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;

    TimeBaseInitStruct.TIM_RepetitionCounter= 0X00;

    // count 10000 time = 1s
    TimeBaseInitStruct.TIM_Period= 65536 - 1;   //ARR

    // SET PRESCALER  72MHZ / 7200 = 10 000 HZ
    TimeBaseInitStruct.TIM_Prescaler = 1 - 1; // PSC

    //init time baseInit
    TIM_TimeBaseInit(TIM3, &TimeBaseInitStruct);
    /********************************END CONFIG TIME BASE UNIT**********************************/

    TIM_ICInitTypeDef TIM_OCInitStruct;
    TIM_ICStructInit(&TIM_OCInitStruct);
    TIM_OCInitStruct.TIM_Channel= TIM_Channel_1;
		
		TIM_OCInitStruct.TIM_ICFilter= 0XF;
    TIM_ICInit(TIM3, &TIM_OCInitStruct);
		
    TIM_OCInitStruct.TIM_Channel= TIM_Channel_2;
		TIM_OCInitStruct.TIM_ICFilter= 0XF;
    TIM_ICInit(TIM3, &TIM_OCInitStruct);
		TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling,TIM_ICPolarity_Rising);
    TIM_Cmd(TIM3, ENABLE);
}

int16_t GetCounter(void)
{
		int16_t temp = TIM_GetCounter(TIM3);
	  TIM_SetCounter(TIM3, 0);
		return temp;
}

