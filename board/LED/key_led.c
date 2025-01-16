#include "ports_pin.h"
#include <rtthread.h>
#include <drv_gpio.h>
#include "led.h"

/* 按键上回调函数 */
void key_up_callback(void *args)
{
    int value = rt_pin_read(KEY_UP);
    rt_kprintf("按键上被按下! %d", value);
    rt_pin_write(LED_RIGHT_DOWN,PIN_LOW);
        rt_pin_write(LED_RIGHT_UP,PIN_LOW);
            rt_pin_write(LED_LEFT_DOWN,PIN_LOW);
                rt_pin_write(LED_LEFT_UP,PIN_LOW);
}

/* 按键下回调函数 */
void key_down_callback(void *args)
{
    int value = rt_pin_read(KEY_DOWN);
    rt_kprintf("按键下被按下! %d", value);
    rt_pin_write(LED_RIGHT_DOWN,PIN_HIGH);
        rt_pin_write(LED_RIGHT_UP,PIN_HIGH);
            rt_pin_write(LED_LEFT_DOWN,PIN_HIGH);
                rt_pin_write(LED_LEFT_UP,PIN_HIGH);
}



/* 引脚中断示例 */
static int rt_pin_irq_example(void)
{
    // 使能LED引脚为输出
    init_LED();


    /* 配置按键引脚为输入并使能上拉 */
    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);

    /* 附加中断回调函数 */
    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_FALLING, key_up_callback, RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_callback, RT_NULL);

    /* 使能中断 */
    rt_pin_irq_enable(KEY_UP, PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_DOWN, PIN_IRQ_ENABLE);

    return RT_EOK;
}

/* 导出命令到 msh */
#ifdef BSP_USING_KEY_LED
INIT_DEVICE_EXPORT(rt_pin_irq_example);
#endif