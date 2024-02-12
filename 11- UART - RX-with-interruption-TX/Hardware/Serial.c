#include "Serial.h"

void Init_UART(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct_Output;
    // TX PIN 9  RX PIN 10
    GPIO_InitStruct_Output.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct_Output.GPIO_Mode= GPIO_Mode_AF_PP;
    GPIO_InitStruct_Output.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct_Output);
    GPIO_SetBits(GPIOA, GPIO_Pin_9);

    GPIO_InitStruct_Output.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct_Output.GPIO_Mode= GPIO_Mode_IPU;
    GPIO_InitStruct_Output.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct_Output);

    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_HardwareFlowControl= USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode= USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStruct.USART_Parity= USART_Parity_No;
    USART_InitStruct.USART_StopBits= USART_StopBits_1;
    USART_InitStruct.USART_WordLength= USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStruct);

    USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel= USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd= ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;

    NVIC_Init(&NVIC_InitStruct);
    USART_Cmd(USART1, ENABLE);

}

void SendData(uint8_t Data)
{
    USART_SendData(USART1, Data);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Send_Array(uint8_t *Data)
{
    uint8_t i;
    for(i=0; i< sizeof(Data) / sizeof(uint8_t); i ++)
    {
        SendData(Data[i]);
    }
}


void Send_String(char *string)
{
    uint8_t i;
    for(i=0; string[i] !='\0'; i ++)
    {
        SendData(string[i]);
    }
}

void sendNumber(uint32_t number)
{
    char buffer[20];
    sprintf(buffer, "%0*d", sizeof(number) / sizeof(uint32_t), number);
    Send_String(buffer);
}

void sendFloat(float value, uint8_t decimalPlaces)
{
    char buffer[20];
    sprintf(buffer, "%.*f", decimalPlaces, value);
    Send_String(buffer);
}

int fputc(int ch, FILE *f)
{
    SendData(ch);
    return ch;
}

void USART1_IRQHandler()
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE))
    {
        printf("%d",USART_ReceiveData(USART1));
    }
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}
