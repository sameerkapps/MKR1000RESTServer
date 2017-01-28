// Copyrights - Sameer Khandekar
// MIT License
// 

#include "LEDResource.h"
// constructor
LEDResource::LEDResource()
{
}
// destructor
LEDResource::~LEDResource()
{
}
// name of the resource
String LEDResource::getName()
{
	return "LED";
}
// POST is used for initiation
// i.e. set the pinMode
void LEDResource::processPost(String params, String * body)
{
	// if it is already initiated, it is a conflict
	if (_isInitiated)
	{
		setResponseHeader(HTTP_409_STATUS);
	}
	else
	{
		// set the pin mode and http status
		pinMode(LEDPin, OUTPUT);
		setResponseHeader(HTTP_201_STATUS);
		_isInitiated = true;
	}
	setResponseBody("");
}
// put turns LED on/off based on the value
void LEDResource::processPut(String params, String * body)
{
	setResponseHeader(HTTP_200_STATUS);
	setResponseBody("");

	if (params.equalsIgnoreCase("on"))
	{
		digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
	}
	else
	{
		digitalWrite(LEDPin, LOW);   // turn the LED off (HIGH is the voltage level)
	}
}
