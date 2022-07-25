#include "UDPsocket.h"
#include <queue>
#include <iostream>
#include <thread>
#define SERVERPORT 8888
#define PORT 8889
#define IP "127.0.0.1"
#pragma once

using namespace std;

class Manager
{
public:
	//queue<char*> messages;

	UDPsocket control_socket;
	UDPsocket data_socket;

	void ctrlMsg();
	void dtMsg();

	Manager();
	~Manager();
};

