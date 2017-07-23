#include "addressbook_service_msghandler.h"
#include "addressbook.pb.h"

#include <iostream>

using std::cout;
using std::endl;
using dts::types::DtsString;

using dts::types::DtsMessageHeader;
using dts::types::DtsMessageHeader_MessageNature;
using dts::types::DtsMessageHeader_MessageNature_SYNC;
using dts::types::DtsMessageHeader_MessageType_RESULT;


#define MID_ADDRESSBOOK_GET 1
#define MID_ADDRESSBOOK_GET_NUMBERS 2
#define MID_ADDRESSBOOK_ADD_PERSON 3
#define MID_ADDRESSBOOK_ADD_NUMBER 4

AddressbookServiceMsgHandler::AddressbookServiceMsgHandler(int fd, AddressbookServiceIF *cb) :
    DtsMessageHandler("AddressBookServer", fd)
{
    this->cb = cb;
}

void AddressbookServiceMsgHandler::onData(DtsMessageHeader &msgHdr)
{
    switch(msgHdr.mid()) {

		case MID_ADDRESSBOOK_GET:
		{
			addressbook::AddressBook addressBook = cb->getContactList();
			DtsMessage dtsMsg(DtsMessageHeader_MessageType_RESULT,
							  MID_ADDRESSBOOK_GET,
							  1,
							  DtsMessageHeader_MessageNature_SYNC);
			dtsMsg.addMessage(addressBook);
			writeDtsMessage(dtsMsg);
			break;
		}
		case MID_ADDRESSBOOK_GET_NUMBERS:
		{
			DtsMessage dtsMsg(DtsMessageHeader_MessageType_RESULT,
							  MID_ADDRESSBOOK_GET_NUMBERS,
							  1,
							  DtsMessageHeader_MessageNature_SYNC);
			DtsString name;
			readMessage(name);
			addressbook::PhoneNumberList numbers = cb->getNumbers(name.string());
			dtsMsg.addMessage(numbers);
			writeDtsMessage(dtsMsg);
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
			DtsString name, number;
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
