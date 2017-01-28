/*
Copyrights - Sameer Khandekar
Creative Commons Attribution-NonCommercial 4.0 International License.
*/

#include "RESTServer.h"

#include "SPI.h"

// creates a WiFiServer with the given port
RESTServer::RESTServer(int port)
{
	// create the server, requesthandler and the resource collection
	_theServer = new WiFiServer(port);
}
// destructor deletes the server
RESTServer::~RESTServer()
{
	delete _theServer;
	_theServer = NULL;
}
// set up will connect to WiFi and start the server
// returns IP Address
String RESTServer::start(String ssidName, String wifiPassword)
{
	connectToWiFi(ssidName, wifiPassword);
	_theServer->begin();

	return getIPAddress();
}
// adds resource to the server
// call this in setup() method
bool RESTServer::addRESTResource(RESTResourceBase* resource)
{
	return _requestHandler.addResource(resource);
}

// checks if a client is available
// if so, reads the request and process it
// else returns. This should be called in the loop() method
void RESTServer::processRequest()
{
	// check if client is available
	WiFiClient client = _theServer->available();
	if (client != NULL)
	{
		boolean currentLineIsBlank = true;
		String request = "";
		while (client.connected())
		{
			if (client.available())
			{
				char c = client.read();
				request += c;
				// collect the request as each character
				if (c == '\n' && currentLineIsBlank) // this will get the entire request body
													 // if (c == '\n') // this will get only the url
				{
					Serial.println("Begin Request");
					Serial.println(request);
					// process the request, that will return the response
					RESTResponse response = _requestHandler.processRequest(request);
					Serial.println("END Request");
					// set the response header
					client.println(response.Header);
					// set the header content type as json
					client.println("Content-Type: application/json");

					client.println("Connection: close");  // the connection will be closed after completion of the response  
					client.println();
					// send body, if applicable
					if (response.Body.length() > 0)
					{
						client.println(response.Body);
					}

					break;
				}
				if (c == '\n')
				{
					// you're starting a new line
					currentLineIsBlank = true;
				}
				else if (c != '\r')
				{
					// you've gotten a character on the current line
					currentLineIsBlank = false;
				}
			}
		}
		// give the web browser time to receive the data
		delay(1);

		// close the connection:
		client.stop();
		Serial.println("client disonnected");
	}

}
// returns the IP address
String RESTServer::getIPAddress()
{
	return IPAddressToString(_localIPAddress);
}

// connects to WiFi
void RESTServer::connectToWiFi(String ssidName, String wifiPassword)
{
	// set up wifi
	WiFi.begin(ssidName, wifiPassword);

	// wait 10 seconds for connection
	delay(10000);

	// update the IPAddress
	_localIPAddress = WiFi.localIP();
}

// converts IPaddress to string
String RESTServer::IPAddressToString(IPAddress address)
{
	String str = String(address[0]);
	str += ".";
	str += String(address[1]);
	str += ".";
	str += String(address[2]);
	str += ".";
	str += String(address[3]);

	return str;
}
