#include <Arduino.h>
#include "Anemometer.h"

const int m_time = 5;      //Measurement time in Seconds
int wind_ct = 0;
float wind = 0.0;
unsigned long time = 0;

void initAnemometer()
{	
	time = millis();
}

void countWind()
{
	wind_ct ++;
}

float getMeassurementWind()
{
	wind_ct = 0;
	time = millis();
	attachInterrupt(1, countWind, RISING);
	delay(1000 * m_time);
	detachInterrupt(1);
	wind = (float)wind_ct / (float)m_time * 2.4;
	
	// Conversion in m/s
	wind = wind/3.6;
	
	return wind;
}