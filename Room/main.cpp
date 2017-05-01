#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>

#include <VLCQtCore/Common.h>

#include "Room.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt Room");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);

    QApplication app(argc, argv);
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");

    Room mainWindow;
    mainWindow.show();

    return app.exec();
}
