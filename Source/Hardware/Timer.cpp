#include "Timer.h"

Timer::Timer(uint8_t data_pin, uint8_t sclk_pin)
{
	time.hour = 0;
	time.minute = 0;
	time.second = 0;
	
	date.month = 1;
	date.day = 1;
	date.year = 2019;
}

void Timer::SetTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	time.hour = hour;
	time.minute = minute;
	time.second = second;
}

Time_t Timer::GetTime()
{
	return time;
}
void Timer::SetDate(uint8_t month, uint8_t day, uint16_t year)
{
	date.month = month;
	date.day = day;
	date.year = year;
}

Date_t Timer::GetDate()
{
	return date;
}