This library turns your MKR1000 (or equivalent) into a REST API server with easy to use API. This enables other devices/apps on the network to read data from the sensors attached to it, and send commands to the actuators. This all can be done using REST API protocol.

The library consists of two classes that are used by a sketch.
# RESTServer
This class is the host for REST Resources. It performs server initialization, resource registration and processing of the requests. It can be done as follows:
Declare a class in your sketch
```
#include "MKR1000ServerLib.h"

RESTServer myRESTfulServer(80);
``` 
In the setup() of your sketch, register the resources and call start method to get the server started. It will return the IPAddress that can be used by client.
```
void setup()  {
	myRESTfulServer.addRESTResource(new DemoResource());
	myRESTfulServer.addRESTResource(new LEDResource());
	myRESTfulServer.start(SSIDName, WiFiPassword);
	String ipAddress = myRESTfulServer.getIPAddress();
	Serial.println(ipAddress);
}
```
The http requests are processed in the loop. Simply call processRequest method in the loop. If a request is available, it is processed by the server, else it returns to the caller.
```
void loop() {
	myRESTfulServer.processRequest();
}
```
While processing the request, it is broken down into resource name, verb, parameters and body. Corresponding resource is identified and method corresponding to the verb is called.

# RESTResourceBase
This is the base class of all resources. It has an abstract method to provide name. Derived class (i.e. the resource) must override this to provide the name that is used to identify itself.
The class has virtual methods corresponding to GET, POST, PUT and DELETE verbs. It also has procesUnsupportedVerb method. By default, it returns “HTTP Status 405: Method Not Allowed”. The resource should override it to process supported verbs.

# Examples
The example consists of two resources
## DemoResource:
This processes 4 verbs GET, POST, PUT and DELETE. The value set in POST and PUT is returned as part of GET. And DELETE removes the information. 

## LEDResource:
This processes POST and PUT verbs. POST is used to initialize the LED pin. Based on the values in PUT, the LED is turned on/off. 

# Steps to use
- Download the MKR1000RESTServer.zip file from github.
- Start Arduino IDE
- Click Sketch Menu -> Include Library -> Add .zip library
- Choose the downloaded library
- In File -> Examples -> Scroll all the way down till you see MKR1000Server in Custom Library examples
- Update the following lines
```
String SSIDName = "Your SSID Name";
String WiFiPassword = "Your WiFi password";
```
- Start the Serial Monitor
- Compile and upload to your MKR1000 and your server is ready.
- After 10 seconds it will display its IP address. 

That can be used by POSTMAN or any other tool to call the REST APIs.

In near future, I will be publishing an app access the API. Stay tuned @sameerIOTApps.








