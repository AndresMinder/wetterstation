#include <Arduino.h>
#include "SystemDefinitions.h"
#include "Calculate.h"

// default constructor
Calculate::Calculate()
{
} //Calculate

// default destructor
Calculate::~Calculate()
{
} //~Calculate

float Calculate::meanValue(uint32_t val)
{
	float result = val/TIME;
	return result;
} //meanValue

WindData Calculate::getWindSpeed(uint32_t val)
{
	WindData windData;
	float windspeed = (float) val / ((float) TIME) * (float) WINDSCALINGFACTOR;
	windData.windspeed = windspeed / 3.6;	//windspeed in m/s
	
	if (windspeed <= 0.2)
	{
		windData.windstrength = 0;
	} 
	else if (0.2 < windspeed && windspeed <= 1.5)
	{
		windData.windstrength = 1;
	}
	else if (1.5 < windspeed && windspeed <= 3.3)
	{
		windData.windstrength = 2;
	}
	else if (3.3 < windspeed && windspeed <= 5.4)
	{
		windData.windstrength = 3;
	}
	else if (5.4 < windspeed && windspeed <= 7.9)
	{
		windData.windstrength = 4;
	}	
	else if (7.9 < windspeed && windspeed <= 10.7)
	{
		windData.windstrength = 5;
	}
	else if (10.7 < windspeed && windspeed <= 13.8)
	{
		windData.windstrength = 6;
	}	
	else if (13.8 < windspeed && windspeed <= 17.1)
	{
		windData.windstrength = 7;
	}	
	else if (17.1 < windspeed && windspeed <= 20.7)
	{
		windData.windstrength = 8;
	}
	else if (20.7 < windspeed && windspeed <= 24.4)
	{
		windData.windstrength = 9;
	}
	else if (24.4 < windspeed && windspeed <= 28.4)
	{
		windData.windstrength = 10;
	}
	else if (28.4 < windspeed && windspeed <= 32.6)
	{
		windData.windstrength = 11;
	}
	else if (32.6 < windspeed)
	{
		windData.windstrength = 12;
	}
	
	return windData;
} //getWindSpeed

float Calculate::getRainfall(uint32_t val)
{
	float rainfall = (float) val * (float) RESOLUTION_OMBROMETER /* ((float) TIME)*/ * (float) OMBROMETERSCALINGFACTOR;
	return rainfall;	// rainfall in liter per m^2 in a certain timespan
}