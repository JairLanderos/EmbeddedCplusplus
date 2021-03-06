#ifndef LCD_H_
#define LCD_H_

#include "pinmap.h"

class LCD
{
	private:
		pinStruct_t rs;
		pinStruct_t en;
		pinStruct_t dataPins[4];
		void WriteNibble(char byte, uint8_t nibbleBitPos);
		void WriteByte(GPIO_PinState lcdMode, char command);
		void WriteBytes(const char* pData);

	public:
		LCD(pinStruct_t& RS,
			pinStruct_t& EN,
			pinStruct_t& D4,
			pinStruct_t& D5,
			pinStruct_t& D6,
			pinStruct_t& D7);
		void SetCursor(uint8_t row, uint8_t column);
		void Print(char data);
		void Print(const char* pData);

};

#endif /* LCD_H_ */
