
#ifndef ROOM_H_
#define ROOM_H_

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTcpSocket>
#include <QLabel>
#include <QSound>

namespace Ui {
    class Room;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class Room : public QMainWindow
{
    Q_OBJECT
public:
    explicit Room(QWidget *parent = 0);
    ~Room();


private slots:
    void openLocal();
    void answer();
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
    void openDoor();
    void kill();
    //void answer();
    //void reject();

private:
    Ui::Room *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
    QProcess *proc = new QProcess();
    QProcess *proc1 = new QProcess();
    QTcpSocket* m_pTcpSocket;
    QLineEdit *txtInput;
    QString pid;
    QString pid1;
    QProcess *pKill;
    QProcess *pKill1;
    QProcess *pKill2;


    
    quint16     m_nNextBlockSize;



};

#endif // ROOM_H_
