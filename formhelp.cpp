#include "formhelp.h"
#include "ui_formhelp.h"
#include <QDebug>
#include "_def.h"

FormHelp::FormHelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHelp)
{
    ui->setupUi(this);

    ui->butClose->setIcon(QIcon());
    ui->butClose->setStyleSheet(RET_BUT_STYLE);
}

FormHelp::~FormHelp()
{
    delete ui;
}

void FormHelp::resizeEvent(QResizeEvent *event)
{
    ui->butClose->move(rect().right() - ui->butClose->width(), rect().y());
}

void FormHelp::on_butClose_clicked()
{
    close();
}
