QT += core gui widgets multimedia network testlib
QT -= gui
QT+=widgets
QT+=network

TARGET = my_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    MyServer.cpp

HEADERS += \
    MyServer.h
