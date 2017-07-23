#include "dts_message.h"

#include "dts.pb.h"

using dts::types::DtsMessageHeader;
using dts::types::DtsMessageHeader_MessageNature;
using dts::types::DtsMessageHeader_MessageType;

DtsMessage::DtsMessage(int type, int mid, int rid, int nature)
{
    DtsMessageHeader msgHdr;
    msgHdr.set_type((DtsMessageHeader_MessageType)type);
    msgHdr.set_mid(mid);
    msgHdr.set_rid(rid);
    msgHdr.set_nature((DtsMessageHeader_MessageNature)nature);
    messages.clear();
    addMessage(msgHdr);
}
