#ifndef FORMDEBUGSUB4_H
#define FORMDEBUGSUB4_H

#include <QWidget>

namespace Ui {
class FormDebugSub4;
}

class FormDebugSub4 : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebugSub4(QWidget *parent = nullptr);
    ~FormDebugSub4();

protected:
    virtual void changeEvent(QEvent * event);

private:
    Ui::FormDebugSub4 *ui;
};

#endif // FORMDEBUGSUB4_H
