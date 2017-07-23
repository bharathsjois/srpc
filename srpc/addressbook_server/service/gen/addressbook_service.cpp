#include "addressbook_service.h"
#include "srpc_utils.h"

#include <fcntl.h>
#include <stdexcept>
#include <netdb.h>
#include <netinet/in.h>

using std::logic_error;

AddressbookService::AddressbookService(std::string host, int port)
{
    startServer(host, port);
    msgHandler = new AddressbookServiceMsgHandler(fd, this);
}

AddressbookService::~AddressbookService()
{
    delete msgHandler;
}

void AddressbookService::startServer(std::string host, int port)
{
	TRACE_INFO("Starting server on %s", host.c_str());
    struct sockaddr_in serv_addr, client_addr;
    int server_sockfd, client_len, client_socketfd;
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0)
    {
        throw logic_error("Error creating server socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(server_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
       throw logic_error("Error binding to port");
    }

    listen(server_sockfd,5);
    client_len = sizeof(client_addr);
    client_socketfd = accept(server_sockfd, (struct sockaddr *) &client_addr, (socklen_t*)&client_len);
    TRACE_INFO("New client arrived");
    if (client_socketfd < 0)
    {
        throw logic_error("Error accepting client");
    }
    fd = client_socketfd;
}

void AddressbookService::start(void)
{
	TRACE("Starting service...");
    msgHandler->start();
}

void AddressbookService::stop(void)
{
	TRACE("Stopping service...");
    msgHandler->stop();
}

void AddressbookService::wait(void)
{
	msgHandler->wait();
}
