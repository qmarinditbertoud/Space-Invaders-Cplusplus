#ifndef ENNEMIS_H
#define ENNEMIS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "typeinfo"


class Ennemis: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ennemis(QGraphicsItem * parent=0);
    void Collision();
public slots:
    void move();
    void Rocket();
};

#endif // ENNEMIS_H
