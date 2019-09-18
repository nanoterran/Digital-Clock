/*!
 * @file
 * @brief Test for ClockModel class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ClockModel.h"
#include "FakeTimer.h"
// #include "Button.h"

enum
{
	SETTINGS_PIN = 4,
	NEXT_PIN = 5,
	PREVIOUS_PIN = 6
};

TEST_GROUP(ClockModelTest)
{
	FakeTimer *timer;

	void setup()
	{
		timer = new FakeTimer();
	}

	void teardown()
	{
		delete timer;
	}
};

TEST(ClockModelTest, ShouldInitializeTheClockModel)
{
	ClockModel model(timer);
	
	CHECK_EQUAL(ClockSM_Init, model.GetClockState());
}

TEST(ClockModelTest, ShouldSetClockTime)
{
	ClockModel model(timer);
	model.SetClockTime(8, 50, 32);

	Time_t time = model.GetClockTime();
	
	CHECK_EQUAL(8, time.hour);
	CHECK_EQUAL(50, time.minute);
	CHECK_EQUAL(32, time.second);
}

TEST(ClockModelTest, ShouldSetClockStateToFaceTwo)
{
	ClockModel model(timer);

	CHECK_EQUAL(ClockSM_Init, model.GetClockState());

	model.SetClockState(ClockSM_FaceTwo);

	CHECK_EQUAL(ClockSM_FaceTwo, model.GetClockState());
}