#ifndef __SDCARD_H__
#define __SDCARD_H__

class sdcard
{
//variables
private:
	unsigned int chipSelect_pin, mosi_pin, miso_pin, sck_pin;
	
//functions
public:
	sdcard(unsigned int cs, unsigned int mosi, unsigned int miso, unsigned int sck);
	~sdcard();
	void getCardInformations();
	void writeFileSDCard(float value2save, String filename);
	void readFileSDCard(String filename);
	void deleteFileSDCard(String filename);
}; // sdcard
#endif //__SDCARD_H__