#ifndef DLGLOAD_H
#define DLGLOAD_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class DlgLoad;
}

class DlgLoad : public QDialog
{
    Q_OBJECT

public:
    explicit DlgLoad(QWidget *parent = nullptr);
    ~DlgLoad();

protected:
    void paintEvent(QPaintEvent *) override;
    virtual void changeEvent(QEvent *);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_butOk_clicked();

    void on_butCancel_clicked();

private:
    Ui::DlgLoad *ui;
};

#endif // DLGLOAD_H
