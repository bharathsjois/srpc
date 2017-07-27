#ifndef ADDRESSBOOK_SERVICE_H
#define ADDRESSBOOK_SERVICE_H

#include "addressbook_service_msghandler.h"
#include "addressbook_service_if.h"

#include <vector>

using std::vector;

class AddressbookService : public AddressbookServiceIF
{
public:
    AddressbookService(std::string host, int port);
    void serverLoop(int server_sockfd);
    void start(void);
    void stop(void);
    void wait(void);
    void onMsgHandlerDisconnected(SrpcMessageHandler* handler);
    ~AddressbookService();
private:

    void startServer(std::string host, int port);

    int fd;
    std::set<SrpcMessageHandler*> msgHandlers;
    std::thread* serverThread;
};

#endif // ADDRESSBOOK_SERVICE_H
