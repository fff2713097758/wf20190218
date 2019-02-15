#ifndef FORMDEBUGSUB5_H
#define FORMDEBUGSUB5_H

#include <QWidget>

namespace Ui {
class FormDebugSub5;
}

class FormDebugSub5 : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebugSub5(QWidget *parent = nullptr);
    ~FormDebugSub5();

protected:
    virtual void changeEvent(QEvent * event);

private:
    Ui::FormDebugSub5 *ui;
};

#endif // FORMDEBUGSUB5_H
