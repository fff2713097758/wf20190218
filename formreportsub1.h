#ifndef FORMREPORTSUB1_H
#define FORMREPORTSUB1_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>

namespace Ui {
class FormReportSub1;
}

class FormReportSub1 : public QWidget
{
    Q_OBJECT

public:
    explicit FormReportSub1(QWidget *parent = nullptr);
    ~FormReportSub1();

protected:
    virtual void changeEvent(QEvent * event);

private slots:
    void on_buttonSickInput_clicked();

private:
    void init_micro_list();
    void init_chemic_list();
    void init_state_list();
    void init_sample_image();
    void init_chemic_image();
    void init_micro_image();

    void insert_table_row(QTableWidget * pTable, QString text);

    void load_sample_image(QString sampleDir);

    void load_image(QLabel * pLabel, QString imagePath);

    void resizeEvent(QResizeEvent *resizeEvent) override;

private:
    Ui::FormReportSub1 *ui;
};

#endif // FORMREPORTSUB1_H
