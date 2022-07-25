#pragma once

#define DATA_MSG_OPCODE 0xD001 

#define MANAGER_TO_AMPLIFIER_CONTROL_MSG_OPCODE  0xA002
#define AMPLIFIER_TO_MANAGER_CONTROL_MSG_OPCODE  0xA003


#define MANAGER_TO_MODEM_CONTROL_MSG_OPCODE 0xA004
#define MODEM_TO_MANAGER_CONTROL_MSG_OPCODE 0xA005

#define MANAGER_TO_ANTENNA_CONTROL_MSG_OPCODE 0xA006
#define ANTENNA_TO_MANAGER_CONTROL_MSG_OPCODE 0xA007
#define MSG_SYNC 0xAA55

typedef struct {
	unsigned short msgSync;
	unsigned short Opcode;
	unsigned int msgCounter;
} Header;

typedef struct {
	Header header;
	char Ack; //This is the body message
}ControlMessage;


typedef struct {
	Header header;
	//There is no  body in data message
}DataMessage;


