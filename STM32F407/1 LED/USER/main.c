#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

int main(void)
{

	delay_init(168);
	LED_Init();
	while(1)
	{
		/*
		//库函数方法
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		*/
		
		/*
		//位带操作
		LED0=0;
		LED1=1;
		delay_ms(200);
		LED0=1;
		LED1=0;
		delay_ms(200);
		*/
		
		//寄存器操作
		GPIOF->BSRRH= GPIO_Pin_9;
		GPIOF->BSRRL= GPIO_Pin_10;
		delay_ms(1000);
		GPIOF->BSRRL= GPIO_Pin_9;
		GPIOF->BSRRH= GPIO_Pin_10;
		delay_ms(1000);
		
	}
	
}

