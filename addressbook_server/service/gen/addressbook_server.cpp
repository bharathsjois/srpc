#include "addressbook_server.h"
#include "srpc_utils.h"

AddressbookServer::AddressbookServer(std::string host, int port) : SrpcServer(host, port)
{

}

AddressbookServer::~AddressbookServer()
{
    for(SrpcMessageHandler* handler : m_MsgHandlers)
    {
    	delete handler;
    }
}

void AddressbookServer::onConnection(int clientSocket)
{
	AddressbookServerMsgHandler* handler = new AddressbookServerMsgHandler(clientSocket, this);
	m_MsgHandlers.insert(handler);
	handler->start();
}

void AddressbookServer::onDisconnection(SrpcMessageHandler* handler)
{
	if(m_MsgHandlers.find(handler) != m_MsgHandlers.end())
	{
		m_MsgHandlers.erase(handler);
	}
}
