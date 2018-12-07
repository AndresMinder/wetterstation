#ifndef __REALTIMECLOCK_H__
#define __REALTIMECLOCK_H__

struct TimeStamp
{
	String dotw;
	uint16_t y;
	uint8_t mo, d, h, mi, s;
};

class RealTimeClock
{
//variables
public:
protected:
private:
	String dayOfWeek;
	uint16_t year;
	uint8_t month, day, hour, minute, second;


//functions
public:
	RealTimeClock();
	~RealTimeClock();
	void initRTC();
	TimeStamp getTimeStamp();
protected:
private:
	void setDateTime();
	RealTimeClock( const RealTimeClock &c );
	RealTimeClock& operator=( const RealTimeClock &c );

}; //RealTimeClock

#endif //__REALTIMECLOCK_H__
