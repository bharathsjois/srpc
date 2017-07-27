#include "addressbook_client_msghandler.h"
#include "addressbook.pb.h"
#include "srpc.pb.h"

#include <iostream>

using std::cerr;
using std::endl;

#define MID_ADDRESSBOOK_GET 1
#define MID_ADDRESSBOOK_GET_NUMBERS 2
#define MID_ADDRESSBOOK_ADD_PERSON 3
#define MID_ADDRESSBOOK_ADD_NUMBER 4

AddressbookClientMsgHandler::AddressbookClientMsgHandler(int fd, AddressbookClientCallbackIF* cb) : SrpcMessageHandler("AddressbookClient", fd)
{
    this->cb = cb;
}

void AddressbookClientMsgHandler::onData(SrpcMessageHeader& msgHdr)
{
    switch(msgHdr.mid()) {
		case MID_ADDRESSBOOK_GET:
		{
			addressbook::AddressBook book;
			readMessage(book);
			cb->onGetAddressbookResult(book);
			break;
		}
		case MID_ADDRESSBOOK_GET_NUMBERS:
		{
			addressbook::PhoneNumberList numbers;
			readMessage(numbers);
			cb->onGetNumbersResult(numbers);
			break;
		}
		default:
		{
			cerr<<"Unhandled method with ID: "<<msgHdr.mid()<<endl;
			break;
		}
    }
}

void AddressbookClientMsgHandler::onDisconnection(SrpcMessageHandler* handler)
{
	TRACE("Server disconnected");
	cb->onServerDisconnection();
}
