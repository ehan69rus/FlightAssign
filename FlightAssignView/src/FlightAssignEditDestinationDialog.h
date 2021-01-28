#ifndef FLIGHTASSIGNEDITDESTINATIONDIALOG_H
#define FLIGHTASSIGNEDITDESTINATIONDIALOG_H

#include <QDialog>

class FlightAssignDestination;

namespace Ui {
class FlightAssignEditDestinationDialog;
}

//! Диалог редактирования пункта назначения
class FlightAssignEditDestinationDialog : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор.
    explicit FlightAssignEditDestinationDialog(FlightAssignDestination *_item,
                                               QWidget *parent = nullptr);
    //! Деструктор.
    ~FlightAssignEditDestinationDialog();

private slots:
    //! Обрабатывает сохранение по нажатию на клавишу
    void saveButtonClickedSlot();

private:
    //! Подготавливает графический интерфейс к работе.
    void prepairUi();

    //! Инициализирует сигнально-слотовые соединения.
    void initConnections();

    //! Создает обьект с формы.
    FlightAssignDestination *createDestination() const;

    //! Заполняет данные на форме.
    void fillForm();

    //! Заполняет выпадающие списки.
    void initComboboxes();

private:
    //! Графический интерфейс пользователя.
    Ui::FlightAssignEditDestinationDialog *m_ui;

    //! Редактируемый обьект.
    FlightAssignDestination *m_item;
};

#endif // FLIGHTASSIGNEDITDESTINATIONDIALOG_H
