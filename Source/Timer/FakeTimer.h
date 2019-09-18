#ifndef FAKETIMER_H
#define FAKETIMER_H

#include "I_Timer.h"

class FakeTimer : public I_Timer
{
private:
	Time_t time;
	Date_t date;

public:
	FakeTimer();
	void SetTime(uint8_t hour, uint8_t minute, uint8_t second);
	Time_t GetTime();
	void SetDate(uint8_t day, uint8_t month, uint16_t year);
	Date_t GetDate();
};

#endif