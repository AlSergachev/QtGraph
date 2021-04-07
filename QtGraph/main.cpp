#include "qtgraph.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtGraph w;
    w.show();
    return a.exec();
}
