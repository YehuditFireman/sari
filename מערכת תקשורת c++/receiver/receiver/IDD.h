#pragma once
#define DATA_MSG_OPCODE 0xD001 
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


