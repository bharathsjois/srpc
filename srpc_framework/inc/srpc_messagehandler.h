#ifndef SRPC_MESSAGEHANLDER_H
#define SRPC_MESSAGEHANLDER_H

#include "srpc_message.h"
#include "srpc.pb.h"
#include "srpc_utils.h"

#include <vector>
#include <thread>
#include <string>

using std::vector;
using std::string;
using std::unique_ptr;
using std::thread;
using google::protobuf::Message;
using srpc::types::SrpcMessageHeader;

namespace srpc
{
class SrpcMessageHandler
{
public:
	SrpcMessageHandler(string name, int fd);
    virtual ~SrpcMessageHandler(){}
    void writeMessage(Message& message);
    void writeSrpcMessage(SrpcMessage& message);
    Message& getMessage(Message& message, char* data, size_t size);
    Message& readMessage(Message& message);
    void start();
    void stop();
    void wait();
    virtual void onData(SrpcMessageHeader& msgHdr) = 0;
    virtual void onDisconnection(int clientSocktfd) = 0;
    void messageLoop();
    template<typename T>
    void addMessage(T& message);
    void traceMessage(string tag, Message& message);

protected:
    int fd;
private:
    string name;
    std::thread* messageLoopThread;
};
}

#endif // SRPC_MESSAGEHANLDER_H
