#include <beep.h>
#include <ports_pin.h>


/* 比如可以在main.c中使用，此为无源蜂鸣器使用，有源的一样，就发声频率不能控制 */
void beep_thread(void)
{
    /* 先初始化 beep */
    /* 第一个参数为蜂鸣器驱动引脚号，可查看drv_gpio.c，或使用GET_PIN()宏得到，如下面为PA11脚 */
    /* 第二个参数为蜂鸣器关断时引脚电平，PIN_LOW或PIN_HIGH */
    /* 对无源蜂鸣器来说，这2个参数在初始化函数内部都没有使用到 */
    beep_init(BEEP_PIN, BEEP_NO_RING);

    /* 鸣叫3声，周期1000ms，鸣叫占空比50%，默认发声频率 */
    beep(3, 1000, 50, 0);

    rt_thread_mdelay(8000);

    /* 鸣叫3声，周期1000ms，鸣叫占空比70%，2500Hz */
    beep(3, 1000, 70, 2500);

    rt_thread_mdelay(8000);

    /* 鸣叫1声，周期800ms，鸣叫占空比100%，上一次的发声频率，即2500Hz */
    beep(1, 800, 100, 0);

    rt_thread_mdelay(5000);

    /* 鸣叫20声，周期1000ms，鸣叫占空比50%，2000Hz */
    beep(20, 1000, 50, 2000);

    rt_thread_mdelay(5000);

    /* 中途打断，停止鸣叫 */
    beep_stop();
    
    beep_deinit();
}

void beep_thread_entry(void *parameter)
{
    rt_thread_t thread = rt_thread_create("beep", beep_thread, RT_NULL, PKG_BEEP_THREAD_STACK_SIZE, PKG_BEEP_THREAD_PRIORITY, PKG_BEEP_THREAD_TIMESLICE);
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
    }
}

MSH_CMD_EXPORT(beep_thread_entry, beep_thread_entry)