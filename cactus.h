#ifndef CACTUS_H
#define CACTUS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Cactus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Cactus();
public slots:
    void move();
};

#endif // CACTUS_H
