#include "FlightAssignClaimTableModel.h"

#include "FlightAssignMainManager.h"

#include <FlightAssignTools.h>
#include <FlightAssignClaim.h>
#include <FlightAssignDataManager.h>

FlightAssignClaimTableModel::FlightAssignClaimTableModel(QObject *_parent) :
    QAbstractTableModel(_parent)
{
}

int FlightAssignClaimTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    return d_dataManager->claimCount();
}

int FlightAssignClaimTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return ColumnCount;
}

QVariant FlightAssignClaimTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid()) {
        return QVariant();
    }

    FlightAssignClaim *claim = d_dataManager->claimAt(index.row());
    if (claim == NULL) {
        return QVariant();
    }

    switch (index.column()) {
    case Number:
        return claim->number();
    case Name:
        return claim->name();
    }

    return QVariant();
}

QVariant FlightAssignClaimTableModel::headerData(int section,
                                                 Qt::Orientation orientation,
                                                 int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case Number:
        return ru("Номер");
    case Name:
        return ru("Наименование");
    }

    return QVariant();
}

void FlightAssignClaimTableModel::update()
{
    beginResetModel();
    endResetModel();
}
