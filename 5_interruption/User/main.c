#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"

int i =0;


int main(void)
{
		
		OLED_Init();
		Init_CounterSensor();
		OLED_ShowNum(1,1,i,4);
		
    while (1)
    {
					
    }
}



void EXTI1_IRQHandler()
{
	
		i++;
		OLED_ShowNum(1,1,i,4);
		EXTI_ClearITPendingBit(EXTI_Line1);
		
}
