#include "UDPsocket.h"


UDPsocket::UDPsocket()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		cout << "Failed. Error Code: " << WSAGetLastError();
	}
	
	if ((my_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		cout << "Could not create socket: " << WSAGetLastError();
	}
	
}
int UDPsocket::Bind(unsigned short port)
{
	sockaddr_in server;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	if (bind(my_socket, (sockaddr*)& server, sizeof(server)) == SOCKET_ERROR)
	{

		cout<< "Bind failed with error code: %d", WSAGetLastError();
		return -1;
		//exit(EXIT_FAILURE);
	}
	//puts("Bind done.");

	return 0;
}

void UDPsocket::send(char* msg, sockaddr_in server)
{
	sockaddr_in server;

	if (sendto(my_socket, msg, strlen(msg), 0, (sockaddr*)& server, sizeof(sockaddr_in)) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code: %d", WSAGetLastError());
		exit(3);
	}
}

char* UDPsocket::recive(sockaddr_in server)
{
	char message[BUFFLEN];
	while (true)
	{
		int message_len;
		int slen = sizeof(sockaddr_in);
		if (message_len = recvfrom(my_socket, message, BUFFLEN, 0, (sockaddr*)& server, &slen) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code: %d", WSAGetLastError());
			exit(0);
		}
		return message;
	}
}

UDPsocket::~UDPsocket()
{
	closesocket(my_socket);
	WSACleanup();
}


