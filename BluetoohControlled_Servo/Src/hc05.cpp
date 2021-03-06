#include "hc05.h"

HC05::HC05(pinStruct_t& usartx_pin,
		   USART_TypeDef* USARTx,
		   uint32_t gpioAFSelectUSARTx,
		   uint32_t BaudRate,
		   uint32_t USARTx_Mode)
{
	/* Set selected pins to use them as USARTx Rx and Tx */
	GPIO_InitTypeDef usartx_gpios = {0};

	usartx_gpios.Mode = GPIO_MODE_AF_PP;
	usartx_gpios.Pull = GPIO_NOPULL;
	usartx_gpios.Speed = GPIO_SPEED_FREQ_LOW;
	usartx_gpios.Alternate = gpioAFSelectUSARTx;
	usartx_gpios.Pin = usartx_pin.selectedPin;
	HAL_GPIO_Init(usartx_pin.GPIOx, &usartx_gpios);

	/* Configure USARTx peripheral */
	huartx.Instance = USARTx;
	huartx.Init.Mode = USARTx_Mode;
	huartx.Init.BaudRate = BaudRate;
	huartx.Init.OverSampling = UART_OVERSAMPLING_16;
	huartx.Init.WordLength = UART_WORDLENGTH_8B;
	huartx.Init.StopBits = UART_STOPBITS_1;
	huartx.Init.Parity = UART_PARITY_NONE;
	huartx.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	HAL_UART_Init(&huartx);
}

char HC05::GetChar(void)
{
	/* Wait for a new data to be received */
	while ( (huartx.Instance->SR & USART_SR_RXNE ) != USART_SR_RXNE );

	/* Return the received byte */
	return huartx.Instance->DR;
}
