#include "LightSensor.h"

static uint8_t Light;
static rt_thread_t LightSensor_thread_handle;

void LightSensor_thread(){
    LightSensor_Init();
    while(1){
        Light = LightSensor_Get();
        rt_thread_delay(1000);
        rt_kprintf("Light: %d\n", Light);
    }
}

void LightSensor_entry(){
    LightSensor_thread_handle = rt_thread_create("LightSensor", LightSensor_thread, RT_NULL, 258, 10, 10);
    rt_thread_startup(LightSensor_thread_handle);

}

MSH_CMD_EXPORT(LightSensor_entry, LightSensor_entry);
