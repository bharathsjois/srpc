#include "srpc_message.h"
#include "srpc.pb.h"

using srpc::types::SrpcMessageHeader;
using srpc::types::SrpcMessageHeader_MessageNature;
using srpc::types::SrpcMessageHeader_MessageType;

namespace srpc
{

SrpcMessage::SrpcMessage(int type, int mid, int rid, int nature)
{
    SrpcMessageHeader msgHdr;
    msgHdr.set_type((SrpcMessageHeader_MessageType)type);
    msgHdr.set_mid(mid);
    msgHdr.set_rid(rid);
    msgHdr.set_nature((SrpcMessageHeader_MessageNature)nature);
    messages.clear();
    addMessage(msgHdr);
}
}
