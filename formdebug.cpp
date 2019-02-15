#include "formdebug.h"
#include "ui_formdebug.h"
#include <QMessageBox>
#include <QDebug>
#include "_def.h"


FormDebug::FormDebug(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDebug)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();

    ui->butClose->setIcon(QIcon());
    ui->butClose->setStyleSheet(RET_BUT_STYLE);

    QWidget* lTitleBar = ui->dockWidget->titleBarWidget();
    QWidget* lEmptyWidget = new QWidget();
    ui->dockWidget->setTitleBarWidget(lEmptyWidget);
    delete lTitleBar;

    ui->tbTab1->setChecked(true);

    m_formDebugSub1 = new FormDebugSub1(ui->mdiArea);
    m_formDebugSub2 = new FormDebugSub2(ui->mdiArea);
    m_formDebugSub3 = new FormDebugSub3(ui->mdiArea);
    m_formDebugSub4 = new FormDebugSub4(ui->mdiArea);
    m_formDebugSub5 = new FormDebugSub5(ui->mdiArea);

    m_formDebugSub1->show();
    m_formDebugSub2->hide();
    m_formDebugSub3->hide();
    m_formDebugSub4->hide();
    m_formDebugSub5->hide();
}

FormDebug::~FormDebug()
{
    delete ui;
}

void FormDebug::resizeEvent(QResizeEvent *event)
{
    ui->butClose->move(rect().right() - ui->butClose->width(), rect().y());
    QRect rc = ui->mdiArea->rect();
    m_formDebugSub1->resize(rc.width(), rc.height());
    m_formDebugSub2->resize(rc.width(), rc.height());
    m_formDebugSub3->resize(rc.width(), rc.height());
    m_formDebugSub4->resize(rc.width(), rc.height());
    m_formDebugSub5->resize(rc.width(), rc.height());

}

void FormDebug::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else {
        QWidget::changeEvent(event);
    }
}

void FormDebug::switch_debug_sub(int subIndex)
{
    if(subIndex == 1)
        m_formDebugSub1->show();
    else
        m_formDebugSub1->hide();

    if(subIndex == 2)
        m_formDebugSub2->show();
    else
        m_formDebugSub2->hide();

    if(subIndex == 3)
        m_formDebugSub3->show();
    else
        m_formDebugSub3->hide();

    if(subIndex == 4)
        m_formDebugSub4->show();
    else
        m_formDebugSub4->hide();

    if(subIndex == 5)
        m_formDebugSub5->show();
    else
        m_formDebugSub5->hide();


    ui->tbTab1->setChecked(subIndex == 1);
    ui->tbTab2->setChecked(subIndex == 2);
    ui->tbTab3->setChecked(subIndex == 3);
    ui->tbTab4->setChecked(subIndex == 4);
    ui->tbTab5->setChecked(subIndex == 5);

    if(subIndex >= 4)
        ui->widget->hide();
    else
        ui->widget->show();

}

void FormDebug::on_tbTab1_clicked()
{
    switch_debug_sub(1);
}

void FormDebug::on_tbTab2_clicked()
{
    switch_debug_sub(2);
}

void FormDebug::on_tbTab3_clicked()
{
    switch_debug_sub(3);
}

void FormDebug::on_tbTab4_clicked()
{
    switch_debug_sub(4);
}

void FormDebug::on_tbTab5_clicked()
{
    switch_debug_sub(5);
}

void FormDebug::on_butClose_clicked()
{
  //  QMessageBox::information(this, "tip", "button clicked");
    close();
}
