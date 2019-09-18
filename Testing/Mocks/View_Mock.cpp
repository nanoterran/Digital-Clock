
#include "View_Mock.h"

View_Mock::~View_Mock() {}

void View_Mock::UpdateView()
{
	mock().actualCall("UpdateView").onObject(this);
}

void View_Mock::ClearView()
{
	mock().actualCall("ClearView").onObject(this);
}