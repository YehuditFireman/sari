#include "UDPclient.h"

UDPclient::UDPclient()
{
	if (WSAStartup(MAKEWORD(2, 2), &ws) != 0)
	{
		cout << "Failed. Error Code: %d", WSAGetLastError();
		exit(1);
	}
	if ((client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) // <<< UDP socket
	{
		cout << "socket() failed with error code: %d", WSAGetLastError();
		exit(2);
	}
}
void UDPclient::init(int port) 
{
	memset((char*)& server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.S_un.S_addr = inet_addr(SERVER);
}

void UDPclient::send(DataMessage dm)
	{
		char* c = (char*)& dm;
		if (sendto(client_socket, c, strlen(c), 0, (sockaddr*)& server, sizeof(sockaddr_in)) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code: %d", WSAGetLastError());
			exit(3);
		}
	}

void UDPclient::close()
	{
		closesocket(client_socket);
		WSACleanup();
	}

UDPclient::~UDPclient()
{
}
