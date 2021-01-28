#include "FlightAssignTools.h"

#include <QMessageBox>

FlightAssignTools::FlightAssignTools()
{
}

void FlightAssignTools::showException(const QString &_error, QWidget *_parent)
{
    QMessageBox::warning(_parent, ru("Ошибка"), _error);
}
