
#ifndef I_TIMER_H
#define I_TIMER_H

/*
 * Timer Interface
 */
#pragma once

#include <stdint.h>

typedef struct Time_t
{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} Time_t;

typedef struct Date_t
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
} Date_t;

class I_Timer
{
public:
	virtual ~I_Timer() {}
	virtual void SetTime(uint8_t hour, uint8_t minute, uint8_t second) = 0;
	virtual Time_t GetTime() = 0;
	virtual void SetDate(uint8_t date, uint8_t mon, uint16_t year) = 0;
	virtual Date_t GetDate() = 0;
};

#endif