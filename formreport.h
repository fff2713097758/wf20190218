#ifndef FORMREPORT_H
#define FORMREPORT_H

#include <QWidget>
#include <QTableWidget>
#include "formreportsub1.h"

namespace Ui {
class FormReport;
}

class FormReport : public QWidget
{
    Q_OBJECT

public:
    explicit FormReport(QWidget *parent = nullptr);
    ~FormReport();

protected:
    virtual void changeEvent(QEvent * event);


private slots:
    void on_toolButton_triggered(QAction *arg1);

    void on_toolButton_6_triggered(QAction *arg1);

private:
    FormReportSub1 * m_formReportSub1;

private:
    void resizeEvent(QResizeEvent *resizeEvent) override;

private:
    void init_sample_list();


private:
    Ui::FormReport *ui;
};

#endif // FORMREPORT_H
