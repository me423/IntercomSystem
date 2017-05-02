#ifndef _Intercom_h_
#define _Intercom_h_

#include <QWidget>
#include <QTcpSocket>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QSound>
#include <QFile>
#include <QMediaPlayer>

class QTextEdit;
class QLineEdit;

class Intercom : public QWidget {
Q_OBJECT
private:
    QTcpSocket *m_pTcpSocket;
    QTextEdit *m_ptxtInfo;
    QLineEdit *m_ptxtInput;
    quint16     m_nNextBlockSize;
    qint32 flag;
    QString pid;
    QProcess *proc = new QProcess();
    QProcess *kill	 = new QProcess();

    QPushButton* first;
    QPushButton* second;
    QPushButton* third;
    QPushButton* fourth;
    QPushButton* fifth;
    QPushButton* sixth;
    QPushButton* seventh;
    QPushButton* eighth;
    QPushButton* ninth;
    QPushButton* star;
    QPushButton* zero;
    QPushButton* resh;
    QPushButton* clear;
    QSound *opened;
    QSound *dtmf;
    QMediaPlayer *player;

public:
    Intercom(const QString& strHost, int nPort, QWidget* pwgt = 0) ;
    ~Intercom();
    QWidget *centralwidget;
    QGridLayout *gridLayout;

private slots:
    void slotReadyRead   (                            );
    void slotError       (QAbstractSocket::SocketError);
    void slotSendToServer(                            );
    void slotConnected   (                            );
    void fst             (                            );
    void snd             (                            );
    void thd             (                            );
    void fth             (                            );
    void ffth            (                            );
    void sth             (                            );
    void snth            (                            );
    void eth             (                            );
    void nth             (                            );
    void staar           (                            );
    void zeero           (                            );
    void reesh           (                            );
    void slotClear       (                            );
    void slotOpen        (                            );
};
#endif  //_Intercom_h_