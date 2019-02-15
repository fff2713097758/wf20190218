#include "formreport.h"
#include "ui_formreport.h"
#include <QMessageBox>
#include "dlgsickinput.h"
#include "formreportsub1.h"
#include "_def.h"
#include <QDebug>


FormReport::FormReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormReport)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();

    QWidget* lTitleBar = ui->dockWidget->titleBarWidget();
    QWidget* lEmptyWidget = new QWidget();
    ui->dockWidget->setTitleBarWidget(lEmptyWidget);
    delete lTitleBar;

    init_sample_list();

    m_formReportSub1 = new FormReportSub1(ui->widget);
    m_formReportSub1->show();
}

FormReport::~FormReport()
{
    delete ui;
}

void FormReport::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    } else {
        QWidget::changeEvent(event);
    }
}


void FormReport::resizeEvent(QResizeEvent *resizeEvent)
{
    QRect rc = ui->widget->rect();
    m_formReportSub1->resize(rc.width(), rc.height());
}


void FormReport::init_sample_list()
{
    QStringList headSampleList;
    headSampleList.push_back(tr("ID"));
    headSampleList.push_back(tr("项目"));
    headSampleList.push_back(tr("报告"));
    headSampleList.push_back(tr("姓名"));
    headSampleList.push_back(tr("性别"));
    headSampleList.push_back(tr("年龄"));
    headSampleList.push_back(tr("科室"));
    headSampleList.push_back(tr("诊断"));
    headSampleList.push_back(tr("病历号"));
    headSampleList.push_back(tr("条形码"));
    ui->twSmpList->setColumnCount(headSampleList.count());//
    ui->twSmpList->setHorizontalHeaderLabels(headSampleList);
    ui->twSmpList->horizontalHeader()->setDefaultSectionSize(60);
    ui->twSmpList->setSelectionMode(QAbstractItemView::SingleSelection);   //设置选择的模式为单选择
    ui->twSmpList->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
    ui->twSmpList->setStyleSheet("QTableWidget::item:selected { background-color: rgb(0, 120, 250) }");
    ui->twSmpList->verticalHeader()->setVisible(false);
    ui->twSmpList->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(230,230,230);font:10pt '宋体';color: black;};");

    for(int i = 0; i<100; i++){
      int row_count = ui->twSmpList->rowCount(); //获取表单行数
        ui->twSmpList->insertRow(row_count); //插入新行
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        //设置相应的图标、文件名、最后更新时间、相应的类型、文件大小
     //   item->setIcon(icon); //icon为调用系统的图标。以后缀来区分
        QString s;

        item->setText(s.setNum(i));
        item1->setText(tr("FOB/Tf"));
        item2->setText(tr("ok")); //type为调用系统的类型。以后缀来区分
        item3->setText(tr("name"));
        //设置样式为灰色
        QColor color("gray");
        item1->setTextColor(color);
        item2->setTextColor(color);
        item3->setTextColor(color);
        ui->twSmpList->setItem(row_count, 0, item);
        ui->twSmpList->setItem(row_count, 1, item1);
        ui->twSmpList->setItem(row_count, 2, item2);
        ui->twSmpList->setItem(row_count, 3, item3);
    }
}


void FormReport::on_toolButton_triggered(QAction *arg1)
{
   // QMessageBox::information(this, tr("aaa"), tr("sick"))
}

void FormReport::on_toolButton_6_triggered(QAction *arg1)
{

}
