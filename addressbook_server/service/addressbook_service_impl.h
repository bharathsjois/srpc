#ifndef ADDRESSBOOKSERVICE_H
#define ADDRESSBOOKSERVICE_H

#include "addressbook_service.h"

class AddressBookServiceImpl : public AddressbookService
{
public:
    AddressBookServiceImpl(string host, int port);
    addressbook::AddressBook getContactList();
    addressbook::PhoneNumberList getNumbers(string name);
    void addContact(addressbook::Contact contact);
    void addNumber(string name, string number);
    ~AddressBookServiceImpl();

private:
    addressbook::AddressBook addressBook;
};

#endif // ADDRESSBOOKSERVICE_H
