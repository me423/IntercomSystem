#include <QFileDialog>
#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <QTest>


#include "Room.h"
#include "ui_Room.h"

Room::Room(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Room),
      _media(0)
      
     
{
    ui->setupUi(this);
    proc->start("ffserver -f ../ffserver_audio.conf");
    proc1->start("ffmpeg -f alsa -i default http://localhost:1234/feed1.ffm");
    qint64 pId= proc->processId();
    pid = QString::number(pId);
    qint64 pId1= proc1->processId();
    pid1 = QString::number(pId1);
    
    ui->call = new QSound("door.wav");
    ui->door = new QSound("door.wav");
    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    ui->video->setMediaPlayer(_player);

    connect(ui->openLocal, &QPushButton::clicked, this, &Room::openLocal);
    connect(ui->answer, &QPushButton::clicked, this, &Room::answer);
    //connect(ui->reject, &QPushButton::clicked, _player, &VlcMediaPlayer::stop, SIGNAL(clicked()), SLOT(kill()));
    
    m_nNextBlockSize = 0;
    m_pTcpSocket = new QTcpSocket(this);

    m_pTcpSocket->connectToHost("localhost", 8082);
    
 
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,         SLOT(slotError(QAbstractSocket::SocketError))
           );

  	
    connect(ui->txtInput, SIGNAL(returnPressed()), 
            this,        SLOT(slotSendToServer())
           );
    //m_ptxtInfo->setReadOnly(true);

    QPushButton* pcmd = new QPushButton("&Send");
    connect(ui->open, SIGNAL(clicked()), SLOT(openDoor()));
    connect(ui->reject, SIGNAL(clicked()), SLOT(kill()));
    
    //ui->txtInput->setText(aa);
    

}

Room::~Room()
{
    delete _player;
    delete _media;
    delete _instance;
    delete proc;
    delete pKill;
    delete pKill1;
    delete pKill2;
    delete ui;
}
void Room::kill(){
    
    /*QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
        return; // если это сделать невозможно, то завершаем функцию
    data = file.readAll();
    std::string message(data.constData(), data.length());
    QString qmessage = QString::fromStdString(message);*/
    //QString pId =  QString(&data);//QTextCodec::codecForMib(106)->toUnicode(data);
    //
    //qint32 pid;
    //data>>pid;
    QFile file("../pid.conf"); // создаем объект класса QFile
    if(!file.open(QIODevice::ReadOnly)) {
        ui->txtInput->setText(file.errorString());
    }

    QTextStream in(&file);
     QString line;
    while(!in.atEnd()) {
        line = in.readLine();    
        QStringList fields = line.split(",");    
            
    }

    file.close();
    ui->txtInput->setText(line);
    _player->stop();

    QProcess *pKill = new QProcess();
    pKill->start("kill -9 "+ line );
    QProcess *pKill1 = new QProcess();
    pKill1->start("kill -9 "+pid);
    QProcess *pKill2 = new QProcess();
    pKill2->start("kill -9 "+ pid1 );
}

void Room::openLocal()
{

    QString file =
            QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    _media = new VlcMedia(file, true, _instance);

    _player->open(_media);
}

void Room::answer()
{
    /*QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;*/
    
    ui->call->stop();
    _media = new VlcMedia("http://localhost:8080/stream.wmv", _instance);

    _player->open(_media);
    
    

    //QTest::qSleep (6000);
    
    
}
void Room::openDoor()
{
    QFile file("../pid.conf"); // создаем объект класса QFile
    if(!file.open(QIODevice::ReadOnly)) {
        ui->txtInput->setText(file.errorString());
    }

    QTextStream in(&file);
     QString line;
    while(!in.atEnd()) {
        line = in.readLine();    
        QStringList fields = line.split(",");    
            
    }

    file.close();
    ui->txtInput->setText(line);
    _player->stop();

    QProcess *pKill = new QProcess();
    pKill->start("kill -9 "+ line );
    QProcess *pKill1 = new QProcess();
    pKill1->start("kill -9 "+pid);
    QProcess *pKill2 = new QProcess();
    pKill2->start("kill -9 "+ pid1 );
    ui->txtInput->setText("Opened");
    ui->txtInput->setText(line);
    _player->stop();
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << QTime::currentTime() << ui->txtInput->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    
   

    m_pTcpSocket->write(arrBlock);
    ui->txtInput->setText("");
}

void Room::slotSendToServer()
{

        QByteArray  arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_2);
        out << quint16(0) << QTime::currentTime() << ui->txtInput->text();

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));

        m_pTcpSocket->write(arrBlock);
        ui->txtInput->setText("");


}
void Room::slotReadyRead()
{
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {

                break;
            }
            in >> m_nNextBlockSize;

        }

        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) {

            break;
        }
        QTime   time;
        QString str;
        in >> time >> str;

        ui->txtInput->setText(str);
        if(str == "Call"){
            ui->call->play();
        }
        if(str=="Door"){
            ui->door->play();
        }
        m_nNextBlockSize = 0;
    }
}

void Room::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(m_pTcpSocket->errorString())
                    );
    ui->txtInput->setText(strError);
}



void Room::slotConnected()
{
    ui->txtInput->setText("Received the connected() signal");   
}

