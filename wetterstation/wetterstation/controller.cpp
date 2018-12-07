// #include <Arduino.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BME280.h>
// #include <Wire.h>
// #include <SoftwareSerial.h>
// #include "sdcard.h"
// #include "sdcard.h"
// #include "Controller.h"
// #include "RTClib.h"
// // #include "Anemometer.h"
// // #include "CLI.h"
// 
// 
// // constructor
// Controller::Controller()
// {	
// } //controller
// 
// // destructor
// Controller::~Controller()
// {
// } //~controller
// 
// void Controller::init()
// {
// 	bool status_bme, status_rtc;
// 	Serial.begin(9600);
// 	status_bme = bme.begin();
// 	status_rtc = rtc.begin();
// 	
// // 	digitalWrite(BME_CS, LOW);
// // 	digitalWrite(SD_CS, LOW);
// // 	while (digitalRead(BME_CS) != LOW & digitalRead(SD_CS) != LOW){}
// // 	if (rtc.lostPower())
// // 	{
// // 		Serial.println("RTC lost power, lets set the time!");
// // 		// following line sets the RTC to the date & time this sketch was compiled
// // 		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
// // 	}
// } // controller
// 
// void Controller::setDateAndTime()
// {
// 	setDateTime();
// 	timeStamp.year = now.year();
// 	timeStamp.month = now.month();
// 	timeStamp.day = now.day();
// 	timeStamp.hour = now.hour();
// 	timeStamp.minute = now.minute();
// 	timeStamp.second = now.second();
// } // setDateAndTime
// 
// void Controller::setDateTime()
// {
// 	now = rtc.now();
// } // setDateTime
// 
// void Controller::setSensorData()
// {
// 	sensordata.temperatur = bme.readTemperature();
// 	sensordata.humidity = bme.readHumidity();
// 	sensordata.pressure = bme.readPressure();
// 	sensordata.altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
// } // setSensorData
// 
// void Controller::saveData()
// {
// 	SD.readFileSDCard("data.txt");
// } // saveData