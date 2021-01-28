#include "FlightAssignDataManager.h"

#include "FlightAssignTools.h"
#include "FlightAssignClaim.h"
#include "FlightAssignAirdrome.h"
#include "FlightAssignDatabaseManager.h"

FlightAssignDataManager::FlightAssignDataManager(FlightAssignDatabaseManager *_dbManager) :
    m_databaseManager(NULL), m_airdromes(QMap<long long, FlightAssignAirdrome *>()),
    m_claims(QMap<int, FlightAssignClaim *>())
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

QMap<long long, FlightAssignAirdrome *> FlightAssignDataManager::airdromes() const
{
    return m_airdromes;
}

void FlightAssignDataManager::addClaim(FlightAssignClaim *_claim)
{
    if (_claim == nullptr) {
        throw ru("Невозможно добавить пустую заявку");
    }

    if (m_claims.contains(_claim->number())) {
        throw ru("Заявка уже существует");
    }

    m_claims[_claim->number()] = _claim;
}

FlightAssignClaim *FlightAssignDataManager::claim(int _number) const
{
    return m_claims.value(_number, NULL);
}

void FlightAssignDataManager::removeClaimByIndex(int _index)
{
    FlightAssignClaim *claim = claimAt(_index);
    if (claim == nullptr) {
        throw ru("Заявка не найдена");
    }

    removeClaimByNumber(claim->number());
}

void FlightAssignDataManager::removeClaimByNumber(int _number)
{
    if (!m_claims.contains(_number)) {
        throw ru("Заявка не найдена");;
    }

    delete m_claims.take(_number);
}

int FlightAssignDataManager::claimCount() const
{
    return m_claims.count();
}

FlightAssignClaim *FlightAssignDataManager::claimAt(int _index) const
{
    return m_claims.values().value(_index, NULL);
}

void FlightAssignDataManager::loadAidromes()
{
    addAirdrome(new FlightAssignAirdrome(1, ru("Калининград (Храброво)"), "ЬМВБ"));
    addAirdrome(new FlightAssignAirdrome(2, ru("Иркутск"), "УННТ"));
    addAirdrome(new FlightAssignAirdrome(3, ru("Тикси"), "УЕСТ"));
    addAirdrome(new FlightAssignAirdrome(4, ru("Москва / Шереметьево"), "УУЕЕ"));
    addAirdrome(new FlightAssignAirdrome(5, ru("Сочи"), "УРСС"));
    addAirdrome(new FlightAssignAirdrome(6, ru("Амдерма"), "УЛДД"));
    addAirdrome(new FlightAssignAirdrome(7, ru("Санкт-Петербург (Пулково)"), "УЛЛИ"));
    addAirdrome(new FlightAssignAirdrome(8, ru("Томск (Богашёво) "), "УНТТ"));
    addAirdrome(new FlightAssignAirdrome(9, ru("Тверь (Мигалово) "), "УУЕМ"));
    addAirdrome(new FlightAssignAirdrome(10, ru("Чкаловский"), "УУМУ"));
}
