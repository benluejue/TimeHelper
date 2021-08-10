#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QMediaPlayer>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);        // 鼠标 右键关闭
    void mouseMoveEvent(QMouseEvent *);         // 点着鼠标左键移动

private slots:
    void onTimeOut();
    void on_Bnt50_clicked();
    void timeRing();
    void on_BntStop_clicked();
    void on_Bnt20_clicked();
    void on_Bnt10_clicked();


private:
    Ui::MainWindow *ui;
    // 获取系统当前时间
    QTime dateTime = QTime::currentTime();
    // 目标定时的时间
    QTime target;
    // 闪烁效果 显示 ”：“
    bool showColon;
    // 播放音乐
    QMediaPlayer *player = new QMediaPlayer;
    QPoint dragPosition;        //保存鼠标点相对电子时钟窗体左上角的偏移值
    QTimer *OTimer;
};
#endif // MAINWINDOW_H
