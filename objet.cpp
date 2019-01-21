#include "Objet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "missile.h"
#include "ennemis.h"
#include <QDebug>
#include <Render.h>
#include "typeinfo"


extern Render* render;

Objet::Objet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/vaisseau_allie2.png"));
}

void Objet::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x()>0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() +100 < 800)
        setPos(x()+20,y());
    }

    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Missile * missile = new Missile();
        missile->setPos(x()+45,y());//modifie poition init du missile
        scene()->addItem(missile);
    }
}

void Objet::spawn()
{
    // create an enemy
    Ennemis * ennemis = new Ennemis();
    scene()->addItem(ennemis);
}
