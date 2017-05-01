QT       += core gui widgets multimedia network


TARGET = Intercom
TEMPLATE = app

SOURCES += main.cpp\
        Intercom.cpp

HEADERS  += Intercom.h

LIBS       += -L/usr/lib/vlc -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += /usr/include/vlc