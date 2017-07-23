#ifndef ADDRESSBOOK_SERVICE_H
#define ADDRESSBOOK_SERVICE_H

#include "addressbook_service_msghandler.h"
#include "addressbook_service_if.h"

class AddressbookService : public AddressbookServiceIF
{
public:
    AddressbookService(std::string host, int port);
    void startServer(std::string host, int port);
    void start(void);
    void stop(void);
    void wait(void);
    ~AddressbookService();
private:
    int fd;
    AddressbookServiceMsgHandler* msgHandler;
};

#endif // ADDRESSBOOK_SERVICE_H
