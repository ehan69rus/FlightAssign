#include "FlightAssignDestination.h"

#include <QString>

FlightAssignDestination::FlightAssignDestination(long long _id, FlightAssignAirdrome *_airdrome) :
   FlightAssignBaseItem(_id), m_airdrome(NULL), m_sum(0), m_information(QString()), m_number(-1)
{
    if (_airdrome == NULL) {
        throw QString::fromUtf8("Ошибка при создании пункта назначения");
    }

    m_airdrome = _airdrome;
}

const FlightAssignAirdrome *FlightAssignDestination::airdrome() const
{
    return m_airdrome;
}

void FlightAssignDestination::setAirdrome(const FlightAssignAirdrome *_airdrome)
{
    m_airdrome = _airdrome;
}

int FlightAssignDestination::sum() const
{
    return m_sum;
}

void FlightAssignDestination::setSum(int _sum)
{
    m_sum = _sum;
}

QString FlightAssignDestination::information() const
{
    return m_information;
}

void FlightAssignDestination::setInformation(const QString &_information)
{
    m_information = _information;
}

int FlightAssignDestination::number() const
{
    return m_number;
}

void FlightAssignDestination::setNumber(int number)
{
    m_number = number;
}
