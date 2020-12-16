#include "FlightAssignMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlightAssignMainWindow w;
    w.show();

    return a.exec();
}
