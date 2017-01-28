/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESTREQUEST_h
#define _RESTREQUEST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Represents a request
class RESTRequest
{
public:
	// constructor
	RESTRequest();
	// destructor
	~RESTRequest();
	// clears all the parts of the request
	void clear();

	// Body of the request
	String Body;
	// Name of the resource
	String ResourceName;
	// Verb
	String Verb;
	// Url params
	String Params;
};


#endif

