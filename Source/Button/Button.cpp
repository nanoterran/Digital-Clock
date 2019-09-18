#include "Button.h"

Button::Button(uint8_t pin)
{
	this->pin = pin;
	this->value = 0;
}

void Button::SetValue(uint8_t value)
{
	this->value = value;
}

uint8_t Button::GetValue()
{
	return value;
}
