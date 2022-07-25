#include <WinSock2.h>
#include <iostream>
#define SERVER "127.0.0.1"
#include "IDD.h"

using namespace std;

#pragma once
class UDPclient
{
	WSADATA ws;
	sockaddr_in server;
	int client_socket;
public:
	UDPclient();
	void init(int port);
	void send(DataMessage dm);
	void close();
	~UDPclient();
};

