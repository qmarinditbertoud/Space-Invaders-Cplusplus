#include "ennemis.h"
#include "Score.h"
#include "vie.h"
#include "render.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <QtGui>
#include <iostream>

#include <QPushButton>
#include <QGridLayout>



Render::Render(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/fond.png")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    /*//Create button
    quitButton = new QPushButton("Quit");
    mainLayout = new QGridLayout;
    mainLayout->addWidget(quitButton);
    QObject::connect(quitButton,SIGNAL(clicked()),this,SLOT(quitWindow()) );
    this->setLayout(mainLayout);
    this->setWindowTitle(tr("Space Invaders"));
    */

    // create the player
    player = new Objet();
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    vie = new Vie();
    vie->setPos(vie->x(),vie->y()+25);
    scene->addItem(vie);

    // spawn enemies
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}

/*void Render::quitWindow()
{
  std::cout<<"Jeu quitté"<<std::endl;
  this->close();
}
*/
