#ifndef CACTUS_H
#define CACTUS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Cactus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int moveSpeed;

public:
    Cactus(int moveSpeed = 1);
public slots:
    void move();
};

#endif // CACTUS_H
