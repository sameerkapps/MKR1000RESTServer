/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/
#include "Arduino.h"
#include "RESTResourceBase.h"
#include "HttpStatusConstants.h"
#include "HttpVerbs.h"

//class RESTProcessorBase

// processes GET, POST, PUT and DELETE verbs.
// for other verbs, override processNotSupportedVerb
void RESTResourceBase::processVerb(String verb, String params, String *body)
{
	if (verb == NULL)
	{
		Serial.println("The verb is null");
		processUnsupportedVerb(verb, params, body);
		return;
	}
	// process verbs
	if (VERB_GET.equalsIgnoreCase(verb))
	{
		processGet(params, body);
	}
	else if (VERB_POST.equalsIgnoreCase(verb))
	{
		processPost(params, body);
	}
	else if (VERB_PUT.equalsIgnoreCase(verb))
	{
		processPut(params, body);
	}
	else if (VERB_DELETE.equalsIgnoreCase(verb))
	{
		processDelete(params, body);
	}
	else
	{
		processUnsupportedVerb(verb, params, body);
	}
}

// returns response body
String RESTResourceBase::getResponseBody()
{
	return _responseBody;
}
// returns response header
String RESTResourceBase::getResponseHeader()
{
	return _responseHeader;
}

// constructor
RESTResourceBase::RESTResourceBase()
{
}
// destructor
RESTResourceBase::~RESTResourceBase()
{
}
// sets the body for response, called by the derived resource
void RESTResourceBase::setResponseBody(String responseBody)
{
	_responseBody = responseBody;
}
// sets the header for response, called by the derived resource
void RESTResourceBase::setResponseHeader(String responseHeader)
{
	_responseHeader = responseHeader;
}
// processes GET verb. Should be overridden by the derived resource if it wants to process it
void RESTResourceBase::processGet(String params, String *body)
{
	processUnsupportedVerb(VERB_GET, params, body);
}
// processes POST verb. Should be overridden by the derived resource if it wants to process it
void RESTResourceBase::processPost(String params, String *body)
{
	processUnsupportedVerb(VERB_POST, params, body);
}
// processes PUT verb. Should be overridden by the derived resource if it wants to process it
void RESTResourceBase::processPut(String params, String *body)
{
	processUnsupportedVerb(VERB_PUT, params, body);
}
// processes DELETE verb. Should be overridden by the derived resource if it wants to process it
void RESTResourceBase::processDelete(String params, String *body)
{
	processUnsupportedVerb(VERB_DELETE, params, body);
}
// processes unsupported verbs by setting header status as 405
// Should be overridden by the derived resource if it wants to process any
void RESTResourceBase::processUnsupportedVerb(String verb, String params, String *body)
{
	_responseHeader = HTTP_405_STATUS;
}

