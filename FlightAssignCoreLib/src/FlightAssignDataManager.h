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

    //! Возращает аэродромы.
    QMap<long long, FlightAssignAirdrome *> airdromes() const;

    //! Добавляет заявку.
    void addClaim(FlightAssignClaim *_claim);
    //! Возвращает заявку.
    FlightAssignClaim *claim(int _number) const;
    //! Удаляет заявку.
    void removeClaimByNumber(int _number);
    //! Удаляет заявку по индексу.
    void removeClaimByIndex(int _index);
    //! Возвращает количество заявок.
    int claimCount() const;
    //! Возвращает заявку по индексу.
    FlightAssignClaim *claimAt(int _index) const;

    //! Загружает аэродромы.
    void loadAidromes();

private:
    //! Менеджер базы данных.
    const FlightAssignDatabaseManager *m_databaseManager;

    //! Список аэродромов сортированный по идентификатору.
    QMap<long long, FlightAssignAirdrome *> m_airdromes;

    //! Список заявок сортированных по номеру.
    QMap<int, FlightAssignClaim *> m_claims;
};

#endif // FLIGHTASSIGNDATAMANAGER_H
