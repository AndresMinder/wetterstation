#include <Arduino.h>
#include "Rj11Sensors.h"

// constructor
Rj11Sensors::Rj11Sensors()
{
} //constructor

// destructor
Rj11Sensors::~Rj11Sensors()
{
} //~destructor

void Rj11Sensors::begin(const byte digitalPinNumber)
{
	attachInterrupt(digitalPinToInterrupt(digitalPinNumber), isrFunction, RISING);
	instance = this;
}  // end of myClass::begin

void Rj11Sensors::countEdges()
{
	numberOfEdges++;
} //countEdges

uint32_t Rj11Sensors::getNumberOfEdges()
{
	return numberOfEdges;
} //getNumberOfEdges