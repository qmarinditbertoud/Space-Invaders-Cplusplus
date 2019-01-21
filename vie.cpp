#include "Vie.h"
#include <QFont>
#include <Render.h>
#include <Objet.h>
#include <iostream>

extern Render* render;

Vie::Vie(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    vie = 10;
    //affichage legende
    setPlainText(QString("Vies: ") + QString::number(vie)); // vie: 5
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vie::diminuer(){
    vie--;
    setPlainText(QString("Vies: ") + QString::number(vie)); // Health: 2
    if (vie == 0){
        render->close(); //Quitte le jeu si on n'a plus de vie
        std::cout<<"Jeu termine";
    };
}

int Vie::getVie(){
    return vie;
}


