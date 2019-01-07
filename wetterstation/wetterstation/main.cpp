#include <Arduino.h>
#include "SystemDefinitions.h"
#include "RealTimeClock.h"
#include "TempHumidPressSensor.h"
#include "Sdcard.h"
#include "Calculate.h"
#include "LightIntensitySensor.h"
#include "ISR.h"
#include "ADC.h"

Sdcard sd;
TempHumidPressSensor thps;
LightIntensitySensor tsl2561;
BME280SensorData sensordata;
WindData windData;
RealTimeClock realtimeclock;
TimeStamp ts;
Calculate calculate;

String logDataHour = "Hour.txt";
String logDataDay = "Day.txt";
String logDataWeek = "Week.txt";
String logDataMonth = "Month.txt";
// it would be useful if there is an option for NOW (current values maybe)!

void measureWeather();
void printWeatherData();

struct WeatherStationData
{
	float temperature, humidity, pressure, lightintesity, windspeed, rainfall;
	uint8_t day, month, hour, minute, second;
	uint16_t year;
	String windstrength, winddirection, weekday;
}weatherStationData;

void setup()
{
	Serial.begin(9600);
	while (!Serial);
	sd.initSdcardBreakout();
	realtimeclock.initRTC();
	thps.initTempHumidPressSensor();
	tsl2561.initLightIntensitySensor();
	beginAnemometer(PIN_ANEMOMETER);
	beginOmbrometer(PIN_OMBROMETER);
	Serial.println(" ");
} //setup

void loop()
{
	delay(TIME * 1000);
	measureWeather();
	printWeatherData();
} //loop

void measureWeather()
{
	sensordata = thps.getData();
	windData = calculate.getWindSpeed(getNumberOfEdgesAnemometer());
	ts = realtimeclock.getTimeStamp();
	
	weatherStationData.temperature = sensordata.t;
	weatherStationData.humidity = sensordata.h;
	weatherStationData.pressure = sensordata.p;
 	weatherStationData.windspeed = windData.windspeed;
	weatherStationData.windstrength = windData.windstrength;
	weatherStationData.winddirection = getWindDirection(binaryToVoltageConverting(analogRead(PIN_WINDDIRECTIONSENSOR)));
	weatherStationData.rainfall = calculate.getRainfall(getNumberOfEdgesOmbrometer());
	weatherStationData.lightintesity = tsl2561.getData();
	
	weatherStationData.weekday = ts.dotw;
	weatherStationData.day = ts.d;
	weatherStationData.month = ts.mo;
	weatherStationData.year = ts.y;
	weatherStationData.hour = ts.h;
	weatherStationData.minute = ts.mi;
	weatherStationData.second = ts.s;
} //measureWeather

void printWeatherData()
{	
	Serial.print(weatherStationData.weekday); Serial.print(":\t"); Serial.print(weatherStationData.hour); Serial.print(":"); 
	Serial.print(weatherStationData.minute); Serial.print(":"); Serial.print(weatherStationData.second); Serial.print("\t"); 
	Serial.print(weatherStationData.day); Serial.print("."); Serial.print(weatherStationData.month); Serial.print("."); 
	Serial.println(weatherStationData.year);
	
	Serial.print("Temperature:\t"); Serial.print(weatherStationData.temperature); Serial.print("\t"); Serial.println("Celsius");
	Serial.print("Humidity:\t"); Serial.print(weatherStationData.humidity); Serial.print("\t"); Serial.println("%");
	Serial.print("Airpressure:\t"); Serial.print(weatherStationData.pressure); Serial.print("\t"); Serial.println("hPa");
	Serial.print("Windspeed:\t"); Serial.print(weatherStationData.windspeed); Serial.print("\t"); Serial.println("m/s");
	Serial.print("Windstrength:\t"); Serial.print(weatherStationData.windstrength); Serial.print("\t"); Serial.println("");
	Serial.print("Winddirection:\t"); Serial.print(weatherStationData.winddirection); Serial.print("\t"); Serial.println("");
	Serial.print("Rainfall:\t"); Serial.print(weatherStationData.rainfall); Serial.print("\t"); Serial.println("ml/m^2");
	Serial.print("Lightintensity:\t"); Serial.print(weatherStationData.lightintesity); Serial.print("\t"); Serial.println("lux");
	Serial.println("");
} //printWeatherData