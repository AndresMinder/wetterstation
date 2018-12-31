
#ifndef __SDCARD_H__
#define __SDCARD_H__

class Sdcard
{
//variables
public:
protected:
private:

//functions
public:
	Sdcard();
	~Sdcard();
	void initSdcardBreakout();
	void writeData(float data, String filename);
	void readData(String filename);
	void deleteFile(String filename);
protected:
private:
	Sdcard( const Sdcard &c );
	Sdcard& operator=( const Sdcard &c );

}; //Sdcard

#endif //__SDCARD_H__
