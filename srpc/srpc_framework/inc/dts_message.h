#ifndef DTS_MESSAGE_H
#define DTS_MESSAGE_H

#include <vector>
#include "dts_message.h"
#include "dts.pb.h"

using google::protobuf::Message;
using std::vector;
using std::unique_ptr;

class DtsMessage
{
public:
    DtsMessage(int type, int mid, int rid, int nature);
    template<typename T>
    void addMessage(T& message)
    {
        messages.emplace_back(new T(message));
    }
    vector<unique_ptr<Message>>& getMessages() { return messages; }

private:
    vector<unique_ptr<Message>> messages;
};

#endif // DTS_MESSAGE_H
