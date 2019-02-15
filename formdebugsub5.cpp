#include "formdebugsub5.h"
#include "ui_formdebugsub5.h"

FormDebugSub5::FormDebugSub5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebugSub5)
{
    ui->setupUi(this);
}

FormDebugSub5::~FormDebugSub5()
{
    delete ui;
}

void FormDebugSub5::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
