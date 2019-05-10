#include "timerlist.h"

#include <QList>
#include <QTimer>

QList<QTimer *> timers;

TimerList::TimerList(){
}

void TimerList::addToList(QTimer *timer) {
    timers.append(timer);
}

QList<QTimer *> TimerList::getList() {
    return timers;
}
