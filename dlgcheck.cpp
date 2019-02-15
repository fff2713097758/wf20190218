#include "dlgcheck.h"
#include "ui_dlgcheck.h"

DlgCheck::DlgCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCheck)
{
    ui->setupUi(this);
}

DlgCheck::~DlgCheck()
{
    delete ui;
}

void DlgCheck::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QDialog::changeEvent(event);
    }
}
