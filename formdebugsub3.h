#ifndef FORMDEBUGSUB3_H
#define FORMDEBUGSUB3_H

#include <QWidget>

namespace Ui {
class FormDebugSub3;
}

class FormDebugSub3 : public QWidget
{
    Q_OBJECT

public:
    explicit FormDebugSub3(QWidget *parent = nullptr);
    ~FormDebugSub3();

protected:
    virtual void changeEvent(QEvent * event);

private:
    Ui::FormDebugSub3 *ui;
};

#endif // FORMDEBUGSUB3_H
