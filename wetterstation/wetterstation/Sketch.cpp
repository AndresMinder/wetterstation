#include <Arduino.h>
#include "SDCard.h"
#include "Anemometer.h"
#include "CLI.h"
#include "Temp_Press_Humid.h"
#include "myRTC.h"

void setup()
{
	Serial.begin(9600);
	initRTC();
}

void loop()
{
	timeStamp();
}
