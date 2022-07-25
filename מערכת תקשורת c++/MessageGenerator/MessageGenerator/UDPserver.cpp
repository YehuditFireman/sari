#include "UDPserver.h"

using namespace std;

	UDPserver::UDPserver()
	{
		if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
			cout <<"Failed. Error Code: "<< WSAGetLastError();
			exit(0);
		}
		if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		{
			cout << "Could not create socket: " << WSAGetLastError();
		}
	}

	void UDPserver::Bind(int port)
	{
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = htons(port);
		if (bind(server_socket, (sockaddr*)& server, sizeof(server)) == SOCKET_ERROR)
		{
			printf("Bind failed with error code: %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		puts("Bind done.");
	}

	char* UDPserver::recive()
	{
		char message[BUFFLEN];
		while (true)
		{
			printf("Waiting for data...");
			fflush(stdout);
			int message_len;
			int slen = sizeof(sockaddr_in);
			if (message_len = recvfrom(server_socket, message, BUFFLEN, 0, (sockaddr*)& client, &slen) == SOCKET_ERROR)
			{
				printf("recvfrom() failed with error code: %d", WSAGetLastError());
				exit(0);
			}
			cout << (DataMessage*)& message;//ìäôåê àú æä ìreturn
		}
	}
	void UDPserver::close()
	{
		closesocket(server_socket);
		WSACleanup();
	}

	UDPserver::~UDPserver()
{
}


