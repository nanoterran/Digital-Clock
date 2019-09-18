#ifndef FAKEVIEW_H
#define FAKEVIEW_H

#include "I_View.h"

class FakeView : public I_View
{
	public:
		void UpdateView();
		void ClearView();
};

#endif