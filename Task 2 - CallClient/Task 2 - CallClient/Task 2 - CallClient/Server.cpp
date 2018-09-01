#include "stdafx.h"
#include "Server.h"

Server::Server()
{

}

// This function creates a socket that is bound to a specific transport service provider
void Server::Socket()
{
	serverSocket = INVALID_SOCKET;
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	try
	{
		if (serverSocket == INVALID_SOCKET)
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

// This function associates a local address with a socket
void Server::Bind()
{
	service.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);

	try
	{
		if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
		{
			// Throws char followed by WSAGetLastError 
			throw "bind() failed: ", WSAGetLastError();
			closesocket(serverSocket);
			WSACleanup();
		}
		else
		{
			cout << "bind() is OK!" << endl;
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

// This functions listens for a client 
void Server::Listen()
{
	try
	{
		if (listen(serverSocket, 1) == SOCKET_ERROR)
			throw "listen(): Error listening on socket ", WSAGetLastError();
		else
			cout << "listen() is OK, I'm waiting for connections..." << endl;
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

// This functions checks to see if the server failed to connect 
void Server::FailedConnection()
{
	fromlen = sizeof(socket_type);
	retval = getsockopt(serverSocket, SOL_SOCKET, SO_TYPE, (char *)&socket_type, &fromlen);
	fromlen = sizeof(from);

	try
	{
		acceptSocket = accept(serverSocket, (SOCKADDR *)&from, &fromlen);
		if (acceptSocket == INVALID_SOCKET)
		{
			throw "accept failed: ", WSAGetLastError();
			WSACleanup();
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

// This function permits an incoming connection on a socket 
void Server::AcceptConnection()
{
	retval = getnameinfo((SOCKADDR *)&from,
		fromlen,
		hoststr,
		NI_MAXHOST,
		servstr,
		NI_MAXSERV,
		NI_NUMERICHOST | NI_NUMERICSERV);

	try
	{
		if (retval != 0)
		{
			throw "getnameinfo failed: ", retval;
			WSACleanup();
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

	cout << "Accepted connection from host " << hoststr << " and port " << servstr << endl;
	cout << "Accepted connection" << endl;
}

void Server::Receive()
{
	while (INFINITE)
	{
		char receiveBuffer[200] = "";
		int byteCount = recv(acceptSocket, receiveBuffer, 200, 0);

		try
		{
			if (byteCount < 0)
			{
				throw "Client: error %ld.\n", WSAGetLastError();
			}
			else
			{
				printf("Received data : %s  \n", receiveBuffer);
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

		try
		{
			char Recieved[200] = "Message Recieved";
			byteCount = send(acceptSocket, Recieved, 200, 0);
			if (byteCount == SOCKET_ERROR)
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
	}
}