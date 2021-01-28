#include "FlightAssignAddClaimDialog.h"
#include "ui_FlightAssignAddClaimDialog.h"

#include "FlightAssignMainManager.h"

#include <FlightAssignTools.h>
#include <FlightAssignClaim.h>
#include <FlightAssignDataManager.h>

FlightAssignAddClaimDialog::FlightAssignAddClaimDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::FlightAssignAddClaimDialog)
{
    m_ui->setupUi(this);

    prepairUi();
}

FlightAssignAddClaimDialog::~FlightAssignAddClaimDialog()
{
    delete m_ui;
}

void FlightAssignAddClaimDialog::saveButtonClickedSlot()
{
    FlightAssignClaim *claim = nullptr;
    try {
        checkFields();
        claim = createClaim();
        d_dataManager->addClaim(claim);
    }
    catch (const QString &error) {
        FlightAssignTools::showException(error, this);
        delete claim;

        return;
    }

    QDialog::accept();
}

void FlightAssignAddClaimDialog::prepairUi()
{
    initConnections();
}

void FlightAssignAddClaimDialog::initConnections()
{
    connect(m_ui->pbAdd, SIGNAL(clicked()), this, SLOT(saveButtonClickedSlot()));
    connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

FlightAssignClaim *FlightAssignAddClaimDialog::createClaim() const
{
    return new FlightAssignClaim(NULL_ID, m_ui->leName->text(), m_ui->sbNumber->value());
}

void FlightAssignAddClaimDialog::checkFields() const
{
    if (m_ui->leName->text().trimmed().isEmpty()) {
        throw ru("Необходимо заполнить наименование");
    }
}
