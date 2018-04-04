TEMPLATE = subdirs
SUBDIRS = srpc_framework addressbook_server addressbook_client
addressbook_server.depends = srpc_framework
addressbook_client.depends = srpc_framework

LIBS += libprotobuf
