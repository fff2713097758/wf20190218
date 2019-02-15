#include "formdebugsub2.h"
#include "ui_formdebugsub2.h"

FormDebugSub2::FormDebugSub2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebugSub2)
{
    ui->setupUi(this);
}

FormDebugSub2::~FormDebugSub2()
{
    delete ui;
}

void FormDebugSub2::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
