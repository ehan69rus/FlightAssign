#ifndef FLIGHTASSIGNCLAIMTABLEMODEL_H
#define FLIGHTASSIGNCLAIMTABLEMODEL_H

#include <QAbstractItemModel>

//! Модель представления заявок
class FlightAssignClaimTableModel : public QAbstractTableModel {
public:
    //! Конструктор.
    FlightAssignClaimTableModel(QObject *_parent = NULL);

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
        Name,       //!< Наименование

        ColumnCount //!< Количество столбцов
    };
};

#endif // FLIGHTASSIGNCLAIMTABLEMODEL_H
