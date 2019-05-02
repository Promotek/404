#ifndef TRAIL_H
#define TRAIL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Trail:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Trail();

public slots:
    void move();
    void spawnLine();
    void slot_create();
    void TrailCreate(int level);

};


#endif // TRAIL_H
