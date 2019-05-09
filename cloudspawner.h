#ifndef CLOUDSPAWNER_H
#define CLOUDSPAWNER_H

#include "timerlist.h"
#include "cloud.h"

#include <QTimer>
#include <QObject>

class CloudSpawner: public QObject {
    Q_OBJECT

private:
    TimerList *allTimers;
    QTimer *timer;
    Cloud *cloud;

public:
    CloudSpawner();

public slots:
    void setCloud();
};

#endif // CLOUDSPAWNER_H
