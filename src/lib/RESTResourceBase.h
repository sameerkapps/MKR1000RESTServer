/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESTPROCESSORBASE_h
#define _RESTPROCESSORBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
// base class for the resources
// the derived classes must implement getName
// and override the methods corresponding to the supported verbs
// other verbs default to verb not supported
class RESTResourceBase
{
public:
	// override this to provide the name of the resoruce
	virtual String getName() = 0;
	// this processes verb and call the corresponding methods
	// if you want to process additional verbs, override processNotSupportedVerb
	virtual void processVerb(String verb, String params, String* body);
	// returns the body of the response
	String getResponseBody();
	// returns the header of the response
	String getResponseHeader();

protected:
	// constructor
	RESTResourceBase();
	// destructor
	~RESTResourceBase();
	// set the response body
	void setResponseBody(String responseBody);
	// set the response header
	void setResponseHeader(String responseHeader);
	// override this to process GET verb
	virtual void processGet(String params, String* body);
	// override this to process POST verb
	virtual void processPost(String params, String* body);
	// override this to process PUT verb
	virtual void processPut(String params, String* body);
	// override this to process DELETE verb
	virtual void processDelete(String params, String* body);
	// override this to process other verbs
	virtual void processUnsupportedVerb(String verb, String params, String* body);

private:
	// variables to store header andbody of the response
	String _responseHeader = "";
	String _responseBody = "";
};

#endif

