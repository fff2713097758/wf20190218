#include "formmain.h"
#include "ui_formmain.h"
#include <QPainter>
#include "dlgset.h"
#include "formdebug.h"
#include "dlguser.h"
#include "formqc.h"
#include "formimagelib.h"
#include "formhelp.h"


FormMain::FormMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMain)
{
    ui->setupUi(this);


}

FormMain::~FormMain()
{
    delete ui;
}

void FormMain::changeEvent(QEvent * event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    } else {
        QWidget::changeEvent(event);
    }
}

void FormMain::on_butDebug_clicked()
{
    FormDebug * formDebug = new FormDebug(this);
    formDebug->setAttribute(Qt::WA_DeleteOnClose);
    formDebug->resize(this->width(), this->height());
    formDebug->show();
}

void FormMain::on_butSet_clicked()
{
  //  ui->horizontalLayoutWidget->hide();
    DlgSet dlg;
    dlg.exec();
  //   ui->horizontalLayoutWidget->show();
}

void FormMain::on_butUser_clicked()
{
   // ui->horizontalLayoutWidget->hide();
    DlgUser dlg;
    dlg.exec();
  //  ui->horizontalLayoutWidget->show();
}

void FormMain::on_butQC_clicked()
{
    FormQC * form = new FormQC(this);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->resize(this->width(), this->height());
    form->show();

}

void FormMain::on_butImage_clicked()
{
    FormImageLib * form = new FormImageLib(this);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->resize(this->width(), this->height());
    form->show();

}

void FormMain::on_butSop_clicked()
{
    FormHelp * form = new FormHelp(this);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->resize(this->width(), this->height());
    form->show();

}
