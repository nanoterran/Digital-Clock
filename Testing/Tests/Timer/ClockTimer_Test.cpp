/*!
 * @file
 * @brief Test for ClockTimer class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "FakeTimer.h"

enum
{
	December = 12
};

TEST_GROUP(TimerTest)
{
	void setup()
	{
	}

	void teardown()
	{
	}
};

TEST(TimerTest, ShouldInitializeAClockTimer)
{
	FakeTimer timer;
	Time_t time = timer.GetTime();
	Date_t date = timer.GetDate();
	
	CHECK_EQUAL(0, time.hour);
	CHECK_EQUAL(0, time.minute);
	CHECK_EQUAL(0, time.second);
	CHECK_EQUAL(1, date.day);
	CHECK_EQUAL(1, date.month);
	CHECK_EQUAL(2019, date.year);
}

TEST(TimerTest, ShouldUpdateTime)
{
	FakeTimer timer;
	timer.SetTime(4, 30, 10);

	Time_t time = timer.GetTime();
	
	CHECK_EQUAL(4, time.hour);
	CHECK_EQUAL(30, time.minute);
	CHECK_EQUAL(10, time.second);
}

TEST(TimerTest, ShouldUpdateDate)
{
	FakeTimer timer;
	timer.SetDate(December, 30, 2020);

	Date_t date = timer.GetDate();
	
	CHECK_EQUAL(December, date.month);
	CHECK_EQUAL(30, date.day);
	CHECK_EQUAL(2020, date.year);
}