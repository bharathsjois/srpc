/*
 * SrpcServer.h
 *
 *  Created on: 29-Jul-2017
 *      Author: bharath
 */

#ifndef SRPCSERVER_H_
#define SRPCSERVER_H_

#include <string>
#include <thread>

class SrpcMessageHandler;

namespace srpc
{

class SrpcServer {
public:
	SrpcServer(std::string host, int port);
	virtual ~SrpcServer();

	void start();
	void serverLoop();
	void stop();
	void wait();
	virtual void onConnection(int clientSocketFd) = 0;
	virtual void onDisconnection(SrpcMessageHandler* handler) = 0;

private:
	std::string m_Host;
	int m_Port;
    std::thread* m_ServerThread;
    int m_ServerSocketFd;
};

}

#endif /* SRPCSERVER_H_ */
