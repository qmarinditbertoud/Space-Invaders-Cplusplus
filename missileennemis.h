#ifndef MISSILEENNEMIS_H
#define MISSILEENNEMIS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class MissileEnnemis: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MissileEnnemis(QGraphicsItem *parent=0);
public slots:
    void move();
};
#endif // MISSILEENNEMIS_H


