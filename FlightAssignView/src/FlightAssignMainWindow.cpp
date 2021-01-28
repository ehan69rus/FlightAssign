#include "FlightAssignMainWindow.h"
#include "ui_FlightAssignMainWindow.h"

#include "FlightAssignMainManager.h"
#include "FlightAssignAddClaimDialog.h"
#include "FlightAssignClaimTableModel.h"
#include "FlightAssignDestinationTableModel.h"

#include <FlightAssignTools.h>
#include <FlightAssignDataManager.h>

FlightAssignMainWindow::FlightAssignMainWindow(QWidget *_parent) :
    QMainWindow(_parent),
    m_ui(new Ui::FlightAssignMainWindow), m_claimModel(nullptr),
    m_destinationsModel(nullptr)
{
    m_ui->setupUi(this);

    prepairUi();
}

FlightAssignMainWindow::~FlightAssignMainWindow()
{
    delete m_claimModel;
    m_claimModel = nullptr;

    delete m_destinationsModel;
    m_destinationsModel = nullptr;

    delete m_ui;
    m_ui = nullptr;
}

void FlightAssignMainWindow::addClaimButtonClickedSlot()
{
    QDialog *dialog = nullptr;
    try {
        dialog = new FlightAssignAddClaimDialog(this);
        if (dialog->exec() == QDialog::Accepted) {
            m_claimModel->update();
        }
    }
    catch (const QString &error) {
        FlightAssignTools::showException(error, this);
    }

    delete dialog;

    m_ui->tvClaims->resizeColumnsToContents();
}

void FlightAssignMainWindow::removeClaimButtonClickedSlot()
{
    QModelIndex index = m_ui->tvClaims->currentIndex();
    if (!index.isValid()) {
        return;
    }

    try {
        d_dataManager->removeClaimByIndex(index.row());
        m_claimModel->update();
    }
    catch (const QString &error) {
        FlightAssignTools::showException(error, this);
    }

    m_ui->tvClaims->resizeColumnsToContents();
}

void FlightAssignMainWindow::currentClaimChangedSlot()
{
    QModelIndex index = m_ui->tvClaims->currentIndex();
    FlightAssignClaim *currentClaim = d_dataManager->claimAt(index.row());

    m_destinationsModel->setClaim(currentClaim);
    m_ui->tvDestinations->resizeColumnsToContents();
}

void FlightAssignMainWindow::addDestinationButtonClickedSlot()
{

}

void FlightAssignMainWindow::editDestinationButtonClickedSlot()
{

}

void FlightAssignMainWindow::removeDestinationButtonClickedSlot()
{

}

void FlightAssignMainWindow::prepairUi()
{
    d_dataManager->loadAidromes();

    m_claimModel = new FlightAssignClaimTableModel(this);
    m_ui->tvClaims->setModel(m_claimModel);

    m_destinationsModel = new FlightAssignDestinationTableModel(this);
    m_ui->tvDestinations->setModel(m_destinationsModel);
    m_ui->tvDestinations->resizeColumnsToContents();

    initConnections();
}

void FlightAssignMainWindow::initConnections()
{
    connect(m_ui->pbAddClaim, SIGNAL(clicked()), this, SLOT(addClaimButtonClickedSlot()));
    connect(m_ui->pbRemoveClaim, SIGNAL(clicked()), this, SLOT(removeClaimButtonClickedSlot()));

    connect(m_ui->pbAddDestination, SIGNAL(clicked()), this, SLOT(addDestinationButtonClickedSlot()));
    connect(m_ui->pbRemoveDestination, SIGNAL(clicked()), this, SLOT(removeDestinationButtonClickedSlot()));
    connect(m_ui->pbEditDestination, SIGNAL(clicked()), this, SLOT(editDestinationButtonClickedSlot()));

    connect(m_ui->tvClaims->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(currentClaimChangedSlot()));
}
