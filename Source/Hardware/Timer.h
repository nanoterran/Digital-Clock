#ifndef TIMER_H
#define TIMER_H

/*
 * Timer class to interfaces with the Real Time Clock
 */ 
#include "I_Timer.h"
#include "DS3231.h"

class Timer : public I_Timer
{
private:
	Time_t time;
	Date_t date;

public:
	Timer(uint8_t data_pin, uint8_t sclk_pin);
	void SetTime(uint8_t hour, uint8_t minute, uint8_t second);
	Time_t GetTime();
	void SetDate(uint8_t day, uint8_t month, uint16_t year);
	Date_t GetDate();
};

#endif