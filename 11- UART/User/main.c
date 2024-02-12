#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "Serial.h"

int main(void)
{

    OLED_Init();
//		Init_ADC1();
		Init_UART();
		
		uint8_t data[4]= {1,2,3,4};
    while (1)
    {	
//				OLED_ShowNum(1,1,data[0], 4);
//				OLED_ShowNum(2,1,data[1], 4);
//				OLED_ShowNum(3,1,data[2], 4);
//				OLED_ShowNum(4,1,data[3], 4);
				printf("Number is %d \r\n", 99);
				Delay_ms(50);
    }
}
