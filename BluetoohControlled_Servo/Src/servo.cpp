#include "servo.h"

Servo::Servo(pinStruct_t& servoPin,
			 TIM_TypeDef* TIMx,
			 uint8_t gpioAFSelectTIMx,
			 uint32_t pwmChannel)
{
	pwmCh = pwmChannel;

	/* Set selected pin to use it as TIMx CHx peripheral */
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = servoPin.selectedPin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = gpioAFSelectTIMx;
	HAL_GPIO_Init(servoPin.GPIOx, &GPIO_InitStruct);

	/* Configure TIMx to generate 2ms period signal */
	htim.Instance = TIMx;
	htim.Init.Prescaler = 10 - 1;	//CK_CNT = 1.6MHz
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = 32000 - 1;	//Reload counter every 2ms
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&htim);

	/* Set PWM signal properties */
	TIM_OC_InitTypeDef pwmConfigOC = {0};
	pwmConfigOC.OCMode = TIM_OCMODE_PWM1;
	pwmConfigOC.Pulse = SERVO_MIDPOS;	//7.5% Duty cycle (1.5ms)
	pwmConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	pwmConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_OC_ConfigChannel(&htim, &pwmConfigOC, pwmChannel);

	/* Start PWM */
	HAL_TIM_PWM_Start(&htim, pwmChannel);
}

void Servo::ServoWrite(uint32_t position)
{
	__HAL_TIM_SET_COMPARE(&htim, pwmCh, position);
}
