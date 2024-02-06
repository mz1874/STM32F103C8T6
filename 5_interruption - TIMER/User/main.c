#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"

int i =0;


int main(void)
{
		
		OLED_Init();
		initTimer2();
    while (1)
    {
			OLED_ShowNum(1,1,i,4);		
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

