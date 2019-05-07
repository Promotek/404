#ifndef TRAILSPAWNER_H
#define TRAILSPAWNER_H
#include <QObject>
#include <QGraphicsScene>

class TrailSpawner: public QObject{
    Q_OBJECT
private:
    QGraphicsScene * scene;
public:
    TrailSpawner(QGraphicsScene *scene);
public slots:
    void spawnTrail();
};
#endif // TRAILSPAWNER_H
