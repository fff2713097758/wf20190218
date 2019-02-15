#ifndef DLGCHECK_H
#define DLGCHECK_H

#include <QDialog>

namespace Ui {
class DlgCheck;
}

class DlgCheck : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCheck(QWidget *parent = nullptr);
    ~DlgCheck();

protected:
    virtual void changeEvent(QEvent *);

private:
    Ui::DlgCheck *ui;
};

#endif // DLGCHECK_H
