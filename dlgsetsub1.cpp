#include "dlgsetsub1.h"
#include "ui_dlgsetsub1.h"

DlgSetSub1::DlgSetSub1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DlgSetSub1)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();

    QStringList s;
    s << "中文" << "English";
    ui->cbLanguage->addItems(s);
}

DlgSetSub1::~DlgSetSub1()
{
    delete ui;
}
