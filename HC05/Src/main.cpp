#include "main.h"
#include "hc05.h"
#include <stdio.h>

char received_data = '\0';

int main(void)
{
	HAL_Init();

	/* Enable the peripherals clock */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();

	/* Initialize the pins used to behave as USART1 (Rx only mode)*/
	pinStruct_t Rx_pin;
	Rx_pin.GPIOx = GPIOA;
	Rx_pin.selectedPin = GPIO_PIN_10;

	static HC05 hc05(Rx_pin, USART1, GPIO_AF7_USART1, 9600, UART_MODE_RX);

	/* Read constantly the value received by the HC05 module */
	while(1)
	{
		received_data = hc05.GetChar();
	}
}


extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}
