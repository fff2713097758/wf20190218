#include "formimagelib.h"
#include "ui_formimagelib.h"
#include "_def.h"

FormImageLib::FormImageLib(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormImageLib)
{
    ui->setupUi(this);

    ui->butClose->setIcon(QIcon());
    ui->butClose->setStyleSheet(RET_BUT_STYLE);
}

FormImageLib::~FormImageLib()
{
    delete ui;
}

void FormImageLib::resizeEvent(QResizeEvent *event)
{
    ui->butClose->move(rect().right() - ui->butClose->width(), rect().y());
}

void FormImageLib::on_butClose_clicked()
{
    close();
}
