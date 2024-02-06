#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.H"
#include "Delay.h"

uint8_t i;
int main(void)
{

    OLED_Init();
    Init_PWM();
    while (1)
    {
				for(int i = 0 ; i <= 100; i ++)
				{
					setTimePulse(i);
					Delay_ms(5);
				}
				
				for (int i = 100 ; i >= 0; i --)
				{
					setTimePulse(i);
					Delay_ms(5);
				}
    }
}




