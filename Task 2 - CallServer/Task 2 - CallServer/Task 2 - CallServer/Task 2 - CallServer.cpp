// Task 2 - CallServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server.h"
#include "Client.h"
#include "Comms.h"
#include <exception>

int main()
{
	// Sets up the server script so main can call its functions
	Server *server = new Server();

	// Calls initialise in comms through the server script
	server->Initialise();

	// Calls the rest of servers functions 
	server->Socket();
	server->Bind();
	server->Listen();
	server->FailedConnection();
	server->AcceptConnection();
	server->Receive();

	system("PAUSE");
	// WSACleanup terminates use of the winsock 2
	WSACleanup();
    return 0;
}

