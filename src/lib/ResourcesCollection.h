/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESOURCESCOLLECTION_h
#define _RESOURCESCOLLECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ResourceNode.h"

// collection of resource nodes
class ResourcesCollection
{
public:
	// constructor
	ResourcesCollection();
	// destructor
	~ResourcesCollection();
	// add resoruce,
	// will inernally create a node and add it
	bool add(RESTResourceBase* resource);
	// returns the resource corresponding to the name
	// it is case insensitive
	RESTResourceBase* get(String resourceName);
private:
	ResourceNode* _root;
};

#endif

