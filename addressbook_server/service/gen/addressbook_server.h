#ifndef ADDRESSBOOK_SERVER_H
#define ADDRESSBOOK_SERVER_H

#include "addressbook_server_if.h"
#include "addressbook_server_msghandler.h"
#include "srpc_server.h"
#include <set>

using srpc::SrpcServer;

class AddressbookServer : public SrpcServer, public AddressbookServerIF
{
public:
    AddressbookServer(std::string host, int port);
    void onConnection(int clientSocketFd);
    void onDisconnection(SrpcMessageHandler* handler);
    ~AddressbookServer();

private:
    std::set<SrpcMessageHandler*> m_MsgHandlers;
};

#endif // ADDRESSBOOK_SERVER_H
