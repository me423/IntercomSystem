#include <QApplication>
#include <QtGui>
#include "MyServer.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MyServer     server(8082);

    server.show();

    return app.exec();
}