#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "AD.h"
#include "OLED.h"


float Voltage;

int main(void)
{

		OLED_Init();
		Init_ADC1();
		
    while (1)
    {
			
			OLED_ShowNum(1,1,Get_ADC_Value(1),4);
//			OLED_ShowNum(2,1,Get_ADC_Value(2),4);
//			OLED_ShowNum(3,1,Get_ADC_Value(3),4);
//			OLED_ShowNum(4,1,Get_ADC_Value(4),4);
			Delay_ms(50);
    }
}
