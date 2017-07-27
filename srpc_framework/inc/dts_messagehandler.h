#ifndef DTS_MESSAGE_HANLDER_H
#define DTS_MESSAGE_HANLDER_H

#include "dts.pb.h"
#include "dts_message.h"
#include "srpc_utils.h"

#include <vector>
#include <thread>
#include <string>

using std::vector;
using std::string;
using std::unique_ptr;
using std::thread;
using google::protobuf::Message;
using dts::types::DtsMessageHeader;

class DtsMessageHandler
{
public:
	DtsMessageHandler(string name, int fd);
    virtual ~DtsMessageHandler(){}
    void writeMessage(Message& message);
    void writeDtsMessage(DtsMessage& message);
    Message& getMessage(Message& message, char* data, size_t size);
    Message& readMessage(Message& message);
    void start();
    void stop();
    void wait();
    virtual void onData(DtsMessageHeader& msgHdr) = 0;
    virtual void onDisconnection(DtsMessageHandler* handler) = 0;
    void messageLoop();
    template<typename T>
    void addMessage(T& message);
    void traceMessage(string tag, Message& message);

private:
    int fd;
    string name;
    std::thread* messageLoopThread;
};

#endif // DTS_MESSAGE_HANLDER_H
