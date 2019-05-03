#ifndef TRAIL_H
#define TRAIL_H

#include <QObject>
#include <QGraphicsRectItem>

class Trail: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Trail(int xPosition, int yPosition);

public slots:
    void move();
};

#endif // TRAIL_H
