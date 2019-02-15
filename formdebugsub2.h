#ifndef FORMDEBUGSUB2_H
#define FORMDEBUGSUB2_H

#include <QWidget>

namespace Ui {
class FormDebugSub2;
}

class FormDebugSub2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebugSub2(QWidget *parent = nullptr);
    ~FormDebugSub2();

protected:
    virtual void changeEvent(QEvent * event);

private:
    Ui::FormDebugSub2 *ui;
};


#endif // FORMDEBUGSUB2_H
