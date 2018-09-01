#include "stdafx.h"
#include "Comms.h"

Comms::Comms()
{

}

void Comms::Initialise()
{
	// Initialises WSA
	wsaerr = WSAStartup(wVersionRequested, &wsaData);

	try
	{
		if (wsaerr != 0)
		{
			// throws error when wsaerr is not equal to 0 
			throw "The Winsock dll not found!";
		}
		else
		{
			cout << "The Winsock dll found!" << endl;
			cout << "The status: " << wsaData.szSystemStatus << endl;
		}
	}
	catch (char * error)
	{
		cout << "Exception : " << error << endl;
	}
	catch (...)
	{
		cout << "Exception : " << endl;
	}
}