#include "Encoder.h"

void Init_Encorder(void){

 /* Enable APB2 Clock*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
		
    GPIO_InitTypeDef GPIO_InitStruct_Output_7;
    GPIO_InitStruct_Output_7.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct_Output_7.GPIO_Mode= GPIO_Mode_IPU;
    GPIO_InitStruct_Output_7.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct_Output_7);
	
		
	
		//direction
	  GPIO_InitTypeDef GPIO_InitStruct_Output_C15;
    GPIO_InitStruct_Output_C15.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStruct_Output_C15.GPIO_Mode= GPIO_Mode_IPU;
    GPIO_InitStruct_Output_C15.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct_Output_C15);
	
		

    /*INIT AFIO EXIT PIn
    	Each peripheral only can select one pin into AFIO for exit
    */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource7);
	
	
    /*Config exit*/
    EXTI_InitTypeDef exit_def;
    exit_def.EXTI_Line = EXTI_Line7;
    exit_def.EXTI_Mode =EXTI_Mode_Interrupt;
    exit_def.EXTI_Trigger = EXTI_Trigger_Falling                                                                                                                 ;
    exit_def.EXTI_LineCmd = ENABLE;
    EXTI_Init(&exit_def);
		
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
			
		NVIC_InitTypeDef NVIC_DEF;
		NVIC_DEF.NVIC_IRQChannel= EXTI9_5_IRQn;
		NVIC_DEF.NVIC_IRQChannelCmd= ENABLE;
		NVIC_DEF.NVIC_IRQChannelPreemptionPriority= 2;
		NVIC_DEF.NVIC_IRQChannelSubPriority= 12;
		NVIC_Init(&NVIC_DEF);
}


/*
*@desc:    Interruption callback function
*@return :  void
*/
void EXTI9_5_IRQHandler()
{		
//		if(GPIO_ReadInputDataBit(GPIOA, 7))
//		{
//		i++;
//		}else
//		{
//			i--;
//		}
//		OLED_ShowNum(1,1,i,4);
//		EXTI_ClearITPendingBit(EXTI_Line7);
}
