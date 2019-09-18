#ifndef CLOCKCONTROLLER_H
#define CLOCKCONTROLLER_H

#include "ClockModel.h"
#include "I_View.h"

class ClockController
{
	private:
		ClockModel *model;
		I_View *view;

	public:
		ClockController(ClockModel *model, I_View *view);
		~ClockController();
		void Run();
};

#endif