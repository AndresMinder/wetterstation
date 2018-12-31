#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include "LightIntensitySensor.h"

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

// constructor
LightIntensitySensor::LightIntensitySensor()
{
} //constructor

// destructor
LightIntensitySensor::~LightIntensitySensor()
{
} //destructor

void LightIntensitySensor::initLightIntensitySensor()
{
	bool status = tsl.begin();
	if(!status)
	{
		Serial.print("Error: Couldn't find BME280, please ensure that the BME280 is powered and correctly wired!");
		while(1);
	}
	else if(status)
	{
// 		displaySensorDetails();
		configureSensor();		
		Serial.println("TSL2561\tsuccessfully initialized!");
	}
}

void LightIntensitySensor::displaySensorDetails()
{
	sensor_t sensor;
	tsl.getSensor(&sensor);
	Serial.println("------------------------------------");
	Serial.print  ("Sensor:       "); Serial.println(sensor.name);
	Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
	Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
	Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
	Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
	Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");
	Serial.println("------------------------------------");
	Serial.println("");
	delay(500);
}

void LightIntensitySensor::configureSensor()
{
	/* You can also manually set the gain or enable auto-gain support */
	// tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
	// tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
	tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
	
	/* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
	//tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
	// tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
	 tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */
}

void LightIntensitySensor::setData()
{
	sensors_event_t event;
	tsl.getEvent(&event);
 
	if (event.light)
	{
		lux = event.light;
	}
	else
	{
		Serial.println("Error: Sensor overload!");
	}	
}

float LightIntensitySensor::getData()
{
	setData();
	return lux;
}