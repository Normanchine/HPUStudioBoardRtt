#include "led.h"

void init_LED(){
    rt_pin_mode(LED_LEFT_UP, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_LEFT_DOWN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RIGHT_UP, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_RIGHT_DOWN, PIN_MODE_OUTPUT);
}