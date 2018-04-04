#ifndef ADDRESSBOOK_CLIENT_MSGHANDLER_H
#define ADDRESSBOOK_CLIENT_MSGHANDLER_H

#include "srpc_messagehandler.h"
#include "addressbook_client_callback_if.h"

using srpc::SrpcMessageHandler;

class AddressbookClientMsgHandler : public SrpcMessageHandler
{
public:
    AddressbookClientMsgHandler(int fd, AddressbookClientCallbackIF *cb);
    void onData(SrpcMessageHeader &msgHdr);
    void onDisconnection(int clientSocketFd);
private:
    AddressbookClientCallbackIF* cb;
};

#endif // ADDRESSBOOK_CLIENT_MSGHANDLER_H
