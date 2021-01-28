#ifndef FLIGHTASSIGNMAINMANAGER_H
#define FLIGHTASSIGNMAINMANAGER_H

class QSqlDatabase;
class FlightAssignMainWindow;
class FlightAssignDataManager;

//! Быстрый вызов менеджера данных.
#define d_dataManager FlightAssignMainManager::instance()->dataManager()

//! Главный менеджер
class FlightAssignMainManager {
public:
    //! Возвращает экземпляр класса.
    static FlightAssignMainManager *instance();

    //! Удаляет экземляр класса.
    static void deleteInstance();

    //! Запрещаем копирование.
    FlightAssignMainManager(FlightAssignMainManager &_item) = delete;
    void operator =(const FlightAssignMainManager &_item) = delete;

    //! Возвращает менеджер данных.
    FlightAssignDataManager *dataManager() const;
    //! Задает менеджер данных.
    void setDataManager(FlightAssignDataManager *_dataManager);

    //! Запускает процесс работы приложения.
    void init();

private:
    //! Конструктор.
    FlightAssignMainManager();
    //! Деструктор.
    ~FlightAssignMainManager();

private:
    //! Экземпляр класса.
    static FlightAssignMainManager *s_instance;

    //! Главное окно приложения.
    FlightAssignMainWindow *m_mainWindow;

    //! Менеджер данных.
    FlightAssignDataManager *m_dataManager;
};

#endif // FLIGHTASSIGNMAINMANAGER_H
