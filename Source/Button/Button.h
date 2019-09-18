#ifndef BUTTON_H
#define BUTTON_H

/*
 * Definition of Button
 */

#include <stdint.h>

class Button
{
	private:
		int pin;
		uint8_t value;

	public:
		Button(uint8_t pin);
		void SetValue(uint8_t value);
		uint8_t GetValue();
};

#endif
