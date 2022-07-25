#include "Modem.h"
Modem::Modem()
{
	thread t1(&Modem::Action, this);
	t1.detach();
	/*thread t2(&Modem::ClientAction, this);
	t1.detach();*/
}

void Modem::Action()
{
	server.Bind(SERVERPORT);
	while (true)
	{
		char* msg = server.recive();
		DataMessage* d = (DataMessage*)&msg;
		if (d->header.Opcode == DATA_MSG_OPCODE)
		{
			client.init(PORT, IP);
			client.send(d);
		}
		//messages.push(msg);
	}
}
//void Modem::ClientAction()
//{
//	client.init(PORT, IP);
//	client.send(messages.front());
//	messages.pop();
//}


Modem::Modem()
{
}


Modem::~Modem()
{
}
