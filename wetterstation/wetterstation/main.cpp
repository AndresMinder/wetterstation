#include <Arduino.h>
#include "RealTimeClock.h"
#include "TempHumidPressSensor.h"
#include "SdcardBreakout.h"
#include "Rj11Sensors.h"
#include "Calculate.h"

#define PIN_ANEMOMETER	2

SdcardBreakout sd;
TempHumidPressSensor thps;
SensorData sensordata;
RealTimeClock realtimeclock;
TimeStamp ts;

Rj11Sensors *Rj11Sensors::instance =  NULL;
Rj11Sensors anemometer;
Rj11Sensors kipp;

String myData = "datalog.txt";

void setup()
{
	Serial.begin(9600);
	while (!Serial);
	sd.initSdcardBreakout();
	realtimeclock.initRTC();
	thps.initTempHumidPressSensor();
	anemometer.begin(PIN_ANEMOMETER);
} //setup

void loop()
{
	
} //loop
