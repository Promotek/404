#ifndef CACTUS_H
#define H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Cactus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Cactus();
public slots:
    void move();
};

#endif // CACTUS_H
