#include "UDPsocket.h"
#include <thread>
#include <queue>
#define SERVERPORT 8889
#define PORT 8890
#define IP "127.0.0.1"

#pragma once

class Modem
{
public:
	//queue<char*> messages;

	UDPsocket server;

	void Action();
	//void ClientAction();

	Modem();
	~Modem(); 
};

