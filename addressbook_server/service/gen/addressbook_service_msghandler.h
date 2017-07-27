#ifndef ADDRESSBOOK_SRV_MSGHANDLER_H
#define ADDRESSBOOK_SRV_MSGHANDLER_H

#include "srpc_messagehandler.h"
#include "srpc.pb.h"

#include "addressbook_service_if.h"

using srpc::types::SrpcMessageHeader;

class AddressbookServiceMsgHandler : public SrpcMessageHandler
{
public:
    AddressbookServiceMsgHandler(int fd, AddressbookServiceIF *cb);
    void onData(SrpcMessageHeader& msgHdr);
    void onDisconnection(SrpcMessageHandler* handler);
    AddressbookServiceIF* cb;
};

#endif // ADDRESSBOOK_SRV_MSGHANDLER_H
