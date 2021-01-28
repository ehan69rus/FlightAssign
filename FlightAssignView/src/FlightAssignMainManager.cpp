#include "FlightAssignMainManager.h"

#include "FlightAssignMainWindow.h"

#include <FlightAssignDataManager.h>
#include <FlightAssignDatabaseManager.h>

#include <QString>
#include <QMessageBox>

FlightAssignMainManager *FlightAssignMainManager::s_instance = NULL;

FlightAssignMainManager *FlightAssignMainManager::instance()
{
    if (s_instance == NULL) {
        s_instance = new FlightAssignMainManager();
    }

    return s_instance;
}

void FlightAssignMainManager::deleteInstance()
{
    delete s_instance;
    s_instance = NULL;
}

FlightAssignMainManager::FlightAssignMainManager() :
    m_mainWindow(NULL), m_dataManager(NULL)
{
}

FlightAssignMainManager::~FlightAssignMainManager()
{
    delete m_mainWindow;
    m_mainWindow = NULL;

    delete m_dataManager;
    m_dataManager = NULL;
}

FlightAssignDataManager *FlightAssignMainManager::dataManager() const
{
    return m_dataManager;
}

void FlightAssignMainManager::setDataManager(FlightAssignDataManager *_dataManager)
{
    m_dataManager = _dataManager;
}

void FlightAssignMainManager::init()
{
    try {
        m_dataManager = new FlightAssignDataManager(new FlightAssignDatabaseManager());

        m_mainWindow = new FlightAssignMainWindow();
        m_mainWindow->show();
    }
    catch (const QString &error) {
        QMessageBox::warning(NULL, QString::fromUtf8("Ошибка"), error);
    }
}
