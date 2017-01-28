// Copyrights - Sameer Khandekar
// MIT License
// 
/*
Demo for processing of all verbs. _fooResource is treated like a resource
It's value is updated based on PUT and POST methods
GET returns a sample JSON that includes its value
DELETE will set the value to empty
*/

#include "DemoResource.h"

// constructor
DemoResource::DemoResource()
{
}
// destructor
DemoResource::~DemoResource()
{
}
// name of the resource
String DemoResource::getName()
{
	return "Demo";
}
// processes GET verb
void DemoResource::processGet(String params, String * body)
{
	// set the header to success
	setResponseHeader(HTTP_200_STATUS);

	// create the response body with json
	String responseBody = "{\"mkr100\": {\"Pin1Voltage\": 3.2,\"Foo\": \"";
	// add value in the resource in it
	if (_fooResource == "")
	{
		responseBody += "";
	}
	else
	{
		responseBody += _fooResource;
	}
	responseBody += "\"}}";

	// set the response body
	setResponseBody(responseBody);
}

// processes POST verb
void DemoResource::processPost(String params, String * body)
{
	// if the current value of the _fooRsource is empty
	// set it
	if (_fooResource == "")
	{
		setResponseHeader(HTTP_201_STATUS);
		_fooResource = params;
	}
	else
	{ // if the current value is not empty, it is conflict
		setResponseHeader(HTTP_409_STATUS);
	}
	setResponseBody("");
}
// processes PUT verb
void DemoResource::processPut(String params, String * body)
{
	// set the value to the new value
	setResponseHeader(HTTP_200_STATUS);
	setResponseBody("");
	_fooResource = params;
}

// process delete
void DemoResource::processDelete(String params, String * body)
{
	// if value is not empty, set it to empty
	if (_fooResource != "")
	{
		setResponseHeader(HTTP_200_STATUS);
		_fooResource = "";
	}
	else
	{ // else resource was not created, so return 404
		setResponseHeader(HTTP_404_STATUS);
	}
	setResponseBody("");
}

