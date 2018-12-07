#include <Arduino.h>
#include "RealTimeClock.h"
#include "TempHumidPressSensor.h"
#include "SdcardBreakout.h"
#include "Rj11Sensors.h"
#include "Calculate.h"

SdcardBreakout sd;
TempHumidPressSensor thps;
SensorData sensordata;
RealTimeClock realtimeclock;
TimeStamp ts;

String myData = "datalog.txt";

void setup()
{
	Serial.begin(9600);
	while (!Serial);
	sd.initSdcardBreakout();
	realtimeclock.initRTC();
	thps.initTempHumidPressSensor();
} //setup

void loop()
{
	
} //loop