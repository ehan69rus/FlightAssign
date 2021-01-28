#include "FlightAssignDestinationTableModel.h"

#include <FlightAssignClaim.h>
#include <FlightAssignTools.h>
#include <FlightAssignAirdrome.h>
#include <FlightAssignDestination.h>

FlightAssignDestinationTableModel::FlightAssignDestinationTableModel(QObject *_parent) :
    QAbstractTableModel(_parent), m_claim(nullptr)
{

}

FlightAssignDestinationTableModel::~FlightAssignDestinationTableModel()
{
    m_claim = nullptr;
}

void FlightAssignDestinationTableModel::setClaim(FlightAssignClaim *_claim)
{
    m_claim = _claim;
    update();
}

void FlightAssignDestinationTableModel::update()
{
    beginResetModel();
    endResetModel();
}

int FlightAssignDestinationTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    if (m_claim == nullptr) {
        return 0;
    }

    return m_claim->destinationsCount();
}

int FlightAssignDestinationTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return ColumnCount;
}

QVariant FlightAssignDestinationTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid()) {
        return QVariant();
    }

    FlightAssignDestination *destinationItem = m_claim->destination(index.row());
    if (destinationItem == NULL) {
        return QVariant();
    }

    switch (index.column()) {
    case Number:
        return destinationItem->number();
    case Airdrome:
        return destinationItem->airdrome()->name();
    case Sum:
        return destinationItem->sum();
    case Information:
        return destinationItem->information();
    }

    return QVariant();
}

QVariant FlightAssignDestinationTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case Number:
        return ru("Номер");
    case Airdrome:
        return ru("Наименование аэродрома");
    case Sum:
        return ru("Требуемая сумма");
    case Information:
        return ru("Дополнительная информация");
    }

    return QVariant();
}
