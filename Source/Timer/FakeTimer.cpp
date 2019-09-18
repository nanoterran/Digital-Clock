#include "FakeTimer.h"

FakeTimer::FakeTimer()
{
	time.hour = 0;
	time.minute = 0;
	time.second = 0;
	
	date.month = 1;
	date.day = 1;
	date.year = 2019;
}

void FakeTimer::SetTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	time.hour = hour;
	time.minute = minute;
	time.second = second;
}

Time_t FakeTimer::GetTime()
{
	return time;
}
void FakeTimer::SetDate(uint8_t month, uint8_t day, uint16_t year)
{
	date.month = month;
	date.day = day;
	date.year = year;
}

Date_t FakeTimer::GetDate()
{
	return date;
}