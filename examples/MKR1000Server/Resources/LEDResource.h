// LEDResource.h

#ifndef _LEDRESOURCE_h
#define _LEDRESOURCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MKR1000ServerLib.h"

class LEDResource : public RESTResourceBase
{
public:
	LEDResource();
	~LEDResource();
	// Inherited via RESTResourceBase
	virtual String getName() override;
protected:
	virtual void processPost(String params, String* body);

	virtual void processPut(String params, String* body);
private:
	bool _isInitiated = false;
	const int LEDPin = 6;
};

#endif

