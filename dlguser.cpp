#include "dlguser.h"
#include "ui_dlguser.h"

DlgUser::DlgUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUser)
{
    ui->setupUi(this);

    init_user_table();
}

DlgUser::~DlgUser()
{
    delete ui;
}

void DlgUser::init_user_table()
{
    QStringList heads;
    heads << "User Name";
    ui->twUser->setColumnCount(heads.size());
    ui->twUser->setHorizontalHeaderLabels(heads);
    ui->twUser->setColumnWidth(0, 300);
    ui->twUser->setSelectionMode(QAbstractItemView::SingleSelection);

    QString s;
    for(int i =0; i<200; i++){
        ui->twUser->insertRow(i);
        QTableWidgetItem * item = new QTableWidgetItem("aaa");
        ui->twUser->setItem(i, 0, item);
    }
}

void DlgUser::on_butSave_clicked()
{

}

void DlgUser::on_butExit_clicked()
{
    close();
}
