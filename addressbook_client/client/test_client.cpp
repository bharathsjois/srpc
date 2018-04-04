#include "test_client.h"
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using std::cout;
using std::endl;

TestClient::TestClient(char* path, int port) : stub(path, port)
{
    stub.start();
}

addressbook::Contact& TestClient::generateContact(addressbook::Contact& c)
{
    int id = rand() % 10 + 1;
    c.set_name("Person-" + std::to_string(id));
    int num_phones = rand() % 3 + 1;
    for(int j = 0; j < num_phones; ++j) {
        c.mutable_numbers()->add_numbers()->set_number("Number-" + std::to_string(id));
    }
    return c;
}

void TestClient::generatePhoneBook(int req_persons, addressbook::AddressBook& book) {
    for(int i = 0; i < req_persons; ++i) {
        addressbook::Contact c;
        generateContact(c);
        book.mutable_contactlist()->Add()->CopyFrom(c);
    }
}

void TestClient::generateCalls(void)
{
    addressbook::Contact c;
    generateContact(c);
    c.set_name("bsr5kor");
    cout<<"Adding contact..."<<endl;
    stub.addContact(c);
    cout<<"Adding another number..."<<endl;
    stub.addNumber(c.name(), "Another number");
    sleep(2);
    cout<<"Adding another number..."<<endl;
    stub.addNumber(c.name(), "Yet another number");
    sleep(2);
    cout<<"Getting contact list..."<<endl;
    std::cout<<stub.getContactList().ShortDebugString()<<endl;
    cout<<"Getting numbers for bsr5kor..."<<endl;
    addressbook::PhoneNumberList numbers = stub.getNumbers("bsr5kor");
    for(int i = 0; i < numbers.numbers_size(); ++i)
    {
    	cout<<numbers.numbers(i).ShortDebugString()<<endl;
    }
    cout<<"All done!"<<endl;
}
