TEMPLATE = lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS TRACING_ACTIVE TRACE_DETAILED

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += gen/ inc/

SOURCES += \
    gen/srpc.pb.cc \
    src/srpc_message.cpp \
    src/srpc_messagehandler.cpp \
    src/srpc_server.cpp

HEADERS += \
    gen/srpc.pb.h \
    inc/srpc_message.h \
    inc/srpc_messagehandler.h \
    inc/srpc_server.h \
    inc/srpc_utils.h

LIBS += -L/usr/local/lib -lprotobuf

DISTFILES += \
    srpc.proto
