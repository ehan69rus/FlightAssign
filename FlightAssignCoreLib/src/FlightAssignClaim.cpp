#include "FlightAssignClaim.h"

FlightAssignClaim::FlightAssignClaim(long long _id, const QString &_name, int _number) :
    FlightAssignBaseItem(_id), m_name(_name), m_number(_number),
    m_destinationPoints(QList<FlightAssignDestination *>())
{

}

FlightAssignClaim::~FlightAssignClaim()
{
    qDeleteAll(m_destinationPoints);
    m_destinationPoints.clear();
}

QString FlightAssignClaim::name() const
{
    return m_name;
}

void FlightAssignClaim::setName(const QString &_name)
{
    m_name = _name;
}

int FlightAssignClaim::number() const
{
    return m_number;
}

void FlightAssignClaim::setNumber(int _number)
{
    m_number = _number;
}

QString FlightAssignClaim::information() const
{
    return m_information;
}

void FlightAssignClaim::setInformation(const QString &_information)
{
    m_information = _information;
}
