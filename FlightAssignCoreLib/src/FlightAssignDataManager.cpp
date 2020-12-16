#include "FlightAssignDataManager.h"

#include "FlightAssignAirdrome.h"
#include "FlightAssignDatabaseManager.h"

FlightAssignDataManager::FlightAssignDataManager(FlightAssignDatabaseManager *_dbManager) :
    m_databaseManager(NULL), m_airdromes(QMap<long long, FlightAssignAirdrome *>()),
    m_claims(QMap<long long, FlightAssignClaim *>())
{
    if (_dbManager == NULL) {
        throw QString::fromUtf8("Ошибка при создании менеджера данных");
    }

    m_databaseManager = _dbManager;
}

FlightAssignDataManager::~FlightAssignDataManager()
{
    delete m_databaseManager;

    qDeleteAll(m_airdromes);
    m_airdromes.clear();

    qDeleteAll(m_claims);
    m_claims.clear();
}

void FlightAssignDataManager::addAirdrome(FlightAssignAirdrome *_airdrome)
{
    if (_airdrome == NULL && !m_airdromes.contains(_airdrome->id())) {
        return;
    }

    m_airdromes[_airdrome->id()] = _airdrome;
}

FlightAssignAirdrome *FlightAssignDataManager::airdrome(long long _id) const
{
    return m_airdromes.value(_id, NULL);
}

void FlightAssignDataManager::removeAirdrome(long long _id)
{
    if (!m_airdromes.contains(_id)) {
        return;
    }

    delete m_airdromes.take(_id);
}
