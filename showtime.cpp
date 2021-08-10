#include "showtime.h"


showTime::showTime()
{
    current_time = QTime::currentTime();
    hour = current_time.hour();        //当前的小时
    minute = current_time.minute();    //当前的分
    second = current_time.second();    //当前的秒
    msec = current_time.msec();        //当前的毫秒
}




