#include <QApplication>
#include "render.h"

Render * render;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    render = new Render();
    render->show();

    return a.exec();
}
