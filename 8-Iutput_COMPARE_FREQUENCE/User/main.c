#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.H"
#include "Delay.h"
#include "IC.H"



uint8_t i;
int main(void)
{

    OLED_Init();
	
		// INIT PWM 2 TO GENERATE A SIGNAL 
    Init_PWM();
	  // INIT INPUT CAPTURE MODE IN TIMER3 TO CAPTURE THE FREQUENCE OUTPUTED BY TIME2
		Init_IC();
		OLED_ShowString(1, 1, "Freq:00000 Hz");
		OLED_ShowString(2, 1, "Duty:%");
	  //change frequence
		setPrescaler(72-1);
		setTimePulse(10);
	
	
    while (1)
    {
			OLED_ShowNum(1, 6, Get_Frequence(), 6);
			OLED_ShowNum(2, 6, Get_Duty(), 2);
    }
}




