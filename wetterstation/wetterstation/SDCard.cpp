#include <SD.h>
#include <SPI.h>
#include <stdlib.h>
#include "sdcard.h"

File myFile;
Sd2Card card;
SdVolume volume;
SdFile root;

// constructor
sdcard::sdcard(unsigned int cs, unsigned int mosi, unsigned int miso, unsigned int sck)
{	
	chipSelect_pin = cs;
	mosi_pin = mosi;
	miso_pin = miso;
	sck_pin = sck;
} // sdcard

// destructor
sdcard::~sdcard()
{
	
} // ~sdcard

void sdcard::getCardInformations()
{
	if (!card.init(SPI_HALF_SPEED, chipSelect_pin)) {
		Serial.println("no card available!");
		return;
	}

	// print the type of card
	Serial.print("Card type: ");
	switch (card.type()) {
		case SD_CARD_TYPE_SD1:
		Serial.println("SD1");
		break;
		case SD_CARD_TYPE_SD2:
		Serial.println("SD2");
		break;
		case SD_CARD_TYPE_SDHC:
		Serial.println("SDHC");
		break;
		default:
		Serial.println("Unknown");
	}

	// try to open the 'volume'/'partition' - it should be FAT16 or FAT32
	if (!volume.init(card)) {
		Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
		return;
	}


	// print the type and size of the first FAT-type volume
	uint32_t volumesize;
	Serial.print("\nVolume type is FAT");
	Serial.println(volume.fatType(), DEC);
	Serial.println();

	volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
	volumesize *= volume.clusterCount();       // we'll have a lot of clusters
	volumesize *= 512;                            // SD card blocks are always 512 bytes
	Serial.print("Volume size (bytes): ");
	Serial.println(volumesize);
	Serial.print("Volume size (Kbytes): ");
	volumesize /= 1024;
	Serial.println(volumesize);
	Serial.print("Volume size (Mbytes): ");
	volumesize /= 1024;
	Serial.println(volumesize);


	Serial.println("Files found on the card (name, date and size in bytes): ");
	root.openRoot(volume);

	// list all files in the card with date and size
	root.ls(LS_R | LS_DATE | LS_SIZE);
} // getCardInformations

void sdcard::writeFileSDCard(float value2save, String filename)
{
	digitalWrite(chipSelect_pin, HIGH);
	while (digitalRead(chipSelect_pin) != HIGH){}
	
	if (!SD.begin(chipSelect_pin))
	{
		Serial.println("Error: no micro sd card found!");
		return;
	}
	// open file
	myFile = SD.open(filename, FILE_WRITE);

	// if the file opened okay, write to it:
	if (myFile)
	{
		myFile.println(String(value2save));
		Serial.println("Data stored!");
		// close the file:
		myFile.close();
	} 
	else
	{
		// if the file didn't open, print an error:
		Serial.println("Error opening: " + filename);
	}	
	digitalWrite(chipSelect_pin, LOW);
	while (digitalRead(chipSelect_pin) != LOW){}
} // writeFileSDCard

void sdcard::readFileSDCard(String filename)
{
	digitalWrite(chipSelect_pin, HIGH);
	while (digitalRead(chipSelect_pin) != HIGH){}

	if (!SD.begin(chipSelect_pin))
	{
		Serial.println("Error: no micro sd card found!");
		return;
	}
	//open the file for reading:
	myFile = SD.open(filename);
	if (myFile) {
		Serial.println("Filename: " + filename);

		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			Serial.write(myFile.read());
		}
		// close the file:
		myFile.close();
		} else {
		// if the file didn't open, print an error:
		Serial.println("Error opening" + filename);
	}
	digitalWrite(chipSelect_pin, LOW);
	while (digitalRead(chipSelect_pin) != LOW){}	
} // readFileSDCard

void sdcard::deleteFileSDCard(String filename)
{
	digitalWrite(chipSelect_pin, HIGH);
	while (digitalRead(chipSelect_pin) != HIGH){}

	if (!SD.begin(chipSelect_pin))
	{
		Serial.println("Error: no micro sd card found!");
		return;
	}
	// delete unwanted file if it exists
	if (SD.exists(filename))
	{
		SD.remove(filename);
	}
	else
	{
		Serial.println("File doesn't exist!");
	}
	digitalWrite(chipSelect_pin, LOW);
	while (digitalRead(chipSelect_pin) != LOW){}
} // deleteFileSDCard