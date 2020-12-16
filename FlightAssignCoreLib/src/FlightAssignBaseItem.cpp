#include "FlightAssignBaseItem.h"

FlightAssignBaseItem::FlightAssignBaseItem(long long _id) :
    m_id(_id)
{
}

long long FlightAssignBaseItem::id() const
{
    return m_id;
}

void FlightAssignBaseItem::setId(long long _id)
{
    m_id = _id;
}
