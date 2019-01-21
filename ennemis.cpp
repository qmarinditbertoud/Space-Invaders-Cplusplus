#include "Ennemis.h"
#include"render.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QBrush>
#include <stdlib.h>
#include <cstdlib>
#include<missile.h>
#include<missileennemis.h>
#include <ctime>
#include "Objet.h"

extern Render *render;

Ennemis::Ennemis(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    //set random position
    int random_number= rand() % 700;
    setPos(random_number,0);
    // drew the rect
    setPixmap(QPixmap(":/images/mechant.png"));
    setTransformOriginPoint(50,50);
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
    QTimer * timermissile = new QTimer();
    connect(timermissile,SIGNAL(timeout()),this,SLOT(Rocket()));

    timermissile->start(1800);
}

void Ennemis::move(){
    // move bullet up
    int random= rand()%50-rand()%50;
    if (pos().x()<20){
        setPos(20+x(),y()+5);  //Empêche la sortie des ennemis
    }
    if (pos().x()>700){
            setPos(-20+x(),y()+5);  //Empêche la sortie des événements
    }
    if (pos().x()<700 || 20<pos().x()){
        setPos(random+x(),y()+5);  //Déplacement ennemis
    }
    if (pos().y()> 500){
        //Decremente le nb de vie
        render->vie->diminuer();
        scene()->removeItem(this);
        delete this;
    }}

void Ennemis::Rocket(){
    MissileEnnemis * missileennemis = new MissileEnnemis();
    missileennemis->setPos(x(),y());//modifie position init du missile
    scene()->addItem(missileennemis);
}

void Ennemis::Collision(){

    // collision missile ennemis
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Objet)){
           //Enlève de la vie
            render->vie->diminuer();
            scene()->removeItem(this);
            delete this;
            return;
        }
}
}
