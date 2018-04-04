#include <iostream>
#include "addressbook_server_impl.h"

using std::cout;
using std::endl;
using std::exception;

int main(int argc, char *argv[])
{
    char path[] = "localhost";
    int port = 50001;
    try {
        AddressBookServerImpl server(path, port);
        server.start();
        server.wait();
    }catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
