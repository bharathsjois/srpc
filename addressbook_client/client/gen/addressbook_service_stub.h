#ifndef ADDRESSBOOK_SERVICE_STUB_H
#define ADDRESSBOOK_SERVICE_STUB_H

#include "addressbook_client_msghandler.h"
#include "addressbook_client_callback_if.h"

#include <string>
#include <future>

using std::string;
using std::future;
using std::promise;

#define MID_ADDRESSBOOK_GET 1
#define MID_ADDRESSBOOK_GET_NUMBERS 2
#define MID_ADDRESSBOOK_ADD_PERSON 3
#define MID_ADDRESSBOOK_ADD_NUMBER 4

class AddressbookServiceStub : public AddressbookClientCallbackIF
{
public:

	/*
	 * To be used by client
	 */
    AddressbookServiceStub(std::string host, int port);
    virtual ~AddressbookServiceStub();
    void connectToServer(std::string host, int port);
    void start(void);
    void stop(void);
    void onServerDisconnection(void);

    /*
     * Method stubs
     */
    addressbook::AddressBook getContactList();
    addressbook::PhoneNumberList getNumbers(std::string name);
    void addContact(addressbook::Contact c);
    void addNumber(std::string name, std::string number);

    /*
     * Sync callback methods from framework
     */
    void onGetAddressbookResult(addressbook::AddressBook& book);
    void onGetNumbersResult(addressbook::PhoneNumberList& numbers);
private:
    int requestId = 0;
    int fd;
    AddressbookClientMsgHandler* msgHandler;
    promise<addressbook::AddressBook> book_promise;
    promise<addressbook::PhoneNumberList> numbers_promise;
};

#endif // ADDRESSBOOK_SERVICE_STUB_H
