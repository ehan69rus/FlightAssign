#ifndef FLIGHTASSIGNTOOLS_H
#define FLIGHTASSIGNTOOLS_H

#include <QString>

#define ru QString::fromUtf8

#define NULL_ID -1

class QWidget;

//! Инструменты для разработки.
class FlightAssignTools {
public:
    //! Выводит сообщение об ошибке.
    static void showException(const QString &_error, QWidget *_parent = nullptr);

private:
    //! Конструтор.
    FlightAssignTools();
};

#endif // FLIGHTASSIGNTOOLS_H
