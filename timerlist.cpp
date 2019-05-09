#include "timerlist.h"

#include <QList>
#include <QTimer>

TimerList::TimerList(){
}

void TimerList::addToList(QTimer *timer) {
    allTimers.append(timer);
}

QList<QTimer *> TimerList::getList() {
    return allTimers;
}
