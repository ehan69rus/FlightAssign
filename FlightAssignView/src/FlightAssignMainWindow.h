#ifndef FLIGHTASSIGNMAINWINDOW_H
#define FLIGHTASSIGNMAINWINDOW_H

#include <QMainWindow>

class FlightAssignClaimTableModel;
class FlightAssignDestinationTableModel;

namespace Ui {
class FlightAssignMainWindow;
}

//! Главное окно приложения
class FlightAssignMainWindow : public QMainWindow {
    Q_OBJECT

public:
    //! Конструктор.
    explicit FlightAssignMainWindow(QWidget *_parent = NULL);
    //! Деструктор.
    ~FlightAssignMainWindow();

private slots:
    //! Обрабатывает добавление заявки по нажатию на клавишу
    void addClaimButtonClickedSlot();
    //! Обрабатывает удаление заявки по нажатию на клавишу
    void removeClaimButtonClickedSlot();

    //! Обрабатывает изменение выбранной заявки.
    void currentClaimChangedSlot();

    //! Обрабатывает добавление пункта назначения по нажатию на клавишу
    void addDestinationButtonClickedSlot();
    //! Обрабатывает редактирование пункта назначения по нажатию на клавишу
    void editDestinationButtonClickedSlot();
    //! Обрабатывает удаление пункта назначения по нажатию на клавишу
    void removeDestinationButtonClickedSlot();

private:
    //! Подготавливает графический интерфейс к работе.
    void prepairUi();

    //! Инициализирует сигнально-слотовые соединения.
    void initConnections();

private:
    //! Графический интерфейс.
    Ui::FlightAssignMainWindow *m_ui;

    //! Модель заявок.
    FlightAssignClaimTableModel *m_claimModel;

    //! Модель пунктов назначения.
    FlightAssignDestinationTableModel *m_destinationsModel;
};

#endif // FLIGHTASSIGNMAINWINDOW_H
