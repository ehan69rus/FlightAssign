#ifndef FLIGHTASSIGNDESTINATIONTABLEMODEL_H
#define FLIGHTASSIGNDESTINATIONTABLEMODEL_H

#include <QAbstractTableModel>

class FlightAssignClaim;

//! Модель представления пунктов назначения
class FlightAssignDestinationTableModel : public QAbstractTableModel
{

public:
    //! Конструктор.
    FlightAssignDestinationTableModel(QObject *_parent = nullptr);

    //! Деструктор.
    ~FlightAssignDestinationTableModel();

    //! Задает заявку для отображения.
    void setClaim(FlightAssignClaim *_claim);

    //! Обновляет содержимое модели.
    void update();

private:
    //! Возвращает количество строк.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    //! Возвращает количество столбцов.
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //! Возвращает данные.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    //! Возвращает название столбца.
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

private:
    //! Столбцы таблицы
    enum TableColumn {
        Number,     //!< Номер
        Airdrome,   //!< Аэродром
        Sum,        //!< Сумма
        Information,//!< Информация

        ColumnCount //!< Количество столбцов
    };

    //! Заявка для отображения пунктов назначения.
    FlightAssignClaim *m_claim;
};

#endif // FLIGHTASSIGNDESTINATIONTABLEMODEL_H
