#include "missile.h"
#include "ennemis.h"
#include "render.h"

#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>

extern Render *render; // there is an external global object called game

Missile::Missile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // dessin
    setPixmap(QPixmap(":/images/missile.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Missile::move(){

    // collision missile ennemis
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Ennemis)){
           //incremente de le score

            render->score->augmenter();
            // supprime les missiles
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
}



    // move bullet up
    setPos(x(),y()-20);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
