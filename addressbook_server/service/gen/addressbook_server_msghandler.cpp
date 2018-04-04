#include "addressbook_server_msghandler.h"
#include "addressbook_server.h"
#include "srpc_message.h"
#include "addressbook.pb.h"

#include <iostream>

using std::cout;
using std::endl;

using srpc::SrpcMessage;
using srpc::types::SrpcMessageHeader;
using srpc::types::SrpcMessageHeader_MessageNature;
using srpc::types::SrpcMessageHeader_MessageNature_SYNC;
using srpc::types::SrpcMessageHeader_MessageType_RESULT;

using google::protobuf::StringValue;

#define MID_ADDRESSBOOK_GET 1
#define MID_ADDRESSBOOK_GET_NUMBERS 2
#define MID_ADDRESSBOOK_ADD_PERSON 3
#define MID_ADDRESSBOOK_ADD_NUMBER 4

AddressbookServerMsgHandler::AddressbookServerMsgHandler(int fd, AddressbookServer *cb) :
    SrpcMessageHandler("AddressBookServer", fd)
{
    this->cb = cb;
}

void AddressbookServerMsgHandler::onData(SrpcMessageHeader &msgHdr)
{
    switch(msgHdr.mid()) {

		case MID_ADDRESSBOOK_GET:
		{
			addressbook::AddressBook addressBook = cb->getContactList();
			SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_RESULT,
							  MID_ADDRESSBOOK_GET,
							  1,
							  SrpcMessageHeader_MessageNature_SYNC);
			srpcMsg.addMessage(addressBook);
			writeSrpcMessage(srpcMsg);
			break;
		}
		case MID_ADDRESSBOOK_GET_NUMBERS:
		{
			SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_RESULT,
							  MID_ADDRESSBOOK_GET_NUMBERS,
							  1,
							  SrpcMessageHeader_MessageNature_SYNC);
			StringValue name;
			readMessage(name);
			addressbook::PhoneNumberList numbers = cb->getNumbers(name.value());
			srpcMsg.addMessage(numbers);
			writeSrpcMessage(srpcMsg);
			break;
		}
		case MID_ADDRESSBOOK_ADD_PERSON:
		{
			addressbook::Contact contact;
			readMessage(contact);
			cb->addContact(contact);
			break;
		}
		case MID_ADDRESSBOOK_ADD_NUMBER:
		{
			StringValue name, number;
			readMessage(name);
			readMessage(number);
			cb->addNumber(name.value(), number.value());
			break;
		}
		default:
		{
			cout<<"Unhandled method with ID: "<<msgHdr.mid()<<endl;
			break;
		}
    }
}

void AddressbookServerMsgHandler::onDisconnection(int clientSocketFd)
{
	cb->onDisconnection(this);
}
