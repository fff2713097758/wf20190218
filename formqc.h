#ifndef QC_H
#define QC_H

#include <QWidget>
#include <QPushButton>


namespace Ui {
class FormQC;
}

class FormQC : public QWidget
{
    Q_OBJECT

public:
    explicit FormQC(QWidget *parent = nullptr);
    ~FormQC();

private:

protected:
    virtual void resizeEvent(QResizeEvent *event);

private slots:
    void on_butClose_clicked();

private:
    Ui::FormQC *ui;
};

#endif // QC_H
