#ifndef SERVO_H_
#define SERVO_H_

#include "pinmap.h"

enum
{
	SERVO_RIGHTPOS = 1599,
	SERVO_MIDPOS = 2399,
	SERVO_LEFTPOS = 3199
};

class Servo
{
	private:
		TIM_HandleTypeDef htim;
		uint32_t pwmCh;

	public:
		Servo(pinStruct_t& servoPin,
			  TIM_TypeDef* TIMx,
			  uint8_t gpioAFSelectTIMx,
			  uint32_t pwmChannel);
		void ServoWrite(uint32_t position);
};


#endif /* SERVO_H_ */
