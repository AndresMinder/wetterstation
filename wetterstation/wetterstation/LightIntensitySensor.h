
#ifndef __LIGHTINTENSITYSENSOR_H__
#define __LIGHTINTENSITYSENSOR_H__

class LightIntensitySensor
{
//variables
public:
protected:
private:
	float lux;

//functions
public:
	LightIntensitySensor();
	~LightIntensitySensor();
	void initLightIntensitySensor();
	float getData();
protected:
private:
	void setData();
	void configureSensor();
	void displaySensorDetails();
	LightIntensitySensor( const LightIntensitySensor &c );
	LightIntensitySensor& operator=( const LightIntensitySensor &c );

}; //LightIntensitySensor

#endif //__LIGHTINTENSITYSENSOR_H__
