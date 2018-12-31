#include <Arduino.h>
#include "ISR.h"

uint32_t numberOfEdgesAnemometer = 0;
uint32_t numberOfEdgesOmbrometer = 0;

void beginAnemometer(uint8_t digitalPinNumber)
{
	attachInterrupt(digitalPinToInterrupt(digitalPinNumber), countEdgesAnemometer, RISING);
} //beginAnemometer

void beginOmbrometer(uint8_t digitalPinNumber)
{
	attachInterrupt(digitalPinToInterrupt(digitalPinNumber), countEdgesOmbrometer, RISING);
} //beginOmbrometer

void countEdgesAnemometer()
{
	numberOfEdgesAnemometer++;
} //countEdgesAnemometer

void countEdgesOmbrometer()
{
	numberOfEdgesOmbrometer++;
} //countEdgesOmbrometer

uint32_t getNumberOfEdgesAnemometer()
{
	uint32_t buff = numberOfEdgesAnemometer;
	numberOfEdgesAnemometer = 0;
	return buff;
} //getNumberOfEdgesAnemometer

uint32_t getNumberOfEdgesOmbrometer()
{
	uint32_t buff = numberOfEdgesOmbrometer;
	numberOfEdgesOmbrometer = 0;
	return buff;
} //getNumberOfEdgesOmbrometer
