/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#include "RequestHandler.h"
#include "HttpStatusConstants.h"

// constructor
RequestHandler::RequestHandler()
{
}
// destructor
RequestHandler::~RequestHandler()
{
}

// processes the request
RESTResponse RequestHandler::processRequest(String request)
{
	_restResponse.clear();
	_restRequest.clear();
	// this will break request into
	// resource, verb, body and params
	// will find resource
	// ask it to process it
	// and return the response
	String url = "";
	for (int i = 0; i< request.length(); i++)
	{
		char c = request.charAt(i);
		if (c == '\n')
		{
			break;
		}

		url += c;
	}

	if (parseRequest(url))
	{
		_restRequest.Body = request;
		handleRequest();
	}

	return _restResponse;
}
// adds a resource to the collection
bool RequestHandler::addResource(RESTResourceBase* resource)
{
	return _resourcesCollection.add(resource);
}

// parses the request into resource name, verb, url params and body
bool RequestHandler::parseRequest(String url)
{
	// initialize values to empty
	String _resourceNParams = "";

	// trim the url
	url.trim();

	// find the index of the verb and resource with params
	int beginRes = url.indexOf(' ');
	int endRes = url.lastIndexOf(' ');

	if ((beginRes == -1) ||
		(endRes == -1) ||
		(beginRes == endRes))
	{
		// error if begin or end is not found or they are equal
		// this will be cuaght in the further processing
	}
	// ensure that url ends with /
	if (url[endRes - 1] != '/')
	{
		_restResponse.Header = HTTP_400_STATUS;
		return false;
	}
	_restRequest.Verb = url.substring(0, beginRes);
	_restRequest.Verb.toUpperCase();
	_resourceNParams = url.substring(beginRes + 2, endRes - 1);
	// obtain resource from resource params
	int resourceEnd = _resourceNParams.indexOf('/');

	// obtain the resource name
	String resourceName = _resourceNParams.substring(0, resourceEnd);

	// make it case insentive
	resourceName.toLowerCase();
	_restRequest.ResourceName = resourceName;
	// assign params
	_restRequest.Params = _resourceNParams.substring(resourceEnd + 1);

	return true;
}
// Finds resources and asks it to process the verb
void RequestHandler::handleRequest()
{
	// this will find resource from the node
	// and ask it to process the request
	RESTResourceBase* resource = _resourcesCollection.get(_restRequest.ResourceName);

	if (resource == NULL)
	{
		_restResponse.Header = HTTP_404_STATUS;
		return;
	}

	resource->processVerb(_restRequest.Verb, _restRequest.Params, &_restRequest.Body);

	_restResponse.Body = resource->getResponseBody();
	_restResponse.Header = resource->getResponseHeader();
}