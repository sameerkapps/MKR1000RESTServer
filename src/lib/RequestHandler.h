/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _REQUESTHANDLER_h
#define _REQUESTHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RESTResponse.h"
#include "RESTRequest.h"
#include "RESTResourceBase.h"
#include "ResourcesCollection.h"

// This hosts resources in the resources collection
// when a processRequest is called, it parses the requests and breaks it down into
// resource, verb, parameters for the resource and body
// It finds resource and asks it to process the verb
class RequestHandler
{
public:
	// constructor 
	RequestHandler();
	// desructor
	~RequestHandler();
	// processes the request
	RESTResponse processRequest(String request);
	// adds a resource to the collection
	bool addResource(RESTResourceBase* resource);

private:
	// parses the request and breaks it down into resource, verb, params and body
	bool parseRequest(String request);
	// finds a resource and asks it to process the verb
	// if resoruce is not found, returns 404
	void handleRequest();

	// resources collection
	ResourcesCollection _resourcesCollection;
	// response and request for each process
	RESTResponse _restResponse;
	RESTRequest _restRequest;
};


#endif

