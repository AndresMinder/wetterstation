
#ifndef __CALCULATE_H__
#define __CALCULATE_H__

struct WindData
{
	float windspeed;
	uint8_t windstrength;
};

class Calculate
{
//variables
public:
protected:
private:


//functions
public:
	Calculate();
	~Calculate();
	WindData getWindSpeed(uint32_t val);
	float getRainfall(uint32_t val);
	float meanValue(uint32_t val);
protected:
private:
	Calculate( const Calculate &c );
	Calculate& operator=( const Calculate &c );

}; //Calculate

#endif //__CALCULATE_H__
