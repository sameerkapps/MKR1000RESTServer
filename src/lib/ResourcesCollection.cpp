/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#include "ResourcesCollection.h"
// constructor
ResourcesCollection::ResourcesCollection()
{
	// ensure that the root is null
	_root = NULL;
}

ResourcesCollection::~ResourcesCollection()
{
}
// adds a resource to collection
// if the resource is null or has invalid name
// prints error message and returns false
bool ResourcesCollection::add(RESTResourceBase* resource)
{
	// validates the resource
	if (resource == NULL)
	{
		Serial.println("resource is null");

		return false;
	}
	// validate the resource name
	String resourceName = resource->getName();
	if (resourceName == NULL ||
		resourceName.length() == 0)
	{
		Serial.println("resourceName is null/empty");

		return false;
	}

	// create a node
	// make existing root as its next node
	// and set it as root.
	ResourceNode* node = new ResourceNode(resource);
	node->Next = _root;
	_root = node;

	return true;
}

// returns resource corresponding to the name (case insensitive comparison)
RESTResourceBase* ResourcesCollection::get(String resourceName)
{
	// validate the input
	if(resourceName == NULL || 
	   resourceName.length() == 0)
	{
		Serial.println("resourceName is null/empty.");

		return false;
	}

	// walk tthrough the collection
	// find the resource and return it
	// if not found, return null
	ResourceNode *node = _root;

	while (node != NULL)
	{
		if (resourceName.equalsIgnoreCase( node->getResource()->getName()))
		{
			return node->getResource();
		}

		node = node->Next;
	}

	return NULL;
}
