#include "addressbook_service_impl.h"

AddressBookServiceImpl::AddressBookServiceImpl(std::string host, int port) : AddressbookService(host, port)
{
}

AddressBookServiceImpl::~AddressBookServiceImpl()
{
}

addressbook::AddressBook AddressBookServiceImpl::getContactList()
{
    return addressBook;
}

addressbook::PhoneNumberList AddressBookServiceImpl::getNumbers(string name)
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

void AddressBookServiceImpl::addContact(addressbook::Contact contact)
{
    addressBook.add_contactlist()->CopyFrom(contact);
}

void AddressBookServiceImpl::addNumber(string name, string number)
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

