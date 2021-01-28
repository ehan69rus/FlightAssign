#include "FlightAssignMainManager.h"
#include <QApplication>

#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int code = 0;

    try {
        FlightAssignMainManager::instance()->init();
        code = a.exec();
    }
    catch (...) {
        QMessageBox::warning(NULL, QString(), QString::fromUtf8("Произошла критическая ошибка"));
    }

    FlightAssignMainManager::deleteInstance();
    return code;
}
