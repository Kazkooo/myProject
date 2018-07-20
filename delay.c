#include "stm32f4xx_hal.h" 

static volatile uint32_t tick;

void SysTick_Handler(void)
{
    tick++;
} /* SysTick_Handler */


void delay(uint32_t msec)
{
  tick = 0;
  while(tick < msec) {}
} /* delay */
