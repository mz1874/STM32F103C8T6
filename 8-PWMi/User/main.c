#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.H"
#include "CounterSensor.h"


int temp;

int main(void)
{
		
		OLED_Init();
		Init_Encorder();
		Init_CounterSensor();
    while (1)
    {
					OLED_ShowSignedNum(1,5, temp, 5);
    }
}

void TIM2_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update))
	{
		temp = GetCounter();
		TIM_SetCounter(TIM3, 0);
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}