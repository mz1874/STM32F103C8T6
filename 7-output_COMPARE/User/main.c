#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.H"
#include "Delay.h"

uint8_t i;
int main(void)
{


    Init_PWM();
		setTimePulse(2500);
		Delay_s(2);
		setTimePulse(500);
    while (1)
    {

    }
}



