#include "FlightAssignDatabaseManager.h"

#include <QString>
#include <QSqlDatabase>

FlightAssignDatabaseManager::FlightAssignDatabaseManager(const QSqlDatabase &_dbConnection) :
    m_dataManager(NULL)
{
    if (!_dbConnection.isOpen()) {
        throw QString::fromUtf8("Ошибка подключения базы данных");
    }

    m_dbConnection = _dbConnection;
}

void FlightAssignDatabaseManager::setDataManager(FlightAssignDataManager *_dataManager)
{
    if (_dataManager == NULL) {
        throw QString::fromUtf8("Ошибка подключения менеджера данных");
    }

    m_dataManager = _dataManager;
}
