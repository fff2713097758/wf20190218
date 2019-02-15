#include "formdebugsub4.h"
#include "ui_formdebugsub4.h"

FormDebugSub4::FormDebugSub4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebugSub4)
{
    ui->setupUi(this);
}

FormDebugSub4::~FormDebugSub4()
{
    delete ui;
}

void FormDebugSub4::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
