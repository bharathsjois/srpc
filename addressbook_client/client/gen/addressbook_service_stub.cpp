#include "srpc_message.h"
#include "addressbook_service_stub.h"
#include "srpc.pb.h"
#include "addressbook.pb.h"

#include <fcntl.h>
#include <stdexcept>
#include <netdb.h>
#include <netinet/in.h>

using srpc::types::SrpcMessageHeader_MessageNature_SYNC;
using srpc::types::SrpcMessageHeader_MessageType_METHOD;
using srpc::types::SrpcString;

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
    SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_GET, requestId++,
                      SrpcMessageHeader_MessageNature_SYNC);
    msgHandler->writeSrpcMessage(srpcMsg);

    return book_promise.get_future().get();
}

void AddressbookServiceStub::onGetAddressbookResult(addressbook::AddressBook& book)
{
    book_promise.set_value(book);
}

addressbook::PhoneNumberList AddressbookServiceStub::getNumbers(string name)
{
    SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_GET_NUMBERS, requestId++,
                      SrpcMessageHeader_MessageNature_SYNC);
    SrpcString srpc_name;
    srpc_name.set_string(name);
    srpcMsg.addMessage(srpc_name);
    msgHandler->writeSrpcMessage(srpcMsg);
    return numbers_promise.get_future().get();
}

void AddressbookServiceStub::onGetNumbersResult(addressbook::PhoneNumberList& numbers)
{
    numbers_promise.set_value(numbers);
}

void AddressbookServiceStub::addContact(addressbook::Contact contact)
{
    SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_ADD_PERSON, requestId++,
                      SrpcMessageHeader_MessageNature_SYNC);
    srpcMsg.addMessage(contact);
    msgHandler->writeSrpcMessage(srpcMsg);
}

void AddressbookServiceStub::addNumber(string name, string number)
{
    SrpcMessage srpcMsg(SrpcMessageHeader_MessageType_METHOD,
                      MID_ADDRESSBOOK_ADD_NUMBER, requestId++,
                      SrpcMessageHeader_MessageNature_SYNC);

    SrpcString srpc_name, srpc_number;
    srpc_name.set_string(name);
    srpc_number.set_string(number);
    srpcMsg.addMessage(srpc_name);
    srpcMsg.addMessage(srpc_number);
    msgHandler->writeSrpcMessage(srpcMsg);
}

void AddressbookServiceStub::onServerDisconnection(void)
{
	TRACE("Server disconnected");
}

