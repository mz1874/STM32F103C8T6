#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.H"
#include "Key.h"

unsigned char key;
int main(void)
{

    LED_Init();
    Key_Init();
    while (1)
    {
        key = Key_GetNum();
        if(key == 1) {
            if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7))
            {
                LED1_OFF();
            } else {
                LED1_ON();
            }

        }
    }
}
