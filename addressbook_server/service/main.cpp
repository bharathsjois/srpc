#include "addressbook_service_impl.h"
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;
using std::exception;

int main(int argc, char *argv[])
{
    char path[] = "localhost";
    int port = 50001;
    try {
        AddressBookServiceImpl service(path, port);
        service.start();
        service.wait();
    }catch(exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}

