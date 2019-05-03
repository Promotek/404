#ifndef TRAIL_REWORKED_H
#define TRAIL_REWORKEDH

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class TrailReworked:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    TrailReworked();

public slots:
    void move();
};


#endif // TRAIL_REWORKED_H
