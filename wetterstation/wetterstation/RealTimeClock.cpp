#include <Wire.h>
#include "RTClib.h"
#include "RealTimeClock.h"

RTC_DS3231 rtc;

// constructor
RealTimeClock::RealTimeClock()
{
} //constructor

// destructor
RealTimeClock::~RealTimeClock()
{
} //~destructor

void RealTimeClock::initRTC()
{
	bool status = rtc.begin();
	if (!status)
	{
		Serial.println("Error: Couldn't find RTC, please ensure that the rtc is powered!");
		while (1);
	}
	else if (status)
	{
		Serial.println("RTC\tsuccessfully initialized!");
	}
	
	if (rtc.lostPower())
	{
		Serial.println("RTC lost power, the time will be set!");
		// following line sets the RTC to the date & time this file was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
	}
} //initRTC

void RealTimeClock::setDateTime()
{
	char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	DateTime now = rtc.now();
	
	dayOfWeek = daysOfTheWeek[now.dayOfTheWeek()];
	year = now.year();
	month = now.month();
	day = now.day();
	hour = now.hour();
	minute = now.minute();
	second = now.second();
} //setDateTime

TimeStamp RealTimeClock::getTimeStamp()
{
	TimeStamp timeStamp;
	setDateTime();
	
	timeStamp.dotw = dayOfWeek;
	timeStamp.y = year;
	timeStamp.mo = month;
	timeStamp.d = day;
	timeStamp.h = hour;
	timeStamp.mi = minute;
	timeStamp.s = second;
	
	return timeStamp;
}