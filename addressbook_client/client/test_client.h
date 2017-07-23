#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H

#include "addressbook_service_stub.h"

class TestClient
{
public:
    TestClient(char *path, int port);
    void testLoop(int num_calls);
    void generateCalls(void);
    addressbook::Contact& generateContact(addressbook::Contact& c);
    void generatePhoneBook(int req_persons, addressbook::AddressBook& book);
private:
    AddressbookServiceStub stub;
};

#endif // TEST_CLIENT_H
