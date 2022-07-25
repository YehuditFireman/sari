#pragma once
#include <WinSock2.h>
#include <iostream>
#include <cstring>
#include "IDD.h"
#define BUFFLEN sizeof(ControlMessage)
using namespace std;

class UDPsocket
{
private:
	SOCKET my_socket;

public:
	UDPsocket();
	void send(char* msg, sockaddr_in server);
	int Bind(unsigned short port);
	char* recive(sockaddr_in);
	~UDPsocket();
};




