#include "dlgsickinput.h"
#include "ui_dlgsickinput.h"
//#include "formsickinputtab1.h"
//#include "formsickinputtab2.h"


DlgSickInput::DlgSickInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSickInput)
{
    ui->setupUi(this);

//    FormSickinputTab1 * form1 = new FormSickinputTab1();
//    FormSickinputTab2 * form2 = new FormSickinputTab2();

 //   ui->tabWidget->insertTab(0, form1, tr("单个录入"));
 //   ui->tabWidget->insertTab(1, form2, tr("批量录入"));
}

DlgSickInput::~DlgSickInput()
{
    delete ui;
}

void DlgSickInput::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else {
        QDialog::changeEvent(event);
    }
}
