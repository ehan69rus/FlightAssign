#ifndef FLIGHTASSIGNDATAMANAGER_H
#define FLIGHTASSIGNDATAMANAGER_H

#include <QMap>

class FlightAssignClaim;
class FlightAssignAirdrome;
class FlightAssignDatabaseManager;

//! Менеджер данных
class FlightAssignDataManager {
public:
    //! Конструктор.
    FlightAssignDataManager(FlightAssignDatabaseManager *_dbManager);

    //! Деструктор.
    ~FlightAssignDataManager();

    //! Добавляет аэродром.
    void addAirdrome(FlightAssignAirdrome *_airdrome);
    //! Возвращает аэродром.
    FlightAssignAirdrome *airdrome(long long _id) const;
    //! Удаляет аэродром.
    void removeAirdrome(long long _id);


private:
    //! Менеджер базы данных.
    const FlightAssignDatabaseManager *m_databaseManager;

    //! Список аэродромов сортированный по идентификатору.
    QMap<long long, FlightAssignAirdrome *> m_airdromes;

    //! Список заявок сортированных по идентификатору.
    QMap<long long, FlightAssignClaim *> m_claims;
};

#endif // FLIGHTASSIGNDATAMANAGER_H
