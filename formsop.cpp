#include "formsop.h"
#include "ui_formsop.h"

FormSop::FormSop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSop)
{
    ui->setupUi(this);

    QWidget* lTitleBar = ui->dockWidget->titleBarWidget();
    QWidget* lEmptyWidget = new QWidget();
    ui->dockWidget->setTitleBarWidget(lEmptyWidget);
    delete lTitleBar;

}

FormSop::~FormSop()
{
    delete ui;
}
