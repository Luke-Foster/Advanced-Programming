#pragma once
#include "stdafx.h"
#include "winsock2.h"
#include "ws2tcpip.h"
#include <iostream>
#include <exception>

using namespace std;

class Comms
{
public:
	Comms();
	void Initialise();
protected:

	// Variable declarations that are both used in client and server cpps
	SOCKADDR_STORAGE from;
	int retval, fromlen, socket_type;
	char servstr[NI_MAXSERV], hoststr[NI_MAXHOST];

	SOCKET serverSocket, clientSocket, acceptSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);

	sockaddr_in service;
	sockaddr_in clientService;

	char buffer[200];
};

// Exception class used in server and client cpp to throw a server send error
class ServerSendError : exception 
{
public:
	virtual const char* what() const throw()
	{
		return "Server send error %ld.\n";
	}
};

// Exception class used in server and client cpp to throw a socket error
class SocketError : exception
{
public:
	virtual const char* what() const throw()
	{
		return "Error at socket(): ";
	}
};