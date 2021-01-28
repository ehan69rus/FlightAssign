#include "FlightAssignClaim.h"

#include "FlightAssignTools.h"
#include "FlightAssignDestination.h"

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

int FlightAssignClaim::destinationsCount() const
{
    return m_destinationPoints.count();
}

void FlightAssignClaim::addDestination(FlightAssignDestination *_destination)
{
    if (_destination == nullptr) {
        throw ru("Ошибка при добавлении пункта назначения");
    }

    _destination->setNumber(m_destinationPoints.count() + 1);
    m_destinationPoints.append(_destination);
}

FlightAssignDestination *FlightAssignClaim::destination(int _index) const
{
    return m_destinationPoints.value(_index, nullptr);
}

void FlightAssignClaim::removeDestinationByNumber(int _index)
{
    if (destination(_index) == nullptr) {
        throw ru("Ошибка при удалении пункта назначения");
    }

    delete m_destinationPoints.takeAt(_index);
}
