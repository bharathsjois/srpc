QT -= gui core

CONFIG += console c++11
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../gen/ client/gen/ ../srpc_framework/inc ../srpc_framework/gen/

SOURCES += \
    ../gen/addressbook.pb.cc \
    client/test_client.cpp \
    client/main.cpp \
    client/gen/addressbook_client_msghandler.cpp \
    client/gen/addressbook_service_stub.cpp

HEADERS += \
    ../gen/addressbook.pb.h \
    client/gen/addressbook_client_callback_if.h \
    client/gen/addressbook_client_msghandler.h \
    client/gen/addressbook_service_stub.h

LIBS += -L/usr/local/lib/ -lprotobuf -L/home/bharath/srpc/build-srpc-Desktop-Debug/srpc_framework/ -lsrpc_framework
