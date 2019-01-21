#ifndef RENDER_H
#define RENDER_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Objet.h"
#include "Score.h"
#include "vie.h"

//class QPushButton;
//class QGridLayout;
class Render: public QGraphicsView{
public:
    Render(QWidget * parent=nullptr);

    QGraphicsScene * scene;
    Objet * player;
    Score * score;
    Vie * vie;
/*private slots :
    void quitWindow();
private :
    QPushButton *quitButton;
    QGridLayout *mainLayout;*/
};


#endif // RENDER_H
