#include "FlightAssignMainWindow.h"
#include "ui_FlightAssignMainWindow.h"

FlightAssignMainWindow::FlightAssignMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlightAssignMainWindow)
{
    ui->setupUi(this);
}

FlightAssignMainWindow::~FlightAssignMainWindow()
{
    delete ui;
}
