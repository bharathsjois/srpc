#ifndef ADDRESSBOOK_SRV_MSGHANDLER_H
#define ADDRESSBOOK_SRV_MSGHANDLER_H

#include "dts_messagehandler.h"
#include "dts.pb.h"

#include "addressbook_service_if.h"

using dts::types::DtsMessageHeader;

class AddressbookServiceMsgHandler : public DtsMessageHandler
{
public:
    AddressbookServiceMsgHandler(int fd, AddressbookServiceIF *cb);
    void onData(DtsMessageHeader& msgHdr);
    void onDisconnection(DtsMessageHandler* handler);
    AddressbookServiceIF* cb;
};

#endif // ADDRESSBOOK_SRV_MSGHANDLER_H
