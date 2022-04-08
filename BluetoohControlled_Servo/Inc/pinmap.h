#ifndef PINMAP_H_
#define PINMAP_H_

#include "stm32f4xx_hal.h"

typedef struct
{
	GPIO_TypeDef* GPIOx;
	uint16_t selectedPin;
}pinStruct_t;

#endif /* PINMAP_H_ */
