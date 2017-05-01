TARGET      = Room
TEMPLATE    = app
CONFIG 	   += c++11

QT       += core gui widgets multimedia network testlib


SOURCES    += main.cpp \
    Room.cpp 

HEADERS    += Room.h \
	ui_Room.h

# Edit below for custom library location
LIBS       += -L/usr/lib/vlc -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += /usr/include/vlc
