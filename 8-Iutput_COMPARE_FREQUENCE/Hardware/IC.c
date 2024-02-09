#include "IC.H"

void Init_IC(void)
{
		/********************************START CONFIG TIME BASE UNIT**********************************/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    // INIT GPIOA PA0
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;

    // !!!!
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // config timer2 use internal clock
    TIM_InternalClockConfig(TIM3);

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
    TimeBaseInitStruct.TIM_Prescaler = 72 - 1; // PSC

    //init time baseInit
    TIM_TimeBaseInit(TIM3, &TimeBaseInitStruct);
    /********************************END CONFIG TIME BASE UNIT**********************************/

    TIM_ICInitTypeDef TIM_OCInitStruct;
    
    TIM_OCInitStruct.TIM_Channel= TIM_Channel_1;
		TIM_OCInitStruct.TIM_ICFilter= 0XF;
		TIM_OCInitStruct.TIM_ICPolarity= TIM_ICPolarity_Rising;
		TIM_OCInitStruct.TIM_ICPrescaler= TIM_ICPSC_DIV1;
		TIM_OCInitStruct.TIM_ICSelection= TIM_ICSelection_DirectTI; 
    TIM_ICInit(TIM3, &TIM_OCInitStruct);
		
		TIM_PWMIConfig(TIM3, &TIM_OCInitStruct);
		//CONFIG TRIGGER 
		TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
		//CONFIG SLAVE MODE 
		TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
		//Enable timer
    TIM_Cmd(TIM3, ENABLE);
}

uint32_t Get_Frequence(void)
{
		return 1000000 / (TIM_GetCapture1(TIM3) +1);

}

uint32_t Get_Duty(void)
{
	return (TIM_GetCapture2(TIM3)*100)/ TIM_GetCapture1(TIM3) +1;
}

