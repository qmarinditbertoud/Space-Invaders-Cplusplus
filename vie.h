#ifndef VIE_H
#define VIE_H


#include <QGraphicsTextItem>

class Vie: public QGraphicsTextItem{
public:
    Vie(QGraphicsItem * parent=0);
    void diminuer();
    int getVie();
private:
    int vie;
};

#endif // VIE_H
