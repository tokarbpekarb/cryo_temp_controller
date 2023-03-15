
#include "stm32f4xx.h"                  // Device header
#include "CPU.h"
#include "GPIO.h"
#include "Timer.h"
#include "SPI.h"
#include "I2C.h"
#include "LCD_api.h"
#include "gui_impl.h"


int main(void)
{
  CPU_init();
  GPIO_setup();
  TIM10_init();
  SPIxInit(SPI3, 0, 0); //~13 MHz
  I2C1_init();
  //EXTI_init();

  Touch_init();
  LCD_init();

  gui_init();

  while(1)
  {
    Touch_handler();
    SGUI_sync(10);
    SGUI_handler();
    delay_ms(10);
  }
}
