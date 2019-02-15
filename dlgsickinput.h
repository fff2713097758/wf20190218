#ifndef DLGSICKINPUT_H
#define DLGSICKINPUT_H

#include <QDialog>

namespace Ui {
class DlgSickInput;
}

class DlgSickInput : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSickInput(QWidget *parent = nullptr);
    ~DlgSickInput();

protected:
    virtual void changeEvent(QEvent *);


private:
    Ui::DlgSickInput *ui;
};

#endif // DLGSICKINPUT_H
