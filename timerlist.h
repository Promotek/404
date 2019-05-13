#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>

class TimerList: public QObject, public QGraphicsPixmapItem{
public:
    TimerList();
    void addToList(QTimer *timer);
    QList<QTimer *> getList();
};

#endif // TEST_H
