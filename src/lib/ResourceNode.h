/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESOURCENODE_h
#define _RESOURCENODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RESTResourceBase.h"

// Node in the collection that hosts a resource and the next node
class ResourceNode
{
public:
	// constructor accepting resource
	ResourceNode(RESTResourceBase* resource);
	// destructor
	~ResourceNode();
	// returns teh resource
	RESTResourceBase* getResource();
	// pointer to the next node
	ResourceNode *Next;
private:
	// cannot construct without a valid resource
	ResourceNode();

	RESTResourceBase* _resource;
};


#endif

