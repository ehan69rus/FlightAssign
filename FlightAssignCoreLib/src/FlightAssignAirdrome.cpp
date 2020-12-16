#include "FlightAssignAirdrome.h"

FlightAssignAirdrome::FlightAssignAirdrome(long long _id,
                                           const QString &_name,
                                           const QString &_index) :
    FlightAssignBaseItem(_id), m_name(_name), m_index(_index)
{
}

QString FlightAssignAirdrome::name() const
{
    return m_name;
}

void FlightAssignAirdrome::setName(const QString &_name)
{
    m_name = _name;
}

QString FlightAssignAirdrome::index() const
{
    return m_index;
}

void FlightAssignAirdrome::setIndex(const QString &_index)
{
    m_index = _index;
}
