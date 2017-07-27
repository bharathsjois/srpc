#include "addressbook_service_msghandler.h"
#include "addressbook.pb.h"

#include <iostream>

using std::cout;
using std::endl;
using srpc::types::SrpcString;

using srpc::types::SrpcMessageHeader;
using srpc::types::SrpcMessageHeader_MessageNature;
using srpc::types::SrpcMessageHeader_MessageNature_SYNC;
using srpc::types::SrpcMessageHeader_MessageType_RESULT;


#define MID_ADDRESSBOOK_GET 1
#define MID_ADDRESSBOOK_GET_NUMBERS 2
#define MID_ADDRESSBOOK_ADD_PERSON 3
#define MID_ADDRESSBOOK_ADD_NUMBER 4

AddressbookServiceMsgHandler::AddressbookServiceMsgHandler(int fd, AddressbookServiceIF *cb) :
    SrpcMessageHandler("AddressBookServer", fd)
{
    this->cb = cb;
}

void AddressbookServiceMsgHandler::onData(SrpcMessageHeader &msgHdr)
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
			SrpcString name;
			readMessage(name);
			addressbook::PhoneNumberList numbers = cb->getNumbers(name.string());
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
			SrpcString name, number;
			readMessage(name);
			readMessage(number);
			cb->addNumber(name.string(), number.string());
			break;
		}
		default:
		{
			cout<<"Unhandled method with ID: "<<msgHdr.mid()<<endl;
			break;
		}
    }
}

void AddressbookServiceMsgHandler::onDisconnection(SrpcMessageHandler* handler)
{
	cb->onMsgHandlerDisconnected(this);
}
