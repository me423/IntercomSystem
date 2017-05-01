#include <QApplication>
#include "Intercom.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Intercom     intercom("localhost", 8082);

    intercom.show();

    return app.exec();
}