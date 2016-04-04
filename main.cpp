#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUSSIAN");
    QApplication a(argc, argv);
    Widget w;
    w.setWindowState(Qt::WindowMaximized);



    w.show();

    return a.exec();
}
