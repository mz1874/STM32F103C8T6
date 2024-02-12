#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DMA.h"

uint8_t source[4] = {49, 50, 51,52};
uint8_t destination[4] = {0, 0, 0,0};

int main(void)
{

    OLED_Init();
		Init_DMA((uint32_t)&source, (uint32_t)destination);
		
		
    while (1)
    {	
				
				OLED_ShowNum(1,1,source[0], 8);
				OLED_ShowNum(2,1,destination[0], 8);
				startTransfer(4);
				OLED_ShowNum(1,1,source[0], 8);
				OLED_ShowNum(2,1,destination[0], 8);
				source[0] +=1;
    }
}
