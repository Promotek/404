#ifndef TRAIL_REWORKED_H
#define TRAIL_REWORKEDH

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class TrailReworked:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    TrailReworked();
    QTimer * TrailTimer;
    QTimer * Controller;
public slots:
    void move();
    void TrailSpawn();
    void TrailSlot();
};


#endif // TRAIL_REWORKED_H
