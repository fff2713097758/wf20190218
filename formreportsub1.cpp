#include "formreportsub1.h"
#include "ui_formreportsub1.h"
#include <QMessageBox>
#include <QColor>
#include <QBrush>



FormReportSub1::FormReportSub1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormReportSub1)
{
    ui->setupUi(this);

    init_micro_list();
    init_chemic_list();
    init_state_list();

    ui->labelMicro->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(130, 135, 144);");
    ui->labelState->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(130, 135, 144);");
    ui->labelChemic->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(130, 135, 144);");
    ui->labelMicros->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(130, 135, 144);");

}

FormReportSub1::~FormReportSub1()
{
    delete ui;
}

void FormReportSub1::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}

void FormReportSub1::resizeEvent(QResizeEvent *resizeEvent)
{
    load_sample_image(tr(""));
}

void FormReportSub1::init_micro_list()
{
    QStringList headSampleList;
    headSampleList.push_back(tr("镜检项目"));
    headSampleList.push_back(tr("结果"));
    ui->twMicro->setColumnCount(2);//
    ui->twMicro->setHorizontalHeaderLabels(headSampleList);
    ui->twMicro->horizontalHeader()->setDefaultSectionSize(100);
    //ui->twMicro->horizontalHeader()-
    ui->twMicro->setSelectionMode(QAbstractItemView::SingleSelection);   //设置选择的模式为单选择
    ui->twMicro->verticalHeader()->setVisible(false);

 /*   QTableWidgetItem * header = ui->twMicro->horizontalHeaderItem(0);  //获得表头的Item对象
    header->setBackground(QBrush(QColor(185,192,201))); //设置单元格背景颜色
    header->setBackgroundColor(QColor(185,192,201)); //设置单元格背景颜色
    header->setTextColor(QColor(200,111,30)); //设置文字颜色
*/
    //QString s = ui->twMicro->horizontalHeader()->styleSheet();
    //QMessageBox::information(this, tr(""), s);
    ui->twMicro->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(230,230,230);font:10pt '宋体';color: black;};");

//    ui->twMicro->verticalHeader()->setVisible(false);

/*    QTableWidgetItem *item = new QTableWidgetItem();
//    QTableWidgetItem *item1 = new QTableWidgetItem();
    QString s;
    QColor color("gray");
//    item1->setTextColor(color);//设置样式为灰色
    int row_count = 0; //获取表单行数

    ui->twMicro->insertRow(row_count); //插入新行
    item->setText(tr("红细胞（RBC）"));
    ui->twMicro->setItem(row_count, 0, item);
    row_count++;

    item = new QTableWidgetItem();
    ui->twMicro->insertRow(row_count); //插入新行
    item->setText(tr("白细胞（WBC）"));
    ui->twMicro->setItem(row_count, 0, item);
    row_count++;
    */
    insert_table_row(ui->twMicro, tr("红细胞"));
    insert_table_row(ui->twMicro, tr("白细胞"));
    insert_table_row(ui->twMicro, tr("吞噬细胞"));
    insert_table_row(ui->twMicro, tr("脓细胞"));
    insert_table_row(ui->twMicro, tr("肿瘤细胞"));
    insert_table_row(ui->twMicro, tr("脂肪滴"));
    insert_table_row(ui->twMicro, tr("虫卵"));
    insert_table_row(ui->twMicro, tr("霉菌"));
    insert_table_row(ui->twMicro, tr("粘液"));
    insert_table_row(ui->twMicro, tr("酵母菌"));
    insert_table_row(ui->twMicro, tr("植物细胞"));
    insert_table_row(ui->twMicro, tr("寄生虫卵"));
    insert_table_row(ui->twMicro, tr("类寄生虫卵"));
    insert_table_row(ui->twMicro, tr("夏科雷登结晶"));
    insert_table_row(ui->twMicro, tr("其他"));
}

void FormReportSub1::insert_table_row(QTableWidget * pTable, QString text)
{
    int rowCount = pTable->rowCount();
    QTableWidgetItem *item = new QTableWidgetItem(text);
    item->setFlags(item->flags() & (~Qt::ItemIsEditable) & (~Qt::ItemIsSelectable) & (~Qt::ItemIsEnabled));
    pTable->insertRow(rowCount);
    pTable->setItem(rowCount, 0, item);
}

void FormReportSub1::init_chemic_list()
{
    QStringList headSampleList;
    headSampleList.push_back(tr("化学项目"));
    headSampleList.push_back(tr("结果"));
    ui->twChemic->setColumnCount(2);//
    ui->twChemic->setHorizontalHeaderLabels(headSampleList);
    ui->twChemic->horizontalHeader()->setDefaultSectionSize(100);
    ui->twChemic->setSelectionMode(QAbstractItemView::SingleSelection);   //设置选择的模式为单选择
    ui->twChemic->verticalHeader()->setVisible(false);
    ui->twChemic->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(230,230,230);font:10pt '宋体';color: black;};");
//    ui->twMicro->verticalHeader()->setVisible(false);

 /*   int row_count = 0; //获取表单行数
    ui->twChemic->insertRow(row_count); //插入新行
    QTableWidgetItem *item = new QTableWidgetItem();
    QTableWidgetItem *item1 = new QTableWidgetItem();
    QString s;

    item->setText(tr("FOB"));
    item1->setText(tr("Tf"));
    //设置样式为灰色
    QColor color("gray");
    item1->setTextColor(color);
    ui->twChemic->setItem(row_count, 0, item);
    ui->twChemic->setItem(row_count, 1, item1);*/

    insert_table_row(ui->twChemic, tr("FOB"));
    insert_table_row(ui->twChemic, tr("转铁蛋白（Tf）"));
    insert_table_row(ui->twChemic, tr("钙卫蛋白"));
    insert_table_row(ui->twChemic, tr("轮状病毒"));
    insert_table_row(ui->twChemic, tr("腺病毒"));
    insert_table_row(ui->twChemic, tr("柯萨奇病毒"));
    insert_table_row(ui->twChemic, tr("诺如病毒"));
    insert_table_row(ui->twChemic, tr("幽门螺旋杆菌"));
    insert_table_row(ui->twChemic, tr("大肠杆菌"));
    insert_table_row(ui->twChemic, tr("霍乱弧菌"));
}


void FormReportSub1::init_state_list()
{
    QStringList headSampleList;
    headSampleList.push_back(tr("样本性状"));
    headSampleList.push_back(tr("结果"));
    ui->twState->setColumnCount(2);//
    ui->twState->setHorizontalHeaderLabels(headSampleList);
    ui->twState->horizontalHeader()->setDefaultSectionSize(100);
    ui->twState->setSelectionMode(QAbstractItemView::SingleSelection);   //设置选择的模式为单选择
    ui->twState->verticalHeader()->setVisible(false);
    ui->twState->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(230,230,230);font:10pt '宋体';color: black;};");

    insert_table_row(ui->twState, tr("颜色"));
    insert_table_row(ui->twState, tr("性状"));


}

void FormReportSub1::init_sample_image()
{

}

void FormReportSub1::init_chemic_image()
{

}

void FormReportSub1::init_micro_image()
{

}


void FormReportSub1::load_sample_image(QString sampleDir)
{return;
    load_image(ui->labelMicro, tr("d:/g/fds/wf/wf/icon/sample_micro.jpg"));
    load_image(ui->labelState, tr("d:/g/fds/wf/wf/icon/sample_state.jpg"));
    load_image(ui->labelChemic, tr("d:/g/fds/wf/wf/icon/sample_chemic.jpg"));
    load_image(ui->labelMicros, tr("d:/g/fds/wf/wf/icon/sample_micros.jpg"));
 /*
   QString filename(tr("d:/g/fds/wf/wf/icon/sample_micro.jpg"));
  //  QMessageBox::information(this, tr("filename"), filename);
    QPixmap img;
    QRect rc = ui->label->rect();
    if(! ( img.load(filename) ) ) //加载图像
    {
        QMessageBox::information(this,
                                 tr("打开图像失败"),
                                 tr("打开图像失败!"));
        return;
    }

    QPixmap img1 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);
    ui->label->setPixmap(img1);

    rc = ui->label_2->rect();
    QPixmap img2 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);
    ui->label_2->setPixmap(img2);

    rc = ui->label_3->rect();
    QPixmap img3 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);
    ui->label_3->setPixmap(img3);

    rc = ui->label_4->rect();
    QPixmap img4 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);
    ui->label_4->setPixmap(img3);
*/
}

void FormReportSub1::load_image(QLabel * pLabel, QString imagePath)
{
    QPixmap img;
    QRect rc = pLabel->rect();
    if(! ( img.load(imagePath) ) ) //加载图像
    {
        QMessageBox::information(this, tr("Error"), tr("打开图像失败!"));
        return;
    }

    QPixmap img1 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pLabel->setPixmap(img1);
}


void FormReportSub1::on_buttonSickInput_clicked()
{
 //   DlgSickInput dlg(this);
 //   dlg.exec();
}
