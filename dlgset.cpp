#include "dlgset.h"
#include "ui_dlgset.h"



DlgSet::DlgSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSet)
{
    ui->setupUi(this);

    QStringList labels;
    labels.push_back(tr("串口通讯"));
    labels.push_back(tr("CCD参数"));
    labels.push_back(tr("用户管理"));
    labels.push_back(tr("试剂耗材"));
    labels.push_back(tr("质控参数"));
    labels.push_back(tr("标准图库"));
    labels.push_back(tr("联网接口"));

    ui->listWidget->addItems(labels);
   // QListWidgetItem * pItem = new QListWidgetItem(tr("串口通讯"));
    //pItem->setSizeHint(QSize(60, 40));  //每次改变Item的高度
    //ui->listWidget->insertItem(0, pItem);
    for(int i=0; i<ui->listWidget->count(); i++)
        ui->listWidget->item(i)->setSizeHint(QSize(60, 40));

    //ui->listWidget->addItems(labels);
    //ui->listWidget->setSizePolicy();

    m_formSet1 = new DlgSetSub1(ui->mdiArea);
    m_formSet2 = new DlgSetSub2(ui->mdiArea);
   // FormSickinputTab2 * form2 = new FormSickinputTab2();

    ui->mdiArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   // ui->mdiArea->setOption(QMdiArea::DontMaximizeSubWindowOnActivation);
   // QMdiSubWindow *sw1 = ui->mdiArea->addSubWindow(m_formSet1);
    //QMdiSubWindow *sw2 = ui->mdiArea->addSubWindow(m_formSet2);
  //  ui->mdiArea->activeSubWindow()->resize(200, 200);

  //  QRect rc = ui->mdiArea->rect();
    //sw1->setFixedSize(rc.width()+10,rc.height());
   // sw2->setFixedSize(rc.width()+10,rc.height());
    //ui->mdiArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //QMdiSubWindow *sw =ui->mdiArea->addSubWindow(imagelabel);
    //sw->setFixedSize(colorImage.size().width()+10,colorImage.size().height()+30); //有效果哦

   // imagelabel->show();
    m_formSet1->show();
    //m_formSet2->hide();

    //ui->tabWidget->insertTab(0, form1, tr("串口设置"));
    //ui->tabWidget->insertTab(1, form2, tr("批量录入"));

}

DlgSet::~DlgSet()
{
    delete ui;
}

 void DlgSet::resizeEvent(QResizeEvent *resizeEvent)
 {
     QRect rc = ui->mdiArea->rect();
     m_formSet1->setFixedSize(rc.width(),rc.height());
     m_formSet2->setFixedSize(rc.width(),rc.height());
 }

 void DlgSet::changeEvent(QEvent * event)
 {
     if(event->type() == QEvent::LanguageChange){
         ui->retranslateUi(this);
     }else{
         QDialog::changeEvent(event);
     }
 }

void DlgSet::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->text() == tr("串口通讯")){
        show_page(1);
    }else if(item->text() == tr("CCD参数")){
        show_page(2);
    }

}


void DlgSet::show_page(int index)
{
    if(index == 1){
        m_formSet1->show();
    }else {
        m_formSet1->hide();
    }

    if(index == 2){
        m_formSet2->show();
    }else {
        m_formSet2->hide();
    }
}


void DlgSet::on_butSave_clicked()
{

}

void DlgSet::on_butExit_clicked()
{
    close();
}
