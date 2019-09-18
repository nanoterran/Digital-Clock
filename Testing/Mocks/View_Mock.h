#ifndef VIEW_MOCK_H_
#define VIEW_MOCK_H_

#include "I_View.h"
#include "CppUTestExt/MockSupport.h"

class View_Mock: public I_View
{
public:
	virtual ~View_Mock();
	void UpdateView();
	void ClearView();
};

#endif /* VIEW_MOCK_H_ */