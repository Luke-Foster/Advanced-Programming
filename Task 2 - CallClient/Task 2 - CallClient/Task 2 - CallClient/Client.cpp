#include "stdafx.h"
#include "Client.h"

Client::Client()
{

}

// This function creates a socket that is bound to a specific transport service provider
void Client::Socket()
{
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	try
	{
		if (clientSocket == INVALID_SOCKET)
		{
			// Throws error to SocketError Class 
			throw SocketError(), WSAGetLastError();
			WSACleanup();
		}
		else
		{
			cout << "socket() is OK!" << endl;
		}
	}
	catch (SocketError& s) // Catches class error 
	{
		cout << "Error: " << s.what() << endl;
	}
	catch (...) // Default catch
	{
		cout << "Error: " << endl;
	}
}

// This function connects a client to a server(invoked from within the client)
void Client::Connect()
{
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	try
	{
		if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
		{
			throw "Client: connect() - Failed to connect.";
			WSACleanup();
		}
		else
		{
			cout << "Client: connect() is OK." << endl;
			cout << "Client: Can start sending and receiving data..." << endl;
		}
	}
	catch (char * error) // Catches char error
	{
		cout << "Exception : " << error << endl;
	}
	catch (...) // Default catch
	{
		cout << "Exception : " << endl;
	}
}

void Client::Send()
{
	while (INFINITE)
	{
		printf("Enter your message ");
		cin.getline(buffer, 200);
		int byteCount = send(clientSocket, buffer, 200, 0);

		try
		{
			if (strcmp(buffer, "SHUTDOWN") == 0)
			{
				abort();
				WSACleanup();
			}
			else if (byteCount == SOCKET_ERROR)
			{
				// Throws error to ServerSendError Class 
				throw ServerSendError(), WSAGetLastError();
			}
			else
			{
				printf("Server: sent %ld bytes \n", byteCount);
			}
		}
		catch (ServerSendError& e) // Catches class error
		{
			cout << "Error: " << e.what() << endl;
		}
		catch (...) // Default catch
		{
			cout << "Error: " << endl;
		}

		char receiveBuffer[200] = "";
		byteCount = recv(clientSocket, receiveBuffer, 200, 0);

		try
		{
			if (byteCount < 0)
			{
				throw "Client send error %ld.\n", WSAGetLastError();
			}
			else
			{
				printf("Server: sent %s  \n", receiveBuffer);
			}
		}
		catch (char * error) // Catches char error
		{
			cout << "Exception : " << error << endl;
		}
		catch (...) // Default catch
		{
			cout << "Exception : " << endl;
		}
	}
}