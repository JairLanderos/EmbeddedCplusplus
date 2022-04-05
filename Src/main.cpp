#include "main.h"
#include "servo.h"

int main()
{
	HAL_Init();

	/* Enable the clock for the peripherals */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();

	/* Initialize the pin used to control servomotor */
	pinStruct_t servoPin;
	servoPin.GPIOx = GPIOB;
	servoPin.selectedPin = GPIO_PIN_8;

	/* Configure the PWM output */
	static Servo servo(servoPin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);

	while(1)
	{
		/* Turn the servomotor repeatedly  every 1 second */
		servo.ServoWrite(SERVO_MIDPOS);
		HAL_Delay(1000);
		servo.ServoWrite(SERVO_LEFTPOS);
		HAL_Delay(1000);
		servo.ServoWrite(SERVO_MIDPOS);
		HAL_Delay(1000);
		servo.ServoWrite(SERVO_RIGHTPOS);
		HAL_Delay(1000);
	}
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}
