// DemoResource.h

#ifndef _DEMORESOURCE_h
#define _DEMORESOURCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MKR1000ServerLib.h"

class DemoResource : public RESTResourceBase
{
public:
	DemoResource();
	~DemoResource();

	// Inherited via RESTResourceBase
	virtual String getName() override;
protected:
	virtual void processGet(String params, String* body);

	virtual void processPost(String params, String* body);

	virtual void processPut(String params, String* body);

	virtual void processDelete(String params, String* body);
	
private:
	String _fooResource = "";
};

#endif

