#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"
#include "Encoder.h"


int i =0;


int main(void)
{
		
		OLED_Init();
		Init_CounterSensor();
		OLED_ShowNum(1,1,i,4);
		Init_Encorder();
    while (1)
    {
					
    }
}

/*
*@desc:    Interruption callback function
*@return :  void
*/
void EXTI9_5_IRQHandler()
{		
		if(GPIO_ReadInputDataBit(GPIOA, 7))
		{
		i++;
		}else
		{
			i--;
		}
		OLED_ShowNum(1,1,i,4);
		EXTI_ClearITPendingBit(EXTI_Line7);
}


void EXTI1_IRQHandler()
{
	
		i++;
		OLED_ShowNum(1,1,i,4);
		EXTI_ClearITPendingBit(EXTI_Line1);
		
}
