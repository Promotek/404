#ifndef DINO_H
#define DINO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class Dino:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool jumping = false;
    int jumpprogress;
    double distance;
    int baselineY;

public:
    Dino(int baselineY);
    void keyPressEvent(QKeyEvent * event);
    void InitJump();

    QTimer * timerPointer;

public slots:
    void DoJump();

};

#endif // Dino
