#include "dlgload.h"
#include "ui_dlgload.h"
#include <QMessageBox>
#include <QPainter>
#include <QDebug>


DlgLoad::DlgLoad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLoad)
{
    ui->setupUi(this);
}

DlgLoad::~DlgLoad()
{
    delete ui;
}


void DlgLoad::paintEvent(QPaintEvent *)
{
    //Q_UNUSED(event);
    QPainter painter(this);

    QPixmap img;
    QRect rc = rect();

    if(! ( img.load(("../wf/icon/bk_tree2.jpg") ) )) //加载图像
        return;

    QPixmap img1 = img.scaled(rc.width(), rc.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(rc, img1);
}

void DlgLoad::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QDialog::changeEvent(event);
    }
}

void DlgLoad::on_buttonBox_clicked(QAbstractButton *button)
{
//    if(button == (QAbstractButton *)(ui->buttonBox->button(QDialogButtonBox::Ok))){
//        if(ui->cbName->currentText() == tr("admin") && ui->edPassword->text() == tr("123456")){
//            accept();
//        } else {
//            QMessageBox::warning(this, tr("Waring"), tr("user name or password error!"), QMessageBox::Ok);
//            ui->cbName->clear();// 清空内容并定位光标
//            ui->edPassword->clear();
//            ui->cbName->setFocus();
//        }
//    }
//    else {
//        reject();
//    }
}

void DlgLoad::on_butOk_clicked()
{
    if(ui->cbName->currentText() == tr("admin") && ui->edPassword->text() == tr("123456")){
        accept();
    } else {
        QMessageBox::warning(this, tr("Waring"), tr("user name or password error!"), QMessageBox::Ok);
        ui->cbName->clear();// 清空内容并定位光标
        ui->edPassword->clear();
        ui->cbName->setFocus();
    }
}

void DlgLoad::on_butCancel_clicked()
{
    reject();
}
