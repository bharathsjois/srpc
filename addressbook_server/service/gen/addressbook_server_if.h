#ifndef ADDRESSBOOK_SERVER_IF_H
#define ADDRESSBOOK_SERVER_IF_H

#include "addressbook.pb.h"
#include "srpc_messagehandler.h"

class AddressbookServerIF
{
public:
    virtual addressbook::AddressBook getContactList() = 0;
    virtual addressbook::PhoneNumberList getNumbers(std::string name) = 0;
    virtual void addContact(addressbook::Contact contact) = 0;
    virtual void addNumber(std::string name, std::string number) = 0;
    virtual ~AddressbookServerIF(){}
};

#endif // ADDRESSBOOK_SERVER_IF_H
