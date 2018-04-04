#include "test_client.h"
#include <iostream>
#include <unistd.h>
#include <thread>

using std::cout;
using std::endl;
using std::exception;

void startTestClient(char* path, int port)
{
    TestClient client(path, port);
    client.generateCalls();
}

int main(int argc, char *argv[])
{
    char path[] = "localhost";
    int port = 50001;
    try {
		std::thread client(startTestClient, path, port);
		client.join();
    }catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
