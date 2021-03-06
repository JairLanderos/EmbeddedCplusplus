#ifndef HC05_H_
#define HC05_H_

#include "pinmap.h"

class HC05
{
	private:
		UART_HandleTypeDef huartx;
	public:
		HC05(pinStruct_t& usartx_pin,
			 USART_TypeDef* USARTx,
			 uint32_t gpioAFSelectUSARTx,
			 uint32_t BaudRate,
			 uint32_t USARTx_Mode);
		char GetChar(void);
};



#endif /* HC05_H_ */
