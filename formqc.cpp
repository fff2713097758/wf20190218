#include "formqc.h"
#include "ui_formqc.h"
#include "_def.h"

FormQC::FormQC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormQC)
{
    ui->setupUi(this);

    ui->butClose->setIcon(QIcon());
    ui->butClose->setStyleSheet(RET_BUT_STYLE);
}

FormQC::~FormQC()
{
    delete ui;
}

void FormQC::resizeEvent(QResizeEvent *event)
{
    ui->butClose->move(rect().right() - ui->butClose->width(), rect().y());
}

void FormQC::on_butClose_clicked()
{
    close();
}
