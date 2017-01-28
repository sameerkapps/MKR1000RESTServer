/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/


#include "RESTRequest.h"
// constructor
RESTRequest::RESTRequest()
{
}
// destructor
RESTRequest::~RESTRequest()
{
}

// clears all members
void RESTRequest::clear()
{
	Body = "";
	ResourceName = "";
	Verb = "";
	Params = "";
}

