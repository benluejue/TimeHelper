#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//不显示面板 边框
    setWindowOpacity(0.8);// 半透明效果
    resize(282,157);							//设置电子时钟显示的尺寸

    QTimer *pTimer = new QTimer(this);
    OTimer = new QTimer(this);
    // 播放音乐
    player->setMedia(QUrl::fromLocalFile("E:\\ALL_project\\TimeHelper\\TimeHelper\\Tobu-Life.mp3"));
    player->setVolume(30);

    // 设置定时间隔 用于更新时间
    pTimer->setInterval(1000);
    // 更新lcd num上的时间
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    // 定时检查 用于响 闹钟
    connect(OTimer, SIGNAL(timeout()),  this, SLOT(timeRing()));
    // 启动定时器
    pTimer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        close();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void MainWindow::onTimeOut()
{
    // 获取系统当前时间
    dateTime = QTime::currentTime();

    //ui->showT->setText(dateTime.toString("HH:mm"));

    QTime dateTime=QTime::currentTime();
    QString text=dateTime.toString("hh:mm:ss");
    if(showColon)
    {
        text[2]=':';
        text[5]=':';
        showColon=false;
    }
    else
    {
        text[2]=' ';
        text[5]=' ';
        showColon=true;
    }

    ui->lcdTime->display(text);                        //显示转换好的字符串时间

}

// 50分钟闹铃
void MainWindow::on_Bnt50_clicked()
{
    OTimer->start(500);
    QTime curTime =  QTime::currentTime();
    target = curTime.addSecs(60*50); // +60秒
    QString text = "将会在"+target.toString("HH:mm")+"提醒您";
    ui->statusbar->showMessage(text);
}
// 检测闹钟是否该开启
void MainWindow::timeRing()
{
    QTime curTime =  QTime::currentTime();
    if( target.hour() == curTime.hour() &&
            target.minute() == curTime.minute()){
        // 如果时间一致
        ui->statusbar->showMessage("时间到了");
        player->play();
        OTimer->setSingleShot(true); // 在下次定时来临前 只能响1次
    }else{
        player->stop();
    }
}

void MainWindow::on_Bnt20_clicked()
{
    OTimer->start(500);
    QTime curTime =  QTime::currentTime();
    target = curTime.addSecs(60*10); // +60秒
    QString text = "将会在"+target.toString("HH:mm")+"提醒您";
    ui->statusbar->showMessage(text);
}

// 10分钟
void MainWindow::on_Bnt10_clicked()
{
    OTimer->start(500);
    QTime curTime =  QTime::currentTime();
    target = curTime.addSecs(60*10); // +60秒
    QString text = "将会在"+target.toString("HH:mm")+"提醒您";
    ui->statusbar->showMessage(text);
}
// 停止
void MainWindow::on_BntStop_clicked()
{

    player->stop();
    OTimer->setSingleShot(false);
}
