// Task 2 - CallClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server.h"
#include "Client.h"
#include "Comms.h"
#include <exception>

int main()
{
	// Sets up the client script so main can call its functions
	Client *client = new Client();

	// Calls initialise in comms through the client script
	client->Initialise();

	// Calls the rest of clients functions 
	client->Socket();
	client->Connect();
	client->Send();

	system("PAUSE");
	// WSACleanup terminates use of the winsock 2
	WSACleanup();
    return 0;
}

