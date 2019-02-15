#include "dlgsetsub2.h"
#include "ui_dlgsetsub2.h"

DlgSetSub2::DlgSetSub2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DlgSetSub2)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
}

DlgSetSub2::~DlgSetSub2()
{
    delete ui;
}
