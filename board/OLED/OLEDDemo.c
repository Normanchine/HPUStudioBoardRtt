#include "OLED.h"
#include "rtthread.h"

static rt_thread_t OLED_thread_handler;

void OLED_thread(){
    OLED_Init();

	OLED_ShowString(1, 1, "Hi,ChenDanyang!");
}

void OLED_entry(){
    OLED_thread_handler = rt_thread_create("OLED_thread", OLED_thread, RT_NULL, 256, 10, 10);
    rt_thread_startup(OLED_thread_handler);
}

MSH_CMD_EXPORT(OLED_entry, OLED_entry);
