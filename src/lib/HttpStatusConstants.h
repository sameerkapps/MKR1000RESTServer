/*
 * Copyrights - Sameer Khandekar.
 * MIT License
*/
#ifndef _HttpStatusConstants_h
#define _HttpStatusConstants_h

#include "Arduino.h"

// This file defines various common http status codes.
// Feel free to add more as you wish.

#define HTTP_200_STATUS "HTTP/1.1 200 OK"
#define HTTP_201_STATUS "HTTP/1.1 201 Created"

#define HTTP_400_STATUS "HTTP/1.1 400 Bad Request"
#define HTTP_403_STATUS "HTTP/1.1 403 Forbidden"
#define HTTP_404_STATUS "HTTP/1.1 404 Not Found"
#define HTTP_405_STATUS "HTTP/1.1 405 Method Not Allowed"
#define HTTP_409_STATUS "HTTP/1.1 409 Conflict"

#define HTTP_500_STATUS "HTTP/1.1 500 Internal Server Error"

// Not so common codes go here. So does not clutter up

// this code was defined by IETF in 1998 as April Fool's joke
// However today it can be used in IOT :)
#define HTTP_418_STATUS "HTTP/1.1 418 I'm a teapot (RFC 2324)"

#endif
