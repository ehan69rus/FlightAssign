#ifndef FLIGHTASSIGNDESTINATION_H
#define FLIGHTASSIGNDESTINATION_H

#include "FlightAssignBaseItem.h"

#include <QString>

class FlightAssignAirdrome;

//! Пункт назначения
class FlightAssignDestination : public FlightAssignBaseItem {
public:
    //! Конструктор.
    FlightAssignDestination(long long _id, FlightAssignAirdrome *_airdrome);

    //! Возвращает аэродром.
    const FlightAssignAirdrome *airdrome() const;
    //! Задает аэродром.
    void setAirdrome(const FlightAssignAirdrome *_airdrome);

    //! Возвращает сумму.
    int sum() const;
    //! Задает сумму.
    void setSum(int _sum);

    //! Возвращает дополнительную информацию.
    QString information() const;
    //! Задает дополнительную информацию.
    void setInformation(const QString &_information);

    //! Возращает номер.
    int number() const;
    //! Задает номер.
    void setNumber(int _number);

private:
    //! Идентификатор.
    long long m_id;

    //! Аэродром.
    const FlightAssignAirdrome *m_airdrome;

    //! Требуемая сумма.
    int m_sum;

    //! Дополнительная информация.
    QString m_information;

    //! Порядковый номер
    int m_number;
};

#endif // FLIGHTASSIGNDESTINATION_H
