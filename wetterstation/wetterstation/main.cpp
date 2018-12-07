#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <SPI.h>
#include "sdcard.h"
#include "Controller.h"
#include "RTClib.h"

#define BME_CS		48
#define SD_CS		53
#define MISO		50
#define MOSI		51
#define SCK			52
#define SEALEVELPRESSURE_HPA 1013.25

Adafruit_BME280 bme(BME_CS, MOSI, MISO, SCK);
sdcard SD(SD_CS, MOSI, MISO, SCK);
RTC_DS1307 rtc;
DateTime now;

void setup()
{	
	bool status_bme, status_rtc;
	Serial.begin(9600);
	status_bme = bme.begin();
	status_rtc = rtc.begin();	
}

void loop()
{
	
}