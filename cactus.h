#ifndef CACTUS_H
#define CACTUS_H
#include <QGraphicsRectItem>
#include <QObject>

class Cactus:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Cactus();

public slots:
    void move();
    void spawn();
    void CreateCactus();
};

#endif // CACTUS_H
