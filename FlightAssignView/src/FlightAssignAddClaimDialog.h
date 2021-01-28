#ifndef FLIGHTASSIGNADDCLAIMDIALOG_H
#define FLIGHTASSIGNADDCLAIMDIALOG_H

#include <QDialog>

class FlightAssignClaim;

namespace Ui {
class FlightAssignAddClaimDialog;
}

//! Диалог добавления заявки
class FlightAssignAddClaimDialog : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор.
    explicit FlightAssignAddClaimDialog(QWidget *parent = nullptr);
    //! Деструктор.
    ~FlightAssignAddClaimDialog();

private slots:
    //! Обрабатывает сохранение по нажатию на клавишу
    void saveButtonClickedSlot();

private:
    //! Подготавливает графический интерфейс к работе.
    void prepairUi();

    //! Инициализирует сигнально-слотовые соединения.
    void initConnections();

    //! Создает обьект с формы.
    FlightAssignClaim *createClaim() const;

    //! Проверяет корректность полей.
    void checkFields() const;

private:
    //! Графический интерфейс.
    Ui::FlightAssignAddClaimDialog *m_ui;
};

#endif // FLIGHTASSIGNADDCLAIMDIALOG_H
