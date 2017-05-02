#include "Intercom.h"
#ifdef QT_STATIC
#include <QtCore/QtPlugin>
Q_IMPORT_PLUGIN(DSServicePlugin)
#endif
Intercom::Intercom(const QString& strHost, 
                   int            nPort, 
                   QWidget*       pwgt /*=0*/
                  ) : QWidget(pwgt)
                    , m_nNextBlockSize(0)
{
    flag=0;
    /*player = new QMediaPlayer(this);
    player->setMedia(QUrl("http://127.0.0.1:1234/test.mp3"));
    player->setVolume(100);
    player->play();*/
    centralwidget = new QWidget();
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    opened = new QSound("../sounds/opened.wav");
    //opened->play();
    first= new QPushButton("&1");
    second= new QPushButton("&2");
    third = new QPushButton("&3");
    fourth= new QPushButton("&4");
    fifth= new QPushButton("&5");
    sixth = new QPushButton("&6");
    seventh= new QPushButton("&7");
    eighth= new QPushButton("&8");
    ninth = new QPushButton("&9");
    star= new QPushButton("&*");
    zero= new QPushButton("&0");
    resh = new QPushButton("&◄");
    clear = new QPushButton("&C");

    m_pTcpSocket = new QTcpSocket(this);
     QFile fileIntercom("../intercom.conf"); // создаем объект класса QFile
    if(!fileRoom.open(QIODevice::ReadOnly)) {
        ui->txtInput->setText(fileRoom.errorString());
    }

    QTextStream in(&fileRoom);
     QString line;
    while(!in.atEnd()) {
        line = in.readLine();    
        QStringList fields = line.split(",");    
            
    }

    fileRoom.close();

    m_pTcpSocket->connectToHost(QUrl(line), 8082);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,         SLOT(slotError(QAbstractSocket::SocketError))
           );
    connect(first, SIGNAL(clicked()), SLOT(fst()));
    connect(second, SIGNAL(clicked()), SLOT(snd()));
    connect(third, SIGNAL(clicked()), SLOT(thd()));
    connect(fourth, SIGNAL(clicked()), SLOT(fth()));
    connect(fifth, SIGNAL(clicked()), SLOT(ffth()));
    connect(sixth, SIGNAL(clicked()), SLOT(sth()));
    connect(seventh, SIGNAL(clicked()), SLOT(snth()));
    connect(eighth, SIGNAL(clicked()), SLOT(eth()));
    connect(ninth, SIGNAL(clicked()), SLOT(nth()));
    connect(star, SIGNAL(clicked()), SLOT(staar()));
    connect(zero, SIGNAL(clicked()), SLOT(zeero()));
    connect(resh, SIGNAL(clicked()), SLOT(reesh()));
    connect(clear, SIGNAL(clicked()), SLOT(slotClear()));

    m_ptxtInfo  = new QTextEdit;
    m_ptxtInput = new QLineEdit;

    connect(m_ptxtInput, SIGNAL(returnPressed()), 
            this,        SLOT(slotSendToServer())
           );
    m_ptxtInfo->setReadOnly(true);

    QPushButton* pcmd = new QPushButton("&►");
    QPushButton *call = new QPushButton("&☏");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(call, SIGNAL(clicked()), SLOT(slotSendToServer()));
    //Layout setup
    /*QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
    pvbxLayout->addWidget(m_ptxtInfo);
    pvbxLayout->addWidget(m_ptxtInput);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);*/
    
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->addWidget(m_ptxtInput,0,0,1,4);
    m_ptxtInput->setReadOnly(true);

    gridLayout->addWidget(first,1,0,1,2);
    gridLayout->addWidget(second,1,2,1,1);
    gridLayout->addWidget(third,1,3,1,1);
    first->setFixedSize(85,25);

    gridLayout->addWidget(fourth,2,0,1,2);
    gridLayout->addWidget(fifth,2,2,1,1);
    gridLayout->addWidget(sixth,2,3,1,1);
    fourth->setFixedSize(85,25);

    gridLayout->addWidget(seventh,3,0,1,2);
    gridLayout->addWidget(eighth,3,2,1,1);
    gridLayout->addWidget(ninth,3,3,1,1);
    seventh->setFixedSize(85,25);

    gridLayout->addWidget(resh,4,0,1,1);  
    gridLayout->addWidget(clear,4,1,1,1);  
    gridLayout->addWidget(zero,4,2,1,1);
    gridLayout->addWidget(pcmd,4,3,1,1);
    resh->setFixedSize(40,25);
    clear->setFixedSize(40,25);

    gridLayout->addWidget(call,5,0,1,3);
    call->setVisible(false);



    

    setLayout(gridLayout);

}
Intercom::~Intercom(){
    kill->start("kill -9 " + pid);
}

void Intercom::slotReadyRead()
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
        if(str=="Opened"){
            opened->play();
        }
        
        if(str=="Null"){
            m_ptxtInput->setText("The room you entered does not exist!");
            proc->kill();
            break;
        }


        m_ptxtInfo->append(time.toString() + " " + str);
        m_nNextBlockSize = 0;
    }
}
void Intercom::slotError(QAbstractSocket::SocketError err)
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
    m_ptxtInfo->append(strError);
}
void Intercom::slotSendToServer()
{
    
        QByteArray  arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_2);
        out << quint16(0) << QTime::currentTime() << m_ptxtInput->text();

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        
        

        proc->start("cvlc v4l2:///dev/video0 :v4l2-standard= :input-slave=alsa://hw:0,0 :live-caching=300 :sout=\"#transcode{vcodec=WMV2,vb=800,scale=1,acodec=wma2,ab=128,channels=2,samplerate=44100}:http{dst=:8080/stream.wmv}\"");
        QFile fileAudio("../ipaudio.conf"); // создаем объект класса QFile
        if(!fileAudio.open(QIODevice::ReadOnly)) {
            //ui->txtInput->setText(file.errorString());
        }

        QTextStream in(&fileAudio);
         QString line;
        while(!in.atEnd()) {
            line = in.readLine();    
            QStringList fields = line.split(",");    
                
        }

        fileAudio.close();
        player = new QMediaPlayer(this);
        player->setMedia(QUrl(line));
        player->setVolume(100);
        player->play();
        m_pTcpSocket->write(arrBlock);
        qint64 pId= proc->processId();
        pid = QString::number(pId);
        //m_ptxtInput->setText(pid);
        QFile file("../pid.conf");
        QTextStream cout(&file);
        if(file.open(QIODevice::WriteOnly))
        {
              cout<<pId;
        }
     
        file.close();
    
}
void Intercom::slotConnected()
{
    m_ptxtInfo->append("Received the connected() signal");
}
void Intercom::slotOpen(){
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << QTime::currentTime() << "Open";

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    m_pTcpSocket->write(arrBlock);
    m_ptxtInput->setText("");
}
void Intercom::fst()
{
    dtmf = new QSound("../sounds/1.wav");
    dtmf->play();
    m_ptxtInput->setText(m_ptxtInput->text()+"1");
}

void Intercom::snd()
{
    /*player = new QMediaPlayer(this);
    player->setMedia(QUrl("http://127.0.0.1:1234/test.mp3"));
    player->setVolume(100);
    player->play();*/
    dtmf = new QSound("../sounds/2.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"2");
}
void Intercom::thd()
{
    dtmf = new QSound("../sounds/3.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"3");
}
void Intercom::fth()
{
    dtmf = new QSound("../sounds/4.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"4");
}
void Intercom::ffth()
{
    dtmf = new QSound("../sounds/5.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"5");
}
void Intercom::sth()
{
    dtmf = new QSound("../sounds/6.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"6");
}
void Intercom::snth()
{
    dtmf = new QSound("../sounds/7.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"7");
}
void Intercom::eth()
{
    dtmf = new QSound("../sounds/8.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"8");
}


void Intercom::nth()
{
    dtmf = new QSound("../sounds/9.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"9");
}
void Intercom::staar()
{
     m_ptxtInput->setText("*");
}
void Intercom::zeero()
{
    dtmf = new QSound("../sounds/0.wav");
    dtmf->play();
     m_ptxtInput->setText(m_ptxtInput->text()+"0");
}

void Intercom::reesh()
{
    QString chop = m_ptxtInput->text();
    chop.chop(1);

     m_ptxtInput->setText(chop);
}
void Intercom::slotClear()
{
  
     m_ptxtInput->clear();
}