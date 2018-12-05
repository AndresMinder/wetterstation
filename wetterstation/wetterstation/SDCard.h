#ifndef __SDCARD_H__
#define __SDCARD_H__

class SDCard
{
//variables
private:
	int chipSelect;
	
//functions
public:
	SDCard(unsigned int pinNumber);
	~SDCard();
	void getCardInformations();
	void writeFileSDCard(double value2save, String filename);
	void readFileSDCard(String filename);
	void deleteFileSDCard(String filename);
}; //test
#endif //__SDCARD_H__