#ifndef ADDRESSBOOK_CLIENT_MSGHANDLER_H
#define ADDRESSBOOK_CLIENT_MSGHANDLER_H

#include "dts_messagehandler.h"
#include "addressbook_client_callback_if.h"

class AddressbookClientMsgHandler : public DtsMessageHandler
{
public:
    AddressbookClientMsgHandler(int fd, AddressbookClientCallbackIF *cb);
    void onData(DtsMessageHeader &msgHdr);
private:
    AddressbookClientCallbackIF* cb;
};

#endif // ADDRESSBOOK_CLIENT_MSGHANDLER_H