#include "addressbook_service_stub.h"
#include "dts_message.h"
#include "dts.pb.h"
#include "addressbook.pb.h"

#include <fcntl.h>
#include <stdexcept>
#include <netdb.h>
#include <netinet/in.h>

using dts::types::DtsMessageHeader_MessageNature_SYNC;
using dts::types::DtsMessageHeader_MessageType_METHOD;
using dts::types::DtsString;

using std::logic_error;
using std::endl;

AddressbookServiceStub::AddressbookServiceStub(std::string host, int port)
{
    connectToServer(host, port);
    msgHandler = new AddressbookClientMsgHandler(fd, this);
}

AddressbookServiceStub::~AddressbookServiceStub()
{
    delete msgHandler;
}

void AddressbookServiceStub::connectToServer(std::string host, int port)
{
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        throw logic_error("Cannot create socket: " + std::string(strerror(errno)));
    }

    server = gethostbyname(host.c_str());

    if (server == NULL)
    {
        throw logic_error("Cannot resolve server name");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        throw logic_error("Cannot connect to server: " + std::string(strerror(errno)));
    }
    fd = sockfd;
}

void AddressbookServiceStub::start(void)
{
    msgHandler->start();
}

void AddressbookServiceStub::stop(void)
{
    msgHandler->stop();
}

addressbook::AddressBook AddressbookServiceStub::getContactList()
{
    DtsMessage dtsMsg(DtsMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_GET, requestId++,
                      DtsMessageHeader_MessageNature_SYNC);
    msgHandler->writeDtsMessage(dtsMsg);

    return book_promise.get_future().get();
}

void AddressbookServiceStub::onGetAddressbookResult(addressbook::AddressBook& book)
{
    book_promise.set_value(book);
}

addressbook::PhoneNumberList AddressbookServiceStub::getNumbers(string name)
{
    DtsMessage dtsMsg(DtsMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_GET_NUMBERS, requestId++,
                      DtsMessageHeader_MessageNature_SYNC);
    DtsString dts_name;
    dts_name.set_string(name);
    dtsMsg.addMessage(dts_name);
    msgHandler->writeDtsMessage(dtsMsg);
    return numbers_promise.get_future().get();
}

void AddressbookServiceStub::onGetNumbersResult(addressbook::PhoneNumberList& numbers)
{
    numbers_promise.set_value(numbers);
}

void AddressbookServiceStub::addContact(addressbook::Contact contact)
{
    DtsMessage dtsMsg(DtsMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_ADD_PERSON, requestId++,
                      DtsMessageHeader_MessageNature_SYNC);
    dtsMsg.addMessage(contact);
    msgHandler->writeDtsMessage(dtsMsg);
}

void AddressbookServiceStub::addNumber(string name, string number)
{
    DtsMessage dtsMsg(DtsMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_ADD_NUMBER, requestId++,
                      DtsMessageHeader_MessageNature_SYNC);

    DtsString dts_name, dts_number;
    dts_name.set_string(name);
    dts_number.set_string(number);
    dtsMsg.addMessage(dts_name);
    dtsMsg.addMessage(dts_number);
    msgHandler->writeDtsMessage(dtsMsg);
}

void AddressbookServiceStub::onServerDisconnection(void)
{
	TRACE("Server disconnected");
}

