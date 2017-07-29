#ifndef ADDRESSBOOK_SERVER_MSGHANDLER_H
#define ADDRESSBOOK_SERVER_MSGHANDLER_H

#include "srpc_messagehandler.h"
#include "srpc.pb.h"

using srpc::SrpcMessageHandler;
using srpc::types::SrpcMessageHeader;

class AddressbookServer;

class AddressbookServerMsgHandler : public SrpcMessageHandler
{
public:
    AddressbookServerMsgHandler(int fd, AddressbookServer* cb);
    void onData(SrpcMessageHeader& msgHdr);
    void onDisconnection(int clientSocketFd);

private:
    AddressbookServer* cb;
};

#endif // ADDRESSBOOK_SERVER_MSGHANDLER_H
