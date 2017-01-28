/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#include "RESTResponse.h"

// constructor
RESTResponse::RESTResponse()
{
}
// destructor
RESTResponse::~RESTResponse()
{
}
// clears the body and the header
void RESTResponse::clear()
{
	Body = "";
	Header = "";
}
