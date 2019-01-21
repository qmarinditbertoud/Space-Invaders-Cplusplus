#ifndef OBJET_H
#define OBJET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Objet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Objet(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();

};
#endif // OBJET_H
