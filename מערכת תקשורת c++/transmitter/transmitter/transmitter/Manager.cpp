#include "Manager.h"

Manager::Manager()
{
	thread ctrl(&Manager::ctrlMsg, this);
	ctrl.detach();
	thread dt(&Manager::dtMsg, this);
	dt.detach();
}

void Manager::ctrlMsg()
{
	control_socket.Bind(SERVERPORT);
	while (true)
	{
		char* msg = control_socket.recive();
		//messages.push(msg);
	}
}

void Manager::dtMsg()
{
	while (true)
	{
		sockaddr_in sendto;
		sendto.sin_family = AF_INET;
		sendto.sin_addr.s_addr = INADDR_ANY;
		sendto.sin_port = htons(SERVERPORT);
		data_socket.Bind(PORT);
		char* c = data_socket.recive(sendto);
		//DataMessage* d = (DataMessage*)& c;
		sendto.sin_port = htons(PORT);
		data_socket.send(c, sendto);
	}
}

Manager::~Manager() 
{

}


