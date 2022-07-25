#pragma once
#include <WinSock2.h>
#include <iostream>
#include "IDD.h"
#define BUFFLEN sizeof(ControlMessage)

class UDPserver
{
private:
	sockaddr_in server, client;
	WSADATA wsa;
	SOCKET server_socket;
public:
	UDPserver();
	void Bind(int port);

	char* recive();
	void close();
	~UDPserver();
};

