
#ifndef UI_ROOM_H
#define UI_ROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtGui>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <VLCQtWidgets/WidgetSeek.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>
#include <Room.h>
#include <QSound>
QT_BEGIN_NAMESPACE

class Ui_Room
{
public:
   
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *openLocal;
    QPushButton *answer;
    QPushButton *reject;
    QPushButton *open;
    QLineEdit *txtInput;
    QTextEdit *txtInfo;
    QSound *call;
    QSound *door;
    

    VlcWidgetVideo *video;
    
    QStatusBar *statusbar;

    

    void setupUi(QMainWindow *Room)
    {
        if (Room->objectName().isEmpty())
            Room->setObjectName(QStringLiteral("Room"));
        Room->resize(640, 640);
        
        centralwidget = new QWidget(Room);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        openLocal = new QPushButton(centralwidget);
        openLocal->setObjectName(QStringLiteral("openLocal"));

        gridLayout_2->addWidget(openLocal, 0, 0, 1, 1);
        openLocal->setVisible(false);
        

        

        video = new VlcWidgetVideo(centralwidget);
        video->setObjectName(QStringLiteral("video"));

        gridLayout_2->addWidget(video, 1, 0, 1, 2);

    	txtInput = new QLineEdit;
        //m_ptxtInfo->setVisible(false);
    	gridLayout_2->addWidget(txtInput,3,0,1,2);
    	reject = new QPushButton("Reject ❌");
        reject->setFixedSize(300,45);
    	answer = new QPushButton("&Answer 🎥");
        answer->setFixedSize(300,45);
        open = new QPushButton("Open door 🔓");
        open->setFixedSize(612,45);
        txtInfo = new QTextEdit;

        gridLayout_2->addWidget(reject, 4, 1, 1, 1);
        gridLayout_2->addWidget(answer, 4, 0, 1, 1);
	    gridLayout_2->addWidget(open,5,0,1,2);
        txtInfo->setFixedSize(300,45);
        gridLayout_2->addWidget(txtInfo,6,0,1,1);


        


        Room->setCentralWidget(centralwidget);
        txtInfo->setVisible(false);
        txtInput->setVisible(false);

        

        retranslateUi(Room);
       
        QMetaObject::connectSlotsByName(Room);
    } // setupUi

    void retranslateUi(QMainWindow *Room)
    {
        Room->setWindowTitle(QApplication::translate("Room", "Room", 0));
        
        openLocal->setText(QApplication::translate("Room", "Open local file", 0));
        answer->setText(QApplication::translate("Room", "Answer 🎥", 0));;
       
    } // retranslateUi

};

namespace Ui {
    class Room: public Ui_Room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Room_H
