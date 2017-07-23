#ifndef ADDRESSBOOK_SERVICE_IF_H
#define ADDRESSBOOK_SERVICE_IF_H

#include "addressbook.pb.h"
#include <list>

class AddressbookServiceIF
{
public:
    virtual addressbook::AddressBook getContactList() = 0;
    virtual addressbook::PhoneNumberList getNumbers(std::string name) = 0;
    virtual void addContact(addressbook::Contact contact) = 0;
    virtual void addNumber(std::string name, std::string number) = 0;
    virtual ~AddressbookServiceIF(){}
};

#endif // ADDRESSBOOK_SERVICE_IF_H
