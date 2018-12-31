#include <SPI.h>
#include <SD.h>
#include "SystemDefinitions.h"
#include "Sdcard.h"

File datalog;

// constructor
Sdcard::Sdcard()
{
} //constructor

// destructor
Sdcard::~Sdcard()
{
} //~destructor

void Sdcard::initSdcardBreakout()
{
	bool status = SD.begin(SD_CS);
	
	if (!status)
	{
		Serial.println("Error: no micro sd card found!");
		while(1)
		{
			status = SD.begin(SD_CS);
			if (status)
			{
				Serial.println("SD card\tsuccessfully initialized!");
				break;
			}
			else if (!status)
			{
				delay(500);
				continue;
			}					
		}
	}
	else if (status)
	{
		Serial.println("SD card\tsuccessfully initialized!");
	}
} //initSdcardBreakout

void Sdcard::writeData(float data, String filename)
{
	datalog = SD.open(filename, FILE_WRITE);
	
	if (datalog)
	{
		datalog.println(data);
		datalog.close();
	}
	else
	{
		Serial.println("Error: no micro sd card found!");		
	}
} //writeData

void Sdcard::readData(String filename)		// now is it called read, later it'll be sendData
{
	datalog = SD.open(filename);
	
	if (datalog)
	{
		while (datalog.available())
		{
			Serial.write(datalog.read());			// at this point it'll go to a communication-modul and send the data
		}
		datalog.close();
	} 
	else
	{
		Serial.println("Error: no micro sd card found or file doesn't exist!");		
	}
} //readData

void Sdcard::deleteFile(String filename)
{
	bool status = SD.exists(filename);
	if (status)
	{
		SD.remove(filename);
		Serial.println(filename + " removed");
	} 
	else
	{
		Serial.println(filename + " doesn't exist");
	}
} //deleteFile