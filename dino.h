#ifndef DINO_H
#define DINO_H

#include <QGraphicsRectItem>
#include <QObject>

class Dino:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawnTrail();
};

#endif // Dino
