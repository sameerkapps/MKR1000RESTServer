/*
 Name:		MKR1000Server.ino
 Created:	1/19/2017 5:10:09 AM
 Author:	Sameer Khandekar
 Editor:	http://www.visualmicro.com
*/

#include "Resources\LEDResource.h"
#include "Resources\DemoResource.h"
#include "MKR1000ServerLib.h"

RESTServer myRESTfulServer(80);

String SSIDName = "Your SSID Name";
String WiFiPassword = "Your WiFi password";

// the setup function runs once when you press reset or power the board
void setup() 
{
	myRESTfulServer.addRESTResource(new DemoResource());
	myRESTfulServer.addRESTResource(new LEDResource());
	myRESTfulServer.start(SSIDName, WiFiPassword);
	String ipAddress = myRESTfulServer.getIPAddress();
	Serial.println(ipAddress);
}

// the loop function runs over and over again until power down or reset
void loop() {
	myRESTfulServer.processRequest();
}
