#include "UDPserver.h"
#include "UDPclient.h"
#include <thread>
#include <queue>
#define SERVERPORT 8890
#define PORT 8891
#define IP "127.0.0.1"

#pragma once

class Modem
{
public:
	queue<char*> messages;

	UDPserver server;
	UDPclient client;

	void ServerAction();
	void ClientAction();

	Modem();
	~Modem();
};

