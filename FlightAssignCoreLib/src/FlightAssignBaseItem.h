#ifndef FLIGHTASSIGNBASEITEM_H
#define FLIGHTASSIGNBASEITEM_H

//! Базовый класс
class FlightAssignBaseItem {
public:
    //! Конструктор.
    FlightAssignBaseItem(long long _id);

    //! Возвращает идентификатор аэродрома.
    long long id() const;
    //! Задает идентификатор аэродрома.
    void setId(long long _id);

private:
    //! Идентификатор.
    long long m_id;
};

#endif // FLIGHTASSIGNBASEITEM_H
