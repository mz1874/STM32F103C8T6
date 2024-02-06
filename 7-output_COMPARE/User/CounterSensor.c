#include "CounterSensor.h"


/***

	What we shoule mentioned that 
	 
	The steps of init exit is
	
	1- GPIO
	2- AFIO
	3- EXIT
	4- NVIC
	what is the most important is 
	The GPIO PIn shoule be same with 
	below GPIO_PinSource1
	EXTI_Line1
	EXTI1_IRQn
	and the Interruption Callback function!!!!!!!!!
***/

void Init_CounterSensor()
{
    /* Enable APB2 Clock*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	
    GPIO_InitTypeDef GPIO_InitStruct_Output;
    GPIO_InitStruct_Output.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStruct_Output.GPIO_Mode= GPIO_Mode_IPU;
    GPIO_InitStruct_Output.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct_Output);

    /*INIT AFIO EXIT PIn
    	Each peripheral only can select one pin into AFIO for exit
    */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
		
    /*Config exit*/
    EXTI_InitTypeDef exit_def;
    exit_def.EXTI_Line = EXTI_Line1;
    exit_def.EXTI_Mode =EXTI_Mode_Interrupt;
    exit_def.EXTI_Trigger = EXTI_Trigger_Falling                                                                                                                 ;
    exit_def.EXTI_LineCmd = ENABLE;
    EXTI_Init(&exit_def);
		
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
			
		NVIC_InitTypeDef NVIC_DEF;
		NVIC_DEF.NVIC_IRQChannel= EXTI1_IRQn;
		NVIC_DEF.NVIC_IRQChannelCmd= ENABLE;
		NVIC_DEF.NVIC_IRQChannelPreemptionPriority= 1;
		NVIC_DEF.NVIC_IRQChannelSubPriority= 1;
		NVIC_Init(&NVIC_DEF);
}



