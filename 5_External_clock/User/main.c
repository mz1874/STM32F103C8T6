#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"

int i =0;


int main(void)
{
		
		OLED_Init();
		Timer_Init();
	
    while (1)
    {
			OLED_ShowNum(1,1,i,4);		
			OLED_ShowNum(2,1,Timer_GetCounter(),5);		
    }
}


void TIM2_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update))
	{
		i++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

