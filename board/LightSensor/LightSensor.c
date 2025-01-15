#include "LightSensor.h"

void LightSensor_Init(void)
{
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// GPIO_InitTypeDef GPIO_InitStructure;
	// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// GPIO_Init(GPIOB, &GPIO_InitStructure);
	rt_pin_mode(LIGHT_SENSOR, PIN_MODE_INPUT_PULLUP);
	
}

uint8_t LightSensor_Get(void)
{
	// return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
	return rt_pin_read(LIGHT_SENSOR);
}
