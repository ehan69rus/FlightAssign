#ifndef FLIGHTASSIGNDATABASEMANAGER_H
#define FLIGHTASSIGNDATABASEMANAGER_H

#include <QSqlDatabase>

class QSqlDatabase;
class FlightAssignDataManager;

//! Менеджер базы данных.
class FlightAssignDatabaseManager {
public:
    //! Конструктор.
    FlightAssignDatabaseManager(const QSqlDatabase &_dbConnection);

    //! Задает менеджер данных.
    void setDataManager(FlightAssignDataManager *_dataManager);

private:
    //! Подключение к БД.
    QSqlDatabase m_dbConnection;

    //! Менеджер данных.
    FlightAssignDataManager *m_dataManager;
};

#endif // FLIGHTASSIGNDATABASEMANAGER_H
