/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#ifndef _RESTSERVER_h
#define _RESTSERVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <WiFi101.h>

#include "RequestHandler.h"

// REST Server that hosts various resources and processes requests
// call setup method in Arduino setup
// call processRequest in the Arduino loop method
class RESTServer
{
public:
	// constructor indicating port
	RESTServer(int port);
	// destructor
	~RESTServer();
	// performs initial setup and connects to WiFi
	// returns the IP address
	// This can take up to 10 sec
	String start(String ssidName, String wifiPassword);
	// adds a REST resource 
	// it is the responsiblity of the caller to ensure that the resouce name is unique in the collection
	bool addRESTResource(RESTResourceBase* resource);
	// processes the request, if available
	void processRequest();
	// returns the ip address of the server
	String getIPAddress();

protected:
	// additional method to connect to WiFi
	void connectToWiFi(String ssidName, String wifiPassword);

private:
	String IPAddressToString(IPAddress address);
	// server
	WiFiServer* _theServer;

	// local IP address:
	IPAddress _localIPAddress;

	// request handler
	RequestHandler _requestHandler;
};

#endif

