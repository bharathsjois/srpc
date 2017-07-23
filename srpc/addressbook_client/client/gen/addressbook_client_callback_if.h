#ifndef ADDRESSBOOK_CLIENT_CALLBACK_IF_H
#define ADDRESSBOOK_CLIENT_CALLBACK_IF_H

#include "addressbook.pb.h"

#include <list>
#include <string>

using std::list;
using std::string;

class AddressbookClientCallbackIF
{
public:
    virtual void onGetAddressbookResult(addressbook::AddressBook& book) = 0;
    virtual void onGetNumbersResult(addressbook::PhoneNumberList& numbers) = 0;
    virtual ~AddressbookClientCallbackIF() {}
};

#endif // ADDRESSBOOK_CLIENT_CALLBACK_IF_H
