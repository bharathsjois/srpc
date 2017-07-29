#include "srpc_messagehandler.h"
#include "srpc.pb.h"

#include <unistd.h>
#include <stdexcept>
#include <exception>
#include <sys/socket.h>

using std::logic_error;
using std::exception;
using std::endl;

namespace srpc
{

void messageLoop(SrpcMessageHandler* messageHandler)
{
    messageHandler->messageLoop();
}

SrpcMessageHandler::SrpcMessageHandler(string name, int fd)
{
    this->name = name;
    this->fd = fd;
    this->messageLoopThread = nullptr;
}

void SrpcMessageHandler::traceMessage(std::string tag, Message& message)
{
	TRACE_DEBUG("From %s: %s %s", name.c_str(), tag.c_str(), message.ShortDebugString().c_str());
}

void SrpcMessageHandler::writeMessage(Message& message)
{
    size_t size = message.ByteSizeLong();
    write(fd, &size, sizeof(size));
    message.SerializeToFileDescriptor(fd);
    traceMessage("Wrote", message);
}

Message& SrpcMessageHandler::getMessage(Message& message, char* data, size_t size)
{
    bool ok = false;
    if(size) {
        if(message.ParseFromArray(data, size)) {
            ok = true;
        }
    }
    if(!ok) {
        std::string err = "Could not parse " + message.GetTypeName() + " from input data";
        throw logic_error(err);
    }
    traceMessage("Read", message);
    return message;
}

void SrpcMessageHandler::writeSrpcMessage(SrpcMessage& message)
{
    vector<unique_ptr<Message>>& messages = message.getMessages();
    for(unique_ptr<Message>& msg : messages) {
        writeMessage(*msg.get());
    }
}

Message& SrpcMessageHandler::readMessage(Message& message)
{
    size_t size = 0;
    char* data = NULL;
    read(fd, (void*)&size, sizeof(size));
    if(!size) throw logic_error("Socket has been closed");
    data = new char[size];
    read(fd, data, size);
    if(!size) throw logic_error("Socket has been closed");
    getMessage(message, data, size);
    delete[] data;
    return message;
}

void SrpcMessageHandler::messageLoop(void)
{
	TRACE_DEBUG("Starting message loop");
    while(1) {
        try {
            SrpcMessageHeader msgHdr;
            readMessage(msgHdr);
            onData(msgHdr);
        }catch(exception& e) {
            TRACE("%s", e.what());
            onDisconnection(fd);
            break;
        }
    }
    TRACE_DEBUG("Message loop ending...");
}

void SrpcMessageHandler::start()
{
    messageLoopThread = new std::thread(srpc::messageLoop, this);
}

void SrpcMessageHandler::stop()
{
	TRACE_DEBUG("%s", __func__);
    close(fd);
    messageLoopThread->join();
    delete messageLoopThread;
}

void SrpcMessageHandler::wait()
{
	messageLoopThread->join();
}

}
