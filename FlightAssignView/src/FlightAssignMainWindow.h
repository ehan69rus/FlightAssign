#ifndef FLIGHTASSIGNMAINWINDOW_H
#define FLIGHTASSIGNMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class FlightAssignMainWindow;
}

class FlightAssignMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlightAssignMainWindow(QWidget *parent = 0);
    ~FlightAssignMainWindow();

private:
    Ui::FlightAssignMainWindow *ui;
};

#endif // FLIGHTASSIGNMAINWINDOW_H
