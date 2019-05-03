#ifndef NEWTRAIL_H
#define NEWTRAIL_H

#include <QObject>
#include <QGraphicsRectItem>

class NewTrail: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    NewTrail(int xPosition, int yPosition);

public slots:
    void move();
};

#endif // NEWTRAIL_H
