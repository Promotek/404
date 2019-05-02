#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsRectItem>
#include <QLabel>



class Scoreboard :public QObject
{
    Q_OBJECT
private:
    int points;
    QTimer * timerPointer;
    QGraphicsTextItem * textItem;
    int ticker;
public:
    int PointsByTick;
    void Start();
    Scoreboard();
    QGraphicsTextItem *GetTextItem();

public slots:
    void DoTick();

};

#endif // SCOREBOARD_H
