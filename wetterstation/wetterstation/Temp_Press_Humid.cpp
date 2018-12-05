// #include <Wire.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BME280.h>
// #include "Temp_Press_Humid.h"

// #define BME_SCK 52
// #define BME_MISO 50
// #define BME_MOSI 51
// #define BME_CS 48
// 
// #define SEALEVELPRESSURE_HPA (1013.25)

//Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
// Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// unsigned long delayTime;



// void initTempPressHumid()
// {
// 	Serial.begin(9600);
// 	Serial.println(F("BME280 test"));
// 
// 	bool status;
// 	
// 	// default settings
// 	// (you can also pass in a Wire library object like &Wire2)
// 	status = bme.begin();
// 	if (!status) {
// 		Serial.println("Could not find a valid BME280 sensor, check wiring!");
// 		while (1);
// 	}
// 	
// 	Serial.println("-- Default Test --");
// 	delayTime = 1000;
// 
// 	Serial.println();
// }

// void printValues()
// {
// 	Serial.print("Temperature = ");
// 	Serial.print(bme.readTemperature());
// 	Serial.println(" *C");
// 
// 	Serial.print("Pressure = ");
// 
// 	Serial.print(bme.readPressure() / 100.0F);
// 	Serial.println(" hPa");
// 
// 	Serial.print("Approx. Altitude = ");
// 	Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
// 	Serial.println(" m");
// 
// 	Serial.print("Humidity = ");
// 	Serial.print(bme.readHumidity());
// 	Serial.println(" %");
// 
// 	Serial.println();
// }