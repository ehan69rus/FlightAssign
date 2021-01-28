#include "FlightAssignEditDestinationDialog.h"
#include "ui_FlightAssignEditDestinationDialog.h"

#include "FlightAssignMainManager.h"

#include <FlightAssignAirdrome.h>
#include <FlightAssignDataManager.h>
#include <FlightAssignDestination.h>

FlightAssignEditDestinationDialog::FlightAssignEditDestinationDialog(FlightAssignDestination *_item,
                                                                     QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::FlightAssignEditDestinationDialog), m_item(_item)
{
    m_ui->setupUi(this);

    prepairUi();
}

FlightAssignEditDestinationDialog::~FlightAssignEditDestinationDialog()
{
    m_item = nullptr;

    delete m_ui;
}

void FlightAssignEditDestinationDialog::saveButtonClickedSlot()
{

}

void FlightAssignEditDestinationDialog::prepairUi()
{
    initComboboxes();
    initConnections();

    if (m_item != nullptr) {
        fillForm();
    }
}

void FlightAssignEditDestinationDialog::initConnections()
{
    connect(m_ui->pbSave, SIGNAL(clicked()), this, SLOT(saveButtonClickedSlot()));
    connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

FlightAssignDestination *FlightAssignEditDestinationDialog::createDestination() const
{


    return new FlightAssignDestination();
}

void FlightAssignEditDestinationDialog::fillForm()
{
    m_ui->lNumberValue->setText(QString::number(m_item->number()));
    m_ui->sbSumm->setValue(m_item->sum());

    for (int i = 0; i < m_ui->cbAirdrome->count(); ++i) {
        long long cbAirdromeId = m_ui->cbAirdrome->itemData(i).toLongLong();
        long long itemAirdromeId = m_item->airdrome()->id();

        if (cbAirdromeId != itemAirdromeId) {
            continue;
        }

        m_ui->cbAirdrome->setCurrentIndex(i);
        break;
    }

    m_ui->teInfo->setText(m_item->information());
}

void FlightAssignEditDestinationDialog::initComboboxes()
{
    m_ui->cbAirdrome->clear();

    QMap<long long, FlightAssignAirdrome *> airdromeMap = d_dataManager->airdromes();
    for (auto *airdrome : airdromeMap) {
        m_ui->cbAirdrome->addItem(airdrome->name(), airdrome->id());
    }
}
