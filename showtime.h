#ifndef SHOWTIME_H
#define SHOWTIME_H
#include <QTime>
#include "ui_mainwindow.h"

class showTime
{
public:
    showTime();






private slots:


private:
    Ui::MainWindow *ui;
    QTime current_time;
    int hour;        //当前的小时
    int minute;    //当前的分
    int second;    //当前的秒
    int msec;        //当前的毫秒
};



#endif // SHOWTIME_H
