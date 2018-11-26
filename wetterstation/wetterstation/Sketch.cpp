#include <Arduino.h>

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = 53;

File myFile;

void setup()
{
	Serial.begin(9600);

}

void loop()
{

}
