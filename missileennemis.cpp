#include "missileennemis.h"
#include "ennemis.h"
#include "render.h"

#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>

extern Render *render; // there is an external global object called game

MissileEnnemis::MissileEnnemis(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    // dessin
    setPixmap(QPixmap(":/images/Meteorite.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void MissileEnnemis::move(){

    // collision missile ennemis
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Objet)){
           //Enlève de la vie

            render->vie->diminuer();
            // supprime les missiles
            scene()->removeItem(this);
            delete this;
            return;
        }
}



    // move bullet up
    setPos(x(),y()+20);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
