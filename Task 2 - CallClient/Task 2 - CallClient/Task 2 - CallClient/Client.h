#pragma once
#include "Comms.h"

// Uses Comms as a base class
class Client : public Comms
{
public:
	// Initializes server functions
	Client();
	void Socket();
	void Connect();
	void Send();
};

