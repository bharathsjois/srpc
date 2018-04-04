/*
 * SrpcServer.cpp
 *
 *  Created on: 29-Jul-2017
 *      Author: bharath
 */

#include "srpc_utils.h"

#include <fcntl.h>
#include <string.h>
#include <stdexcept>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <srpc_server.h>

using std::logic_error;

namespace srpc {

void serverThreadCallback(SrpcServer* server)
{
	server->serverLoop();
}

SrpcServer::SrpcServer(std::string host, int port)
: m_Host(host)
, m_Port(port)
, m_ServerThread(nullptr)
, m_ServerSocketFd(-1)
{

}

SrpcServer::~SrpcServer()
{
	stop();
	if(m_ServerThread != nullptr)
	{
		m_ServerThread->join();
		delete m_ServerThread;
	}
}

void SrpcServer::start()
{
	TRACE_INFO("Starting server on %s:%d", m_Host.c_str(), m_Port);
    struct sockaddr_in serv_addr;
    m_ServerSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_ServerSocketFd < 0)
    {
        throw logic_error("Error creating server socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(m_Port);

    /* Now bind the host address using bind() call.*/
    if (bind(m_ServerSocketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
       throw logic_error("Error binding to port");
    }

    m_ServerThread = new std::thread(serverThreadCallback, this);
}

void SrpcServer::stop()
{
	TRACE("Stopping server...");
	if(m_ServerSocketFd != -1)
	{
		close(m_ServerSocketFd);
		m_ServerSocketFd = -1;
	}
	if(m_ServerThread != nullptr)
	{
		m_ServerThread->join();
	}
}

void SrpcServer::wait()
{
	m_ServerThread->join();
}

void SrpcServer::serverLoop()
{
	int clientLength, clientSocketFd;
	struct sockaddr_in client_addr;
	while(1)
	{
		listen(m_ServerSocketFd,5);
		clientLength = sizeof(client_addr);
		clientSocketFd = accept(m_ServerSocketFd, (struct sockaddr *) &client_addr, (socklen_t*)&clientLength);
		TRACE_INFO("New client arrived");
		if (clientSocketFd < 0)
		{
			throw logic_error("Error accepting client");
		}
		onConnection(clientSocketFd);
	}
}
}
