#include <Arduino.h>
#include "SDCard.h"
#include "Anemometer.h"
#include "CLI.h"

void setup()
{
	Serial.begin(9600);
	initAnemometer();
	initCLI();
	writeFileSDCard(1345, "data.txt");
}

void loop()
{
	
}