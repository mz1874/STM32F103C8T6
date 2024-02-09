#include "CounterSensor.h"


void Init_CounterSensor()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

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
		TimeBaseInitStruct.TIM_Period= 10000 - 1;
		
		// SET PRESCALER  72MHZ / 7200 = 10 000 HZ
    TimeBaseInitStruct.TIM_Prescaler = 7200 - 1;
    TIM_TimeBaseInit(TIM2, &TimeBaseInitStruct);
		
		TIM_ClearFlag(TIM2, TIM_IT_Update);
		// allow TIM2 update interruption
		TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
		
		//set nvic group
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		// init NVIC
		NVIC_InitTypeDef NVIC_InitStruct;
		NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
		NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	
		//config nciv
		NVIC_Init(&NVIC_InitStruct);
		
		//Enable timer
		TIM_Cmd(TIM2, ENABLE);
}



