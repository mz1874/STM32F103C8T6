#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "AD.h"
#include "OLED.h"


float Voltage;

int main(void)
{

		OLED_Init();
		Init_ADC1();
		OLED_ShowString(1,1, "ADValue:");
	  OLED_ShowString(2,1, "Volatage::");
    while (1)
    {
			Voltage =(float) Get_ADC_Value() / 4095 * 3.3;
			OLED_ShowNum(1,9,Get_ADC_Value(), 4);
			OLED_ShowNum(2,9,Voltage, 1);
			OLED_ShowNum(2,11,(uint16_t)(Voltage * 100) % 100, 2);
    }
}
