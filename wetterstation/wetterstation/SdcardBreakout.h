
#ifndef __SDCARDBREAKOUT_H__
#define __SDCARDBREAKOUT_H__

#define SD_CS 53

class SdcardBreakout
{
//variables
public:
protected:
private:

//functions
public:
	SdcardBreakout();
	~SdcardBreakout();
	void initSdcardBreakout();
	void writeData(float data, String filename);
	void readData(String filename);
	void deleteFile(String filename);
protected:
private:
	SdcardBreakout( const SdcardBreakout &c );
	SdcardBreakout& operator=( const SdcardBreakout &c );

}; //SdcardBreakout

#endif //__SDCARDBREAKOUT_H__
