#include <Arduino.h>
#include "SystemDefinitions.h"
#include "ADC.h"

float binaryToVoltageConverting(int val)
{
	float voltage = ((float) (val * SYSTEMVOLTAGE))/((float) RESOLUTION_ADC);
	return voltage;
} //voltageADC

String getWindDirection(float voltage)
{
	String windDirection;
	
	if (0 < voltage && voltage <= 0.66)
	{
		windDirection = "NEE";
	}
	else if (0.66 < voltage && voltage <= 0.87)
	{
		windDirection = "E";
	}
	else if (0.87 < voltage && voltage <= 1.05)
	{
		windDirection = "SSE";
	}
	else if (1.05 < voltage && voltage <= 1.18)
	{
		windDirection = "SEE";
	}
	else if (1.18 < voltage && voltage <= 1.34)
	{
		windDirection = "SE";
	}
	else if (1.34 < voltage && voltage <= 1.57)
	{
		windDirection = "SSW";
	}
	else if (1.57 < voltage && voltage <= 2.03)
	{
		windDirection = "S";
	}
	else if (2.03 < voltage && voltage <= 2.72)
	{
		windDirection = "NE";
	}
	else if (2.72 < voltage && voltage <= 3.11)
	{
		windDirection = "SWW";
	}
	else if (3.11 < voltage && voltage <= 3.34)
	{
		windDirection = "SW";
	}
	else if (3.34 < voltage && voltage <= 3.66)
	{
		windDirection = "NNW";
	}
	else if (3.66 < voltage && voltage <= 3.94)
	{
		windDirection = "N";
	}
	else if (3.94 < voltage && voltage <= 4.2)
	{
		windDirection = "NWW";
	}
	else if (4.2 < voltage && voltage <= 4.47)
	{
		windDirection = "NW";
	}
	else if (4.47 < voltage && voltage <= 4.74)
	{
		windDirection = "W";
	}
	else if (4.74 < voltage && voltage <= 5)
	{
		windDirection = "NNE";
	}
	
	return windDirection;
} //sortWindDirectionVoltage