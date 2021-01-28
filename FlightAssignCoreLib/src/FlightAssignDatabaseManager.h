#ifndef FLIGHTASSIGNDATABASEMANAGER_H
#define FLIGHTASSIGNDATABASEMANAGER_H

class FlightAssignDataManager;

//! Менеджер базы данных.
class FlightAssignDatabaseManager {
public:
    //! Конструктор.
    FlightAssignDatabaseManager();

    //! Задает менеджер данных.
    void setDataManager(FlightAssignDataManager *_dataManager);

private:
    //! Менеджер данных.
    FlightAssignDataManager *m_dataManager;
};

#endif // FLIGHTASSIGNDATABASEMANAGER_H
