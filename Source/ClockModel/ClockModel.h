#ifndef CLOCKMODEL_H
#define CLOCKMODEL_H

#include "I_Timer.h"
#include "Button.h"

enum 
{
	ClockSM_Init,
	ClockSM_SetTime,
	ClockSM_FaceOne,
	ClockSM_FaceTwo
};
typedef uint8_t Clock_State;

class ClockModel
{
	private:
		I_Timer *clockTimer;
		Clock_State state;
		// Button *settingsButton;
		// Button *nextButton;
		// Button *previousButton;

	public:
		ClockModel(I_Timer *clockTimer);
		~ClockModel();
		Time_t GetClockTime();
		void SetClockTime(uint8_t hour, uint8_t minute, uint8_t second);
		Clock_State GetClockState();
		void SetClockState(Clock_State state);
		// void SetSettingsButtonState(uint8_t state);
		// uint8_t GetSettingsButtonState();
};

#endif