#pragma once
#include "Comms.h"

// Uses Comms as a base class
class Server : public Comms
{
public:
	// Initializes server functions
	Server();
	void Socket();
	void Bind();
	void Listen();
	void FailedConnection();
	void AcceptConnection();
	void Receive();
};

