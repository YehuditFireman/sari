#include "TX.cpp"
#include "RX.cpp"
#include "UDPserver.h"
#define PORT 8888
#define MSG_SYNC 0xAA55
#define DATA_MSG_OPCODE 0xD001 

int main()
{
	TX tx;
	tx.client.init(PORT);

	DataMessage dm;
	for (int i = 0; i < 3; i++)
	{
		dm.header.msgCounter = i;
		dm.header.msgSync = MSG_SYNC;
		dm.header.Opcode = DATA_MSG_OPCODE;
		tx.client.send(dm);
	}
}
