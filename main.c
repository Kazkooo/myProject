#include "stm32f4xx_hal.h"
#include "delay.h"


int executionTime = 0;


void LED_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
 
  // GPIO Ports Clock Enable
  __GPIOG_CLK_ENABLE();
 
  // Configure GPIO pin PG13
  GPIO_InitStruct.Pin   = GPIO_PIN_13;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;        // push-pull output
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;              // pull-down enabled
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;             // analog pin bandwidth limited
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
        
} /* LED_Init */



int main(void) {
   HAL_Init();
   
    LED_Init();
  
  // Blink the LED on pin PG.13
  while (1) {
    // turn the LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
    // introduce some delay
    delay(1000);
    // turn the LED off
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
    // introduce some delay
    delay(1600);
		
		printf("Program execution time: %ds\n\r", executionTime++);
  } // while (1) 
    return 0; 
}
