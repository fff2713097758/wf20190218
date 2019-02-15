#include "formdebugsub3.h"
#include "ui_formdebugsub3.h"

FormDebugSub3::FormDebugSub3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebugSub3)
{
    ui->setupUi(this);
}

FormDebugSub3::~FormDebugSub3()
{
    delete ui;
}

void FormDebugSub3::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
