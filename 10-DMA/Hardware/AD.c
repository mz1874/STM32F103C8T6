#include "AD.h"

void Init_ADC1(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
		ADC_InitTypeDef ADC_InitStruct;
		
		// Always to convert 
		ADC_InitStruct.ADC_ContinuousConvMode= ENABLE;
		ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
		ADC_InitStruct.ADC_ExternalTrigConv= ADC_ExternalTrigConv_None; 
		ADC_InitStruct.ADC_Mode= ADC_Mode_Independent;
		ADC_InitStruct.ADC_NbrOfChannel= 1;
		ADC_InitStruct.ADC_ScanConvMode= DISABLE;
		ADC_Init(ADC1,&ADC_InitStruct);
	
		ADC_Cmd(ADC1, ENABLE);
		
		ADC_ResetCalibration(ADC1);
		while(ADC_GetResetCalibrationStatus(ADC1));
		ADC_StartCalibration(ADC1);
		while(ADC_GetCalibrationStatus(ADC1));
}

uint16_t Get_ADC_Value(uint8_t ADC_Channel)
{
		ADC_RegularChannelConfig(ADC1, ADC_Channel, 1,ADC_SampleTime_55Cycles5);
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
		return ADC_GetConversionValue(ADC1);
}