#include "main.h"
#include "servo.h"
#include "hc05.h"

char received_data = '\0';

int main(void)
{
	HAL_Init();

	/* Enable the clock for the peripherals */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();

	/* Initialize the pin used to control servomotor */
	pinStruct_t servo_Pin;
	servo_Pin.GPIOx = GPIOB;
	servo_Pin.selectedPin = GPIO_PIN_8;

	/* Initialize the pins used to behave as USART1 (Rx only mode)*/
	pinStruct_t Rx_pin;
	Rx_pin.GPIOx = GPIOA;
	Rx_pin.selectedPin = GPIO_PIN_10;

	/* Configure the PWM output */
	static Servo servo(servo_Pin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);

	/* Configure the USART1 settings */
	static HC05 hc05(Rx_pin, USART1, GPIO_AF7_USART1, 9600, UART_MODE_RX);

	while(1)
	{
		/* Move the servo according to the received command */
		received_data = hc05.GetChar();
		switch (received_data)
		{
			case 'l':
			case 'L':
				servo.ServoWrite(SERVO_LEFTPOS);
				break;
			case 'm':
			case 'M':
				servo.ServoWrite(SERVO_MIDPOS);
				break;
			case 'r':
			case 'R':
				servo.ServoWrite(SERVO_RIGHTPOS);
				break;
		}
	}
}


extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}
