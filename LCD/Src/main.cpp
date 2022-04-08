#include "main.h"
#include "lcd.h"

int main(void)
{
	HAL_Init();

	__HAL_RCC_GPIOC_CLK_ENABLE();

	pinStruct_t rs = {GPIOC, GPIO_PIN_0};
	pinStruct_t en = {GPIOC, GPIO_PIN_1};
	pinStruct_t d4 = {GPIOC, GPIO_PIN_2};
	pinStruct_t d5 = {GPIOC, GPIO_PIN_3};
	pinStruct_t d6 = {GPIOC, GPIO_PIN_4};
	pinStruct_t d7 = {GPIOC, GPIO_PIN_5};

	static LCD lcd(rs, en, d4, d5, d6, d7);

	lcd.Print('A');
	lcd.SetCursor(2,1);
	lcd.Print("How are you?");

	while(1)
	{

	}

}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}
