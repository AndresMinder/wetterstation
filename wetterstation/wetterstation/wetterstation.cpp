#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SDCard.h"
#include "Anemometer.h"
#include "CLI.h"
#include "Temp_Press_Humid.h"
#include "myRTC.h"

#define BME_SCK 52
#define BME_MISO 50
#define BME_MOSI 51
#define BME_CS 48
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);
SDCard mySD(53);

void setup()
{	
	Serial.begin(9600);	
	bool status = bme.begin();
}

void loop()
{
	Serial.print("Temperatur: ");
	Serial.print(bme.readTemperature());
	Serial.println(" C");
	Serial.print("rel. Luftfeuchte: ");
	Serial.print(bme.readHumidity());
	Serial.println(" %");
	Serial.print("Luftdruck: ");
	Serial.print(bme.readPressure());
	Serial.println(" hPa");
	Serial.print("Höhe: ");
	Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
	Serial.println(" m");
	delay(2000);
}