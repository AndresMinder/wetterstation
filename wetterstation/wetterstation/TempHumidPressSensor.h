#define SEALEVELPRESSURE_HPA (1013.25)

#ifndef __TEMPHUMIDPRESSSENSOR_H__
#define __TEMPHUMIDPRESSSENSOR_H__

struct SensorData
{
	float t, h, p, a;	
};

class TempHumidPressSensor
{
//variables
public:
protected:
private:
	float temperatur, humidity, pressure, altitude;

//functions
public:
	TempHumidPressSensor();
	~TempHumidPressSensor();
	void initTempHumidPressSensor();
	SensorData getData();
protected:
private:
	void setData();
	TempHumidPressSensor( const TempHumidPressSensor &c );
	TempHumidPressSensor& operator=( const TempHumidPressSensor &c );

}; //TempHumidPressSensor

#endif //__TEMPHUMIDPRESSSENSOR_H__
