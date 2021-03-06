/*
github.com/ek33/Sumo-Bot-IR-Distance-Sensors

A library for testing and getting distance values from IR Distance Sensors.

This library is designed to use with: "Sharp GP2Y0A60SZLF Analog Distance Sensor 10-150cm, 5V"
More information about the sensor: "pololu.com/product/2474"

*/
#include <SharpSensor.h>

//Constructor
SharpSensor::SharpSensor(){}
SharpSensor::SharpSensor(int pin)
{
  _pin = pin;
  _distance = 0;
}

//Get Distance Function
uint16_t SharpSensor::getDistance()
{	
	calculateDistance();
  	return this->_distance;
}

//The function that calculates the distance by reading the sensor pin
void SharpSensor::calculateDistance()
{
  uint16_t sensorValue = analogRead(A7);
  this->_distance = 187754 * pow(sensorValue, -1.51);
}

int SharpSensor::getPin()
{
	return this->_pin;
}
