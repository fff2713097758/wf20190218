#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>


namespace Ui {
class FormMain;
}

class FormMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain();

protected:
    virtual void changeEvent(QEvent * event);

private:
//    FormDebug * m_formDebug;

protected:

private slots:
    void on_butDebug_clicked();

    void on_butSet_clicked();

    void on_butUser_clicked();

    void on_butQC_clicked();

    void on_butImage_clicked();

    void on_butSop_clicked();

private:
    Ui::FormMain *ui;
};

#endif // FORMMAIN_H
