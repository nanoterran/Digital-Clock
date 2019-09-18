/*!
 * @file
 * @brief Test for ClockModel class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ClockController.h"
#include "ClockModel.h"
#include "View_Mock.h"
#include "Button.h"

// Button *buttonOne;

// static const Button_Configuration_t modelConfiguration[] = 
// 	{
// 		{ buttonOne, 10 }
// 	};

TEST_GROUP(ClockControllerTest)
{
	View_Mock fakeView;

	void setup()
	{
	}

	void teardown()
	{
	}

	void UpdateViewShouldBeCalled()
	{
		mock().expectOneCall("UpdateView").onObject(&fakeView);
	}

	void ClearViewShouldBeCalled()
	{
		mock().expectOneCall("ClearView").onObject(&fakeView);
	}
};

// TEST(ClockControllerTest, ShouldBeAbleToInitializeTheClockWithInitialState)
// {
// 	ClockModel model;

// 	CHECK_EQUAL(ClockSM_Init, model.GetClockState());
// }

// TEST(ClockControllerTest, ShouldBeAbleToChangeToFaceOne)
// {
// 	ClockModel model;
// 	ClockController controller(&model, &fakeView);

// 	ClearViewShouldBeCalled();
// 	UpdateViewShouldBeCalled();

// 	controller.Run();

// 	CHECK_EQUAL(ClockSM_FaceOne, model.GetClockState());
// }
