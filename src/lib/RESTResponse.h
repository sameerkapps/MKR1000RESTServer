/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESTRESPONSE_h
#define _RESTRESPONSE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
// Represents response after processing
class RESTResponse
{
public:
	// constructor
	RESTResponse();
	// destructor
	~RESTResponse();
	// clears the body and the header
	void clear();
	// body of the response
	String Body;
	// header of the response
	String Header;
};

#endif

