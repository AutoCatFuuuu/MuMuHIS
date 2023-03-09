#include "mainwidget.h"
#include <QApplication>

#include "databasehelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    DataBaseHelper s;
    s.init();
    return a.exec();
}

