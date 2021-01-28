#ifndef FLIGHTASSIGNCLAIM_H
#define FLIGHTASSIGNCLAIM_H

#include "FlightAssignBaseItem.h"

#include <QList>
#include <QString>

class FlightAssignDestination;

//! Заявка
class FlightAssignClaim : public FlightAssignBaseItem {
public:
    //! Конструктор.
    FlightAssignClaim(long long _id, const QString &_name, int _number);

    //! Деструктор.
    ~FlightAssignClaim();

    //! Возращает наименование аэродрома.
    QString name() const;
    //! Задает наименование аэродрома.
    void setName(const QString &_name);

    //! Возращает номер.
    int number() const;
    //! Задает номер.
    void setNumber(int _number);

    //! Возвращает дополнительную информацию.
    QString information() const;
    //! Задает дополнительную информацию.
    void setInformation(const QString &_information);

    //! Возвращает количество пунктов назначения.
    int destinationsCount() const;
    //! Добавляет заявку.
    void addDestination(FlightAssignDestination *_destination);
    //! Возвращает заявку.
    FlightAssignDestination *destination(int _index) const;
    //! Удаляет заявку.
    void removeDestinationByNumber(int _index);

private:
    //! Наименование.
    QString m_name;

    //! Номер.
    int m_number;

    //! Дополнительная информация.
    QString m_information;

    //! Список пунктов назначения.
    QList<FlightAssignDestination *> m_destinationPoints;
};

#endif // FLIGHTASSIGNCLAIM_H
