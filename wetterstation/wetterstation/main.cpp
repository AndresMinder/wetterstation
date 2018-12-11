#include <Arduino.h>
#include "RealTimeClock.h"
#include "TempHumidPressSensor.h"
#include "SdcardBreakout.h"
#include "Calculate.h"

#define PIN_ANEMOMETER	2
#define PIN_OMBROMETER	3

void beginAnemometer(uint8_t digitalPinNumber);
void beginOmbrometer(uint8_t digitalPinNumber);
void countEdgesAnemometer();
void countEdgesOmbrometer();

SdcardBreakout sd;
TempHumidPressSensor thps;
SensorData sensordata;
RealTimeClock realtimeclock;
TimeStamp ts;

String myData = "datalog.txt";

uint32_t numberOfEdgesAnemometer = 0;
uint32_t numberOfEdgesOmbrometer = 0;

void setup()
{
	Serial.begin(9600);
	while (!Serial);
	sd.initSdcardBreakout();
	realtimeclock.initRTC();
	thps.initTempHumidPressSensor();
	beginAnemometer(2);
	beginOmbrometer(3);
} //setup

void loop()
{
	
} //loop

// FUNCTIONS***********************************************************
void beginAnemometer(uint8_t digitalPinNumber)
{
	attachInterrupt(digitalPinToInterrupt(digitalPinNumber), countEdgesAnemometer, RISING);
} //beginAnemometer

void beginOmbrometer(uint8_t digitalPinNumber)
{
	attachInterrupt(digitalPinToInterrupt(digitalPinNumber), countEdgesOmbrometer, RISING);
} //beginOmbrometer
// FUNCTIONS***********************************************************

// ISR*****************************************************************
void countEdgesAnemometer()
{
	Serial.println(numberOfEdgesAnemometer);
	numberOfEdgesAnemometer++;
} //countEdges

void countEdgesOmbrometer()
{
	Serial.println(numberOfEdgesOmbrometer);
	numberOfEdgesOmbrometer++;
} //countEdges
// ISR*****************************************************************