#ifndef __RJ11SENSORS_H__
#define __RJ11SENSORS_H__

class Rj11Sensors
{
//variables
public:	
	static Rj11Sensors * instance;
private:
	uint32_t numberOfEdges = 0;

//functions
public:
	Rj11Sensors();
	~Rj11Sensors();
	void begin(const byte whichPin);
	uint32_t getNumberOfEdges();
private:	
	static void isrFunction()
	{
		if (Rj11Sensors::instance != NULL)
		Rj11Sensors::instance->countEdges();
	}  // end of myClass::isrFunction
	void countEdges();	
	Rj11Sensors( const Rj11Sensors &c );
	Rj11Sensors& operator=( const Rj11Sensors &c );
}; //Rj11Sensors

#endif //__RJ11SENSORS_H__