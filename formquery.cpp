#include "formquery.h"
#include "ui_formquery.h"

FormQuery::FormQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormQuery)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();

    QWidget* lTitleBar = ui->dockWidget->titleBarWidget();
    QWidget* lEmptyWidget = new QWidget();
    ui->dockWidget->setTitleBarWidget(lEmptyWidget);
    delete lTitleBar;

}

FormQuery::~FormQuery()
{
    delete ui;
}

void FormQuery::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        ui->retranslateUi(this);
    }else{
        QWidget::changeEvent(event);
    }
}
