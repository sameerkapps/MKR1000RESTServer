/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#include "ResourceNode.h"
// default constructor - this is private
ResourceNode::ResourceNode()
{
}
// destructor
ResourceNode::~ResourceNode()
{
}

// constructor that accespts resource
// validates it and prints error message, if it is invalid
ResourceNode::ResourceNode(RESTResourceBase* resource)
{
	// validate for null
	if (resource == NULL)
	{
		Serial.println("error:null resource.");
		return;
	}
	// validate the name
	String resourceName = resource->getName();
	if (resourceName == NULL || resourceName.length() == 0)
	{
		Serial.println("error: Invalid resourceName.");
		return;
	}

	_resource = resource;
}
// return the resource
RESTResourceBase* ResourceNode::getResource()
{
	return _resource;
}
