#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "Serial.h"

int main(void)
{

    OLED_Init();
    Init_UART();
    Init_ADC1();
    while (1)
    {
        printf("%d\r\n", data[0]);
        printf("%d\r\n", data[1]);
        printf("%d\r\n", data[2]);
        printf("%d\r\n", data[3]);
				Delay_ms(1000);
    }
}
