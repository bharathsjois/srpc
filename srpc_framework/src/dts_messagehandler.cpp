#include "dts_messagehandler.h"
#include "dts.pb.h"

#include <unistd.h>
#include <stdexcept>
#include <exception>
#include <sys/socket.h>

using std::logic_error;
using std::exception;
using std::endl;
using dts::types::DtsString;

void messageLoop(DtsMessageHandler* messageHandler)
{
    messageHandler->messageLoop();
}

DtsMessageHandler::DtsMessageHandler(string name, int fd)
{
    this->name = name;
    this->fd = fd;
    this->messageLoopThread = nullptr;
}

void DtsMessageHandler::traceMessage(std::string tag, Message& message)
{
	TRACE_DEBUG("From %s: %s %s", name.c_str(), tag.c_str(), message.ShortDebugString().c_str());
}

void DtsMessageHandler::writeMessage(Message& message)
{
    size_t size = message.ByteSizeLong();
    write(fd, &size, sizeof(size));
    message.SerializeToFileDescriptor(fd);
    traceMessage("Wrote", message);
}

Message& DtsMessageHandler::getMessage(Message& message, char* data, size_t size)
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

void DtsMessageHandler::writeDtsMessage(DtsMessage& message)
{
    vector<unique_ptr<Message>>& messages = message.getMessages();
    for(unique_ptr<Message>& msg : messages) {
        writeMessage(*msg.get());
    }
}

Message& DtsMessageHandler::readMessage(Message& message)
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

void DtsMessageHandler::messageLoop(void)
{
	TRACE_DEBUG("Starting message loop");
    while(1) {
        try {
            DtsMessageHeader msgHdr;
            readMessage(msgHdr);
            onData(msgHdr);
        }catch(exception& e) {
            TRACE("%s", e.what());
            break;
        }
    }
}

void DtsMessageHandler::start()
{
    messageLoopThread = new std::thread(::messageLoop, this);
}

void DtsMessageHandler::stop()
{
	TRACE_DEBUG("%s", __func__);
    close(fd);
    messageLoopThread->join();
    delete messageLoopThread;
}

void DtsMessageHandler::wait()
{
	messageLoopThread->join();
}
