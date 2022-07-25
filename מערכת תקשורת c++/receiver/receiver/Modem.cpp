#include "Modem.h"
Modem::Modem()
{
	thread t1(&Modem::ServerAction, this);
	t1.detach();
	thread t2(&Modem::ClientAction, this);
	t1.detach();
}

void Modem::ServerAction()
{
	server.Bind(SERVERPORT);
	while (true)
	{
		char* msg = server.recive();
		messages.push(msg);
	}
}
void Modem::ClientAction()
{
	client.init(PORT, IP);
	client.send(messages.front());
	messages.pop();
}


Modem::Modem()
{
}


Modem::~Modem()
{
}
