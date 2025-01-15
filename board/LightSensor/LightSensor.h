#include "rtthread.h"
#include "drv_gpio.h"
#include "ports_pin.h"
#ifndef __LIGHT_SENSOR_H
#define __LIGHT_SENSOR_H

void LightSensor_Init(void);
uint8_t LightSensor_Get(void);

#endif
