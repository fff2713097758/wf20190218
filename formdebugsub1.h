#ifndef FORMDEBUGSUB1_H
#define FORMDEBUGSUB1_H

#include <QWidget>


namespace Ui {
class FormDebugSub1;
}

class FormDebugSub1 : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebugSub1(QWidget *parent = nullptr);
    ~FormDebugSub1();

protected:
    virtual void changeEvent(QEvent *);

private:

private:
    Ui::FormDebugSub1 *ui;
};

#endif // FORMDEBUGSUB1_H
