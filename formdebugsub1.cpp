#include "formdebugsub1.h"
#include "ui_formdebugsub1.h"

FormDebugSub1::FormDebugSub1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebugSub1)
{
    ui->setupUi(this);

    ui->tabWidget->setStyleSheet("background-color:rgb(240,240,240)");
 //   m_formDebugMicro = new FormDebugSub1Sub1();
//    m_formDebugCapture = new FormDebugSub1Sub2();

 //   ui->tabWidget->insertTab(0, m_formDebugMicro, tr("显微镜"));
//    ui->tabWidget->insertTab(0, m_formDebugCapture, tr("摄像机"));

}

FormDebugSub1::~FormDebugSub1()
{
    delete ui;
}

void FormDebugSub1::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
