
#ifndef __TEMPHUMIDPRESSSENSOR_H__
#define __TEMPHUMIDPRESSSENSOR_H__

struct BME280SensorData
{
	float t, h, p, a;
};

class TempHumidPressSensor
{
//variables
private:
	float temperatur, humidity, pressure, altitude;

//functions
public:
	TempHumidPressSensor();
	~TempHumidPressSensor();
	void initTempHumidPressSensor();
	BME280SensorData getData();
private:
	void setData();
	TempHumidPressSensor( const TempHumidPressSensor &c );
	TempHumidPressSensor& operator=( const TempHumidPressSensor &c );

}; //TempHumidPressSensor

#endif //__TEMPHUMIDPRESSSENSOR_H__
