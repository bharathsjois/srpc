#include "addressbook_service.h"
#include "srpc_utils.h"

#include <fcntl.h>
#include <stdexcept>
#include <netdb.h>
#include <netinet/in.h>

using std::logic_error;

void serverThreadCallback(AddressbookService* service, int server_sockfd)
{
	service->serverLoop(server_sockfd);
}

AddressbookService::AddressbookService(std::string host, int port)
{
    startServer(host, port);
}

AddressbookService::~AddressbookService()
{
    for(SrpcMessageHandler* handler : msgHandlers)
    {
    	delete handler;
    }
}

void AddressbookService::startServer(std::string host, int port)
{
	TRACE_INFO("Starting server on %s:%d", host.c_str(),port);
    struct sockaddr_in serv_addr;
    int server_sockfd;
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

    serverThread = new std::thread(serverThreadCallback, this, server_sockfd);
}

void AddressbookService::serverLoop(int server_sockfd)
{
	int client_len, client_socketfd;
	struct sockaddr_in client_addr;
	while(1)
	{
		listen(server_sockfd,5);
		client_len = sizeof(client_addr);
		client_socketfd = accept(server_sockfd, (struct sockaddr *) &client_addr, (socklen_t*)&client_len);
		TRACE_INFO("New client arrived");
		if (client_socketfd < 0)
		{
			throw logic_error("Error accepting client");
		}
		AddressbookServiceMsgHandler* msgHandler = new AddressbookServiceMsgHandler(client_socketfd, this);
		msgHandlers.insert(msgHandler);
		msgHandler->start();
	}
}

void AddressbookService::start(void)
{
	TRACE("Starting service...");
}

void AddressbookService::stop(void)
{
	TRACE("Stopping service...");
    for(SrpcMessageHandler* handler : msgHandlers)
    {
    	handler->stop();
    }
}

void AddressbookService::wait(void)
{
	serverThread->join();
}

void AddressbookService::onMsgHandlerDisconnected(SrpcMessageHandler* handler)
{
	TRACE("Client disconnected");
	if(msgHandlers.find(handler) != msgHandlers.end())
	{
		msgHandlers.erase(handler);
	}
}
