#ifndef CACTUS_H
#define CACTUS_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cactus:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Cactus();
    QTimer * SpawnTimer;

public slots:
    void move();
    void spawn();
    void CreateCactus();
};

#endif // CACTUS_H
