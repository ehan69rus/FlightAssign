#ifndef FLIGHTASSIGNAIRDROME_H
#define FLIGHTASSIGNAIRDROME_H

#include "FlightAssignBaseItem.h"

#include <QString>

//! Аэродром
class FlightAssignAirdrome : public FlightAssignBaseItem
{
public:
    //! Конструктор.
    FlightAssignAirdrome(long long _id, const QString &_name, const QString &_index);

    //! Возращает наименование аэродрома.
    QString name() const;
    //! Задает наименование аэродрома.
    void setName(const QString &_name);

    //! Возвращает индекс аэродрома.
    QString index() const;
    //! Задает индекс аэродрома.
    void setIndex(const QString &_index);

private:
    //! Идентификатор.
    long long m_id;

    //! Наименование.
    QString m_name;

    //! Индекс.
    QString m_index;
};

#endif // FLIGHTASSIGNAIRDROME_H
