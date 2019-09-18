#include "ClockModel.h"

ClockModel::ClockModel(I_Timer *timer)
{
	clockTimer = timer;
	state = ClockSM_Init;
}

ClockModel::~ClockModel() {}

Time_t ClockModel::GetClockTime()
{
	return clockTimer->GetTime();
}

void ClockModel::SetClockTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	clockTimer->SetTime(hour, minute, second);
}

Clock_State ClockModel::GetClockState()
{
	return state;
}

void ClockModel::SetClockState(Clock_State state)
{
	this->state = state;
}