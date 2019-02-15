#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QtMath>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDockWidget>
#include "dlgset.h"
#include "dlgsickinput.h"
#include "dlgcheck.h"
#include "wf_run.h"
#include "wf_set.h"
#include "wf_db.h"
#include <QToolButton>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->toolBar->addWidget(spacer);


    QPushButton * p = new QPushButton(ui->toolBar);
     p->setMinimumSize(QSize(64, 32));
     p->setToolTip("Minimize the main Window.");
    p->setStyleSheet("QPushButton{border-image: url(:/icon/butmin.png) 0 0 0 0;border:none;color:rgb(255, 255, 255);}"
                     "QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}"
                     "QPushButton:pressed{background-color: rgb(200, 62, 134);border:none;color:rgb(255, 255, 255);}");

    ui->toolBar->addWidget(p);
    connect(p, SIGNAL(pressed()), this, SLOT(on_actionMinimize_triggered()));

    p = new QPushButton(ui->toolBar);
     p->setMinimumSize(QSize(64, 32));
      p->setToolTip("Close the main Window !");
    p->setStyleSheet("QPushButton{border-image: url(:/icon/butclose.png) 0 0 0 0;border:none;color:rgb(255, 255, 255);}"
                     "QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}"
                     "QPushButton:pressed{background-color: rgb(200, 62, 134);border:none;color:rgb(255, 255, 255);}");
    ui->toolBar->addWidget(p);
    connect(p, SIGNAL(pressed()), this, SLOT(on_actionClose_triggered()));

    ui->actionMain->setChecked(true);

    QHBoxLayout * layout = new QHBoxLayout(ui->widget);


    m_formMain = new FormMain(ui->widget);
    layout->addWidget(m_formMain);
    m_formMain->show();

    m_formReport = new FormReport(ui->widget);
    layout->addWidget(m_formReport);
    m_formReport->hide();

    m_formQuery = new FormQuery(ui->widget);
    layout->addWidget(m_formQuery);
    m_formQuery->hide();

//    m_formDebug = new FormDebug(ui->widget);
//    layout->addWidget(m_formDebug);
//    m_formDebug->hide();

//    m_formSop = new FormSop(ui->widget);
//    layout->addWidget(m_formSop);
//    m_formSop->hide();

    m_macState = MAC_INIT;

    //运行wf_run静态库测试代码
    Wf_run::create_instance();
    Wf_run::open_comm();

    vtcmd cmd, cmdRet;
    cmd.push_back(0x18);
    cmd.push_back(0xff);
    cmdRet = Wf_run::send_cmd(cmd);
    Wf_run::close_comm();
    Wf_run::release_instance();

    Wf_set::create_instance();
    QString s("language");
    Wf_set::set_str(s, tr("type"), QString("chinese"));
    s = Wf_set::get_str(QString("language"), QString("type"), QString("111"));
    qDebug() << s << endl;
    Wf_set::release_instance();

    QString dbPath = "./wf.db";
//    Wf_db::create_database(dbPath);
    RecordSick rec;
    rec.set_field(0, "201901110001");
    rec.set_field(1, "name张三");
    rec.set_field(2, "男");
    rec.set_field(3, "23岁");
    Wf_db::set_sick(rec);

    QList<RecordSick> recs;
    Wf_db::get_sick("ID like \'2019%\'", recs);

    QList<RecordSick>::iterator it;
    for(it = recs.begin(); it != recs.end(); ++it){
        qDebug() << it->get_field(0) << it->get_field(1) << it->get_field(2) << it->get_field(3)
                 << it->get_field(4) << it->get_field(5) << '\n';
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap img;
    QRect rc = rect();
    if(! ( img.load(tr("../wf/icon/bkimg.jpg") ) )) //加载图像
        return;

    QPixmap img1 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(rc, img1);

    QFont font("宋体", 15, QFont::Black, false);
    painter.setFont(font);

    // 设置画笔颜色
    painter.setPen(QColor(120, 120, 250));

    QString s = "Wanhua Puman Bioengineering Co., Ltd. ";
    s += "Version 1.0.0.201812";

    // 绘制区域为当前界面的整个区域
    rc = rect();
    rc.setLeft(rc.left() + 10);
    rc.setBottom(rc.bottom() - 20);

    painter.drawText(rc, Qt::AlignLeft | Qt::AlignBottom, s);

    rc.setTop(rc.top() + 30);
    rc.setRight(rc.right() - 200);
    s = QDateTime::currentDateTime().toString(Qt::LocalDate);
    painter.drawText(rc, Qt::AlignRight | Qt::AlignTop, s);

}


void MainWindow::switch_page(uint pageIndex)
{
    ui->actionMain->setChecked(pageIndex == 0);
    if(pageIndex == 0)
        m_formMain->show();
    else
        m_formMain->hide();
    ui->actionReport->setChecked(pageIndex == 1);
    if(pageIndex == 1)
        m_formReport->show();
    else
        m_formReport->hide();
    ui->actionQuery->setChecked(pageIndex == 2);
    if(pageIndex == 2)
        m_formQuery->show();
    else
        m_formQuery->hide();
//    ui->actionDebug->setChecked(pageIndex == 3);
//    if(pageIndex == 3)
//        m_formDebug->show();
//    else
//        m_formDebug->hide();
//    ui->actionSop->setChecked(pageIndex == 4);
//    if(pageIndex == 4)
//        m_formSop->show();
//    else
//        m_formSop->hide();
}

void MainWindow::on_actionMain_triggered()
{
    switch_page(0);

}

void MainWindow::on_actionReport_triggered()
{
    switch_page(1);
}

void MainWindow::on_actionQuery_triggered()
{
    switch_page(2);
}


void MainWindow::on_actionDebug_triggered()
{
    switch_page(3);
}


void MainWindow::on_actionSop_triggered()
{
    switch_page(4);
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionMinimize_triggered()
{
    this->showMinimized();
}


void MainWindow::on_actionStart_triggered()
{
    switch(m_macState)
    {
    case MAC_INIT:{
        m_macState = MAC_RUNNING;
        QIcon ic(":/icon/mypause.png");
        ui->actionStart->setIcon(ic);
        break;
    }
    case MAC_RUNNING:{
        m_macState = MAC_PAUSE;
        QIcon ic(":/icon/mystart.png");
        ui->actionStart->setIcon(ic);
        break;
    }
    case MAC_PAUSE:{
        m_macState = MAC_RUNNING;
        QIcon ic(":/icon/mypause.png");
        ui->actionStart->setIcon(ic);
        break;
    }
    case MAC_SHUTDOWN:
        QMessageBox::information(this, tr("Error"), tr("Machine is shutdown!!!"));
    }
}

void MainWindow::on_actionShutdown_triggered()
{
    QMessageBox::information(this, tr("button trigged"), tr("shutdown machine button trigged"));
}

void MainWindow::on_actionSet_triggered()
{
    DlgSet dlg(this);
    dlg.exec();
}

void MainWindow::on_actionSickinput_triggered()
{
    DlgSickInput dlg(this);
    dlg.exec();
}

void MainWindow::on_actionCheck_triggered()
{
    DlgCheck dlg(this);
    dlg.exec();
}
