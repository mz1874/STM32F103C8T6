#include "PWM.h"

void Init_PWM(void)
{


    /********************************START CONFIG TIME BASE UNIT**********************************/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    // INIT GPIOA PA0
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
    GPIO_InitTypeDef GPIO_InitStruct;
    // !!!!
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
	
    // config timer2 use internal clock
    TIM_InternalClockConfig(TIM2);

    //INIT TIME BASE UINT
    TIM_TimeBaseInitTypeDef TimeBaseInitStruct;

    // SER CLOCK DIVISION
    TimeBaseInitStruct.TIM_ClockDivision= TIM_CKD_DIV1;
    // UP DOWN OR CENTER A
    TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;

    TimeBaseInitStruct.TIM_RepetitionCounter= 0X00;

    // count 10000 time = 1s
    TimeBaseInitStruct.TIM_Period= 20000 -1;   //ARR

    // SET PRESCALER  72MHZ / 7200 = 10 000 HZ
    TimeBaseInitStruct.TIM_Prescaler = 72 - 1; // PSC

    //init time baseInit
    TIM_TimeBaseInit(TIM2, &TimeBaseInitStruct);
    /********************************END CONFIG TIME BASE UNIT**********************************/
		
    TIM_OCInitTypeDef TIM_OCInitStruct;
    TIM_OCStructInit(&TIM_OCInitStruct);
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_Pulse = 0; //CCR
    TIM_OC1Init(TIM2, &TIM_OCInitStruct);

    //Enable timer
    TIM_Cmd(TIM2, ENABLE);

}


void setTimePulse(int index)
{
	 TIM_SetCompare1(TIM2,index); 
}



