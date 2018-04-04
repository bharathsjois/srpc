#include "addressbook_server_impl.h"

AddressBookServerImpl::AddressBookServerImpl(std::string host, int port) : AddressbookServer(host, port)
{
}

AddressBookServerImpl::~AddressBookServerImpl()
{
	stop();
}

addressbook::AddressBook AddressBookServerImpl::getContactList()
{
    return addressBook;
}

addressbook::PhoneNumberList AddressBookServerImpl::getNumbers(string name)
{
	int n = addressBook.contactlist_size();
	for(int i = 0; i < n; ++i)
	{
		if(addressBook.contactlist(i).name() == name)
		{
			return addressBook.contactlist(i).numbers();
		}
	}
    name = "Person " + name + "not found";
    throw std::out_of_range(name);
}

void AddressBookServerImpl::addContact(addressbook::Contact contact)
{
    addressBook.add_contactlist()->CopyFrom(contact);
}

void AddressBookServerImpl::addNumber(string name, string number)
{
	int n = addressBook.contactlist_size();
	for(int i = 0; i < n; ++i)
	{
		if(addressBook.contactlist(i).name() == name)
		{
			addressBook.mutable_contactlist(i)->mutable_numbers()->add_numbers()->set_number(number);
		}
	}
}

