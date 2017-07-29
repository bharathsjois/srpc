#ifndef SRPC_MESSAGE_H
#define SRPC_MESSAGE_H

#include "srpc_message.h"
#include <vector>
#include "srpc.pb.h"

using google::protobuf::Message;
using std::vector;
using std::unique_ptr;

namespace srpc
{
class SrpcMessage
{
public:
	SrpcMessage(int type, int mid, int rid, int nature);
    template<typename T>
    void addMessage(T& message)
    {
        messages.emplace_back(new T(message));
    }
    vector<unique_ptr<Message>>& getMessages() { return messages; }

private:
    vector<unique_ptr<Message>> messages;
};
}
#endif // SRPC_MESSAGE_H
