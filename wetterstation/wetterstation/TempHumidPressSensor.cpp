#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SystemDefinitions.h"
#include "TempHumidPressSensor.h"

Adafruit_BME280 bme280;

// constructor
TempHumidPressSensor::TempHumidPressSensor()
{
} //constructor

// destructor
TempHumidPressSensor::~TempHumidPressSensor()
{
} //~destructor

void TempHumidPressSensor::initTempHumidPressSensor()
{
	bool status = bme280.begin();
	
	if (!status)
	{
		Serial.println("Error: Couldn't find BME280, please ensure that the BME280 is powered and correctly wired!");
		while (1);
	}
	else if (status)
	{
		Serial.println("BME280\tsuccessfully initialized!");
	}
} //initTempHumidPressSensor

void TempHumidPressSensor::setData()
{
	temperatur = bme280.readTemperature();
	humidity = bme280.readHumidity();
	pressure = bme280.readPressure() / (float) 100.0;
	altitude = bme280.readAltitude(SEALEVELPRESSURE_HPA);
} //setData

BME280SensorData TempHumidPressSensor::getData()
{
	setData();
	BME280SensorData sensordata;
	
	sensordata.t = temperatur;
	sensordata.h = humidity;
	sensordata.p = pressure;
	sensordata.a = altitude;
	
	return sensordata;
} //getData
