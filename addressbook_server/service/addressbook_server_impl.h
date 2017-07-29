#ifndef ADDRESSBOOK_SERVER_IMPL_H
#define ADDRESSBOOK_SERVER_IMPL_H

#include "addressbook_server.h"

class AddressBookServerImpl : public AddressbookServer
{
public:
    AddressBookServerImpl(string host, int port);
    addressbook::AddressBook getContactList();
    addressbook::PhoneNumberList getNumbers(string name);
    void addContact(addressbook::Contact contact);
    void addNumber(string name, string number);
    ~AddressBookServerImpl();

private:
    addressbook::AddressBook addressBook;
};

#endif // ADDRESSBOOK_SERVER_IMPL_H
