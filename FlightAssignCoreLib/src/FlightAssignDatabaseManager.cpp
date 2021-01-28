#include "FlightAssignDatabaseManager.h"

#include <QString>

FlightAssignDatabaseManager::FlightAssignDatabaseManager() :
    m_dataManager(NULL)
{
}

void FlightAssignDatabaseManager::setDataManager(FlightAssignDataManager *_dataManager)
{
    if (_dataManager == NULL) {
        throw QString::fromUtf8("Ошибка подключения менеджера данных");
    }

    m_dataManager = _dataManager;
}
