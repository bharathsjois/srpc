#ifndef ADDRESSBOOK_CLIENT_MSGHANDLER_H
#define ADDRESSBOOK_CLIENT_MSGHANDLER_H

#include "srpc_messagehandler.h"
#include "addressbook_client_callback_if.h"

class AddressbookClientMsgHandler : public SrpcMessageHandler
{
public:
    AddressbookClientMsgHandler(int fd, AddressbookClientCallbackIF *cb);
    void onData(SrpcMessageHeader &msgHdr);
    void onDisconnection(SrpcMessageHandler* handler);
private:
    AddressbookClientCallbackIF* cb;
};

#endif // ADDRESSBOOK_CLIENT_MSGHANDLER_H
